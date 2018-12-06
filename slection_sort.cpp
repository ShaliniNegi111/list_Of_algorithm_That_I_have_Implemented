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
		ll mini = arr[ i  ] , pos (i);
		for ( ll j = i + 1 ; j < n ; j ++ )
		{
			if ( arr [ j ] < mini )
			{
				mini = arr [ j ] ;
				pos = j ;
			}
		}
		swap ( arr [ i ] , arr [ pos ] ) ;
		for( ll i = 0 ; i < n ; i++ ) cout <<  arr [ i ] << " " ;
		cout << endl ;
	}

	// your code goes here
	return 0;
}
