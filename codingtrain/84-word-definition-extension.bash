#!/bin/bash

API_KEY="a2a73e7b926c924fad7001ca3111acd55af2ffabf50eb4ae5"

definition() {
	word="$@"
	wordesc=${word/ /%20}
	curl --silent https://api.wordnik.com/v4/word.json/"$wordesc"/"definitions?limit=1&includeRelated=false&sourceDictionaries=all&useCanonical=false&includeTags=false&api_key"="$API_KEY" 
}

definition $@ | jq -r '.[0].text' | cowsay 
