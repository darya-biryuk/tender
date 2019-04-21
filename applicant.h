#ifndef APPLICANT_H
#define APPLICANT_H

#define APPLICANT_FILEPATH "../tender/data/applicants"
#define APPLICANTS_LIST_SIZE 15
#define APPLICANT_BUF_SIZE 64

#include <stdbool.h>

struct Address
{
    char country[APPLICANT_BUF_SIZE];
    char city[APPLICANT_BUF_SIZE];
    char street[APPLICANT_BUF_SIZE];
};

struct Applicant
{
    char name[APPLICANT_BUF_SIZE];
    char email[APPLICANT_BUF_SIZE];
    char phone[APPLICANT_BUF_SIZE];
    char price[APPLICANT_BUF_SIZE];
    char delivery_date[APPLICANT_BUF_SIZE];
    char remark[APPLICANT_BUF_SIZE];
    struct Address addr;
};

struct Applicant applicants[APPLICANTS_LIST_SIZE];

void printApplicant(struct Applicant list[], int size);
void getApplicants();
void setApplicants(struct Applicant newApplicants[], int size);
void getField(char* buff, char* result[]);
bool applicantIsEmpty(struct Applicant applicant);

#endif // APPLICANT_H
