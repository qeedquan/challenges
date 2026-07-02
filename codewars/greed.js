/*

In my "getQuotes" function, I am trying to extract only the quotes from a string.

#Example

getQuotes('"example quote #1" some text "example quote #2"'); 
// should return ["\"example quote #1\"","\"example quote #2\""]

However, my test results are not as expected. can you find out what I did wrong?

*/

const reg = /"[^"]+"/g;
const getQuotes = (string) => string.match(reg);

console.log(getQuotes('"example quote #1" some text "example quote #2"'));

