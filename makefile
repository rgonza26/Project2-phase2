#Group 4:
#	Roberto Gonzalez[rgonza26]
#	Peter Johnson	[ptjohns2]

make: lister.c print_functions.c common.h
	gcc -o lister.o lister.c -c
	gcc -o print_functions.o print_functions.c -c
	gcc -o lister lister.o print_functions.o
	rm *.o
