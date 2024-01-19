#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("usage: ./copy.o <buff size> <src file> <dst file>\n");
        return 1;
    }

    int buffor_size = atoi(argv[1]);
    char *src_file_name = argv[2];
    char *dst_file_name = argv[3];

    FILE *src_file_pointer = fopen(src_file_name, "rb"); // get pointer for a file start

    fseek(src_file_pointer, 0, SEEK_END);     // set pointer to file end
    long file_size = ftell(src_file_pointer); // save pointer to get len of file
    fseek(src_file_pointer, 0, SEEK_SET);     // return pointer back to the begening

    int buffor_count = file_size / buffor_size;

    void *data = calloc(buffor_count, buffor_size);

    fread(data, buffor_size, buffor_count, src_file_pointer);

    FILE *dst_file_pointer = fopen(dst_file_name, "wb");
    fwrite(data, buffor_size, buffor_count, dst_file_pointer);

    free(data);
    fclose(src_file_pointer);
    fclose(dst_file_pointer);
    return 0;
}
