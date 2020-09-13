#include <iostream>
using namespace std;
#define SIZE 11
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}
int firstNonRepeatingNo(int* a, int size)
{
    for (int i = 0 ; i < size ; i++ )
    {
        int flag = 0 ;
        for( int j = i+1 ; j < size ; j++)
        {
            if( a[i] != a[j] ) continue ;
            else 
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return a[i] ;
    }
    return 0;
}
int main ()
{
    int a[] = { 1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8 } ;
    cout << "Given Array :\t" ; print(a,SIZE) ;
    int e = firstNonRepeatingNo(a,SIZE);
    cout << "\nFirst Non Repeating Number Is  : "<< e << endl;
    return 0 ;
}