// stable selection sort
// A sorting algorithm is said to be stable if two objects with equal or same keys appear
//in the same order in sorted output as they appear in the input array to be sorted.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n , m ;
	cin >> n ;
	ll arr [ n ] ;
	for( ll i = 0 ; i < n ; i++ ) cin >> arr [ i ] ;
	for ( ll i = 0 ; i < n - 1; i ++ )
	{
		ll mini = i ;
		for ( ll j = i + 1 ; j < n ; j ++ )
		{
			if ( arr [ j ] < arr [mini] )
			{
				mini = j ;
			}
		}
		ll temp = arr [ mini ] ;
		for ( ll j = mini ; j >= i + 1   ; j -- )
		{
			arr [ j ] = arr [ j - 1 ] ;
		}
		arr [ i ] = temp ;
	}
	for( ll i = 0 ; i < n ; i++ ) cout <<  arr [ i ] << " ";
	return 0;
}
}
