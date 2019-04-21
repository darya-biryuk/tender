#ifndef USER_H
#define USER_H

#define USERS_SIZE 15
#define SHADOW_FILEPATH "../tender/data/shadow"
#include <stdbool.h>

struct User
{
    char login[15];
    char password[15];
    bool admin;
};

struct User users[USERS_SIZE];

void getUsers();
void setUsers(struct User newUsers[], int size);
void printUser(struct User user);
bool userIsEmpty(struct User user);

#endif // USER_H
