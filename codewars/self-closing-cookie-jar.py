#!/usr/bin/env python3

"""

When you were little, your mother used to make the most delicious cookies, which you could not resist. So, every now and then, when your mother didn't see you, you sneaked into the kitchen, climbed onto a stool to reach the cookie jar, and stole a cookie or two. However, sometimes while doing this, you would hear foot steps approaching, so you quickly jumped down from the stool and, when your mother entered the kitchen, you pretended as if nothing had happened (whistle, whistle innocently). However, your mother knew. How did she know? You forgot to put the lid back on the cookie jar! Oh, no!

Growing older (and still not able to resist your mother's cookies), you deviced a contraption that would automatically put the lid back on the cookie jar, no matter what would happen.

The class CookieJar is provided:

class CookieJar(object):

    def __init__(self):
        self._is_open = False

    def take(self):
        if not self._is_open:
            raise ValueError("Cookie jar is closed")
        return "Cookie"

    def open_jar(self):
        self._is_open = True

    def close_jar(self):
        self._is_open = False

    def is_open(self):
        return self._is_open
Your task is to implement the 'contraption' SelfClosing (class, method, whatever; it's your choice) such that, given an instancecookie_jar of CookieJar, you may call:

with SelfClosing(cookie_jar) as jar:
    cookie = jar.take()
after which, cookie_jar.is_open() == False, no matter what.

Do not alter the provided code. (Tests will be performed with a code that differs slightly from the one provided, so modifying it is to no avail.)

Enjoy!

"""

class CookieJar(object):
    def __init__(self):
        self._is_open = False

    def take(self):
        if not self._is_open:
            raise ValueError("Cookie jar is closed")
        return "Cookie"

    def open_jar(self):
        self._is_open = True

    def close_jar(self):
        self._is_open = False

    def is_open(self):
        return self._is_open


class SelfClosing:
    def __init__(self, jar):
        self.jar = jar

    def __enter__(self):
        self.jar.open_jar()
        return self.jar

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.jar.close_jar()

jar = CookieJar()
SelfClosing(jar)
try:
    print(jar.take())
except Exception as ex:
    print(ex)

