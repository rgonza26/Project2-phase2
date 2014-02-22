//Group4:
//	Roberto Gonzalez[rgonza26]
//	Peter Johnson	[ptjohns2]

#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char *line, char source_name_to_print[], char date_to_print[]){
	//Initialize local variables
	char save_ch = '\0';
	static int line_count = MAX_LINES_PER_PAGE;
	
	//Print page header is number of lines printed is more than one page
	if ((++line_count)  > MAX_LINES_PER_PAGE)
	{
		print_page_header(source_name_to_print, date_to_print);
		line_count = 1;
	}
	 
	//this should stop lines from printing longer than 80 characters...
	//but '\t' is one character which in the console takes up more
	//then one character icon, so sometimes there is spillage   
	if (sizeof(line) > MAX_PRINT_LINE_LENGTH){
		save_ch = line[MAX_PRINT_LINE_LENGTH];
		line[MAX_PRINT_LINE_LENGTH] = '\0';
	}
    	//print line
	printf(line);

	//restore line to unconcatenated form (replace the overwritten '\0')
	if (save_ch != '\0'){
		line[MAX_PRINT_LINE_LENGTH] = save_ch;
	}
}




static void print_page_header(char source_name[], char date[]){
	//Initialize local variables
	static int page_number = 0;
    
	//Print new page
	printf("%c",FORM_FEED_CHAR);
	
	//Increment page_number
	page_number++;
    
	//Print Header
	printf("Page\t%d\t%s\t%s\n", page_number, source_name, date);
}
