#include <stdio.h>
#include <stdlib.h>

#define KAPREKARS_CONSTANT 495

int validate(int num);
int cmp_increasing(const void *p1, const void *p2);
int cmp_decreasing(const void *p1, const void *p2);
int kaprekar_procces(int num);

int main(void)
{
  int i, steps;

  for (i = 100; i < 1000; i++) {
    steps = kaprekar_process(i);
    printf("%d, %d steps\n", i, steps);
  }

  return 0;
}

int kaprekar_process(int num)
{
  int cur_num = num, i = 0;
  char little[4], big[4];

  do {
    i++;

    sprintf(little, "%d", cur_num);
    sprintf(big, "%d", cur_num);
    qsort(little, 3, sizeof(char), cmp_increasing);
    qsort(big, 3, sizeof(char), cmp_decreasing);

    if (!validate(cur_num)) {
      return -1;
    }
  }
  while((cur_num = atoi(big) - atoi(little)) != KAPREKARS_CONSTANT);

  return i;
}

int validate(int num)
{
  if ((num <= 0) || (num < 100) || (num > 999) || (num % 111 == 0)) {
    return 0;
  }

  return 1;
}

int cmp_increasing(const void *p1, const void *p2)
{
  char a, b;

  a = *((char *)p1);
  b = *((char *)p2);

  if (a < b) {
    return -1;
  }

  else if (a == b) {
    return 0;
  }

  else {
    return 1;
  }
}

int cmp_decreasing(const void *p1, const void *p2)
{
    char a, b;

  a = *((char *)p1);
  b = *((char *)p2);

  if (a < b) {
    return 1;
  }

  else if (a == b) {
    return 0;
  }

  else {
    return -1;
  }
}
