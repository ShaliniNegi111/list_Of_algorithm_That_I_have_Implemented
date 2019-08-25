//Merge k Sorted Arrays

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll N = 1001 ;
struct MinHeapNode 
{
	ll data , row , col ;
};
class MinHeap 
{
	ll Heap_Size ;
	ll capacity  ;
	MinHeapNode * Heap  ;
	public :

	MinHeap ( ll capacity )
	{
		Heap_Size = 0 ;
		this->capacity = capacity ;
		Heap = new MinHeapNode [ capacity ] ;
	}
	
	void Heapify (ll ind )
	{
		ll MinInd = ind ;
		ll mini = Heap [ MinInd ].data  ;
		if ( ind * 2 + 1 < Heap_Size and Heap [ ind * 2 + 1 ] .data < mini )
		{
			mini = Heap [ ind *2  + 1 ] .data;
			MinInd =  ind *2  + 1 ;
		}
		
			
		if ( ind * 2 + 2  < Heap_Size and Heap [ ind * 2 + 2 ] .data < mini )
		{
			mini = Heap [ ind *2  + 2 ].data  ;
			MinInd = ind *2  + 2  ;
		}
		
		if ( MinInd != ind  )
		{
			swap ( Heap [ MinInd ] , Heap [ ind  ] ) ;
			Heapify ( MinInd ) ;
		}
	}
	
	void insert ( ll x , ll row , ll col  )
	{
		Heap [ Heap_Size ] . data = x   ;
		Heap [ Heap_Size ] . row = row    ;
		Heap [ Heap_Size ] . col = col    ;
		ll p = Heap_Size ;
		Heap_Size ++ ;
		while ( p != 0 and Heap [ ( p - 1 ) / 2 ] .data > Heap [ p ].data )
		{
			swap ( Heap [ ( p - 1 )  / 2  ] , Heap [ p ] ) ;
			p = ( p - 1 ) / 2 ;
		}
	}
	
	ll GetMin ()
	{
		return Heap [ 0 ] .data ;
	}
	
	void Extract ( ll arr [ ][ N ] , ll n  )
	{
		if ( Heap [ 0 ].col + 1 < n )
		{
			Heap [ 0 ].col ++ ;
			Heap [ 0 ].data  = arr [ Heap [ 0 ].row ] [ Heap [ 0 ].col ];
			Heapify ( 0 ) ;
		}
		else 
		{
			Heap [ 0 ] = Heap [ Heap_Size - 1 ] ;
			Heap_Size -- ;
			Heapify ( 0 ) ;
		}
	}
	
	
	void show ()
	{
		for ( ll i = 0 ; i < Heap_Size  ; i ++ )
			cout << Heap [ i ].data << " " ;
		cout << endl ;
	}

} ;
int main()
{
	
	ll k , n  ;
	cin >> k >> n ;
	ll arr [ k ] [ N ] ;
	for ( ll i = 0 ; i < k ; i ++ )
	{
		for ( ll j = 0 ; j < n ; j ++ )
			cin >> arr [ i ] [ j ] ;
	}
	
	MinHeap MH ( k );
	for ( ll i = 0 ; i < k ; i ++ )
	{
		MH.insert ( arr [ i ] [ 0 ] , i , 0 ) ;
	}
	
	for ( ll i = 0 ; i < n ; i ++ )
	{
		for ( ll j = 0 ; j < k ; j ++ )
		{
			cout <<  MH.GetMin () << " " ;
			MH. Extract (  arr  , n  ) ;
		}
	}
	return 0;
}
