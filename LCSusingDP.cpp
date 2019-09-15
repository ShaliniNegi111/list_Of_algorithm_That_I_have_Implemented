#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
int main() {
	
	
	string s1 ,  s2 ; 
	cin >> s1 >> s2 ; 
	ll n1 , n2 ; 
	n1 = s1.length() , n2 = s2.length() ; 
	string  dp [ n1 + 1 ] [ n2 + 1  ]  ;
	for ( ll i = 0 ; i<= n1 ; i ++ )
	{
		for ( ll j = 0 ; j <= n2 ; j ++ )
		{
			dp [ i ] [ j ] ="" ; 
		}
	}
	for ( ll i = 1 ; i<= n1 ; i ++ )
	{
		for ( ll j = 1 ; j <= n2 ; j ++ )
		{
			if ( s1 [ i - 1 ] == s2 [ j - 1 ] )
				dp [ i ] [ j ] = dp [ i - 1 ] [ j - 1 ] + s1 [ i - 1 ] ; 
			else 
			{
					string t1 = dp [ i -1 ] [ j ] ;
					
					string t2 = dp [ i ] [ j - 1 ]  ; 
					if ( t1.length() > t2.length() )
						dp [ i  ]  [ j ] = t1 ; 
					else dp [ i ] [ j ] = t2 ; 
			}
		}
	}
	cout<< dp [ n1 ] [ n2 ] ; 

	return 0;
}
