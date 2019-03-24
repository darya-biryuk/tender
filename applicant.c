#include <stdio.h>
#include <string.h>
#include "applicant.h"


void getApplicants()
{
    int i = 0;

    FILE* fd = fopen(APPLICANT_FILEPATH, "r");
    char buff[256];
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

void printApplicant()
{
    int i = 0;
    while(i < APPLICANTS_LIST_SIZE)
    {
        if(applicantIsEmpty(applicants[i])) {
            i++;
            continue;
        }
        printf("Name of organization: %s\n", applicants[i].name);
        printf("Organization email: %s\n", applicants[i].email);
        printf("Organization phone: %s\n", applicants[i].phone);
        printf("Price: %s\n", applicants[i].price);
        printf("Delivery date: %s\n", applicants[i].delivery_date);
        printf("Country: %s", applicants[i].addr.country);
        printf("City: %s", applicants[i].addr.city);
        printf("Street: %s", applicants[i].addr.street);
        printf("Remark: %s\n", applicants[i].remark);
        i++;
    }
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
    }
}
