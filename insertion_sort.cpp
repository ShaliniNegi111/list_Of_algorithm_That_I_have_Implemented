#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n ;
	cin >> n ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;

	for ( ll i = 1 ; i > n ; i ++ )
	{
		ll key = arr [ i ] ;
		ll j = i - 1 ;
		while ( j >= 0 and arr [ j ] > key )
		{
			arr [ j + 1 ] = arr [ j  ] ;
			j -- ;
		}
		arr [ j + 1 ] = key ;
	}
	for ( ll i = 0 ; i < n ; i ++ ) cout <<  arr [ i ] << " ";
	// your code goes here
	return 0;
}
