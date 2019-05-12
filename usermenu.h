#ifndef USERMENU_H
#define USERMENU_H

#include <stdlib.h>
#include "systools.h"

void userMenu();
void userHelp();
void search();
void sort();
void task();

struct topApplicants
{
    int index;
    int value;
};

#endif // USERMENU_H
