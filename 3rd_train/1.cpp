#include <stdio.h>

using namespace std;

int main() 
{
  char string[200];
  int freq['z'-'!' + 1] = {0};
  char Chars['z'-'!' + 2];
  int max = 0;
  
  while (scanf(" %200s", string) == 1)
    for (int i = 0; string[i] != '\0'; i++)
    {
      freq[string[i]-'!']++;
      if (freq[string[i]-'!'] > max)
        max = freq[string[i]-'!'];
    }
  
  int count = 0;
  for (int i = 0; i < 'z'-'!' + 1; i++)
    if (freq[i])
    {
      Chars[count] = i + '!';
      count++;
    }
  Chars[count] = '\0';
  
  char out[200];
  for (int i = 0; i < max; i++)
  {
    for (int j = 0; j < count; j++)
    {
      if (max - freq[Chars[j] - '!'] <= i)
        out[j] = '#';
      else
        out[j] = ' ';
    }
    out[count] = '\0';
    printf("%s\n", out);
  }
  printf("%s\n", Chars);
}
