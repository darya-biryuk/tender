#include "user.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"

int getUsers()
{
    int i = 0;
    char buff[256];
    FILE* fd = fopen(SHADOW_FILEPATH, "r");
    if (fd == NULL)
        return -1;
    memset(users, 0, sizeof(users));
    while(fgets(buff, 256, fd) != NULL)
    {
        if(strcmp(buff, "[User]\n") == 0)
        {
            struct User user;
            user.admin = false;
            while(fgets(buff,256,fd) != NULL)
            {
                char* result[2];
                getField(buff, result);
                if(strcmp(result[0],"login") == 0)
                {
                    strcpy(user.login, result[1]);
                }
                else if(strcmp(result[0],"password") == 0)
                {
                    strcpy(user.password, result[1]);
                }
                else if(strcmp(result[0],"admin") == 0)
                {
                    if(strcmp(result[1], "y") == 0)
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
    return 0;
}

void setUsers(struct User newUsers[], int size)
{
    int i = 0;
    FILE* f = fopen(SHADOW_FILEPATH, "w");
    while(i < size)
    {
        if(userIsEmpty(newUsers[i]))
        {
            i++;
            continue;
        }
        else
        {
            fprintf(f, "\n[User]\n");
            fprintf(f, "login=%s\n", newUsers[i].login);
            fprintf(f, "password=%s\n", newUsers[i].password);
            if (newUsers[i].admin)
                fprintf(f, "admin=y\n");
            fprintf(f, "[End]\n");
        }
        i++;
    }
    fclose(f);
    getUsers();
}

void printUser(struct User user)
{
    printf("[Пользователь]\n");
    printf("Логин: %s", user.login);
    printf("Пароль: %s", user.password);
    printf("Уровень доступа: %d\n", user.admin);
    printf("\n");
}

bool userIsEmpty(struct User user)
{
    if(strlen(user.login) == 0)
        return true;
    else
        return false;
}
