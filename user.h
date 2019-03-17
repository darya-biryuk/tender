#ifndef USER_H
#define USER_H

#define SHADOW_FILEPATH "/home/darya/projects/tender/data/shadow"
#include <stdbool.h>

struct User
{
    char login[15];
    char password[15];
    bool admin;
};

struct User* getUsers();
void addUser(struct User);
void deleteUser(char*);

#endif // USER_H
