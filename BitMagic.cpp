/*
Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	
	ll n , x (0);
	cin >> n ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ )
		cin >> arr [ i ] ;
	for ( ll i = 0 ; i < 32 ; i ++ )
	{
		ll c(0) ;
		
		for ( ll j = 0 ; j < n ; j ++ )
		{
			if ( (  arr [ j ] &  ( 1 << i )  ) >> i  == 1 )   
				c++ ;
		}
		if ( c % 3 )
			x = x  + pow ( 2 , i ) ;
	}
	cout << x ;
	return 0;
}
