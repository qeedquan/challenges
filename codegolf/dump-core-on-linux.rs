/*

Write the shortest program which, when run with no arguments, stdin, or user input, triggers a core dump.

Your code must behave this way when run on some common out-of-the-box Linux distribution. Other than installing support for your target language, you may not reconfigure the system to make it more fragile than it is as provided.

25-byte C example: int main(){*((int*)0)=0;} on my Ubuntu outputs

Segmentation fault (core dumped)

*/

fn main() {
    unsafe {
        let p = 0x0 as *mut i32;
        *p = 0;
    }
}
