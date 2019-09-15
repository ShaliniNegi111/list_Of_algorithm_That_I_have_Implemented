#include <bits/stdc++.h>
using namespace std;
typedef  long long ll ; 
int main() {
	
	ll t ; 
	cin >> t ; 
	while ( t-- )
	{
		string s ; 
		cin >> s ; 
	    ll n = s.length()  ; 
	    string  dp [ n ] [n ] ; 
	    for ( ll i = 0 ; i < n ; i ++ )
	    {
	    	for (ll j = 0 ; j < n ; j ++ )
	    		dp [ i ] [ j ] = "" ; 
	    }
	    for ( ll i = 0 ; i < n ; i ++ )
	    	dp [ i ] [ i ] = s [ i ] ; 
	    for ( ll i = 1 ; i < n ;i ++ )
	    {
	    	ll c = i ; 
	    	for ( ll j = 0 ; j < n - i ; j ++ )
	    	{
	    		if ( s [ j ] == s [ c ] )
	    		{
	    			dp [ j ] [ c ] = s [ j ] + dp [ j + 1 ] [ c - 1 ] + s [ c ]  ; 
	    		}
	    		else 
	    		{
	    			if ( dp [ j + 1 ] [ c ] .length() > dp [ j ] [ c - 1 ] .length() )
	    				dp [ j ] [ c ] =  dp [ j + 1 ] [ c ] ; 
	    			else
	    				dp [ j ] [ c ] =  dp [ j ] [ c - 1 ] ;
	    		}
	    		c++ ; 
	    	}
	    }
	    cout << dp [ 0 ] [ n - 1 ] << endl ; 
	}
	return 0;
}
