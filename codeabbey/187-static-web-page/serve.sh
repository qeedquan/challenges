#!/bin/sh

cat << EOF >/dev/null

This problem is the first in a short series which is dedicated to creating your own web-pages. Next one is Basics of HTML.

To start you need to choose some web-hosting (I suppose, free one) where you will create your stuff. If you do not know much about it, please refer either to hosting choice instruction or (perhaps, better) to the video below, which demonstrates using free and powerful Github-Pages service to host your site.

https://www.youtube.com/watch?v=x-AGsmF7d2g

Now the first task would be just to learn how to register at your chosen hosting, create your site and upload a single file there. I recommend it to have .txt extension since it has no special markup.

In the input data below you will see a "secret value" - you will use it in your file (so that we can check your success). The content should be exactly like this:

Secret value is ########
Where instead hashes the requested number is following.

Input data will contain a secret value (integer).
Answer should contain full url of the page you uploaded (please use either http: or https: prefix explicitly).

Example:

input data:
314159

answer:
http://codeabbey.github.io/data/static-web-page.txt
If you visit http://codeabbey.github.io/data/static-web-page.txt you'll see how your own "page" should look like.

EOF

python3 -m http.server 8080

