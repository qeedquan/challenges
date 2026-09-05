/*

Your task is to write code that will leak at least one byte of memory in as few bytes as possible. The memory must be leaked not just allocated.

Leaked memory is memory that the program allocates but loses the ability to access before it can deallocate the memory properly. For most high level languages this memory has to be allocated on the heap.

An example in C++ would be the following program:

int main(){new int;}
This makes a new int on the heap without a pointer to it. This memory is instantly leaked because we have no way of accessing it.

Here is what a leak summary from Valgrind might look like:

LEAK SUMMARY:
   definitely lost: 4 bytes in 1 blocks
   indirectly lost: 0 bytes in 0 blocks
     possibly lost: 0 bytes in 0 blocks
   still reachable: 0 bytes in 0 blocks
        suppressed: 0 bytes in 0 blocks
Many languages have a memory debugger (such as Valgrind) if you can you should include output from such a debugger to confirm that you have leaked memory.

The goal is to minimize the number of bytes in your source.

*/

use std::ffi::*;

unsafe extern "C" {
    fn malloc(size: usize) -> c_void;
}

fn main() {
    loop {
        unsafe {
            malloc(1 << 20);
        }
    }
}
