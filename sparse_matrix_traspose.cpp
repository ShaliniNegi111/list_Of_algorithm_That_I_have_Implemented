// traspose of matrix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr [ 100 ] [ 100 ] ;
int main() {
	ll n1 , n2 , m1 , m2 , k (0);
	cin >> n1 >> n2 ;

	for (ll i = 0 ;  i < n1 ; i ++ )
	{
		for ( ll j = 0 ; j < n2 ; j ++ )
		{
			cin >> arr [ i ] [ j ] ;
			if ( arr [ i ] [ j ] ) k ++ ;
		}
	}
	ll sparse [ k + 1 ] [ 3 ] ,ans [ k +1 ] [ 3 ] ;
	sparse [ 0 ] [ 0 ] = n1 ;
	sparse [ 0 ] [ 1 ] = n2 ;
	sparse [ 0 ] [ 2 ] = k ;
	k = 1 ;
	for (ll i = 0 ;  i < n1 ; i ++ )
	{
		for ( ll j = 0 ; j < n2 ; j ++ )
		{

			if ( arr [ i ] [ j ] )
			{
				sparse [ k ] [ 0 ] = i ;
				sparse [ k ] [ 1 ] = j ;
				sparse [ k ] [ 2 ] = arr [ i ] [ j ]  ;
				k ++ ;
			}
		}
	}

	for ( ll i = 0 ; i <= sparse [ 0 ] [ 2 ] ; i ++ )
	cout << sparse  [i ] [0 ] << " " << sparse [ i ] [ 1 ] << " " << sparse [ i ][ 2 ] << endl ;

	cout << endl ;
	k = 1 ;
	ans [ 0 ] [ 0 ] = sparse [ 0 ] [ 1 ];
	ans [ 0 ] [ 1 ] = sparse [ 0 ] [ 0 ] ;
	ans [ 0 ] [ 2 ] = sparse [ 0 ] [ 2 ] ;
	for ( ll i = 0 ; i < sparse [ 0 ] [ 1 ] ; i ++ )
	{
		for ( ll j = 1 ; j <= sparse [ 0 ] [ 2 ] ; j ++ )
		{
			if ( sparse [ j ] [ 1 ] == i )
			{
				ans [ k ] [ 0 ] = sparse [ j ] [ 1 ] ;
				ans [ k ] [ 1 ] = sparse [ j ] [ 0 ] ;
				ans [ k ] [ 2 ] = sparse [ j ] [ 2 ]	;
				k ++ ;
			}
		}
	}
	for ( ll i = 0 ; i <= ans [ 0 ] [ 2 ] ; i ++ )
	cout << ans  [i ] [0 ] << " " << ans [ i ] [ 1 ] << " " << ans [ i ][ 2 ] << endl ;


}

