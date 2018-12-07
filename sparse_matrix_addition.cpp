// addition of sparse matrix ;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr [ 100 ] [ 100 ] ;
int main() {
	ll n1 , n2 , m1 , m2 , k (0);
	cin >> n1 >> n2 >> m1 >> m2 ;

	for (ll i = 0 ;  i < n1 ; i ++ )
	{
		for ( ll j = 0 ; j < n2 ; j ++ )
		{
			cin >> arr [ i ] [ j ] ;
			if ( arr [ i ] [ j ] ) k ++ ;
		}
	}
	ll sparse [ k + 1 ] [ 3 ] ;
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

	k = 0 ;
	for (ll i = 0 ;  i < m1 ; i ++ )
	{
		for ( ll j = 0 ; j < m2 ; j ++ )
		{
			cin >> arr [ i ] [ j ] ;
			if ( arr [ i ] [ j ] ) k ++ ;
		}
	}


	ll sparse2 [ k + 1 ] [ 3 ] ;
	sparse2 [ 0 ] [ 0 ] = m1 ;
	sparse2 [ 0 ] [ 1 ] = m2 ;
	sparse2 [ 0 ] [ 2 ] = k ;
	k = 1 ;
	for (ll i = 0 ;  i < m1 ; i ++ )
	{
		for ( ll j = 0 ; j < m2 ; j ++ )
		{

			if ( arr [ i ] [ j ] )
			{
				sparse2 [ k ] [ 0 ] = i ;
				sparse2 [ k ] [ 1 ] = j ;
				sparse2 [ k ] [ 2 ] =  arr [ i ] [ j ] ;
				k ++ ;
			}
		}
	}

	ll ans [ 100 ] [ 3 ] ;
	if ( sparse [ 0 ] [ 0 ] == sparse2 [ 0 ] [0 ] and sparse [ 0 ] [ 1 ] == sparse2 [ 0 ] [ 1 ])
	{
		ans [ 0 ] [ 0 ] = sparse [0 ] [ 0 ] ;
		ans [ 0 ] [ 1 ] = sparse [ 0 ] [ 1 ] ;
		ll i(1) , j(1) ;
		k = 1 ;
		while ( i <= sparse [ 0 ] [ 2 ] and j <= sparse [ 0 ] [ 2 ] )
		{
			if ( sparse [ i ] [ 0 ] == sparse2 [ j ] [ 0 ]) // whem row are equal
			{
				if ( sparse [ i ] [ 1 ] == sparse2 [ j ] [ 1 ]) // whwn col are equal
				{
					ans [ k ] [ 0 ] = sparse [ i ] [ 0 ];
					ans [ k ] [ 1 ] = sparse [ i ] [ 1 ];
					ans [ k ] [ 2 ] = sparse [ i ] [ 2 ] + sparse2 [ j ] [ 2 ] ;
					k ++ ;
			    	i ++ , j ++ ;
				}
				else if ( sparse [ i ] [ 1 ] <  sparse2 [ j ] [ 1 ] )
				{
					ans [ k ] [ 0 ] = sparse [ i ] [ 0 ];
					ans [ k ] [ 1 ] = sparse [ i ] [ 1 ];
					ans [ k ] [ 2 ] = sparse [ i ] [ 2 ];
					k ++ ;
			    	i ++  ;
				}
				else
				{
					ans [ k ] [ 0 ] = sparse2 [ j ] [ 0 ];
					ans [ k ] [ 1 ] = sparse2 [ j ] [ 1 ];
					ans [ k ] [ 2 ] = sparse2 [ j ] [ 2 ];
					k ++ ;
			    	j ++ ;
				}
			}
			else if ( sparse [ i ] [ 0 ] > sparse2 [ j ] [ 0 ] )
			{
				ans [ k ] [ 0 ] = sparse2 [ j ] [ 0 ];
				ans [ k ] [ 1 ] = sparse2 [ j ] [ 1 ];
				ans [ k ] [ 2 ] = sparse2 [ j ] [ 2 ];
				k ++ ;
			    j ++ ;
			}
			else
			{
				ans [ k ] [ 0 ] = sparse [ i ] [ 0 ];
				ans [ k ] [ 1 ] = sparse [ i ] [ 1 ];
				ans [ k ] [ 2 ] = sparse [ i ] [ 2 ];
				k ++ ;
			    i ++  ;
			}
		}

			while ( i <= sparse [ 0 ] [ 2 ] )
			{
				ans [ k ] [ 0 ] = sparse [ i ] [ 0 ];
				ans [ k ] [ 1 ] = sparse [ i ] [ 1 ];
				ans [ k ] [ 2 ] = sparse [ i ] [ 2 ];
				k ++ ;
			    i ++  ;
			}
			while ( j <= sparse2 [ 0 ] [ 2 ] )
			{
				ans [ k ] [ 0 ] = sparse2 [ j ] [ 0 ];
				ans [ k ] [ 1 ] = sparse2 [ j ] [ 1 ];
				ans [ k ] [ 2 ] = sparse2 [ j ] [ 2 ];
				k ++ ;
			    j ++ ;
			}
			ans [ 0 ] [ 2 ] = k -1;
	}
	else return cout << "not compatible for addition " , 0 ;
	for ( ll i = 0 ; i <= ans [ 0 ] [ 2 ] ; i ++ )
	cout << ans [ i ] [ 0 ] << " " << ans [ i ] [ 1 ] << " " << ans [ i ] [ 2 ] << endl ;
}

