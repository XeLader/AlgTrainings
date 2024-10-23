#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> Ann{};
    set<int> Bor{};
    int N, M, a;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
      cin >> a;
      Ann.insert(a);
    }
    
    for (int i = 0; i < M; i++)
    {
      cin >> a;
      Bor.insert(a);
    }
    
    set<int> intersect;
    set_intersection(Ann.begin(), Ann.end(), Bor.begin(), Bor.end(),
                 inserter(intersect, intersect.begin()));
    
    cout << intersect.size()<<'\n';
    for (const int& elem : intersect)
    {
      cout << elem << ' ';
      Ann.erase(elem);
      Bor.erase(elem);
    }    
    
    cout<<'\n'<<Ann.size()<<'\n';
    for (const int& elem : Ann)
    {
      cout << elem << ' ';
    }    
    
    cout<<'\n'<<Bor.size()<<'\n';
    for (const int& elem : Bor)
    {
      cout << elem << ' ';
    }    
    
}
