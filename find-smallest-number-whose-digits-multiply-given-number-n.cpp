#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
vector < ll > v ;
bool isprime ( ll n ) // to check whether a no is prime or not
{
	for( ll i = 2; i * i <= n ; i ++ )
	{
		if ( n % i == 0 and i != n )
			return 0 ; // return 0 if it is prime
	}
	return 1 ; // return 1 if it is not prime
}
ll CountDigit ( ll n ) // function to find no of digit in a no
{
	ll c = 0 ;
	while ( n / 10 )
	{
		n = n / 10 ;
		c ++ ;
	}
	return c + 1 ;
}
int main() {
	ll n ;
	cin >> n ;
	if ( n < 10 ) return cout << 10 + n , 0 ;
	if ( isprime ( n )  )
		return cout << "not possible \n " , 0 ;
	for ( ll i = 9 ; i > 1 ; i -- )
	{
		while ( n % i == 0 )
		{
			v.push_back ( i ) ;
			n = n / i ;
		}
	}
	sort ( v.begin() , v.end() ) ;
	for ( auto i : v ) cout << i  ;
	return 0;
}
