make: lister.c print_functions.c test_cases.c
	gcc test_cases.c -o test_cases.o -c
	gcc lister.c -o lister.o -c
	gcc print_functions.c -o print_functions.o -c
	gcc -o test_cases test_cases.o lister.o print_functions.o
	rm *.o
