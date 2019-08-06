
// Find LCA in Binary Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int mod = 1000000007;
const int N = 2e5;
vector < ll > g[N];
const int LG = 20;
ll  a[N], lvl[N], P[N][LG] , visit [ N ];
void dfs( ll  u, ll  par)
{
	
	if ( visit [ u ] == 1 )
		return ;
	visit [ u ] = 1 ;
	//cout << u << " " ;
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for( auto  v:g[u]){
		
		dfs(v, u);
	}
}

ll  lca( ll  u, ll  v)
{
    
    if ( lvl[u] < lvl[v] ) 
    	swap(u, v);
    for ( ll i = 0 ; i < 20 ; i ++ ) 
    {
    	if ( P [ v ] [ i ] != 0 and lvl [ P[ v ] [ i ] ] == lvl [ u ] )
    	{
    		v = P [ v ] [ i ] ;
    		break ;
    	}
    }

    if (u == v) 
    	return u;

    for ( ll i = 0 ; i < 20 ; i ++ )
    {
    	if ( P [ v ] [ i ] == P [ u ] [ i ] )
    		return P [ u ] [ i ] ;
    }
}
    

int main()
{
	
	ll  n , x , y ;
	cin >> n >> x >>  y  ;
	for ( ll i = 0 ; i < n ; i ++)
	{
		    int u, v;
            cin>>u>>v;
            g[u].push_back (v);
            g[v].push_back (u);
	}
    for ( ll i = 1 ; i <= n  ; i ++ )
    {
    	for ( ll j = 0 ; j < 20  ; j ++ )
    		P [  i ] [ j   ] = -1 ;
    }
    
	lvl[0] = -1;
	dfs(1, 0);
	for ( ll i = 1 ; i < 20 ; i ++ )
	{
		for ( ll j = 1 ; j <= n ; j ++ )
		{
			if ( P [ j ] [ i - 1 ] != -1 )
			{
				P [ j ] [ i  ] = P [ P [ j ] [ i - 1 ] ] [ 0 ] ; 
			}
		}
	}
	cout << lca(  x ,   y ) << endl ;
	return 0;
}

