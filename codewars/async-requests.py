#!/usr/bin/env python3

"""

Async Request Manager
Your task is it to implement a coroutine which sends n requests and concats the returned strings of each response to one string.

A request can be made by invoking the prebuild coro send_request. When invoked, the coro sleeps for 1 sec and then returns a single character.

Your overall task is to implement an async request_manager which completes all n requests in under 1.5 sec

Summary:
Implement a coro request_manager which sends and processes fake requests

It accepts the parameter n which represents the amount of requests that should be made

Requests have to be made with send_request

send_request is a preloaded coroutine : (coro) send_request() -> str

It takes 1 sec until a character is returned to the caller

The waiting time is implemented via asyncio.sleep

Characters returned by send_request have to be concat to one string

That string is then returned by your request_manager

The characters in the string need to be ordered, so that the character returned by the first request is at index 0, the character returned by the second request is at index 1 etc.

Your request_manager has 1.5 sec to start & process all n requests and to return the desired string

Good Luck, should be easy :)

"""

from preloaded import send_request
import asyncio

async def request_manager(n: int) -> str:
    return ''.join(await asyncio.gather(*(send_request() for _ in range(n))))

