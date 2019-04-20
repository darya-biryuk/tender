#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "applicant.h"
#include "user.h"
#include "adminmenu.h"
#include "usermenu.h"
#include "product.h"

void sig_handler(int signal)
{
    printf("\nЗавершение работы\n");
    exit(0);
}

struct User* login()
{
    char name[30];
    char password[30];

    printf("Введите имя: ");
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
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    printf("Нажмите комбинацию клавиш Ctrl+C для выхода из программы.\n");
    while (true)
    {
        struct User* user;
        getUsers();
        user = login();
        if (user == NULL)
        {
            printf("Failed attempt.\n");
            continue;
        }
        else
            printf("Success.\n");
            run(user);
    }
    return 0;
}
