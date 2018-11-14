

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main() {
	ll n , sum (0);
	cin >> n ;
	for ( ll i = 1 ; sum <= n ; i += 2 )
	{
		sum += i ;
		if ( sum == n )
		{
			cout <<"NO IS PERFECT NO " ;
			return 0 ;
		}
	}
	cout << " NO IS NOT PERFECT NO " ;
	return 0;
}
