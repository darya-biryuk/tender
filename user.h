#ifndef USER_H
#define USER_H

#define USERS_SIZE 15
#define MAX_LOGIN_SIZE 15
#define MAX_PASSWORD_SIZE 15
#define SHADOW_FILEPATH "../tender/data/shadow"
#include <stdbool.h>

struct User
{
    char login[MAX_LOGIN_SIZE];
    char password[MAX_PASSWORD_SIZE];
    bool admin;
};

struct User users[USERS_SIZE];

int getUsers();
void setUsers(struct User newUsers[], int size);
void printUser(struct User user);
bool userIsEmpty(struct User user);

#endif // USER_H
