//============================================================================
// Name        : LinearSearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 5
int search(int i , int *a , int n )
{
	if( a[i] == n)
		return i;
	else {
		if ( i < SIZE)
		search ( ++i, a , n);
		else
			return -1;
	}
	return -1;

}
int main() {
	int a[SIZE] = { 11 , 43 , 22 , 33 , 55 }; int n = 0 ;
	//int n = 0 ; cout << "No Of Elements  ?" ; cin >> n;
	//cout << "\nEnter Element" ; for( int i = 0 ; i < SIZE ; i++ ) cin >> a[i] ;
	cout << "\nArray Element\n" ; for( int i = 0 ; i < SIZE ; i++ ) cout << a[i] << "\t" ;
	cout << "\nEnter element to be found : " ; cin >> n ;
	int i = search (0, a ,n);
	if (  i != -1) cout << "\nThe number found at " << i << " index \n";
	else cout << "\nNo such element has been found \n " ;

	return 0;
}
