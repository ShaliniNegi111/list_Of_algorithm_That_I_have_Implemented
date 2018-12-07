// array represenatation of sparese matrix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n , m,  k(0) , x ;
	cin >> n >> m  ; // no of rows and no of column ;
	ll sparse  [ 1000 ] [ 3 ] ;
	for( ll i = 0 ; i < n; i ++ )
	{
		for ( ll j = 0 ; j < m ;j ++ )
		{
			cin >>  x ;
			if ( x )
			{
				sparse [ k ] [ 0 ] = i ;
				sparse [ k ] [ 1 ] = j ;
				sparse [ k ] [ 2 ] = x ;

				k ++ ;
			}
		}
	}
	for ( ll i = 0 ;i < 3 ; i ++ )
	{
		for ( ll j = 0 ; j < k ; j ++ )
			cout <<  sparse [ j ] [ i ]<< " " ;
		cout << endl ;
	}
	return 0;
}
