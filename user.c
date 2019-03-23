#include "user.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"

void getUsers()
{
    int i = 0;

    FILE* fd = fopen(SHADOW_FILEPATH, "r");
    char buff[256];
    while(fgets(buff, 256, fd) != NULL)
    {
        if(strcmp(buff, "[User]\n") == 0)
        {
            struct User user;
            while(fgets(buff,256,fd) != NULL)
            {
                char* result[2];
                getField(buff, result);
                if(strcmp(result[0],"name") == 0)
                {
                    strcpy(user.login, result[1]);
                }
                else if(strcmp(result[0],"password") == 0)
                {
                    strcpy(user.password, result[1]);
                }
                else if(strcmp(result[0],"admin") == 0)
                {
                    if(strcmp(result[1], "y\n") == 0)
                        user.admin = true;
                }

                if(strcmp(buff,"[End]\n") == 0)
                    break;
            }
            if (i >= USERS_SIZE)
                break;
            users[i++] = user;
        }
    }
    fclose(fd);
}

void printUser(struct User user)
{
    printf("name %s", user.login);
    printf("password %s", user.password);
    printf("admin %d\n", user.admin);
}
