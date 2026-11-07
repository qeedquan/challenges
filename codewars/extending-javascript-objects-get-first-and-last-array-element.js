/*

Your task is to extend JavaScript Array object, with methods .first() and .last(), so you can get respectively first or last element of the array.

var a = [2, 5, 7, 3 ,4];

a.first();  // 2
a.last();   // 4

Note: in case of empty array, methods should return undefined.

*/

Array.prototype.first = function () {
    return this[0];
};

Array.prototype.last = function () {
    return this[this.length - 1];
};

var a = [2, 5, 7, 3, 4];
console.log(a.first());
console.log(a.last());
