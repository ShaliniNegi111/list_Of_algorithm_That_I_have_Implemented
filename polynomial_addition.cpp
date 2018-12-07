// addition of polynomial
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct poly
{
	int exp ;
	int coeff ;
};
int main() {
	int t1 , t2 ;
	cin >> t1 >> t2 ;
	poly p1[ t1 ] , p2[ t2 ] ;
	for ( ll i = 0 ; i < t1 ; i ++ )
	 cin >> p1 [ i ].exp >> p1 [ i ].coeff ;

	for ( ll i = 0 ;  i < t1 ; i ++ )
	cout << p1 [ i ].exp <<  " " << p1 [ i ].coeff << endl  ;
	cout << endl ;
	for ( ll i = 0 ; i < t2 ; i ++ )
	 cin >> p2 [ i ].exp >> p2 [ i ].coeff ;

	 cout << endl ;
	 for ( ll i = 0 ;  i < t2 ; i ++ )
	cout << p2 [ i ].exp <<  " " << p2 [ i ].coeff << endl  ;

	cout << endl ;

	poly ans [ 1000 ] ;
	ll i (0) , j (0) , k (0);
	while ( i < t1 and j < t2 )
	{
		if ( p1 [ i ].exp == p2 [ j ].exp )
		{
			ans [ k ].exp = p1 [ i ].exp ;
			ans [ k ].coeff = p1 [ i ].coeff + p2 [ j ].coeff ;
			k ++ , j ++ , i ++ ;
		}
		else if ( p1 [ i ].exp >  p2 [ j ].exp )
		{
			ans [ k ].exp = p2 [ j ].exp ;
			ans [ k ].coeff =  p2 [ j ].coeff ;
			k ++ , j ++ ;
		}
		else
		{
			ans [ k ].exp = p1 [ i ].exp ;
			ans [ k ].coeff =  p1 [ i ].coeff ;
			k ++ , i ++ ;
		}

	}
	while ( i < t1 )
	{
			ans [ k ].exp = p1 [ i ].exp ;
			ans [ k ].coeff =  p1 [ i ].coeff ;
			k ++ , i ++ ;
	}
	while( j < t2 )
	{
		    ans [ k ].exp = p2 [ j ].exp ;
			ans [ k ].coeff =  p2 [ j ].coeff ;
			k ++ , j ++ ;
	}

	for ( ll i = 0 ;  i < k ; i ++ )
	cout << ans [ i ].exp <<  " " << ans [ i ].coeff << endl  ;
	// your code goes here
	return 0;
}
