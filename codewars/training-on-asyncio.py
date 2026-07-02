#!/usr/bin/env python3

"""

Story
As you walk the streets with your crush beside you, you are thinking about the world and how everything works... Wait!! Your crush? Shit, you are dreaming again.

Task
Now implement a coroutine dreaming which sleeps for n seconds and then returns m ** n without entirely blocking the execution of other coroutines that might be running.

Note
0 < n < 7

0 < m < 100

"""

import asyncio

async def dreaming(n, m):
    await asyncio.sleep(n)
    print(m**n)
    return m**n

async def main():
    task1 = asyncio.create_task(dreaming(3, 50))
    task2 = asyncio.create_task(dreaming(1, 3))
    task3 = asyncio.create_task(dreaming(2, 56))
    value1 = await task1
    value2 = await task2
    value3 = await task3
    print(value1, value2, value3)

asyncio.run(main())
