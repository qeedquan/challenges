#!/bin/sh

MODEL="qwen3.8"

while true; do
	echo -n "User) "
	read -r request
	echo $request | espeak-ng
	response=$(echo $request | ollama run "$MODEL")
	echo "Bot) $response"
	echo $response | espeak-ng -ven+f4
done
