# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

flood_fill: stack_ll.o stack_ll_driver.o
	c99 -o flood_fill stack_ll.o stack_ll_driver.o

stack_ll.o: stack_ll.c
	c99 -c stack_ll.c

stack_ll_driver.o: stack_ll_driver.c
	c99 -c stack_ll_driver.c
