#!/usr/bin/env python3

r"""

A Tiefling is a character race, from Dungeons and Dragons, that has this list of possible traits:

small horns
fangs or sharp teeth
a forked tongue
catlike eyes
six fingers on each hand
goat-like legs
cloven hoofs
a forked tail
leathery or scaly skin
red or dark blue skin
cast no shadow or reflection
exude a smell of brimstone.
Given a list of Tiefling traits as input, randomly pick 1d4 + 1 (uniform distribution from 2-5) traits from that list and output them.

This challenge uses the standard definition of random, and the number and trait selection from the list must separately conform to definition 1 from here:

All possible [numbers] should be produced with the same probability;
All possible [traits] should be produced with the same probability;
You are allowed to pick randomly from the list by first shuffling it and taking the top 1d4+1 traits, so long as the shuffle does not favour any item in the list. Repeat selections of the same trait are not allowed.

Here is a non-golfed implementation in Javascript:

const dice = (n, s, a, doSum) => {
  const die = () => Math.floor(Math.random() * s) + 1;
  const dieResults = Array.from(Array(n)).map(each => {
    return die();
  });
  const sum = dieResults.reduce((sum, curr) => sum + curr + a, 0);
  // logging not required here
  console.log(`rolled '${dieResults.join(` + ${a}, `)} + ${a}${doSum ? ` = ${sum}`:''}'`);
  return doSum ? dieResults.reduce((sum, curr) => sum + curr + a, 0) : dieResults.map(each => each + a);
};

const shuffleSlice = (num, array) => array
  .map(value => ({
    value,
    sort: Math.random()
  }))
  .sort((a, b) => a.sort - b.sort)
  .map(({
    value
  }) => value).slice(0, num);

// you can take the list as a string or an actual list
const tieflingTraits = "small horns; fangs or sharp teeth; a forked tongue; catlike eyes; six fingers on each hand; goat-like legs; cloven hoofs; a forked tail; leathery or scaly skin; red or dark blue skin; cast no shadow or reflection; exude a smell of brimstone".split(/;\s+/);

// calling the function
console.log(shuffleSlice(dice(1, 4, 1, true), tieflingTraits))

// outputs like
//  ['goat-like legs', 'cast no shadow or reflection', 'a forked tongue']

"""

from random import *

def gen(a):
    return sample(a, randint(2, 5))

def main():
    for i in range(5, 50):
        print(gen(range(i)))

main()
