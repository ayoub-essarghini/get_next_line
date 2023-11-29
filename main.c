#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
    int fd;
    char *line;

    fd = open("tests/test.txt", O_RDONLY);
    line = get_next_line(fd);
        if (line == NULL)
        return (0);
       
        printf("%s", line);
          printf("%s", line);
            printf("%s", line);
        free(line);
        
        
      
    
}