/*

Return the type of the sum of the two arguments

*/

use std::any::*;

fn main() {
    assert_eq!(typesum(0isize, 2isize), TypeId::of::<isize>());
    assert_eq!(typesum(usize::MAX, usize::MAX), TypeId::of::<usize>());
    assert_eq!(typesum(0.2, 2.4), TypeId::of::<f64>());
    assert_eq!(typesum(54u8, 2u8), TypeId::of::<u8>());
    assert_eq!(typesum(532i16, 2i16), TypeId::of::<i16>());
    assert_eq!(typesum(53u32, 2u32), TypeId::of::<u32>());
}

fn typesum<T: Any>(_: T, _: T) -> TypeId {
    TypeId::of::<T>()
}
