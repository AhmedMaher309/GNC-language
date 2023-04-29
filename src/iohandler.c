#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* io_readfile(void)
{
    char buffer[30];
    char filename[26];
    fprintf(stdout, "Please enter the file name using the format r_*filepath/filename.txt*\n");
    fgets(buffer, 30, stdin);
    if(sscanf(buffer, "r_%25s", filename) == 0)
    {
        return NULL;
    }
    return fopen(filename, "r");
}

FILE* io_writefile(void)
{
    char buffer[30];
    char filename[26];
    fprintf(stdout, "Please enter the file name using the format w_*filepath/filename.txt*\n");
    fgets(buffer, 30, stdin);
    if(sscanf(buffer, "w_%25s", filename) == 0)
    {
        return NULL;
    }
    return fopen(filename, "w");
}

int io_closefile(FILE* output)
{
    return fclose(output);
}