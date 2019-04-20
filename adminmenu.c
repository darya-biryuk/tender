#include "adminmenu.h"
#include <stdio.h>
#include "applicant.h"
#include "product.h"

void adminMenu()
{
    int er;
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
            getApplicants();
            printApplicant(applicants, APPLICANTS_LIST_SIZE);
            break;
        case 5:
            getProducts();
            printProduct();
            break;
        case 6:
            getProducts();
            getApplicants();
            search();
            break;
        case 7:
            getProducts();
            getApplicants();
            sort();
            break;
        case 8:
            break;
        case 9:
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
    printf("9.Exit\n");
}
