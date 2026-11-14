#!/usr/bin/env python3

"""

Jason has a big JSON but it's unreadable, so he needs to prettify it.

Formatting Spec
The JSON has 4 different types:

Numbers; Just 0-9
Strings; Double quoted " strings escaped with \
Arrays; Delimited by [], with items separated by ,, items can be any of these types
Objects; Delimited by {}, format is key: value where key is a string and value is any of these types
Spacing

Arrays should have exactly one space after the commas between items
Objects should have have just one space between the key and the value, after the :
Indentation

Each nesting level is indented 2 more than the previous
Each object key/value pair is always on its own line. Objects are indented
An array is indented across multiple lines if it contains another array or object. Otherwise the array remains on one line

Rules
Built-ins which trivialize this task are not allowed.
As always standard loopholes are disallowed

Examples
[1,2,3]
[1, 2, 3]
{"a":1,"b":4}
{
  "a": 1,
  "b": 4
}
"foo"
"foo"
56
56
{"a":[{"b":1,"c":"foo"},{"d":[2,3,4,1], "a":["abc","def",{"d":{"f":[3,4]}}]}]}
{
  "a": [
    {
      "b": 1,
      "c": "foo"
    },
    {
      "d": [2, 3, 4, 1],
      "a": [
        "abc",
        "def",
        {
          "d": {
            "f": [3, 4]
          }
        }
      ]
    }
  ]
}
[2,["foo123 ' bar \" baz\\", [1,2,3]]]
[
  2,
  [
    "foo123 ' bar \" baz\\",
    [1, 2, 3]
  ]
]
[1,2,3,"4[4,5]"]
[1, 2, 3, "4[4,5]"]
[1,2,3,{"b":["{\"c\":[2,5,6]}",4,5]}]
[
  1,
  2,
  3,
  {
    "b": ["{\"c\":[2,5,6]}", 4, 5]
  }
]

"""

import json

JSON1 = '[1,2,3]'
JSON2 = '{"a":1,"b":4}'
JSON3 = '"foo"'
JSON4 = '56'
JSON5 = '{"a":[{"b":1,"c":"foo"},{"d":[2,3,4,1], "a":["abc","def",{"d":{"f":[3,4]}}]}]}'
JSON6 = '[2,["foo123 \' bar \\" bazz\\\\", [1,2,3]]]'
JSON7 = '[1,2,3,"4[4,5]"]'
JSON8 = '[1,2,3,{"b":["{\\\"c\\\":[2,5,6]}",4,5]}]'

def jsonfmt(src):
    return json.dumps(json.loads(src), indent=4)

def main():
    print(jsonfmt(JSON1))
    print(jsonfmt(JSON2))
    print(jsonfmt(JSON3))
    print(jsonfmt(JSON4))
    print(jsonfmt(JSON5))
    print(jsonfmt(JSON6))
    print(jsonfmt(JSON7))
    print(jsonfmt(JSON8))

main()
