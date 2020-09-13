#include <iostream>
using namespace std;
#define SIZE 7
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}
int findRank(int* a, int size , int n)
{
    int rank = 0; 
    for (int i = 0 ; i < size ; i++ )
        if(a[i] <= n) rank++;
    return rank ;
}
int main ()
{
    int a[] = { 10, 20, 15, 3, 4, 4, 1 } ;
    cout << "Given Array : \t" ; print(a,SIZE) ;
    int n; cout << " enter the number : " ; cin >> n ;
    int rank = findRank(a,SIZE , n);
    cout << "Rank of " << n << " is : " << rank << endl;
    return 0 ;
}