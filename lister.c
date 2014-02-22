//Group4:
//	Roberto Gonzalez[rgonza26]
//	Peter Johnson	[ptjohns2]

#include "common.h"

int main (int argc, char *argv[]){
       	//Initialization of local variables
       	FILE *file = NULL;
       	char source_file_name[MAX_FILE_NAME_LENGTH] = {'\0'};
       	char date[DATE_STRING_LENGTH] = {'\0'};
       
       	//Initialize lister - update date, time; return FILE* file
       	file = init_lister(argv[1], source_file_name, date);
       
       	//Read then print lines in a loop until get_source_line returns false
       	while (get_source_line(file, source_file_name, date));

       	return 0;
}//=>main
   
FILE *init_lister(const char *name, char source_file_name[], char dte[]){
  	//Initialization of local variables
       	time_t timer;
       	FILE *file = NULL;
       
       	//copy char* name to source_file_name[] parameter
       	strcpy(source_file_name, name);
       	
       	//Open file in read mode
       	file = fopen(source_file_name, "r");
       	
       	//Update timer variable with current time
       	time(&timer);
       	
       	//Copy current time to char dte[] parameter
       	strcpy(dte, ctime(&timer));
       	
	//Return FILE* file
       	return file;
}//=>init_lister
    
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[]){
       	//Initialize of local variables
       	char print_buffer[MAX_SOURCE_LINE_LENGTH] = {'\0'};
       	char source_buffer[MAX_SOURCE_LINE_LENGTH] = {'\0'};
       	static int line_number = 0;
       	
       	//CASE EOF; line unsuccessfully read	-	(return false)
       	if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) == NULL){    
		return FALSE;
	}
       	
       	//Increment line_number
       	line_number++;
       	
       	//Concatenate line number with code line
       	sprintf(print_buffer, "%3d: %s", line_number, source_buffer);
       	
       	//Print the formatted line
       	print_line(print_buffer, src_name, todays_date);
       	
       	//CASE no EOC;  successfully read	-	(return true)
       	return TRUE;
}//=>get_source_line	
