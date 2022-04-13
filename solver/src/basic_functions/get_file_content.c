/*
** EPITECH PROJECT, 2022
** get_file_content
** File description:
** get the content of a file to put it in a char *
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *get_file_content(char const *filepath)
{
    struct stat buf;
    int fd;
    char *buffer;

    if ((fd = open(filepath, O_RDONLY)) < 0) {
        write(2, "Failed to open the file\n", 24);
        return NULL;
    }
    stat(filepath, &buf);
    buffer = malloc(sizeof(char *) * buf.st_size + 1);
    strcpy(buffer, filepath);
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    close(fd);
    return buffer;
}
