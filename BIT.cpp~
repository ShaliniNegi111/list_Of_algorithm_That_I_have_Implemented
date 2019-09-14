#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 

void Update ( ll BIT [ ] , ll x , ll delta , ll n )
{
	for ( ll i = x ; i  <= n  ; i = i + ( i & ( - i ) )  )
	{
		BIT [ i ] += delta ; 
	}
	
}

ll  Query( ll BIT [ ] , ll  x)
{
     ll  sum = 0;
     for(; x > 0; x -= x&-x)
     {
        sum += BIT[x];
     }
     return sum;
}


int main() {
	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; 
	ll n , q ; 
	cin >> n >> q ; 
	ll arr [ n + 1 ] , BIT [ n + 1 ]= { 0 }  ; 
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		cin >> arr [ i ] ;
		Update ( BIT , i ,  arr [ i ] , n ) ; 
	}
	
	while ( q -- )
	{
		ll x , l , r ; 
		cin >> x >> l >> r ; 
		if ( x == 1 )
		{
			Update ( BIT , l , r - arr [ l ] , n ) ; 
		}
		else 
		{
			cout << Query ( BIT , r   ) - Query ( BIT , l ) << endl ; 
		}
	}
	// your code goes here
	return 0;
}
