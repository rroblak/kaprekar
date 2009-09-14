#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define KAPREKARS_CONSTANT_3 495
#define KAPREKARS_CONSTANT_4 6174

int validate(int num, int start, int end);
int cmp_increasing(const void *p1, const void *p2);
int cmp_decreasing(const void *p1, const void *p2);
int kaprekar_process(int num, int kaprekars_constant, int start, int end);

int main(void)
{
  int i, steps, digits,
    start, end, kaprekars_constant;

  printf("Would you like to generate for 3 digits or 4 digits? ");
  scanf("%d", &digits);

  if (digits == 3) {
    kaprekars_constant = KAPREKARS_CONSTANT_3;
  } else {
    kaprekars_constant = KAPREKARS_CONSTANT_4;
  }

  start = pow((double) 10, (double) (digits - 1));
  end  = pow((double) 10, (double) digits);

  for (i = start; i < end; i++) {
    steps = kaprekar_process(i, kaprekars_constant, start, end);
    printf("%d, %d steps\n", i, steps);
  }

  return 0;
}

int kaprekar_process(int num, int kaprekars_constant, int start, int end)
{
  int cur_num = num, i = 0;
  char little[5], big[5];

  do {
    i++;

    sprintf(little, "%d", cur_num);
    strcpy(big, little);

    qsort(little, strlen(little), sizeof(char), cmp_increasing);
    qsort(big, strlen(big), sizeof(char), cmp_decreasing);

    if (!validate(cur_num, start, end)) {
      return -1;
    }
  }
  while((cur_num = atoi(big) - atoi(little)) != kaprekars_constant);

  return i;
}

int validate(int num, int start, int end)
{
  if ((num < start) || (num > end)) {
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
