#!/bin/sh

cat << EOF > /dev/null

The code provided is supposed replace all the dots . in the specified String str with dashes -

But it's not working properly.

Task
Fix the bug so we can all go home early.

Notes
String str will never be null.

EOF

fixme() {
	echo $@ | tr '.' '-'
}

fixme "hello..."
fixme "sk. fejkfejo. ef.."

