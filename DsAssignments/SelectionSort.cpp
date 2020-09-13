#include <iostream>
using namespace std;
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
        for(int j = i+1 ; j < size ; j++ )
        {
            if( a[i] < a[j])
                continue ;
            else
            {
                a[i] = a[i] ^ a[j] ;
                a[j] = a[i] ^ a[j] ;
                a[i] = a[i] ^ a[j] ;
            }
            
        }
    }
    cout <<"\n Array after swapping \n" ;
    print(a,10);
}
int main()
{
    int a[10] = { 22,14,54,24,78,95,99,23,45,21 } ;
    cout << "initial array \n" ;
    print(a,10);
    sortArray(a,10);
}