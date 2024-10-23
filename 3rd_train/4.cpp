#include <iostream>

using namespace std;

int main()
{
  int N, K, col, lr;
  cin >> N >> K >> col >> lr;
  
  int VasSeat;
  int PetSeat = ((col - 1) * 2 + lr);
  int PetN = PetSeat % K;
  PetN = (PetN == 0) ? K : PetN;
  
  if (N < (K + PetN))
    cout << -1;


  else if (PetSeat + K > N)
  {
    VasSeat = PetSeat - K;
    cout << VasSeat / 2 + VasSeat % 2 << " " << 2 - VasSeat % 2;  
  }
  else if (PetSeat - K <= 0)
  {
    VasSeat = PetSeat + K;
    cout << VasSeat / 2 + VasSeat % 2 << " " << 2 - VasSeat % 2;  
  }
  else
  {
  VasSeat = PetSeat - K;
  int col1 = VasSeat / 2 + VasSeat % 2;
  int lr1 = 2 - VasSeat % 2;
   VasSeat = PetSeat + K;
  int col2 = VasSeat / 2 + VasSeat % 2;
  int lr2 = 2 - VasSeat % 2;
  
  if (col - col1 < col2 - col)
    cout << col1 << " " << lr1;
  else
    cout << col2 << " " << lr2;
  }
}
