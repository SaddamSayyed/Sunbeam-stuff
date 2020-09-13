#include <iostream>
using namespace std;
#define SIZE 10
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}
void sortArray(int* a, int size)
{
    for(int i = 0 ; i < size-1 ; i++ )
    {
        int flag = 0 ;
        for(int j = 0 ; j < size-1-i ; j++ )
        {
            if( a[j] > a[j+1])
            {
                a[j] = a[j] ^ a[j+1] ;
                a[j+1] = a[j] ^ a[j+1] ;
                a[j] = a[j] ^ a[j+1] ;
                flag = 1 ;
            }   
        }
       if ( flag == 0 ) break ;
    }
}
int main()
{
    int a[SIZE] = { 22,14,54,24,78,95,99,23,45,21 } ;
    cout << "initial array \n" ;
    print(a,SIZE);
    sortArray(a,SIZE);
    cout <<"\n Array after swapping \n" ;
    print(a,SIZE);
    return 0;
}