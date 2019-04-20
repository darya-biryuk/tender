#include "adminmenu.h"
#include <stdio.h>
#include "applicant.h"
#include "product.h"

void adminMenu()
{
    int er;
    getProducts();
    getApplicants();
    while(1)
    {
        adminHelp();
        scanf("%d", &er);
        switch(er)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printApplicant(applicants, APPLICANTS_LIST_SIZE);
            break;
        case 5:
            printProduct();
            break;
        case 6:
            search();
            break;
        case 7:
            sort();
            break;
        case 8:
            break;
        case 9:
            getProducts();
            getApplicants();
            break;
        case 10:
            fflush(stdin);
            getchar();
            return;
        default:
            printf("Wrong choice/n");
        }
    }
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
    printf("9.Обновить списки данных\n");
    printf("10.Exit\n");
}
