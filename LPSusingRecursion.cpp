// Longest palindromic subsequence using recursion 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 

string LongestPalindrome ( string s  , ll start  , ll end ,  string dp [ ] [ 1001 ])
{	if ( end < start )
	{
		dp [ start ] [ end ] =  "" ; 
		return dp [ start ] [ end ] ; 
	}
	
	if ( dp [ start ] [ end ]  != "#")
		return dp [ start ] [ end ] ; 
	
	if ( start == end )
	{
		string g( 1 , s [ start ] )  ; 
		dp [ start ] [ end ] = g ; 
		return g ; 
	}
	
	if ( s [ start ] == s [ end ] )
	{
		dp [ start ] [ end ] = s [ start ] + LongestPalindrome ( s , start + 1 , end -1 , dp ) + s [ end ] ; 
	}
	else 
	{
		string temp1 =  LongestPalindrome ( s , start  , end -1 , dp )  ;
		string temp2 =  LongestPalindrome ( s , start +1 , end , dp )  ;
		if( temp1 .length() > temp2.length() )
			dp [ start   ] [ end ] = temp1 ; 
		else 	dp [ start   ] [ end ] =  temp2 ; 
	
	}
	
		return dp [ start ] [ end ] ; 
	
}
int main() {
	
	
	string s ; 
	cin >> s ; 
	string dp [ s.length()] [ 1001 ] ;
	for (  ll i = 0 ; i < s.length() ; i ++ )
	{
		for ( ll j = 0 ; j < s.length() ; j ++ )
			dp [ i ] [ j ] = "#" ; 
	}
	
	cout << LongestPalindrome ( s , 0 , s.length() - 1 , dp ) ; 
	// your code goes here
	return 0;
}
