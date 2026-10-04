#!/usr/bin/env python3

"""

HDR imaging is the process of combining images of different exposure times from the camera to get different lighting responses in order to make the final image have more dynamic range (better contrast, nicer colors, etc)
The combination of images are processed in a larger colorspace than 8 bit RGB but reduced to 8 bits at the end, the colors generated is fused from multiple images so even with lower bitdepth we can still get better range

The camera response function (CRF) gives us the connection between the scene radiance to the measured intensity values.
Algorithms like Debevec and Robertson can be calibrated to approximate the the inverse CRF for correct lighting

The image brightness is proportional to the exposure time (longer=brighter, shorter=darker)

"""

import cv2 as cv
import numpy as np

img_fn = ["venice_over.jpg", "venice.jpg", "venice_under.jpg"]
img_list = [cv.imread(fn) for fn in img_fn]
exposure_times = np.array([10.0, 2.5, 0.25], dtype=np.float32)

merge_debevec = cv.createMergeDebevec()
hdr_debevec = merge_debevec.process(img_list, times=exposure_times.copy())
merge_robertson = cv.createMergeRobertson()
hdr_robertson = merge_robertson.process(img_list, times=exposure_times.copy())

tonemap1 = cv.createTonemap(gamma=2.2)
res_debevec = tonemap1.process(hdr_debevec.copy())

res_robertson = tonemap1.process(hdr_robertson.copy())

merge_mertens = cv.createMergeMertens()
res_mertens = merge_mertens.process(img_list)

res_debevec_8bit = np.clip(res_debevec*255, 0, 255).astype('uint8')
res_robertson_8bit = np.clip(res_robertson*255, 0, 255).astype('uint8')
res_mertens_8bit = np.clip(res_mertens*255, 0, 255).astype('uint8')

cv.imwrite("ldr_debevec.jpg", res_debevec_8bit)
cv.imwrite("ldr_robertson.jpg", res_robertson_8bit)
cv.imwrite("fusion_mertens.jpg", res_mertens_8bit)
