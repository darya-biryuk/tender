#include "adminmenu.h"
#include <stdio.h>

void adminMenu()
{
    adminHelp();
}

void adminHelp()
{
    printf("1.Enter new record\n");
    printf("2.Edit record\n");
    printf("3.Delete record\n");
    printf("4.Print applicants\n");
    printf("5.Print products\n");
    printf("6.Search\n");
    printf("7.Sort\n");
    printf("8.User managment\n");
    printf("9.Exit\n");
}
