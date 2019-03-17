#ifndef TOOLS_H
#define TOOLS_H

void getField(char* buff, char* result[])
{
    int i = 0;
    char delim[] = "=";

    char *ptr = strtok(buff, delim);

    while(ptr != NULL)
    {
        result[i++] = ptr;
        ptr = strtok(NULL, delim);
    }
}

#endif // TOOLS_H
