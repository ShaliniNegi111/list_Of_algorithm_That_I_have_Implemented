// non - recurssive bibary search
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n , x ;
    cin >> n ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;
	cin >> x ;
	ll s = 0 , e = n ;
	while ( s <= e )
	{
		ll mid = ( e + s ) / 2 ;
		//cout << arr [ mid ] << " " ;
		if ( arr [ mid ] == x ) return cout << mid , 0 ;
		else if( arr [ mid ] > x ) e = mid - 1 ;
		else  s = mid + 1 ;
	}
	cout << -1 ;// when element is not found ;
	return 0;
}
