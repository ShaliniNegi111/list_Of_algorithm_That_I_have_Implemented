#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll __gcd ( ll a , ll b )
{
	if ( a == b )
		return a ;
	if ( b > a )
		swap (a , b ) ;
	return __gcd ( a - b , b ) ;

}
void JugglingAlgoclock  ( ll arr [ ] , ll n , ll d )
{
	for ( ll i = 0 ; i < __gcd ( n , d ) ; i ++ )
	{
		ll j = i ;
		ll temp = arr [ j ] ;
		while ( 1 )
		{
			ll k = j + d ;
			if ( k >= n )
				k = k - n ;
			if ( k == i )
				break ;

			arr [ j ] = arr [ k ] ;
			j = k ;
		}
		arr [ j ] = temp ;
	}
}

void JugglingAlgoAnticlock  ( ll arr [ ] , ll n , ll d )
{
	for ( ll i = 0 ; i < __gcd ( n , d ) ; i ++ )
	{
		vector < ll > v ;
		ll j = i ;
		while ( 1 )
		{
			v.push_back ( j ) ;
			ll k = j + d ;
			if ( k >= n )
				k = k - n ;
			if ( k == i )
				break ;
			j = k ;
		}
		ll temp = arr [ v [ v.size() - 1 ] ];
		for ( ll k =  v.size() - 1 ; k - 1 >=0  ; k -- )
			arr [ v [ k ] ] = arr [ v [ k  - 1 ] ] ;
		 arr [ v [ 0 ] ] = temp ;
	}

}

void ReversalAlgoClock ( ll arr [ ] , ll n  , ll d )
{
	reverse ( arr , arr + d ) ;
	reverse ( arr + d , arr + n ) ;
	reverse ( arr , arr + n ) ;
}

void ReversalAlgoAntiClock ( ll arr [ ] , ll n  , ll d )
{
	reverse ( arr , arr + n  ) ;
	reverse ( arr  , arr + d ) ;
	reverse ( arr + d  , arr + n ) ;
}



int main() {

	ll n, d  ;
	cin >> n >> d ;
	ll arr1 [ n ] , arr2 [ n ] , arr3 [ n ] , arr4 [ n ];
	for ( ll i = 0 ; i < n ; i ++ )
		cin >> arr1 [ i ] ;

	for ( ll i = 0 ; i < n ; i ++ )
		 arr2 [ i ] =  arr1 [ i ] ;

    for ( ll i = 0 ; i < n ; i ++ )
		 arr3 [ i ] =  arr1 [ i ] ;


   	for ( ll i = 0 ; i < n ; i ++ )
		 arr4 [ i ] =  arr1 [ i ] ;

	JugglingAlgoAnticlock  (  arr1 ,  n ,  d ) ;
	JugglingAlgoclock  (  arr2,  n ,  d ) ;
	ReversalAlgoClock (  arr3 ,  n  , d ) ;
	ReversalAlgoAntiClock ( arr4  ,  n  ,  d );

    for ( ll i = 0 ; i < n ; i ++ )
		 cout << arr1 [ i ] << " " ; 
	cout << endl ;

    for ( ll i = 0 ; i < n ; i ++ )
		 cout << arr2 [ i ] << " " ;
	cout << endl ;

	for ( ll i = 0 ; i < n ; i ++ )
		 cout << arr3 [ i ] << " " ;
	cout << endl ;

    for ( ll i = 0 ; i < n ; i ++ )
		 cout << arr4 [ i ] << " " ;
	cout << endl ;


	// your code goes here
	return 0;
}
