#include <iostream>

using namespace std;

int main()
{ int n,i,j ;
int *a = new int [n] ;
for (i=0 ; i<n ; i++)
{
    a[i]=1 ;
} ;
for ( i =2 ; i < n ; i++)
{
    if (a [i]==1)
    {
        for ( j=i ;j<n ; j+=i)
        {
            a[j]=0 ;
        }
        a[i]=1
        }
}
    int q = 0 ;
    for ( int i = 2 ; i<n ; i++)
    {
        if (a[i]==1)
    }
    cout << "setw(5)" << i << " ";
    q++ ;
    if ( q % 5==0) cout << endl ;
}
}
delete [a]
    return 0;
}
