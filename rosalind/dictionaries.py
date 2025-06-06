#!/usr/bin/env python3

"""

Intro to Python dictionary

We've already used lists and strings to store and process data. Python also has a variable type called a "dictionary" that is similar to a list, but instead of having integer indices, you provide your own index, called a "key". You can assign data to a dictionary as follows: phones = {'Zoe':'232-43-58', 'Alice':'165-88-56'}. We can therefore think of a dictionary as a "function" that maps a collection of keys to values. As with lists, the values of the list can be of any type: strings, integers, floating point numbers, even lists or dictionaries themselves. For keys you can use only strings, numbers, floats and other immutable types. Accessing values of a dictionary is also similar to accessing values of a list:

phones = {'Zoe':'232-43-58', 'Alice':'165-88-56'}
print phones['Zoe']
Here, the output should be:

232-43-58
Adding new values to a dictionary or assigning a new value to an existing key can be done as follows:

phones['Zoe'] = '658-99-55'
phones['Bill'] = '342-18-25'
print phones
This should produce the following:

{'Bill': '342-18-25', 'Zoe': '658-99-55', 'Alice': '165-88-56'}
Note that the new 'Bill' appeared in the beginning of the dictionary, not in the end, as you might expect. Dictionaries do not have an obvious ordering.

Remember that dictionaries are case-sensitive if you are using strings as keys. For example, 'key' and 'Key' are viewed as different keys:

d = {}
d['key'] = 1
d['Key'] = 2
d['KEY'] = 3
print d
Output:

{'KEY': 3, 'Key': 2, 'key': 1}
Note how we created an empty dictionary with d = {}. This could be useful in case you need to add values to dictionary dynamically (for example, when reading a file). If you need to check whether there a key in dictionary, you can use key in d syntax:

if 'Peter' in phones:
    print "We know Peter's phone"
else:
    print "We don't know Peter's phone"
Output:

We don't know Peter's phone
In case you need to delete a value from a dictionary, use the del command:

phones = {'Zoe':'232-43-58', 'Alice':'165-88-56'}
del phones['Zoe']
print phones
This produces the following output:

{'Alice': '165-88-56'}
Problem
Given: A string s of length at most 10000 letters.

Return: The number of occurrences of each word in s, where words are separated by spaces. Words are case-sensitive, and the lines in the output can be in any order.

Sample Dataset
We tried list and we tried dicts also we tried Zen
Sample Output
and 1
We 1
tried 3
dicts 1
list 1
we 2
also 1
Zen 1

To iterate over the words in a string, you can split it at each occurrence of empty space as follows:

for word in str.split(' '):
    print word
For a pretty representation when outputting a dictionary, you can use the built in .items() function:

for key, value in dict.items():
    print key
    print value

"""

def wordcount(sentence):
    result = {}
    for word in sentence.split(" "):
        if word not in result:
            result[word] = 0
        result[word] += 1
    return result

def main():
    print(wordcount("We tried list and we tried dicts also we tried Zen"))

main()
