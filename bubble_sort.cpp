#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n , x ;
	cin >> n ;
	cout <<  n << "\n" ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cout <<  arr [ i ]  << " ";
	cout << "\n" ;
	for ( ll i = 0 ; i < n ; i ++ )
	{
		for ( ll j = 0 ; j < n - i - 1 ; j ++ )
		{
			if ( arr [ j ]  > arr [ j + 1 ] )
			{
				swap ( arr [ j ] , arr [ j + 1 ] ) ;
			}
		}
	}
		for ( ll i = 0 ; i < n ; i ++ ) cout <<  arr [ i ] <<" " ;
		cout << endl ;

	// your code goes here
	return 0;
}
