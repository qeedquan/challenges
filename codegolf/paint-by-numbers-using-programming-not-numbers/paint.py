#!/usr/bin/env python3

"""

Your task is to create a program which takes a black-and-white outlined image (example images are below) and fills it in with colour. It is up to you how you section off each region and which colour to fill it with (you could even use an RNG).

For example:
https://i.sstatic.net/IW9gZ.jpg

As you can see I am clearly an artist of a superior calibre when it comes to MS Paint.

Scoring
This is a popularity contest, so the answer with the most net votes wins. Voters are encouraged to judge answers by

Input criterion: any image that consists of white/light-grey background and black/dark-grey outlines
How well the colouring is done; meaning few or no areas are white unlike the above (unless you obviously intend to use white e.g. for clouds)
Customisability of the colours used in certain sections
How well the system works on a range of different images (of varying detail)
Post how long your program takes per image. We might not be playing code golf, but shorter, faster and more efficient code should be regarded as better
Should output the new image either onto the screen or to a file (no larger than 2MB so that it can be shown in the answer)
Please justify why you chose to output to that image type and comment/explain the workings of your code
The applicability of the colour used to the respective shape it is bound by (realistic colour scheme i.e. grass is green, wooden fences are brown etc.)
"I could randomly color each area, but if I could identify the "fence" and make it similarly colored, then that's something that deserves upvotes." - NathanMerrill

Seeing as this is a popularity contest, you can also optionally judge by:

Overall appeal (how good the image looks)
Artistic flair; if you can program in shading or watercolour-style colouring etc.
In general, the smallest outputted image (file size) of the highest quality, with the fasted program and the highest public vote will win.

If you have other judging specifications that you think should be used, please recommend them in the comments of this post.

Examples
I own nothing; all example images are of a creative commons license.

Source: https://pixabay.com/ro/stejar-arbore-schi%C5%A3%C4%83-natura-303890/

Source: http://www.freestockphotos.biz/stockphoto/10665

Source: http://crystal-rose1981.deviantart.com/art/Dragon-Tattoo-Outline-167320011

Source: http://jaclynonacloudlines.deviantart.com/art/Gryphon-Lines-PF-273195317

Source: http://captaincyprus.deviantart.com/art/Dragon-OutLine-331748686

Source: http://electric-meat.deviantart.com/art/A-Heroes-Farewell-280271639

Source: http://movillefacepalmplz.deviantart.com/art/Background-The-Pumpkin-Farm-of-Good-old-Days-342865938

EDIT: Due to anti-aliasing on lines causing non-black/white pixels and some images that may contain grey instead of black/white, as a bonus challenge you can attempt to deal with it. It should be easy enough in my opinion.

"""

"""

Ported from @N. Virgo solution

This uses a sophisticated mathematical algorithm to produce colourful nonsense. The algorithm is related to Google's PageRank algorithm, but for pixels instead of web pages.

I took this approach because I thought that unlike flood-fill based methods it might be able to cope with images like the chicken and the tree, where there are shapes that aren't entirely enclosed by black lines. As you can see, it sort of works, though it also tends to colour in different parts of the sky in different colours

For the mathematically minded: what it's doing is essentially constructing the adjacency graph of the while pixels in the image, then finding the top 25 eigenvectors of the graph Laplacian. (Except it's not quite that, because we do include the dark pixels, we just give their connections a lower weight. This helps in dealing with antialiasing, and also seems to give better results in general.) Having found the eigenvectors, it creates a random linear combination of them, weighted by their inverse eigenvalues, to form the RGB components of the output image.

In the interests of computation time, the image is scaled down before doing all this, then scaled back up again and then multiplied by the original image. Still, it does not run quickly, taking between about 2 and 10 minutes on my machine, depending on the input image, though for some reason the chicken took 17 minutes.

It might actually be possible to turn this idea into something useful, by making an interactive app where you can control the colour and intensity of each of the eigenvectors. That way you could fade out the ones that divide the sky into different sections, and fade in the ones that pick up on relevant features of the image. But I have no plans to do this myself :)

"""

import sys
from PIL import Image
import numpy as np
import scipy.sparse as sp
import scipy.sparse.linalg as spl
import os
import time

start_time = time.time()

if len(sys.argv) < 2:
    print("usage: <image>")
    exit(2)
filename = sys.argv[1]
img = Image.open(filename)
orig_w, orig_h = img.size

# convert to monochrome and remove any alpha channel
# (quite a few of the inputs are transparent pngs)
img = img.convert('LA')
pix = img.load()
for x in range(orig_w):
    for y in range(orig_h):
        l, a = pix[x,y]
        l = (255-a) + a*l//255
        a = 255
        pix[x, y] = l, a
img = img.convert('L')

orig_img = img.copy()

# resize to 300 pixels wide - you can get better results by increasing this,
# but it takes ages to run
orig_w, orig_h = img.size
print("working on image", filename)
print("original size:", str(orig_w)+ ', ' + str(orig_h))
new_w = 300
img = img.resize((new_w, orig_h*new_w//orig_w), Image.LANCZOS)

pix = img.load()
w, h = img.size
print("resizing to", str(w)+ ', '+ str(h))

def coords_to_index(x, y):
    return x*h+y

def index_to_coords(i):
    return (int(i/h), i%h)

print("creating matrix")

A = sp.lil_matrix((w*h, w*h))

def setlink(p1x, p1y, p2x, p2y):
    i = coords_to_index(p1x, p1y)
    j = coords_to_index(p2x, p2y)
    ci = pix[p1x,p1y]/255.
    cj = pix[p2x,p2y]/255.
    if ci*cj > 0.9:
        c = 1
    else:
        c =  0.01
    A[i,j] = c
    return c

for x in range(w):
    for y in range(h):
        d = 0.
        if x>0:
            d += setlink(x, y, x-1, y)
        if x<w-1:
            d += setlink(x, y, x+1, y)
        if y>0:
            d += setlink(x, y, x, y-1)
        if y<h-1:
            d += setlink(x, y, x, y+1)
        i = coords_to_index(x, y)
        A[i,i] = -d

A = A.tocsr()

# the greater this number, the more details it will pick up on. But it increases
# execution time, and after a while increasing it won't make much difference
n_eigs = 25

print("finding eigenvectors (this may take a while)")
L, V = spl.eigsh(A, k=n_eigs, tol=1e-12, which='LA')

print("found eigenvalues", L)

out = Image.new("RGB", (w, h), "white")
out_pix = out.load()

print("painting picutre")

V = np.real(V)
n = np.size(V,0)
R = np.zeros(n)
G = np.zeros(n)
B = np.zeros(n)

for k in range(n_eigs-1):
    weight = 1./L[k]
    R = R + V[:, k]*np.random.randn()*weight
    G = G + V[:, k]*np.random.randn()*weight
    B = B + V[:, k]*np.random.randn()*weight

R -= np.min(R)
G -= np.min(G)
B -= np.min(B)
R /= np.max(R)
G /= np.max(G)
B /= np.max(B)

for x in range(w):
    for y in range(h):
        i = coords_to_index(x,y)
        r = R[i]
        g = G[i]
        b = B[i]
        pixval = tuple(int(v*256) for v in (r, g, b))
        out_pix[x, y] = pixval

out = out.resize((orig_w, orig_h), Image.LANCZOS)
out_pix = out.load()
orig_pix = orig_img.load()

for x in range(orig_w):
    for y in range(orig_h):
        r, g, b = out_pix[x, y]
        i = orig_pix[x, y]/255.
        out_pix[x, y] = tuple(int(v*i) for v in (r, g, b))

fname, extension = os.path.splitext(filename)
out.save('out_' + fname + '.png')

print("completed in %s seconds" % (time.time() - start_time))
