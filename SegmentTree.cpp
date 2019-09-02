#include <bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
ll Segment [ 10001 ] ; 

ll Construct (  ll arr [ ] , ll index , ll left , ll right )
{
	if ( left == right )
	{
			Segment [ index ] = arr [ left ] ; 
			return Segment [ index  ] ; 
	}
	ll mid = ( left + right ) / 2 ; 
	Segment [ index ] = Construct ( arr , 2 * index + 1 , left , mid ) + Construct ( arr ,  2 * index + 2 , mid + 1 , right ) ; 
	return Segment [ index  ] ; 
}

ll Query ( ll index , ll x , ll y  , ll left , ll right )
{
	//cout << index << " " << x << " " << y << " " << left << " " << right << endl ; 
	if ( x >= left  and y <= right  )
		return Segment [ index ] ; 
	else if ( y < left  or x  >  right  )
		return 0 ;
	else 
	{
		ll mid = ( x + y  ) / 2 ; 
		return Query ( 2 * index + 1 , x , mid ,   left , right  ) + Query ( 2 * index + 2 ,  mid + 1 , y ,  left   , right   );
	}

}
void Update (  ll index , ll x , ll y  , ll key  , ll diff  )
{
	if ( key < x or key > y  )
		return ; 
	Segment [ index  ] +=  diff ; 

	if (  x != y  )
	{
		ll mid = ( x + y ) / 2 ; 
		Update (  2 * index + 1 , x , mid , key , diff ) ; 
		Update ( 2  * index + 2 , mid + 1 , y  , key , diff ) ; 
	}
	
	
}
int main() 
{
	
	ll n ; 
	cin >> n  ; 
	ll arr [ n ] ; 
	for ( ll i = 0 ; i < n ; i ++ )
		cin >> arr [ i ] ; 
	Construct ( arr , 0 , 0 , n - 1 ) ;

    ll q ;
    cin >> q ; 
    while ( q -- )
    {
    	ll x ,  l , r ;  
    	cin >> x >> l >> r ; 
    	if ( x == 1 ) 
    		cout << Query ( 0 , 0 ,  n - 1 , l , r ) << endl ; 
    	else 
    		Update (  0 , 0 ,  n - 1 , l , r - arr [ l ] ) ; 
    }
	
	return 0;
}
