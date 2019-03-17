#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "tools.h"


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

void printApplicant(struct Applicant applicant)
{
    printf("name %s", applicant.name);
    printf("email %s", applicant.email);
    printf("phone %s", applicant.phone);
    printf("price %s", applicant.price);
    printf("date %s", applicant.delivery_date);
    printf("remark %s", applicant.remark);
    printf("country %s", applicant.addr.country);
    printf("city %s", applicant.addr.city);
    printf("street %s", applicant.addr.street);
}
