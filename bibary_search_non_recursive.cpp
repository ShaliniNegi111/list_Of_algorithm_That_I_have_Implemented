// non - recurssive bibary search
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n , x ;
ll  sort ( ll arr[ ] , ll s , ll e  , ll x )
{
	if ( s == e and arr [ s ] != x )return -1 ; // when element is not found
	ll mid = ( s + e ) / 2 ;
	if ( arr [ mid ] == x ) return mid ; // when element is found
	if ( arr [ mid ] > x )  return sort ( arr , s , mid - 1 , x ) ;
    return sort ( arr , mid + 1 , e  , x ) ;

}
int main() {

    cin >> n ;
	ll arr [ n ] ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;
	cin >> x ;
	cout << sort ( arr ,0 , n , x ) ;
	// your code goes here
	return 0;
}
