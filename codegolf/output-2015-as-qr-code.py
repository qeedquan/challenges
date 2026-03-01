#!/usr/bin/env python3

"""

Mission is simple. Just output number 2015 as QR code and write it to file named newyear.png in PNG format. Code must be valid any day, so maybe you shall not use current year.

QR code as text looks like this:

# # # # # # #   # # # #     # # # # # # #
#           #           #   #           #
#   # # #   #   # #     #   #   # # #   #
#   # # #   #       #   #   #   # # #   #
#   # # #   #       #   #   #   # # #   #
#           #               #           #
# # # # # # #   #   #   #   # # # # # # #
                #   # #
#   #     # #     # #     # #       #   #
  # # #   #   #   #   # #   #     #   # #
#   # #   # # #   # # # # # #   #       #
# # #         # #         # # # #
# # # # #   #   #     #     #   #     #
                      # # # #
# # # # # # #       #   # #   # #   #   #
#           #   #         # # # #
#   # # #   #         #     #   #     #
#   # # #   #     #     # # # # #
#   # # #   #   #   #   # #   # #   #   #
#           #     # #       # # #   # # #
# # # # # # #   #           #   #   #   #

The result written in newyear.png must contain that QR code with white 5 pixel borders and one pixel sized dots. It must not contain anything else than QR code.

"""

import qrcode

def main():
    img = qrcode.make("2015")
    img.save("newyear.png")

main()
