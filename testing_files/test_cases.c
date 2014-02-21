#include "common.h"

	int main(int argc, char *argv[]){
		char choice;

		char* test1_argv = "lister.c";
		char* test2_argv = "nonexistent_file.txt";


		printf("Choose test 1 (should succeed) or test 2 (should fail).\nEnter an integer:\t");
		choice = getchar();

		switch(choice){

			case '1':
				//successful test case - file exists
				func_main(2, test1_argv);
				break;

			case '2':
				//unsuccessful test case - file does not exist
				func_main(2, test2_argv);
				break;

			default:
				printf("ERROR[int main(int argc, char *argv[])]:\tInvalid input - not test case %d found\n", choice);
				break;

		}

		return 0;
	}



