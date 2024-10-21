#!/usr/bin/env python3

"""

I am trying my hand at writing super small programs. I wrote a simple "tree" display program for showing a graphical representation of a folder hierarchy. I have made it small in all the ways I can think of. I was just wondering if you guys had more creative ways to "minify" it further. Here is the small version as well as a human-readable version.

import os,os.path as p
def w(c,d,s):
    a=os.listdir(c);s=s+'|';i=0
    for f in a:
        print s+'--'+f;j=p.join(c,f);
        if p.isdir(j):w(j,d+1,s[:-i==len(a)-1]+'  '*(d+1));i=i+1
def t(c):print c;w(c,0,'')
t(p.curdir)
That's a total of 236 bytes

import os

def treeWrap(curdir,depth,pipeStr):
    files = os.listdir(curdir)
    pipeStr = pipeStr + '|'
    for f in files:
        print pipeStr + '--' + f
        if os.path.isdir(os.path.join(curdir,f)):
            dir = os.path.join(curdir,f)
            if files.index(f) == (len(files)-1):
                treeWrap(dir,depth+1,pipeStr[:-1] + '  '*(depth+1))
            else:
                treeWrap(dir,depth+1,pipeStr + '  '*(depth+1))

def tree(curdir):
    print curdir
    treeWrap(curdir,0,'')

tree(os.path.curdir)

Oh, in addition, does anyone know how I can use the unicode ├,└,─ in this program? Whenever I use them they appear as garbage in the console and the idle interpreter.

"""

import os
import sys

def walk(curdir, depth, pipe):
    try:
        files = os.listdir(curdir)
        pipe = pipe + '|'
        for f in files:
            print(pipe + '--' + f)
            if os.path.isdir(os.path.join(curdir,f)):
                dir = os.path.join(curdir,f)
                if files.index(f) == (len(files)-1):
                    walk(dir, depth + 1, pipe[:-1] + '  ' * (depth + 1))
                else:
                    walk(dir, depth + 1, pipe + '  ' * (depth + 1))
    except Exception as exception:
        print((depth + 1) * '  ' + str(exception))


def tree(curdir):
    print(curdir)
    walk(curdir, 0, '')

def main():
    dir = os.path.curdir
    if len(sys.argv) > 1:
        dir = sys.argv[1]
    tree(dir)

main()
