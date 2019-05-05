#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "applicant.h"
#include "user.h"
#include "adminmenu.h"
#include "usermenu.h"
#include "product.h"
#include "systools.h"

void sig_handler(int signal)
{
    printf("\nЗавершение работы.\n");
    exit(0);
}

void setStdinEcho(bool enable)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

struct User* login()
{

    char name[MAX_LOGIN_SIZE];
    char password[MAX_PASSWORD_SIZE];

    printf("Введите имя: ");
    fgets(name, sizeof(name), stdin);
    if (strlen(name) >= MAX_LOGIN_SIZE - 1) {
        clearStdin();
        return NULL;
    }
    name[strcspn(name, "\n")] = 0;

    printf("Введите пароль: ");
    setStdinEcho(false);
    fgets(password, sizeof(password), stdin);
    setStdinEcho(true);
    if (strlen(password) >= MAX_PASSWORD_SIZE - 1) {
        clearStdin();
        printf("\n");
        return NULL;
    }
    password[strcspn(password, "\n")] = 0;

    if (strlen(name) == 0)
        return NULL;

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
    {
        system("clear");
        printf("Выполнен вход в систему (администратор).\n\n");
        adminMenu();
    }
    else
    {
        system("clear");
        printf("Выполнен вход в систему (пользователь).\n\n");
        userMenu();
    }
}

int main()
{
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    while (true)
    {
        printf("Нажмите комбинацию клавиш Ctrl+C для выхода из программы.\n");
        struct User* user;
        if (getUsers() < 0)
        {
            printf("Ошибка открытия файла пользователей: %m\n");
            return -1;
        }
        user = login();
        if (user == NULL)
        {
            system("clear");
            printf("Неудачная попытка.\n\n");
            continue;
        }
        else
            run(user);
    }
    return 0;
}
