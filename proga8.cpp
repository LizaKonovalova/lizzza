#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Migraine_minimization(int n)
{
 vector <int> a(n + 1);
 a[0] = 0;
 for (int i = 1; i <= n; i++)
    {
  a[i] = a[i - 1];
  for (int s = 1; s * s <= i; s++)
   a[i] = min(a[i], a[i - s*s]);
  a[i]++;
 }
 return 4 * a[n];
}
int main(){
 int N;
 cin >> N;
 cout << Migraine_minimization(N);
 return 0;
}

