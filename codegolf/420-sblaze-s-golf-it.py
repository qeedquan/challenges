#!/usr/bin/env python3

"""

This is a pretty simple challenge, but (I hope) a fun one.

Task
If right now either the month is 4 and the day is 20, the hour (on a 12 hour clock) is 4 and the minute is 20, or the minute is 4 and the second is 20, print this ascii art:

                        .
                       .:.
                       :|:
                      .:|:.
                      ::|::
       :.             ::|::             .:
       :|:.          .::|::.          .:|:
       ::|:.         :::|:::         .:|:;
       `::|:.        :::|:::        .:|::'
        ::|::.       :::|:::       .::|:;
        `::|::.      :::|:::      .::|::'
         :::|::.     :::|:::     .::|::;
         `:::|::.    :::|:::    .::|::;'
`::.      `:::|::.   :::|:::   .::|::;'     .:;'
 `:::..    `;::|::.  :::|:::  .::|:::    ::::;
   `:::::.    ':|::. :::|::: .::|:'   ,::::;'
     `:::::.    ':|:::::|:::::|:'   :::::;'
       `:::::.:::::|::::|::::|::::.,:::;'
          ':::::::::|:::|:::|:::::::;:'
             ':::::::|::|::|:::::::''
                  `::::::::::;'
                 .:;'' ::: ``::.
                      :':':
                        ;
You can have trailing spaces.

Otherwise, print the number of minutes and seconds left until the next such occasion in the format: %d minutes and %d seconds left until your next hit. with the time being minimized.

This is code-golf, so shortest code in bytes wins!

P.S. If this challenge is too inappropriate for this site, tell me and I'll change it.

"""

from datetime import *
from time import *

WEED = """
                        .
                       .:.
                       :|:
                      .:|:.
                      ::|::
       :.             ::|::             .:
       :|:.          .::|::.          .:|:
       ::|:.         :::|:::         .:|:;
       `::|:.        :::|:::        .:|::'
        ::|::.       :::|:::       .::|:;
        `::|::.      :::|:::      .::|::'
         :::|::.     :::|:::     .::|::;
         `:::|::.    :::|:::    .::|::;'
`::.      `:::|::.   :::|:::   .::|::;'     .:;'
 `:::..    `;::|::.  :::|:::  .::|:::    ::::;
   `:::::.    ':|::. :::|::: .::|:'   ,::::;'
     `:::::.    ':|:::::|:::::|:'   :::::;'
       `:::::.:::::|::::|::::|::::.,:::;'
          ':::::::::|:::|:::|:::::::;:'
             ':::::::|::|::|:::::::''
                  `::::::::::;'
                 .:;'' ::: ``::.
                      :':':
                        ;

"""

def main():
    while True:
        now = datetime.now()
        if now.month == 4 and now.day == 20:
            print(WEED)
        elif now.hour%12 == 4 and now.minute == 20:
            print(WEED)
        elif now.minute == 4 and now.second == 20:
            print(WEED)
        else:
            print(now)

        sleep(1)

main()
