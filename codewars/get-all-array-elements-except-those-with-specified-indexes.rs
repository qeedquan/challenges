/*

Extend the Array prototype/class with a function to return all elements of that array, except the ones with the indexes passed in the parameter.

The function should accept either an array or a single integer as parameters, like this:

var array = ['a', 'b', 'c', 'd', 'e'];
var array2 = array.except([1,3]);
// array2 should contain ['a', 'c', 'e']
or

var array = ['a', 'b', 'c', 'd', 'e'];
var array2 = array.except(1);
// array2 should contain ['a', 'c', 'd', 'e']

*/

fn main() {
    assert_eq!(
        except(&['a', 'b', 'c', 'd', 'e'], &mut [1, 3]),
        vec!['a', 'c', 'e']
    );
    assert_eq!(
        except(&['a', 'b', 'c', 'd', 'e'], &mut [1]),
        vec!['a', 'c', 'd', 'e']
    );
}

fn except<T: Copy>(array: &[T], indices: &mut [usize]) -> Vec<T> {
    let mut result = vec![];
    let mut offset = 0;
    indices.sort();
    for index in 0..array.len() {
        if offset < indices.len() && index == indices[offset] {
            offset += 1;
        } else {
            result.push(array[index]);
        }
    }
    result
}
