#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c, n, d, count = 0;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int bin = 0b0000000000;
    bin = (0b1 << a) + (0b1 << b) + (0b1 << c);
    do {
    d = n % 10;
    if (!((0b1 << d) & bin))
    {
      count++;
      bin += (0b1 << d);
    }
    n /= 10;
    } while (n);
    printf("%d", count);
}
