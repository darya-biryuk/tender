#include "systools.h"

void clearStdin()
{
    while (getchar() != '\n');
}
