#include "stdio.h"

using namespace std;

int main()
{
  int N, hour, min, sec, time, timePrev = 0, delay, max = 0;
  
  int count[60*60*9 + 1] = {0};
  
  scanf("%d", &N);
  scanf("%d:%d:%d %d", &hour, &min, &sec, &delay);
  for (int i = 1; i < N; i++)
  {
    scanf("%d:%d:%d", &hour, &min, &sec);
    time = (hour - 9)*60*60 + min * 60 + sec;
    for (int t = timePrev; t < time; t++)
    {
      if ((t <= (13 - 9) * 60 * 60) or (t >= (14 - 9) * 60 * 60)) 
      {
        if (count[t] > max)
          max = count[t];
        if (((t < (13 - 9) * 60 * 60) and (t + delay <= (13 - 9) * 60 * 60)) or ((t >= (14 - 9) * 60 * 60) and (t + delay <= (18 - 9) * 60 * 60)))
          if (count[t + delay] < max + 1)
            count[t + delay] = max + 1;
      }
    }  
    timePrev = time;
    scanf("%d", &delay);
  }
  time = (18 - 9) * 60 * 60;
    for (int t = timePrev; t <= time; t++)
    {
      if ((t <= (13 - 9) * 60 * 60) or (t >= (14 - 9) * 60 * 60)) 
      {
        if (count[t] > max)
          max = count[t];
        if (((t < (13 - 9) * 60 * 60) and (t + delay <= (13 - 9) * 60 * 60)) or ((t >= (14 - 9) * 60 * 60) and (t + delay <= (18 - 9) * 60 * 60)))
          if (count[t + delay] < max + 1)
            count[t + delay] = max + 1;
      }
    } 
  printf("%d", max);
}
