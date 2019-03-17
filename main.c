#include <stdio.h>
#include "applicant.h"

int main()
{
    getApplicants();
    printApplicant(applicants[0]);
    printApplicant(applicants[1]);
    printApplicant(applicants[2]);
    return 0;
}
