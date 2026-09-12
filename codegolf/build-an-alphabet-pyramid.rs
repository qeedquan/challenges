/*

Today we're going to build a pyramid out of letters! Here's an example letter pyramid for the first 5 letters:

Write the first 5 letters with a space between, first ascending and then descending.

A B C D E D C B A
Do the same thing for the first four letters on the line above, but with two extra leading spaces:

  A B C D C B A
A B C D E D C B A
Repeat the same step until the last line is just 'A'

        A 
      A B A
    A B C B A
  A B C D C B A
A B C D E D C B A
Repeat steps two and three going down instead of going up:

        A 
      A B A
    A B C B A
  A B C D C B A
A B C D E D C B A
  A B C D C B A
    A B C B A
      A B A
        A 

This same pattern can be extended up to 26 characters. Your challenge is to write a program or function that takes an integer as input, and produces the corresponding letter pyramid. You can choose to use uppercase or lowercase characters. You may always assume that the input will be an integer in [1, 26], and the output may be any reasonable format for a 2d string. For example, a string with newlines in it, an array of characters, printing to a file, etc. Each line may have trailing spaces on it, and you may optionally output one trailing newline.

Here are some example inputs/outputs:

1:

A

2:

  A
A B A
  A

3:

    A
  A B A
A B C B A
  A B A
    A

5:
        A 
      A B A
    A B C B A
  A B C D C B A
A B C D E D C B A
  A B C D C B A
    A B C B A
      A B A
        A 

13:


                        A
                      A B A
                    A B C B A
                  A B C D C B A
                A B C D E D C B A
              A B C D E F E D C B A
            A B C D E F G F E D C B A
          A B C D E F G H G F E D C B A
        A B C D E F G H I H G F E D C B A
      A B C D E F G H I J I H G F E D C B A
    A B C D E F G H I J K J I H G F E D C B A
  A B C D E F G H I J K L K J I H G F E D C B A
A B C D E F G H I J K L M L K J I H G F E D C B A
  A B C D E F G H I J K L K J I H G F E D C B A
    A B C D E F G H I J K J I H G F E D C B A
      A B C D E F G H I J I H G F E D C B A
        A B C D E F G H I H G F E D C B A
          A B C D E F G H G F E D C B A
            A B C D E F G F E D C B A
              A B C D E F E D C B A
                A B C D E D C B A
                  A B C D C B A
                    A B C B A
                      A B A
                        A


26:

                                                  A
                                                A B A
                                              A B C B A
                                            A B C D C B A
                                          A B C D E D C B A
                                        A B C D E F E D C B A
                                      A B C D E F G F E D C B A
                                    A B C D E F G H G F E D C B A
                                  A B C D E F G H I H G F E D C B A
                                A B C D E F G H I J I H G F E D C B A
                              A B C D E F G H I J K J I H G F E D C B A
                            A B C D E F G H I J K L K J I H G F E D C B A
                          A B C D E F G H I J K L M L K J I H G F E D C B A
                        A B C D E F G H I J K L M N M L K J I H G F E D C B A
                      A B C D E F G H I J K L M N O N M L K J I H G F E D C B A
                    A B C D E F G H I J K L M N O P O N M L K J I H G F E D C B A
                  A B C D E F G H I J K L M N O P Q P O N M L K J I H G F E D C B A
                A B C D E F G H I J K L M N O P Q R Q P O N M L K J I H G F E D C B A
              A B C D E F G H I J K L M N O P Q R S R Q P O N M L K J I H G F E D C B A
            A B C D E F G H I J K L M N O P Q R S T S R Q P O N M L K J I H G F E D C B A
          A B C D E F G H I J K L M N O P Q R S T U T S R Q P O N M L K J I H G F E D C B A
        A B C D E F G H I J K L M N O P Q R S T U V U T S R Q P O N M L K J I H G F E D C B A
      A B C D E F G H I J K L M N O P Q R S T U V W V U T S R Q P O N M L K J I H G F E D C B A
    A B C D E F G H I J K L M N O P Q R S T U V W X W V U T S R Q P O N M L K J I H G F E D C B A
  A B C D E F G H I J K L M N O P Q R S T U V W X Y X W V U T S R Q P O N M L K J I H G F E D C B A
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Y X W V U T S R Q P O N M L K J I H G F E D C B A
  A B C D E F G H I J K L M N O P Q R S T U V W X Y X W V U T S R Q P O N M L K J I H G F E D C B A
    A B C D E F G H I J K L M N O P Q R S T U V W X W V U T S R Q P O N M L K J I H G F E D C B A
      A B C D E F G H I J K L M N O P Q R S T U V W V U T S R Q P O N M L K J I H G F E D C B A
        A B C D E F G H I J K L M N O P Q R S T U V U T S R Q P O N M L K J I H G F E D C B A
          A B C D E F G H I J K L M N O P Q R S T U T S R Q P O N M L K J I H G F E D C B A
            A B C D E F G H I J K L M N O P Q R S T S R Q P O N M L K J I H G F E D C B A
              A B C D E F G H I J K L M N O P Q R S R Q P O N M L K J I H G F E D C B A
                A B C D E F G H I J K L M N O P Q R Q P O N M L K J I H G F E D C B A
                  A B C D E F G H I J K L M N O P Q P O N M L K J I H G F E D C B A
                    A B C D E F G H I J K L M N O P O N M L K J I H G F E D C B A
                      A B C D E F G H I J K L M N O N M L K J I H G F E D C B A
                        A B C D E F G H I J K L M N M L K J I H G F E D C B A
                          A B C D E F G H I J K L M L K J I H G F E D C B A
                            A B C D E F G H I J K L K J I H G F E D C B A
                              A B C D E F G H I J K J I H G F E D C B A
                                A B C D E F G H I J I H G F E D C B A
                                  A B C D E F G H I H G F E D C B A
                                    A B C D E F G H G F E D C B A
                                      A B C D E F G F E D C B A
                                        A B C D E F E D C B A
                                          A B C D E D C B A
                                            A B C D C B A
                                              A B C B A
                                                A B A
                                                  A
                                                  
As always, this is code-golf so standard loopholes apply and the shortest answer in bytes wins!

*/

fn main() {
    pyramid(1);
    pyramid(2);
    pyramid(3);
    pyramid(5);
    pyramid(13);
    pyramid(26);
}

fn pyramid(n: isize) {
    println!("n={}", n);
    let (mut i, mut s) = (1, 1);
    while i > 0 {
        let p = (n + 1 - i) * 2;
        for _ in 0..p {
            print!(" ");
        }

        let mut c = 65;
        while c < 64 + i {
            print!("{} ", chr(c));
            c += 1;
        }
        while c > 64 {
            print!("{} ", chr(c));
            c -= 1;
        }
        println!();

        if i == n {
            s = -1;
        }
        i += s;
    }
}

fn chr(c: isize) -> char {
    char::from_u32(c as u32).unwrap()
}
