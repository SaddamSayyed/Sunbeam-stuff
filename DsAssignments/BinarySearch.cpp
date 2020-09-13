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
int main() {
	int a[SIZE] = { 11 , 43 , 22 , 33 , 55 }, n = 0;
	//int n = 0 ; cout << "No Of Elements  ?" ; cin >> n;
	//cout << "\nEnter Element" ; for( int i = 0 ; i < SIZE ; i++ ) cin >> a[i] ;
	sort(a,a+SIZE);
	cout << "\nArray Elements\n" ; for( int i = 0 ; i < SIZE ; i++ ) cout << a[i] << "\t" ;
	cout << "\nEnter element to be found : " ; cin >> n ;
	int l = 0, r = SIZE -1 , mid = 0;
	int index = -1 ;
	while (l <= r) {
		mid = (r+l)/2 ;
		if (a[mid] == n ) index = mid;
		else if ( a[mid] < n) l = mid+1 ;
		else r = mid-1 ;
		if ( index > -1) {
			cout << "\nThe number found at " << mid << " index \n";
			return 0;
		}
	}
	cout << "\nNo such element has been found \n " ;
	return 0;
}