//============================================================================
// Name        : BinarySearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 5
int search(int mid , int *a , int n, int l , int r )
{
	if ( l > r) return -1;
	mid = (r+l)/2 ;
	if (a[mid] == n ) return mid;
	else if ( a[mid] < n) return search (mid, a , n, mid+1 , r) ;
	else return search (mid, a , n, l , mid-1) ;
	return -1 ;

}
int main() {
	int a[SIZE] = { 11 , 43 , 22 , 33 , 55 }, n = 0;
	//int n = 0 ; cout << "No Of Elements  ?" ; cin >> n;
	//cout << "\nEnter Element" ; for( int i = 0 ; i < SIZE ; i++ ) cin >> a[i] ;
	sort(a,a+SIZE);
	cout << "\nArray Elements\n" ; for( int i = 0 ; i < SIZE ; i++ ) cout << a[i] << "\t" ;
	cout << "\nEnter element to be found : " ; cin >> n ;
	int l = 0, r = SIZE -1 , mid = 0;
	int index = search ( (r+l)/2,a,n,0,SIZE-1);
	if ( index != -1) cout << "No has been found at " << index << " Index\n" ;
	else cout << "\nNo such element has been found \n " ;
	return 0;
}
