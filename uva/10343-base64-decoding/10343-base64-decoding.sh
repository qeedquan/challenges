#!/bin/sh

solve() {
	echo $@ | base64 -d
	echo "#"
}

solve "VGhpc0lzVGVzdA=="
solve "QSBUZXN0IElucHV0W3soKX1d"
