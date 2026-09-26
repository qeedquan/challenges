#!/bin/sh

zip2john forensics-flag2.zip > zip.hash
john zip.hash
john --show zip.hash

