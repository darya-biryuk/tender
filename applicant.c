#include <stdio.h>
#include <string.h>
#include "applicant.h"


void getApplicants()
{
    int i = 0;
    FILE* fd = fopen(APPLICANT_FILEPATH, "r");
    char buff[256];
    memset(applicants, 0, sizeof(applicants));
    while(fgets(buff, 256, fd) != NULL)
    {
        if(strcmp(buff, "[Applicant]\n") == 0)
        {
            struct Applicant applicant;
            while(fgets(buff,256,fd) != NULL)
            {
                char* result[2];
                getField(buff, result);
                if(strcmp(result[0],"name") == 0)
                {
                    strcpy(applicant.name, result[1]);
                }
                else if(strcmp(result[0],"email") == 0)
                {
                    strcpy(applicant.email, result[1]);
                }
                else if(strcmp(result[0],"phone") == 0)
                {
                    strcpy(applicant.phone, result[1]);
                }
                else if(strcmp(result[0],"price") == 0)
                {
                    strcpy(applicant.price, result[1]);
                }
                else if(strcmp(result[0],"date") == 0)
                {
                    strcpy(applicant.delivery_date, result[1]);
                }
                else if(strcmp(result[0],"remark") == 0)
                {
                    strcpy(applicant.remark, result[1]);
                }
                else if(strcmp(result[0],"country") == 0)
                {
                    strcpy(applicant.addr.country, result[1]);
                }
                else if(strcmp(result[0],"city") == 0)
                {
                    strcpy(applicant.addr.city, result[1]);
                }
                else if(strcmp(result[0],"street") == 0)
                {
                    strcpy(applicant.addr.street, result[1]);
                }
                if(strcmp(buff,"[End]\n") == 0)
                    break;
            }
            if (i >= APPLICANTS_LIST_SIZE)
                break;
            applicants[i++] = applicant;
        }
    }
    fclose(fd);
}

void printApplicant(struct Applicant list[], int size)
{
    int i = 0;
    int isEmpty = 1;
        puts("|===|======================|=====================|=======================|=========================================================|==================|===============|===========================================|");
        puts("|   |                      |                     |                       |            Адрес огранизации                            |                  |               |                                           |");
        puts("| № | Название организации |  Электронная почта  |    Номер телефона     |==================|=================|====================|     Стоимость    | Дата доставки |           Дополнительно                   |");
        puts("|   |                      |                     |                       |      Страна      |      Город      |       Улица        |                  |               |                                           |");
        puts("|===|======================|=====================|=======================|==================|=================|====================|==================|===============|===========================================|");
        while(i < size)
        {
            if(applicantIsEmpty(list[i])) {
                i++;
                continue;
            }
            isEmpty = 0;
            printf("|%-3d", i+1);
            printf("|%*s", 22 + strlen(list[i].name)/2, list[i].name);
            printf("|%*s", 21, list[i].email);
            printf("|%*s", 23 , list[i].phone);
            printf("|%*s", 18 + strlen(list[i].addr.country)/2, list[i].addr.country);
            printf("|%*s", 17 + strlen(list[i].addr.city)/2, list[i].addr.city);
            printf("|%*s", 20 + strlen(list[i].addr.street)/2, list[i].addr.street);
            printf("|%*s", 18, list[i].price);
            printf("|%*s", 15, list[i].delivery_date);
            printf("|%*s|\n", 43 + strlen(list[i].remark)/2, list[i].remark);
            puts("|===|======================|=====================|=======================|==================|=================|====================|==================|===============|===========================================|");
            i++;
        }


    if (isEmpty)
        printf("Список пуст.\n\n");
}

void setApplicants(struct Applicant newApplicants[], int size)
{
    int i = 0;
    FILE* f = fopen(APPLICANT_FILEPATH, "w");
    while(i < size)
    {
        if(applicantIsEmpty(newApplicants[i]))
        {
            i++;
            continue;
        }
        else
        {
            fprintf(f, "\n[Applicant]\n");
            fprintf(f, "name=%s\n", newApplicants[i].name);
            fprintf(f, "email=%s\n", newApplicants[i].email);
            fprintf(f, "phone=%s\n", newApplicants[i].phone);
            fprintf(f, "price=%s\n", newApplicants[i].price);
            fprintf(f, "date=%s\n", newApplicants[i].delivery_date);
            fprintf(f, "remark=%s\n", newApplicants[i].remark);
            fprintf(f, "country=%s\n", newApplicants[i].addr.country);
            fprintf(f, "city=%s\n", newApplicants[i].addr.city);
            fprintf(f, "street=%s\n", newApplicants[i].addr.street);
            fprintf(f, "[End]\n");
        }
        i++;
    }
    fclose(f);
    getApplicants();
}

bool applicantIsEmpty(struct Applicant applicant)
{
    if(strlen(applicant.name) == 0)
        return true;
    else
        return false;
}

void getField(char* buff, char* result[])
{
    int i = 0;
    char delim[] = "=";

    char *ptr = strtok(buff, delim);

    while(ptr != NULL)
    {
        result[i++] = ptr;
        ptr = strtok(NULL, delim);
        if (i > 1) break;
    }

    char* value = result[1];
    value[strcspn(value, "\n")] = 0;
    result[1] = value;
    return;
}
