#ifndef APPLICANT_H
#define APPLICANT_H

#define APPLICANT_FILEPATH "/home/darya/projects/tender/data/applicants"
#define APPLICANTS_LIST_SIZE 15

#include <stdbool.h>

struct Address
{
    char country[15];
    char city[15];
    char street[15];
};

struct Applicant
{
    char name[20];
    char email[20];
    char phone[20];
    char price[20];
    char delivery_date[20];
    char remark[100];
    struct Address addr;
};

struct Applicant applicants[APPLICANTS_LIST_SIZE];
void printApplicant(struct Applicant list[], int size);
void getApplicants();
void getField(char* buff, char* result[]);
bool applicantIsEmpty(struct Applicant applicant);

#endif // APPLICANT_H
