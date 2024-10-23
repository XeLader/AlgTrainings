#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n;
  long double min = 30, max = 4000,  freq1, freq2;
  char cf;
  cin >> n;
  cin >> freq1;
  for (int i = 1; i < n; i++)
  {
    scanf("%LF %c%*s", &freq2, &cf);
    if (abs(freq2-freq1) > 0.000001)
    switch (cf)
    {
     case 'c':
       if (freq2 < freq1)
       {
         if ((freq2 + freq1) / 2.0 < max)
           max = (freq2 + freq1) / 2.0;
       }
       else
       {
         if ((freq1 + freq2) / 2.0 > min)
           min = (freq1 + freq2) / 2.0;
       }
       break;
    
     case 'f':
       if (freq2 < freq1)
       {
         if ((freq2 + freq1) / 2.0 > min) 
           min = (freq2 + freq1) / 2.0 ;
       }
       else
       {
         if ((freq1 + freq2) / 2.0 < max)
           max = (freq1 + freq2) / 2.0;
       }
       break;
    }
    
    freq1 = freq2;
  }
  printf("%LF %LF", min, max);
}
