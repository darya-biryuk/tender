#include "usermenu.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "adminmenu.h"
#include "product.h"

int sch = 0;
int k;

void userMenu()
{
    int er;
    getApplicants();
    getProducts();
    while(1)
    {
        userHelp();
        printf(">> ");
        scanf("%d", &er);
        switch(er)
        {
        case 1:
            printApplicant(applicants, APPLICANTS_LIST_SIZE);
            break;
        case 2:
            printProduct();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 5:
            break;
        case 6:
            getApplicants();
            getProducts();
            break;
        case 7:
            fflush(stdin);
            getchar();
            printf("Выход в окно авторизации.\n");
            printf("Нажмите комбинацию клавиш Ctrl+C для выхода из программы.\n");
            return;
        default:
            printf("Ошибка выбора.\n");
        }
    }
}

void userHelp()
{
        printf("1.Вывести список участников\n");
        printf("2.Вывести список товаров\n");
        printf("3.Поиск\n");
        printf("4.Сортировка\n");
        printf("5.Выбрать предложение (задание)\n");
        printf("6.Обновить списки данных\n");
        printf("7.Выход\n");
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
        printf("5.Назад\n");
        printf(">> ");
        scanf("%d", &sw);

        switch(sw)
        {
        case 1:
        {
            int i = 0;
            char company[APPLICANT_BUF_SIZE];
            fflush(stdin);
            getchar();
            enterField("Введите искомую компанию:", company, APPLICANT_BUF_SIZE, 0);
            company[strcspn(company, "\n")] = 0;
            while(i < APPLICANTS_LIST_SIZE)
            {
                if(applicantIsEmpty(applicants[i]))
                {
                    i++;
                    continue;
                }
                if(strcmp(company, applicants[i].name) == 0)
                {
                    printApplicant(&applicants[i], 1);
                }
                i++;
            }
            break;
        }
        case 2:
        {
            int j = 0;
            char mail[APPLICANT_BUF_SIZE];
            fflush(stdin);
            getchar();
            enterField("Введите искомую электронную почту:", mail, APPLICANT_BUF_SIZE, 0);
            mail[strcspn(mail, "\n")] = 0;
            while(j < APPLICANTS_LIST_SIZE)
            {
                if(applicantIsEmpty(applicants[j]))
                {
                    j++;
                    continue;
                }
                if(strcmp(mail, applicants[j].email) == 0)
                {
                    printApplicant(&applicants[j], 1);
                }
                j++;
            }
            break;
        }
        case 3:
        {
            int k = 0;
            char typs[PRODUCT_BUF_SIZE];
            fflush(stdin);
            getchar();
            enterField("Введите искомый вид техники:", typs, PRODUCT_BUF_SIZE, 0);
            typs[strcspn(typs, "\n")] = 0;
            while(k < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[k]))
                {
                    k++;
                    continue;
                }
                if(strcmp(typs, products[k].type) == 0)
                {
                    printf("[Товар]\n");
                    printf("Название: %s\n", products[k].type);
                    printf("Бренд: %s\n", products[k].brand);
                    printf("Модель: %s\n", products[k].model);
                    printf("Характеристики: %s\n", products[k].stats);
                    printf("Количество: %s\n", products[k].count);
                    printf("\n");
                }
                k++;
            }
            break;
        }
        case 4:
        {
            int m = 0;
            char mark[PRODUCT_BUF_SIZE];
            fflush(stdin);
            getchar();
            enterField("Введите искомого производителя:", mark, PRODUCT_BUF_SIZE, 0);
            mark[strcspn(mark, "\n")] = 0;
            while(m < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[m]))
                {
                    m++;
                    continue;
                }
                if(strcmp(mark, products[m].brand) == 0)
                {
                    printf("[Товар]\n");
                    printf("Название: %s\n", products[m].type);
                    printf("Бренд: %s\n", products[m].brand);
                    printf("Модель: %s\n", products[m].model);
                    printf("Характеристики: %s\n", products[m].stats);
                    printf("Количество: %s\n", products[m].count);
                    printf("\n");
                }
                m++;
            }
            break;
        }
        case 5:
            printf("Выход в окно авторизации.\n");
            return;
        default:
            printf("Выберите существующее значение.\n");
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




