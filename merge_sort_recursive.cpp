// using recursion
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
void merge ( ll l [ ] , ll r [ ] , ll arr [ ] , ll  n1 , ll n2  )
{
	ll i (0), j(0) , k(0) ;
    //i = j = k = 0 ;
	while ( i < n1 and j < n2 )
	{
		if ( l [ i ] <= r[ j ] )
		{
			arr [ k ] = l [ i ] ;
			i ++ ;
		}
		else
		{
			arr [ k ] = r [ j ] ;
			j ++ ;
		}
		k ++ ;
	}
	while ( i < n1 )
	{
		arr [ k ] = l [ i ] ;
		k ++ , i ++ ;
	}

	while ( j < n2 )
	{
		arr [ k ] = r [ j ] ;
		k ++ , j ++ ;
	}
}
void merge_sort (ll arr[ ] , ll n  )
{
	if ( n < 2 ) return ;
	ll n1 = n / 2 , k (0) ;
	ll l [ n1 ] , r [ n - n1 ] ;
	for ( ll i = 0 ; i < n1 ; i ++ ) l [ i ] = arr [ k ++ ] ;
	for ( ll i = 0 ; i <n - n1 ; i ++ ) r [ i ] = arr [ k ++ ] ;
	merge_sort ( l , n1 ) ;
	merge_sort ( r , n - n1  ) ;
	merge ( l , r , arr , n1 , n - n1  ) ;
}
int main() {
	ll n ;
	cin >> n ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;
	merge_sort ( arr , n ) ;
	for ( ll i = 0 ; i < n ; i ++ ) cout <<  arr [ i ] << " ";

	// your code goes here
	return 0;
}
