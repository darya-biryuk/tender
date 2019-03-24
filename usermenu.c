#include "usermenu.h"
#include <stdio.h>
#include "applicant.h"
#include "product.h"

int sch = 0;
int k;

void userMenu()
{
    int er;
    while(1)
    {
        userHelp();
        scanf("%d", &er);
        switch(er)
        {
        case 1:
            getApplicants();
            printApplicant();
            break;
        case 2:
            getProducts();
            printProduct();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            return;
        default:
            printf("Wrong choice/n");
        }
    }
}

void userHelp()
{
        printf("1.Print applicants\n");
        printf("2.Print products\n");
        printf("3.Search\n");
        printf("4.Sort\n");
        printf("5.Choose commercial offer\n");
        printf("6.Exit\n");
}


