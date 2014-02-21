//include common.h
#include "common.h"

	int main (int argc, char *argv[]) {

        
        //Initialization of variables
        FILE *file = NULL;
        char source_file_name[MAX_FILE_NAME_LENGTH] = {'\0'};
        char date[DATE_STRING_LENGTH] = {'\0'};
        
        //Get date/time, Open File
        file = init_lister(argv[1], source_file_name, date);
        
        //Read then print lines in a loop until get_source_line returns false
        while (get_source_line(file, source_file_name, date));
        
        return 0;
        
    }
    

    FILE *init_lister(const char *name, char source_file_name[], char dte[]) {
        
      	//local Variables
        time_t timer;
        FILE *file = NULL;
        
        //copy parameter name to parameter source_file_name
        strcpy(source_file_name, name);
        
        //Open file
        file = fopen(source_file_name, "r");
        
        //set timer variable to current time
        time(&timer);
        
        //copy current time to dte parameter
        strcpy(dte, ctime(&timer));
        
        return file;
        
    }

    
    BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[]) {
        
        //Initialize variables
        char print_buffer[MAX_SOURCE_LINE_LENGTH] = {'\0'};
        char source_buffer[MAX_SOURCE_LINE_LENGTH] = {'\0'};
        static int line_number = 0;
        
        //Reached end of file
        if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) == NULL){    
		return FALSE;
	}
        
        //line numner +1
        line_number++;
        
        //Concatenate line number with code line
        sprintf(print_buffer, "%3d: %s", line_number, source_buffer);
        
        //Print the formatted line
        print_line(print_buffer, src_name, todays_date);
        
        //Pass
        return TRUE;
        
    }
