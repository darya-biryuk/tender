#ifndef APPLICANT_H
#define APPLICANT_H

#define APPLICANT_FILEPATH "data/applicant"

struct Address
{
    char country[15];
    char city[15];
    char street[15];
    int house;
};

struct Applicant
{
    char name[20];
    char email[25];
    char phone[10];
    char price_in_euro[8];
    char delivery_date[20];
    char remark[100];
    Address addr;
};

#endif // APPLICANT_H
