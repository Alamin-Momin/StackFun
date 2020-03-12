The purpose of this program is to interact with a picture (ie grid) of colored pixels (ie letter) by entering a pixel
coordinate and desired change in color. The program will read the current color of the desired pixel and change the
color of all the neighboring pixels that have the same color, effectiveily "flood filling" an area with another color.

To compile, type make into the command line and it will compile the stack_ll.c and the driver into an object file called
"flood_fill".

The code works for all test cases. If an invalid character is entered for any three of the inputs then a corresponding
error is printed, the grid prints again, and user is prompted to enter new inputs.

To run the code type "./flood_fill ***.***".