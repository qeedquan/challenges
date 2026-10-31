#!/bin/sh

set -e

SITE=127.0.0.1:8080

request() {
	sid=$(uuidgen)
	secret=$(curl -s -b "session_id=$sid" $SITE)
	echo "Secret:" $secret

	answer=$((100 - $secret))
	echo "Answer:" $answer

	curl -s -b "session_id=$sid; answer=$answer" $SITE
	echo
}

for i in $(seq 1000); do
	request
done
