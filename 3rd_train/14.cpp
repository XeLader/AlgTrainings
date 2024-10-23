#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class BigInt{
    string digits;
public:
 
    //Constructors:
    BigInt(unsigned long long n = 0);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    BigInt &operator=(const BigInt &);
 
    friend bool operator<(const BigInt &, const BigInt &);
 
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);

    friend ostream &operator<<(ostream &,const BigInt &);


};
 
BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt & a){
    return a.digits.size();
}


bool operator<(const BigInt&a,const BigInt&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}


BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}
  
 
BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}
 
ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

int main()
{
  int N;
  cin >> N;
  
  stack<int> height;
  stack<int> num;
  
  int *left = new int[N];
  int *right = new int[N];
  int *high = new int[N];
  
  int h;
  for (int i = 0; i < N; i ++)
  {
    cin >> h;
    high[i] = h;
    if (!height.empty())
    {
      while (height.top() > h)
      {
        right[num.top()] = i;
        num.pop();
        height.pop();
        if (height.empty())
          break;
      }
    }
    
    if (!height.empty())
      left[i] = num.top();
    else
      left[i] = -1;    
    num.push(i);
    height.push(h);
  }
  while (!height.empty())
  {
        right[num.top()] = N;
        num.pop();
        height.pop();
  }
  
  
  BigInt maxH((unsigned long long )0);
  BigInt temp((unsigned long long )0);

  for (int i = 0; i < N; i ++)
  {
    BigInt length(right[i] - left[i] - 1);
    BigInt hiight (high[i]);
    temp = length * hiight;
    if (maxH < temp)
      maxH = temp;
  }
  
  cout << maxH;
}
