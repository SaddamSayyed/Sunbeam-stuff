#include <iostream>
using namespace std;
void print(int* a, int size)
{
    for (int i = 0; i < size ; i++)
        cout << a[i] <<"\t";
        cout<<endl ;
}
int main()
{
    int size,temp;
    cout << "Please enter the number of elements\n" ;
    cin >> size ;
    int *a = (int *) calloc(size , sizeof(int)); print(a,size) ;
    cout << "enter " << size << " elements : " ;
    cin >> a[0] ; print(a,size) ;
    for(int i = 1 ; i < size ; i++ )
    {
        int j = i-1 ;
        cin >> temp ;
        while( j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j] ; j--;
        }
        a[j+1] = temp ;
        print(a,size) ;

    }
    cout << "\nInserted Elements in sorted form are :\t" ;
    print(a,size) ;
    return 0 ;

}