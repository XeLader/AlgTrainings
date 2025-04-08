#include "stdlib.h"
#include "stdio.h"
#include "string.h"

const char greet_str[] = "Initial array: \n";
const char dots_str[] = "**********\n";
const char phase_str[] = "Phase %d\n";
const char bucket_str[] = "Bucket %d: ";
const char empty_str[] = "empty\n";
const char finish_str[] = "Sorted array:\n";

void printarr(char *arr, int N, size_t len)
{
  if (N == 0)
  {
    printf("%s", empty_str);
    return; 
  }
  for (int i = 0; i < N - 1; i++)
    printf("%s, ", arr + i*len);
  printf("%s\n", arr + (N-1)*len);
}

int main()
{
  int N;
  scanf("%d", &N);
  char test[21] = {0};
  scanf("%20s", test);
  size_t len = strlen(test) + 1;
  char *arr = calloc(N*len, sizeof(char));
  char **baskets = calloc(10, sizeof(char*));
  unsigned short basketsCount[10] = {0};
  for (int i = 0; i < 10; i++)
    baskets[i] =  calloc(N*len, sizeof(char));
  
  strcpy(arr, test);
  for (int i = 1; i < N; i++)
    scanf("%s", arr+i*len);
    
  printf(greet_str);
  printarr(arr, N, len);
  for (int i = len - 2; i >= 0; i--)
  {
    printf(dots_str);
    printf(phase_str, len - 1 - i);
    
    for (int j = 0; j < N; j++)
    { 
      char dig = arr[j*len + i] - '0';
      strcpy(baskets[dig] + basketsCount[dig]*len, arr + j*len);
      basketsCount[dig]++;
    }
    int total = 0;
    for (int k = 0; k < 10; k++)
    {
      printf(bucket_str, k);
      printarr(baskets[k], basketsCount[k], len);
      for (int j = 0; j < basketsCount[k]; j++)
      {
        strcpy(arr + total*len, baskets[k] + len*j);
        total++;
      }
      basketsCount[k] = 0;
    }  
  }
  printf("%s%s",dots_str, finish_str);
  printarr(arr, N, len);
}
