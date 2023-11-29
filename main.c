#include "get_next_line.h"


int main()
{
    int fd;
    char *buff;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file");
        return 1;
    }

    buff = get_next_line(fd);
    if (!buff)
    {
        printf("Error reading line\n");
        return 1;
    }
    printf("%s\n", buff);
    free(buff);

    buff = get_next_line(fd);
    if (!buff)
    {
        printf("Error reading line\n");
        return 1;
    }
    printf("%s\n", buff);
    free(buff);
    

    close(fd);
    return 0;
}
