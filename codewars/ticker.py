#!/usr/bin/env python3

"""

While using public transport we could see simple displays with a ticker. It often provides information about next stations and expected arrival time.

Let's implement a function which will return a chunk of text to be displayed on a display of fixed width. The function should take text to display, width of the display and tick as a step of the ticker. The function will be called many times with tick parameter constantly incrementing.

At very beginning the display is empty. At first step only one character should be displayed in the most right position and so on. When the message is displayed, it should be dissapear char by char to left position and return to blank state of the display. After that cycle should start again.

For example

ticker('Hello world!', 10, 4)   // '      Hell'
We could expect that our function will be called from simple script like this one

const demo = (text, width) => {
  let tick = 0;
  setInterval(_ => {
    someDisplayFunction(ticker(text, width, tick));
    tick++
  }, 100);
}

"""

def ticker(text, width, tick):
    output = ' '*width + text + ' '*width
    index0 = tick % (len(output) - width)
    index1 = index0 + width
    return output[index0:index1]

def main():
    assert(ticker("Hello world!", 10, 4) == "      Hell")
    assert(ticker("Beautiful is better than ugly.", 10, 0) == "          ")
    assert(ticker("Beautiful is better than ugly.", 10, 5) == "     Beaut")
    assert(ticker("Beautiful is better than ugly.", 10, 30) == "than ugly.")
    assert(ticker("Beautiful is better than ugly.", 10, 39) == ".         ")
    assert(ticker("Beautiful is better than ugly.", 10, 41) == "         B")

main()
