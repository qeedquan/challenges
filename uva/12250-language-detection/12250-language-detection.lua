#!/usr/bin/env lua

function detect(s)
	tab = {
		["HELLO"] = "ENGLISH",
		["HOLA"] = "SPANISH",
		["HALLO"] = "GERMAN",
		["BONJOUR"] = "FRENCH",
		["CIAO"] = "ITALIAN",
		["ZDRAVSTVUJTE"] = "RUSSIAN",
	}
	
	l = tab[s]
	if l == nil then
		l = "UNKNOWN"
	end
	
	return l
end

assert(detect("HELLO") == "ENGLISH")
assert(detect("HOLA") == "SPANISH")
assert(detect("HALLO") == "GERMAN")
assert(detect("BONJOUR") == "FRENCH")
assert(detect("CIAO") == "ITALIAN")
assert(detect("ZDRAVSTVUJTE") == "RUSSIAN")
assert(detect("???") == "UNKNOWN")
