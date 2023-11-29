#include "get_next_line.h"

char	*read_line(char **line, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t nbytes;

    while (!ft_strchr(*line, '\n'))
    {
        nbytes = read(fd, buffer, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(*line);
            return (NULL);
        }

        if (nbytes == 0 && **line == '\0')
        {
            free(*line);
            return (NULL); // End of file reached
        }

        buffer[nbytes] = '\0';
        *line = ft_strjoin(*line, buffer);
    }

    return (*line);
}

char	*get_next_line(int fd)
{
    static char *tmp;
    char *line;

    line = ft_strdup("");

    if (tmp)
    {
        line = ft_strjoin(line, tmp);
        free(tmp);
    }

    line = read_line(&line, fd);
    tmp = save_line(line);

    return line;
}

char	*save_line(char *line)
{
    char	*next;
    char	*tmp;

    next = ft_strchr(line, '\n');
    if (!next)
        return (NULL);

    tmp = ft_strdup(next + 1);
    *next = '\0';
    return (tmp);
}
