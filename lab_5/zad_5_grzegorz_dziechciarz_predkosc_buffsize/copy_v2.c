#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./copy_v2.o <buffer size> <src file> <dst file>\n");
        return 1;
    }

    int buffer_size = atoi(argv[1]);
    char *src_file_name = argv[2];
    char *dst_file_name = argv[3];

    FILE *src_file_pointer = fopen(src_file_name, "rb");
    if (src_file_pointer == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    FILE *dst_file_pointer = fopen(dst_file_name, "wb");
    if (dst_file_pointer == NULL)
    {
        perror("Error opening destination file");
        fclose(src_file_pointer);
        return 1;
    }

    char *buffer = malloc(buffer_size);

    // coś takiego jest możliwe bo fread i fwrite mają indykator swojej pozycji w pliku
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, buffer_size, src_file_pointer)) > 0)
    {
        fwrite(buffer, 1, bytes_read, dst_file_pointer);
    }


    free(buffer);
    fclose(src_file_pointer);
    fclose(dst_file_pointer);
    return 0;
}
