=begin

Description
I'm sure many of you in web application development are familiar with templating engines. At some level you can think of it as a huge string interpolation exercise, but with much more: looping and conditionals, for instance. Template engines exist in a variety of languages and styles, and seem to appear like rafts of fire ants after a flood, mostly focusing on speed.

Many immediately associate template engines with HTML output, but they can support any output, including text, configuration files (for instance Chef templates), and more.

For today's challenge, let's implement a subset of the Erb templating language:

<% %> - Denotes tag start and end.

<%= EXPRESSION %> — Inserts the value of an expression.

<% CODE %>— Executes code, but does not insert a value. This code may include loops and conditionals, and pair with an <% end %> tag.

Everything else is output without modification.

(Please note that Erb uses Ruby, and I'm not a Ruby programmer so if I messed up some syntax please let me know. Thanks.)

Example Input
You'll be given a simple template and a JSON data structure to use.

The JSON to use:

{"foo": "bar", "fizz": "buzz", "a": 1, "b": [1,2,3]}
And the example template, calling the above data:

Hello <%= @data["foo"] %>!
Example Output
The above should yield:

Hello bar!
Challenge Input
The JSON to use (and reference as data):

{
    "store_name": "Barry's Farmer's Market",
    "foods": {
        "apple": "5.91",
        "peach": "1.84",
        "carrot": "6.44",
        "beans": "3.05",
        "orange": "5.75",
        "cucumber": "6.42"
    },
    "store_location": "Corner of Elm Tree Hill and 158th Street"
}
And the template to use:

<head>
<title>Local Farmer's Market: <%= data["store_name"] %></title>
</head>
<body>
<table>
<th>Food</th>
<th>Price (10 lbs)</th>
<thead>
</thead>
<tbody>
<% data["foods"].each do |k,v| %>
<tr>
<td><%= k %></td>
<td><%= v %></td>
</tr>
<% end %>
</tbody>
</table>
</body>

=end

# ported from @mn-haskell-guy solution

require "json"
require "pp"

def escape_html(s)
  return s.gsub(/[<>&"']/, "<" => "&lt;", ">" => "&gt;", "&" => "&amp;", '"' => "&quot;", "'" => "&#039;" )
end

def quote_hashes(s)
  return s.gsub(/#/, '\\#')
end

def parse(template)
  template << "<%%>"
  statements = Array.new
  parts = template.scan(/(.*?)<%([=]?)(.*?)%>/m)
  parts.each { |x| 
    pre = x[0]
    kind = x[1]
    body = x[2]
    if pre.length > 0
      statements  << ("print %q#" + quote_hashes(pre) + "#")
    end
    if kind == "="
      statements << ("print escape_html((" + body + ").to_s)")
    else
      statements << body
    end
  }
  return statements.join(";\n")
end

data = JSON.parse(File.read("input.json"))
template = File.read("template.erb")
code = parse(template)
eval(code)
