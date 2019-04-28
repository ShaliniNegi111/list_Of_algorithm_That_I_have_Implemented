#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
class min_heap 
{
	int capacity , heap_size ;
	int * arr ;
	public : 
		
		min_heap ( int capacity )
		{
			this-> capacity = capacity ;
			heap_size = 0 ;
			arr = new int [ capacity ] ;
		}
		int parent ( int i )
		{
			return ( i - 1 ) / 2 ;
		}
		void insert ( int val )
		{
			if ( heap_size == capacity )
			{
				return ;
			}
			arr [ heap_size ] = val ;
			int i = heap_size ;
			heap_size ++ ;
			while ( i !=0 and arr [ parent ( i ) ] > arr [ i ] )
			{
				swap ( arr[ i ] , arr [ parent ( i ) ] ) ;
				i = parent ( i ) ;
			}
		}
		int get_mini ()
		{
			return arr [ 0 ] ;
		}
		
		void decrease_val ( int i , int val ) 
		{
			arr [ i ] = val ;
			while ( i != 0 and arr [ parent (i ) ] > arr [ i ] )
			{
				swap (arr [ parent (i ) ]  ,  arr [ i ] ) ;
				i = parent (i ) ;
			}
		}
		void heapify (int x )
		{
			int l = left ( x ) ;
			int r= left ( x ) ;
			int small = x ;
			if ( l < heap_size and  arr [ l ] < arr [ small ] )
				small = l ;
			
			if ( r < heap_size and  arr [ r ] < arr [ small ] )
				small = r ;
			if ( small != i )
			{
				swap ( arr [ i ] , arr [ small ] ) ;
				heapify ( small ) ;
			}
		}
		int  extract_min () 
		{
			int root = arr [ 0 ] ;
			arr [ 0 ] = arr [ heap_size() - 1 ] ;
			heapify (0 ) ;
			return root ;
		}
		void delete_ind ( int i  )
		{
			decrease_val ( i , INT_MIN ) ;
			extract_min () ;
		}
} ;


int main() {
	
	
	min_heap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.delete_ind (1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.extract_min() << " "; 
    cout << h.get_mini() << " "; 
    h.decrease_val(2, 1); 
    cout << h.get_mini(); 
	
	// your code goes here
	return 0;
}
