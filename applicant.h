#ifndef APPLICANT_H
#define APPLICANT_H

#define APPLICANT_FILEPATH "/home/darya/projects/tender/data/applicants"
#define APPLICANTS_LIST_SIZE 15

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
void printApplicant(struct Applicant applicant);
void getApplicants();


#endif // APPLICANT_H
