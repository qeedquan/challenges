#!/usr/bin/env lua

--[[

All these functional languages that return the same value every time a function is called give me a headache.

Your task is to write a function that returns something different every time it is called.

Here are the rules:

Your function must continue to return something different every time it is run

It must return a different value on your computer than it does on my computer

Your function must be guaranteed to be different (no random numbers)

+20 if your code gets time from the system or an online clock

--]]

function sleep(t)
	local sec = tonumber(os.clock() + t)
	while (os.clock() < sec)
	do
	end
end

function f()
	sleep(1)
	math.randomseed(os.time())
	return math.random()
end

print(f())
