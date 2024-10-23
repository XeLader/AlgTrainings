#include <iostream>
#include <limits>

using namespace std;

int main()
{
  long long max1_pos = 0, max2_pos = 0, max3_pos = 0, max1_neg = 0, max2_neg = 0;
  long long min1_neg = numeric_limits<long long>::min();
  long long min2_neg = numeric_limits<long long>::min();
  long long min3_neg = numeric_limits<long long>::min();
  long long min1_pos = numeric_limits<long long>::max();
  long long min2_pos = numeric_limits<long long>::max();
  long long temp;
  int  null_count = 0, pos_count = 0, neg_count = 0;
  while (cin >> temp)
  {
    if (temp>0)
    {
      pos_count++;
      if (temp > max1_pos)
      {
        max3_pos = max2_pos;
        max2_pos = max1_pos;
        max1_pos = temp;
      }
      else if (temp > max2_pos)
      {
        max3_pos = max2_pos;
        max2_pos = temp;
      }
      else if (temp > max3_pos)
        max3_pos = temp;
        
      if (temp < min1_pos)
      {
        min2_pos = min1_pos;
        min1_pos = temp;
      }
      else if (temp < min2_pos)
        min2_pos = temp;
    } 
    else if (temp < 0)
    {
      neg_count++;
      if (temp < max1_neg)
      {
        max2_neg = max1_neg;
        max1_neg = temp;
      }
      else if (temp < max2_neg)
        max2_neg = temp;
        
      if (temp > min1_neg)
      {
        min3_neg = min2_neg;
        min2_neg = min1_neg;
        min1_neg = temp;
      }
      else if (temp > min2_neg)
      {
        min3_neg = min2_neg;
        min2_neg = temp;
      }
      else if (temp > min3_neg)
        min3_neg = temp;
    }
    else if (temp == 0)
      null_count++; 
  }
  
  
  if (max1_pos && max2_pos && max3_pos && max1_neg && max2_neg)
  {
    if (max1_pos*max2_pos*max3_pos > max1_neg*max2_neg*max1_pos )
      cout << max3_pos << ' ' << max2_pos << ' ' << max1_pos;
    else 
      cout << max1_neg << ' ' << max2_neg << ' ' << max1_pos;
  }
  else if (max1_pos && max2_pos && max3_pos)
    cout << max3_pos<< ' ' << max2_pos<< ' ' << max1_pos;
  else if (max1_neg && max2_neg && max1_pos)
    cout << max1_neg<< ' ' << max2_neg<< ' ' <<max1_pos;
  else if (null_count)
    switch (pos_count)
    {
    case 1:
      if (null_count > 1)
        cout << "0 0 " << max1_pos;
      else
        cout<< max1_neg<< " 0 " << max1_pos;
      break;
      
    case 0:
      if (null_count > 2)
        cout << "0 0 0";
      else if (null_count > 1)
        cout<< max1_neg<< " 0 0";
      else
        cout << max1_neg<<' ' << max2_neg << " 0";
      break;
    
    default:
      cout << "0 "<< max2_pos << ' ' << max1_pos;
    }
  else
    switch (neg_count)
    {
      case 1:
        cout << min1_neg<< ' ' << min1_pos << ' ' << min2_pos;
        break;
        
      default:
        cout<< min1_neg<< ' ' << min2_neg << ' ' <<min3_neg;
        break;
      
    }
}
