/*

I wanted to write some classes for dogs. In my model dogs either bark or sleep. I know that it is popular practice to set default values like this

var value = value || DEFAULT_VALUE

And so i did. But something is wrong, and I don't know why. Can you help me out?

*/

const BARK = 'woof woof';
const SLEEP = 'zzzzzzzzz....';

const dog_bark_by_default = (bark = true) => (bark ? BARK : SLEEP);
const dog_bark_only_if_told_so = (bark = false) => (bark ? BARK : SLEEP);
const dog_dont_bark_by_default = (dont_bark = true) => (!dont_bark ? BARK : SLEEP);
const dog_dont_bark_only_if_told_so = (dont_bark = false) => (!dont_bark ? BARK : SLEEP);

console.log(dog_bark_by_default());
console.log(dog_bark_only_if_told_so());
console.log(dog_dont_bark_by_default());
console.log(dog_dont_bark_only_if_told_so());
