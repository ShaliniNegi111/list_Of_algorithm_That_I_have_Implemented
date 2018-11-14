
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n  , m , x , y , flag  , c  ;
ll parent  [ 100000 ] ;
int find ( ll x )
{
	if ( parent [ x ] == x )
        	return x ;
   	 return find ( parent [ x ] ) ; 
}
void   join ( ll x , ll y )
{
	x = find ( x )  ;
	y = find ( y )  ;

	if ( x != y )
        parent [ x ] = y ;

}
int main() {

	cin >> n >> m ;
	for ( ll i = 0 ; i < n ; i++ )
		parent [ i ] = i  ;

	while ( m -- )
	{
		cin >> x >> y ;
		if ( find ( x ) != find ( y )) 	join( x , y ) ;
		else if ( find ( x ) == find ( y ) )
        {
            cout << "CYCLE DETECHED \n " ;
            return  0 ;
        }
	}
	return 0;
}
