#!/usr/bin/env python33

"""

Your job is to open a browser window of the default browser to http://codegolf.stackexchange.com.

Your code must open the browser itself, and cannot rely on an open one.

This is code-golf, so the shortest answer in bytes wins.

"""

import webbrowser

def main():
    webbrowser.open("http://codegolf.stackexchange.com")

main()
