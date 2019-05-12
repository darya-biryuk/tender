#include "systools.h"
#include <stdio.h>
#include <time.h>

void clearStdin()
{
    while (getchar() != '\n');
}

int getDaysSinceEpoch()
{
    time_t seconds;
    seconds = time (NULL);
    return seconds/(60*60*24);
}

int stoi(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
  {
      if (*str == '-')
        puiss = puiss * -1;
      str++;
  }
  while ((*str >= '0') && (*str <= '9'))
  {
      result = (result * 10) + ((*str) - '0');
      str++;
  }
  return (result * puiss);
}
