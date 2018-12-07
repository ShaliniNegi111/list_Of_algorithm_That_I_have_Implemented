// link list representation of sparse matrix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct node
{
	ll row , col , val ;
	node * next ;
};
int main() {

	ll n , m , flag (0) , x ;
	cin >> n >> m ;
	node* start , * pre ;
	for ( ll i = 0; i < n ; i ++ )
	{
		for ( ll j = 0 ; j < m ; j ++ )
		{
			cin >> x ;
			if ( x )
			{
				if ( flag  )
				{
					pre -> next = ( node *) malloc ( sizeof ( node ) ) ;
					pre = pre -> next ;
					pre -> row = i ;
					pre -> col = j ;
					pre -> val = x ;
				}
				else
				{
					start  = ( node *) malloc ( sizeof ( node ) ) ;
					pre = start ;
					pre -> row = i ;
					pre -> col = j ;
					pre -> val = x ;
					flag = 1 ;
				}
			}
		}
	}
	pre -> next = NULL ;
	node * temp ;
	temp = start ;
	while( temp != NULL)
	{
		cout << temp -> row << " " << temp-> col << " " << temp -> val << endl ;
		temp = temp -> next ;
	}
	return 0;
}
