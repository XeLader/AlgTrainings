#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "utility"
#include "set"

using namespace std;

map<string *, vector<string *>> tree;
map<string *, int> levelCount;
map<string, int> ordering;
vector<string *> visitingOrder;
vector<int> visitingOrderLevel;
vector<int> firstVisiting;

void deep(string* member, int level)
{
  levelCount[member] = level;
  visitingOrder.push_back(member);
  for (int i = 0; i < tree[member].size(); i++)
  {
    deep(tree[member][i], level + 1);
    visitingOrder.push_back(member);
  }
}

int min(int r, int l)
{
   
   if (l > r)
   {
    int temp = l;
    l = r;
    r = temp;
   }
   
   int min = visitingOrderLevel[l], minEl = l;
   
   for (int i = l; i < r;  i++)
   {
     if (visitingOrderLevel[i] < min)
     {
        min = visitingOrderLevel[i];
        minEl = i;
      }
    }
    return minEl;
}




int main()
{
  map<string *, bool> parentCount;
  string child, parent;

  int N;
  cin >> N;
  vector<pair<string,string>> prebuild(N);
  set<string> allmembers;
  vector<string> members(N);
  firstVisiting.assign(N, -1);
  for (int i =0 ; i < N-1; i++)
  {
    cin >> child >> parent;
    prebuild[i] = make_pair(child, parent);
    allmembers.insert(child);
    allmembers.insert(parent);
    
  }

  int count = 0;
  for (auto it = allmembers.begin(); it !=  allmembers.end(); it++)
  {
    members[count] = *it;
    ordering[members[count]] = count;
    tree[&members[count]] = vector<string*>(0);
    count++;
  }
  string* head, *itChild, *itParent;
  for (int i =0 ; i < N-1; i++)
  {
    itChild = &members[ordering[prebuild[i].first]];
    itParent= &members[ordering[prebuild[i].second]];
    parentCount[itChild] = true;
    if (!parentCount.contains(itParent))
    {
      parentCount[itParent] = false;
    }
    tree[itParent].push_back(itChild);
  }



  for (auto it = parentCount.begin(); it !=  parentCount.end(); it++)
  {
    if (!it -> second)
    {
      head = (it->first);
      break;
    }
  }
  deep(head, 0);
  
  visitingOrderLevel.resize(visitingOrder.size());
  for (int i = 0; i < visitingOrder.size(); i++)
  {
    child = *visitingOrder[i];
    if (firstVisiting[ordering[child]] == -1)
      firstVisiting[ordering[child]] = i;
    visitingOrderLevel[i] =  levelCount[visitingOrder[i]];
  }
  count = 0;
  
  while(cin >> child >> parent)
  {
    int l = ordering[child], r = ordering[parent];
    int minEl = min(firstVisiting[l] ,firstVisiting[r]);
    cout << *visitingOrder[minEl] << '\n';
  }     

}
