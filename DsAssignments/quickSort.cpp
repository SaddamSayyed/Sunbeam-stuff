#include <iostream>
using namespace std;
#define SIZE 10
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}

int partition (int* a, int lb , int ub)
{
    int start = lb , end = ub , pivote = a[lb];
    while(start < end)
    {
        while(a[start] <= pivote )
            start++ ;
        while(a[end] > pivote )
            end--;
        if(start < end) 
        {
            swap(a[start],a[end]);
        } 
        print(a,SIZE);
 
    }
    swap(a[lb],a[end]);
    return end; 
}
void sortArray(int* a, int lb , int ub)
{
    int loc;
    if(lb < ub) 
    {
        loc = partition( a ,lb , ub) ;
        sortArray(a,lb,loc-1);
        sortArray(a,loc+1,ub);
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