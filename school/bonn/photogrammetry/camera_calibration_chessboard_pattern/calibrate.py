#!/usr/bin/env python3

"""

https://docs.opencv.org/4.x/da/d0d/tutorial_camera_calibration_pattern.html
https://learnopencv.com/camera-calibration-using-opencv/
https://docs.opencv.org/4.x/dc/dbb/tutorial_py_calibration.html
https://en.wikipedia.org/wiki/Distortion_(optics)

Cameras calibration consist of estimating the intrinsic and extrinsic matrix to correct for imperfections as cameras in the real world are not perfect pinhole cameras.

The intrinsic matrix accounts for the camera characteristic such as focal length and centers
The extrinsic matrix accounts for the orientation and position of the camera in world space

Another name for the intrinsic matrix is the camera matrix

The projection matrix is:
P = K * (R | t) where K=intrinsic and (R | t)=extrinsic

Intrinsic Matrix:
K = [fx skew cx]
    [0  fy   cy]
    [0  0    1]

(fx, fy) = focal length (scale)
(cx, cy) = camera center of the image (translation)
skew     = skew factor of x vs y axis (shear), usually 0 for alot of cameras

A real camera also has a set of distortion parameters that makes the captured image bulge out in or out (straight lines are warped at the output)
Here are some common names for the distortions that can occur:
Radial distortions: Barrel, Fisheye, Pincushion, Mustache
Translational distortion: Tangential (Decentering)

Mathematically the distortion formula is as follows:
Radial distortion:
    x_distorted = x*(1 + k1*r^2 + k2*r^4 + k3*r^6)
    y_distorted = y*(1 + k1*r^2 + k2*r^4 + k3*r^6)

Translational distortion:
    x_distorted = x + (2*p1*x*y         + p2*(r^2 + 2*x^2))
    y_distorted = y + (p1*(r^2 + 2*y^2) + 2*p2*x*y)

The distortion coefficients are then (k1, k2, p1, p2, k3) for characterizing the radial/translational distortion

One common way to calibrate the camera is to take pictures of a chessboard pattern and see how it distorts the lines through the camera
A chessboard pattern is useful because it is easy to find edges/corners and estimate lines start/ending on it

"""

import numpy as np
import cv2

def calibrate(image_file, pattern_size):
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
 
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((pattern_size[0]*pattern_size[1], 3), np.float32)
    objp[:,:2] = np.mgrid[0:pattern_size[0], 0:pattern_size[1]].T.reshape(-1,2)
 
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
 
    img = cv2.imread(image_file)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    ret, corners = cv2.findChessboardCorners(gray, pattern_size, None)
    if ret == True:
        objpoints.append(objp)

    corners2 = cv2.cornerSubPix(gray,corners, (11, 11), (-1,-1), criteria)
    imgpoints.append(corners2)

    print("Corners:")
    print(corners2)
    print()

    # draw the chessboard corners to see to see how the corners
    cv2.drawChessboardCorners(img, pattern_size, corners2, ret)
    cv2.imwrite('corners.png', img)

    # calibrate the camera using the corner correspondences with the dots positions
    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
   
    print("Intrinsic Camera Matrix:")
    print(mtx)
    print()

    print("Distortion Coefficients:")
    print(dist)
    print()

    print("Rotation Vectors:")
    print(rvecs)
    print()

    print("Translation Vectors:")
    print(tvecs)
    print()

    # take into account of scaling by generating a new camera matrix for the distorted image
    h, w = img.shape[:2]
    newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))
    
    # undistort using the intrinsic matrix and distortion coefficient
    dst = cv2.undistort(img, mtx, dist, None, newcameramtx)
    # crop the fixed image and output it
    x, y, w, h = roi
    dst = dst[y:y+h, x:x+w]
    cv2.imwrite('calibresult.png', dst)

    mean_error = 0
    for i in range(len(objpoints)):
        imgpoints2, _ = cv2.projectPoints(objpoints[i], rvecs[i], tvecs[i], mtx, dist)
        error = cv2.norm(imgpoints[i], imgpoints2, cv2.NORM_L2)/len(imgpoints2)
        mean_error += error
    print( "Total error: {}".format(mean_error/len(objpoints)) )

def main():
    calibrate("pattern.png", (9, 6))

main()
