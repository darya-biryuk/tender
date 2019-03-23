#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "user.h"
#include "adminmenu.h"
#include "usermenu.h"

struct User* login()
{
    char name[30];
    char password[30];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    int i = 0;
    while(i < USERS_SIZE)
    {
        if(strcmp(name,users[i].login) == 0 && strcmp(password,users[i].password) == 0)
            return &users[i];
        i++;
    }
    return NULL;
}

void run(struct User* user)
{
    bool admin = user->admin;
    if (admin)
        adminMenu();
    else
        userMenu();
}

int main()
{
    getUsers();
    struct User* user;

    while (true)
    {
        user = login();
        if (user == NULL)
        {
            printf("Failed attempt.\n");
            continue;
        }
        else
            printf("Success.\n");
            run(user);
            break;
    }

    return 0;
}
