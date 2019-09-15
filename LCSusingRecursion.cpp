#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 

string  LCS ( string s1 , string s2 , ll l1 , ll l2 )
{
	if ( l1 < 0 or l2 < 0 )
		return "" ; 
	if ( s1 [ l1 - 1 ] == s2 [ l2 - 1 ] )
		return LCS ( s1 , s2 , l1 -1 , l2 - 1 ) + s1 [ l1 - 1 ] ; 
	else 
	{
		string t1 = LCS ( s1 , s2 , l1 -1 , l2 ) ; 
		string t2 = LCS ( s1 , s2 , l1 , l2 - 1 ) ; 
		if ( t1.length() > t2.length() )
			return t1 ; 
		else return t2 ; 
	}
}
int main() {
	
	
	string s1 ,  s2 ; 
	cin >> s1 >> s2 ; 
	ll n1 , n2 ; 
	n1 = s1.length() , n2 = s2.length() ; 
	cout << LCS ( s1 , s2 , n1 , n2 ) ; 
	return 0;
}
