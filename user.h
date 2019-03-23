#ifndef USER_H
#define USER_H

#define USERS_SIZE 15
#define SHADOW_FILEPATH "/home/darya/projects/tender/data/shadow"
#include <stdbool.h>

struct User
{
    char login[15];
    char password[15];
    bool admin;
};

struct User users[USERS_SIZE];

void getUsers();
void addUser(struct User);
void deleteUser(char*);
void printUser(struct User user);

#endif // USER_H
