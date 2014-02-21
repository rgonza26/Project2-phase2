#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char *line, char source_name_to_print[], char date_to_print[])
{
    
    //initialize variables
    char save_ch = '\0';
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    line_count++;
    
    if (line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print, date_to_print);
        line_count = 1;
    }
    
    if (sizeof(line) > MAX_PRINT_LINE_LENGTH)
    {
        save_chp = &line[sizeof(line)-1];
    }
    
    if (save_chp != NULL)
    {
        save_ch = *save_chp;
        save_chp = '\0';
    }
    
    printf(line);
    
}




static void print_page_header(char source_name[], char date[])
{
    //initialize variables
    static int page_number = 0;
    
    //New Page
    printf("%c",FORM_FEED_CHAR);
    page_number++;
    
    //Print Header
    printf("Page\t%d   %s   %s \n", page_number, source_name, date);
    
}