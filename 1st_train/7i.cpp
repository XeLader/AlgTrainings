#include <iostream> 
#include <set>
#include <array>

using namespace std; 

int main()
{
  int N, M, dep, hd, md, ar, ha, ma;
  long long BusUsed = 0;
  long long *depo, *balance;
  
  multiset<array<int,3>> timetbl;
  multiset<array<int,3>>::iterator itr;
  
  cin >> N >> M;
  depo = new long long[N];
  balance = new long long[N];
  
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d:%d %d %d:%d",  &dep, &hd, &md, &ar, &ha, &ma);
    md += hd*60;
    ma += ha*60;
    if (md > ma)
      BusUsed ++;
    timetbl.insert({ma, -1, ar});
    timetbl.insert({md, 1, dep});
    balance[ar-1]++;
    balance[dep -1]--;
  }
  
  for (int i = 0; i < N; i++)
    if (balance[i]!=0)
    {
    cout << -1;
    return 0;
    }
  
  
  for(itr = timetbl.begin(); itr != timetbl.end(); itr++)
  {
    switch ((*itr)[1])
    {
      case -1:
        depo[(*itr)[2]-1]++;
        break;
        
      case 1:
        if (depo[(*itr)[2]-1] > 0)
          depo[(*itr)[2]-1]--;
        break;
    }
  }
  for (int i = 0; i < N; i++)
    BusUsed +=depo[i];
  cout << BusUsed;

  
}
