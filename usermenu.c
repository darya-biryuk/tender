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
        system("clear");
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
            task();
            break;
        case 6:
            system("sl");
            system("clear");
            break;
        case 7:
            getApplicants();
            getProducts();
            printf("Списки данных обновлены.\n\n");
            break;
        case 8:
            fflush(stdin);
            getchar();
            printf("Выход в окно авторизации.\n\n");
            return;
        default:
            clearStdin();
            printf("Ошибка выбора.\n\n");
        }
    }
}

void userHelp()
{
        printf("1.Вывести список участников\n");
        printf("2.Вывести список товаров\n");
        printf("3.Поиск\n");
        printf("4.Сортировка\n");
        printf("5.Топ предложений\n");
        printf("6.Запустить паровозик\n");
        printf("7.Обновить списки данных\n");
        printf("8.Выход\n");
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
        system("clear");
        switch(sw)
        {
        case 1:
        {
            char company[APPLICANT_BUF_SIZE] = "\0";
            fflush(stdin);
            getchar();
            enterField("Введите искомую компанию:", company, APPLICANT_BUF_SIZE, 0);
            company[strcspn(company, "\n")] = 0;
            system("clear");
            int i = 0, j = 0;
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
                    j++;
                }
                i++;
            }
            if (j == 0)
                printf("Ничего не найдено.\n\n");
            break;
        }
        case 2:
        {
            char mail[APPLICANT_BUF_SIZE] = "\0";
            fflush(stdin);
            getchar();
            enterField("Введите искомую электронную почту:", mail, APPLICANT_BUF_SIZE, 0);
            mail[strcspn(mail, "\n")] = 0;
            system("clear");
            int i = 0, j = 0;
            while(i < APPLICANTS_LIST_SIZE)
            {
                if(applicantIsEmpty(applicants[j]))
                {
                    i++;
                    continue;
                }
                if(strcmp(mail, applicants[j].email) == 0)
                {
                    printApplicant(&applicants[i], 1);
                    j++;
                }
                i++;
            }
            if (j == 0)
                printf("Ничего не найдено.\n\n");
            break;
        }
        case 3:
        {
            char typs[PRODUCT_BUF_SIZE] = "\0";
            fflush(stdin);
            getchar();
            enterField("Введите искомый вид техники:", typs, PRODUCT_BUF_SIZE, 0);
            typs[strcspn(typs, "\n")] = 0;
            system("clear");
            int i = 0, j = 0;
            while(i < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[i]))
                {
                    i++;
                    continue;
                }
                if(strcmp(typs, products[i].type) == 0)
                {
                    printf("[Товар]\n");
                    printf("Название: %s\n", products[k].type);
                    printf("Бренд: %s\n", products[k].brand);
                    printf("Модель: %s\n", products[k].model);
                    printf("Характеристики: %s\n", products[k].stats);
                    printf("Количество: %s\n", products[k].count);
                    printf("\n");
                    j++;
                }
                i++;
            }
            if (j == 0)
                printf("Ничего не найдено.\n\n");
            break;
        }
        case 4:
        {
            char mark[PRODUCT_BUF_SIZE] = "\0";
            fflush(stdin);
            getchar();
            enterField("Введите искомого производителя:", mark, PRODUCT_BUF_SIZE, 0);
            mark[strcspn(mark, "\n")] = 0;
            system("clear");
            int i = 0, j = 0;
            while(i < PRODUCTS_LIST_SIZE)
            {
                if(productIsEmpty(products[i]))
                {
                    i++;
                    continue;
                }
                if(strcmp(mark, products[i].brand) == 0)
                {
                    printf("[Товар]\n");
                    printf("Название: %s\n", products[i].type);
                    printf("Бренд: %s\n", products[i].brand);
                    printf("Модель: %s\n", products[i].model);
                    printf("Характеристики: %s\n", products[i].stats);
                    printf("Количество: %s\n", products[i].count);
                    printf("\n");
                    j++;
                }
                i++;
            }
            if (j == 0)
                printf("Ничего не найдено.\n\n");
            break;
        }
        case 5:
            return;
        default:
            clearStdin();
            printf("Выберите существующее значение.\n\n");
            break;
        }
    }
}

void sort()
{
    struct Applicant list[APPLICANTS_LIST_SIZE];
    memcpy(list, applicants, sizeof(list));
    int listSize = 0;
    for (int i = 0; i < APPLICANTS_LIST_SIZE; i++)
        if (!applicantIsEmpty(list[i]))
            listSize++;
    if (!listSize) {
        printf("Список пуст.\n\n");
        return;
    }
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

void task()
{
    getApplicants();
    struct topApplicants top[APPLICANTS_LIST_SIZE];
    int topSize = 0;

    for (int i = 0; i < APPLICANTS_LIST_SIZE; i++)
    {
        if (applicantIsEmpty(applicants[i]))
            continue;
        int applicantDays = stoi(applicants[i].date.day) + stoi(applicants[i].date.month) * 30 + (stoi(applicants[i].date.year) - 1970) * 365 - 19;
        int deliveryStamp = applicantDays - getDaysSinceEpoch();

        printf("days: %d\n", applicantDays);
        printf("stamp: %d\n", deliveryStamp);

        if (deliveryStamp <= 0)
            continue;

        int cost = stoi(applicants[i].price);
        if (cost < 0)
            continue;

        int value = cost * cost + deliveryStamp * deliveryStamp * deliveryStamp;

        top[topSize].index = i;
        top[topSize].value = value;
        topSize++;
    }

    struct Applicant result[APPLICANTS_LIST_SIZE];

    for(int i = 0; i  < topSize; i++)
        for(int j = topSize - 1; j >= i; j--)
            if( top[j].value < top[i].value )
            {
                struct topApplicants a = top[i];
                top[i] = top[j];
                top[j] = a;
            }

    for (int i = 0; i < topSize; i++)
    {
        result[i] = applicants[top[i].index];
    }

    printApplicant(result, topSize);
}
