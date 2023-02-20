#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    // char *line;
	// char *temp_buffer;

	// temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);

    // if (argc < 2)
    // {
    //     printf("Usage: ./test_gnl [filename]\n");
    //     return (1);
    // }

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        return (1);
    }
	// read(fd, temp_buffer, BUFFER_SIZE);
	// temp_buffer[BUFFER_SIZE] = 0;
	// printf("%s\n", temp_buffer);
	printf("%d\n", fd);
	printf("%s\n",get_next_line(fd));

    // while ((line = get_next_line(fd)))
    // {
    //     printf("%s\n", line);
    //     free(line);
    // }

    //close(fd);
    return (0);
}