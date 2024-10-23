#include <iostream>
#include <limits>

using namespace std;
int main()
{
  long long max1_pos = 0, max2_pos = 0, max1_neg = 0, max2_neg = 0, min_pos = numeric_limits<long long>::max(), min_neg = numeric_limits<long long>::min();
  long long temp;
  int  null_count = 0, pos_count = 0;
  while (cin >> temp)
  {
    if (temp > max1_pos)
    {
      max2_pos = max1_pos;
      max1_pos = temp;
    }
    else if (temp > max2_pos)
      max2_pos = temp;
    else if (temp < max1_neg)
    {
      max2_neg = max1_neg;
      max1_neg = temp;
    }
    else if (temp < max2_neg)
      max2_neg = temp;
    if (min_pos > temp and temp > 0)
    {
      min_pos = temp;
      pos_count++;
    }
    else if (min_neg < temp and temp < 0)
      min_neg = temp;
    else if (temp == 0)
      null_count++; 
  }
  if (max1_pos && max2_pos && max1_neg && max2_neg)
  {
    if (max1_pos*max2_pos > max1_neg*max2_neg)
      cout << max2_pos<<' ' << max1_pos;
    else 
      cout << max1_neg << ' ' << max2_neg;
  }
  else if (max1_pos && max2_pos)
    cout << max2_pos<< ' ' << max1_pos;
  else if (max1_neg && max2_neg)
    cout << max1_neg<< ' ' << max2_neg;
  else if (null_count)
  {
    if (pos_count)
      cout<< 0 << ' ' << min_pos;
    else if (null_count > 1)
      cout<< "0 0";
    else
      cout << min_neg<< ' '<< 0;
  }
  else
    cout << min_neg<< ' '<<min_pos;
}
