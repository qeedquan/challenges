#!/bin/bash

cat << EOF >/dev/null

XPath is a very valuable tool, often used for querying XML databases. XPath queries (or close variants) are also used in the process of Web Scraping while retreiving data from structured XHTML-compliant web pages, specially those with tabulated data.

A quick XPath tutorial is available here.

Provided XML Fragment and Task Description

Assume that you have been provided the fragment of XML, shown below. Your task is to write the XPath selector for finding the number of characters (i.e, the string-length) of the description of the second movie in the XML file.

The Ruby code for handling input, output and document construction has already been provided. You only need to fill up the required blanks as indicated in the template code provided. This challenge is agnostic to language-specific knowledge and you do not require to know ruby - as only the XPath selector needs to be completed by you.

<collection shelf="Classics">
<movie title="The Enemy" shelf="A">
   <type>War, Thriller</type>
   <format>DVD</format>
   <year>2001</year>
   <rating>PG</rating>
   <popularity>10</popularity>
   <description>Talk about a war</description>
</movie>
<movie title="Transformers" shelf="B">
   <type>Science Fiction</type>
   <format>DVD</format>
   <year>1980</year>
   <rating>R</rating>
   <popularity>7</popularity>
   <description>Science Fiction</description>
</movie>
   <movie title="Trigun" shelf="B">
   <type>Action</type>
   <format>DVD</format>
   <episodes>4</episodes>
   <rating>PG</rating>
   <popularity>10</popularity>
   <description>Quite a bit of action!</description>
</movie>
<movie title="Ishtar" shelf="A">
   <type>Comedy</type>
   <format>VHS</format>
   <rating>PG</rating>
   <popularity>2</popularity>
   <description>Boring</description>
</movie>
</collection>
Expected Output

15
Your code will also be run against a hidden test case, which is similar in schema and format to the XML fragment shown above - only some of the values in the fields will be changed. This is to prevent the submission of hard-coded answers.

EOF

read -r -d '' XML << EOF
<?xml version="1.0"?>
<collection shelf="Classics">
  <movie title="The Enemy" shelf="A">
    <type>War, Thriller</type>
    <format>DVD</format>
    <year>2001</year>
    <rating>PG</rating>
    <popularity>10</popularity>
    <description>Talk about a war</description>
  </movie>
  <movie title="Transformers" shelf="B">
    <type>Science Fiction</type>
    <format>DVD</format>
    <year>1980</year>
    <rating>R</rating>
    <popularity>7</popularity>
    <description>Science Fiction</description>
  </movie>
  <movie title="Trigun" shelf="B">
    <type>Action</type>
    <format>DVD</format>
    <episodes>4</episodes>
    <rating>PG</rating>
    <popularity>10</popularity>
    <description>Quite a bit of action!</description>
  </movie>
  <movie title="Ishtar" shelf="A">
    <type>Comedy</type>
    <format>VHS</format>
    <rating>PG</rating>
    <popularity>2</popularity>
    <description>Boring</description>
  </movie>
</collection>
EOF

echo $XML | xmllint --xpath "string-length(/collection/movie[2]/description)" -
