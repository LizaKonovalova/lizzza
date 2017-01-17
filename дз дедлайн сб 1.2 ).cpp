#include <iostream>
#include <cmath>
using namespace std;

void reverse( int a );
void print_palindrom( int x );

int main()
{
int x;
cin » x;
print_palindrom(x);
system("pause");
return 0;
}

void reverse( int a )
{
while (a != 0)
{
cout « a % 10;
a /= 10;
}
}

void print_palindrom( int x )
{
if (x % 2 == 0)
{
int i = pow(10, x / 2 - 1);
int n = i - 1;
while (true)
{
n += 9;
if (n / (10 * i) != 0)
break;
cout « n;
reverse(n);
cout « " ";
}
}
else
{
int i = pow(10, x / 2 - 1);
int n = i - 1;
while (true)
{
n++;
if (n / (10 * i) != 0)
break;
cout « n « 9 - ((n * 2) % 9);
reverse(n);
cout « " ";
}
}
}
