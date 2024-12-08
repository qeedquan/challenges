/*

Your challenge is to make a program(less number of bytes than what the below program takes) that should print the map of India with any special character of choice.

#include <stdio.h>
int main()
{
    int a = 10, b = 0, c = 10;
    char* str = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
                "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
                "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
                "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
    while (a != 0)
    {
    a = str[b++];
        while (a-- > 64)
        {
            if (++c == 90)
            {
                c = 10;
                putchar('\n');
            }
            else
            {
                if (b % 2 == 0)
                    putchar('!');
                else
                    putchar(' ');
            }
        }
    }
    return 0;
}

The program outputs:

                !!!!!!
                !!!!!!!!!!
                 !!!!!!!!!!!!!!!
                   !!!!!!!!!!!!!!
                 !!!!!!!!!!!!!!!
                  !!!!!!!!!!!!
                  !!!!!!!!!!!!
                    !!!!!!!!!!!!
                    !!!!!!!!
                    !!!!!!!!!!
                   !!!!!!!!!!!!!!
                 !!!!!!!!!!!!!!!!
                !!!!!!!!!!!!!!!!                                  !!!!!
              !!!!!!!!!!!!!!!!!!!                               !!!!!!!!!!
             !!!!!!!!!!!!!!!!!!!!!!!                 !         !!!!!!!!!!
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!              !!     !!!!!!!!!!!!
       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        !!      !!!!!!!!
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! !!!!!!!!!!!!
          !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  !!!!!!!!!!!!
   !!!!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        !!!!!!
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!      !!!!!
      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        !
      !!!!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
       !!!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!!
              !!!!!!!!!!!!!!!!!!!!!!!!!
               !!!!!!!!!!!!!!!!!!!!!!!!
                !!!!!!!!!!!!!!!!!!!!
                !!!!!!!!!!!!!!!!!!!
                 !!!!!!!!!!!!!!!!
                  !!!!!!!!!!!!!!!!
                  !!!!!!!!!!!!!!!
                   !!!!!!!!!!!!!!
                    !!!!!!!!!!!!
                    !!!!!!!!!!!!
                    !!!!!!!!!!!!
                      !!!!!!!!
                      !!!!!!
                       !!!!

*/

#include <stdio.h>

void
india(void)
{
	static const char map[] = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
	                          "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
	                          "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
	                          "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";

	unsigned a, b, c;

	a = c = 10;
	for (b = 0; b < sizeof(map); b++) {
		for (a = map[b]; a > 64; a--) {
			if (++c == 90) {
				c = 10;
				putchar('\n');
			} else if (b & 1)
				putchar('!');
			else
				putchar(' ');
		}
	}
}

int
main(void)
{
	india();
	return 0;
}
