#include "headers/iohelper.h"

//
//  Convenience method to read an entire file into memory.
//
char* freadall(char* fname)
{
    char* buffer = 0;
    long length;
    FILE* f = fopen(fname, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = calloc(1, length);

        if (buffer)
            fread(buffer, 1, length, f);

        fclose(f);
    }

    if (buffer)
        return buffer;

    return "";
}