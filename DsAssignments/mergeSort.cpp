#include <iostream>
using namespace std;
#define SIZE 10
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}

void merge (int* a, int lb ,int mid, int ub)
{
    int i = lb , j = mid+1 , k = lb , b[SIZE] = {0};
    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j] )
        {
            b[k] = a[i] ; i++;
        }
        else
        {
            b[k] = a[j] ; j++;
        }
        k++;        
    }
    if(i > mid )
    {
        while( j <= ub )
        {
            b[k] = a[j] ; j++ ; k++ ;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i] ; i++ ; k++ ;
        }  
    }
    for( int k = lb ; k <= ub ; k++ )
        a[k] = b[k] ;
}
void sortArray(int* a, int lb , int ub)
{
    int mid;
    if(lb < ub) 
    {
        mid = (lb+ub)/2;
        sortArray(a,lb,mid);
        sortArray(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }   
}
int main()
{
    int a[SIZE] = { 22,14,54,24,78,95,99,23,45,21 } ;
    cout << "initial array \n" ;
    print(a,SIZE);
    sortArray(a,0,SIZE-1);
    cout <<"\n Array after swapping \n" ;
    print(a,SIZE);
    return 0;
}