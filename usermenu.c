#include "usermenu.h"
#include <stdio.h>
#include <string.h>
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
            printApplicant(applicants, APPLICANTS_LIST_SIZE);
            break;
        case 2:
            getProducts();
            printProduct();
            break;
        case 3:
            getProducts();
            getApplicants();
            search();
            break;
        case 4:
            getProducts();
            getApplicants();
            sort();
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

void search()
{
    int sw;
    while(1)
    {
        printf("Выберите параметр поиска :\n");
        printf("1.Компания\n");
        printf("2.e-mail компании\n");
        printf("3.Вид техники\n");
        printf("4.Бренд производителя\n");
        printf("5.Выход\n");
        scanf("%d", &sw);

        switch(sw)
        {
        case 1:
        {
            int i = 0;
            char company[30];
            printf("Введите искомую компанию :\n");
            fflush(stdin);
            getchar();
            fgets(company,sizeof(company),stdin);
            while(i < APPLICANTS_LIST_SIZE)
            {
                if(applicantIsEmpty(applicants[i]))
                {
                    i++;
                    continue;
                }
                if(strcmp(company, applicants[i].name) == 0)
                {
                    printf("Name of organization: %s\n", applicants[i].name);
                    printf("Organization email: %s\n", applicants[i].email);
                    printf("Organization phone: %s\n", applicants[i].phone);
                    printf("Price: %s\n", applicants[i].price);
                    printf("Delivery date: %s\n", applicants[i].delivery_date);
                    printf("Country: %s", applicants[i].addr.country);
                    printf("City: %s", applicants[i].addr.city);
                    printf("Street: %s", applicants[i].addr.street);
                    printf("Remark: %s\n", applicants[i].remark);
                }
                i++;
            }
            break;
        }
        case 2:
        {
            int j = 0;
            char mail[30];
            printf("Введите искомую электронную почту :\n");
            fflush(stdin);
            getchar();
            fgets(mail, sizeof(mail), stdin);
            while(j < APPLICANTS_LIST_SIZE)
            {
                if(applicantIsEmpty(applicants[j]))
                {
                    j++;
                    continue;
                }
                if(strcmp(mail, applicants[j].email) == 0)
                {
                    printf("Name of organization: %s\n", applicants[j].name);
                    printf("Organization email: %s\n", applicants[j].email);
                    printf("Organization phone: %s\n", applicants[j].phone);
                    printf("Price: %s\n", applicants[j].price);
                    printf("Delivery date: %s\n", applicants[j].delivery_date);
                    printf("Country: %s", applicants[j].addr.country);
                    printf("City: %s", applicants[j].addr.city);
                    printf("Street: %s", applicants[j].addr.street);
                    printf("Remark: %s\n", applicants[j].remark);
                }
                j++;
            }
            break;
        }
        case 3:
        {
            int k = 0;
            char typs[20];
            printf("Введите искомый вид техники :\n");
            fflush(stdin);
            getchar();
            fgets(typs, sizeof(typs), stdin);
            while(k < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[k]))
                {
                    k++;
                    continue;
                }
                if(strcmp(typs, products[k].type) == 0)
                {
                    printf("type %s\n", products[k].type);
                    printf("brand %s\n", products[k].brand);
                    printf("model %s\n", products[k].model);
                    printf("stats %s\n", products[k].stats);
                    printf("count %s\n", products[k].count);
                }
                k++;
            }
            break;
        }
        case 4:
        {
            int m = 0;
            char mark[20];
            printf("Введите искомого производителя :\n");
            fflush(stdin);
            getchar();
            fgets(mark, sizeof(mark), stdin);
            while(m < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[m]))
                {
                    m++;
                    continue;
                }
                if(strcmp(mark, products[m].brand) == 0)
                {
                    printf("type %s\n", products[m].type);
                    printf("brand %s\n", products[m].brand);
                    printf("model %s\n", products[m].model);
                    printf("stats %s\n", products[m].stats);
                    printf("count %s\n", products[m].count);
                }
                m++;
            }
            break;
        }
        case 5:
            return;
        default:
            printf("Выберите существующее значение \n");
            break;
        }
    }
}

void sort()
{
    struct Applicant list[APPLICANTS_LIST_SIZE];
    memcpy(list, applicants, sizeof(list));
    for(int i = 0; i < APPLICANTS_LIST_SIZE; i++)
        for(int j = APPLICANTS_LIST_SIZE - 1; j >= i; j--)
            if(strcmp(list[i].name, list[j].name) > 0)
            {
                struct Applicant tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
    printApplicant(list, APPLICANTS_LIST_SIZE);
}




