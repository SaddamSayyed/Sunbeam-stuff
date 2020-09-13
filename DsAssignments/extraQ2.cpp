#include <iostream>
using namespace std;
#define SIZE 11
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}
void firstNonRepeatingNo(int* a, int size , int* ans)
{
    int count = 0,flag;
    for (int i = 0 ; i < size ; i++ )
    {
        flag = 0;
        for( int j = 0 ; j < size ; j++)
        {
            if( a[i] != a[j] || i == j ) continue ;
            else 
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0 )
        {
            cout << a[i] << "\n";
            ans[count++] = a[i] ;
            if(count == 3) break;
        }
            
    }
}
int main ()
{
    int a[] = { 1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8 } ;
    cout << "Given Array : \t" ; print(a,SIZE) ;
    int ans[3] = {0};
    firstNonRepeatingNo(a,SIZE,ans);
    cout << "First 3 Non repeating Elements Are :\t" ;
    print(ans,3);
    return 0 ;
}