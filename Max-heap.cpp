#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
class max_heap 
{
	int capacity , heap_size ; // capacity = maximum size of heap ;
								// heap_size = current size of heap ;		
	int * arr ; // heap array 
	public : 
		
		max_heap ( int capacity ) // constructor 
		{
			this-> capacity = capacity ;
			heap_size = 0 ;
			arr = new int [ capacity ] ;
		}
		int parent ( int i ) // This function return parent of i 
		{
			return ( i - 1 ) / 2 ;
		}
		int left ( int i ) // This function return left child of i 
		{
			return ( 2 * i + 1 ) ;
		}
		int right ( int i ) // This function return left child of i 
		{
			return ( 2 * i + 2 ) ;
		}
		void insert ( int val ) // This function insert a value in heap 
		{
			if ( heap_size == capacity )
			{
				return ;
			}
			arr [ heap_size ] = val ;
			int i = heap_size ;
			heap_size ++ ;
			while ( i !=0 and arr [ parent ( i ) ] <  arr [ i ] )
			{
				swap ( arr[ i ] , arr [ parent ( i ) ] ) ;
				i = parent ( i ) ;
			}
		}
		int get_maxi () // return the mimimum element in heap ie root node 
		{
			return arr [ 0 ] ;
		}
		
		void increase_val ( int i , int val )  // This function dcrease the value if element at index i to val 
		{
			arr [ i ] = val ;
			while ( i != 0 and arr [ parent (i ) ] < arr [ i ] )
			{
				swap (arr [ parent (i ) ]  ,  arr [ i ] ) ;
				i = parent (i ) ;
			}
		}
		void heapify (int x )
		{
			int l = left ( x ) ;
			int r= right ( x ) ;
			int large  = x ;
			if ( l < heap_size and  arr [ l ] > arr [ large ] )
				large = l ;
			
			if ( r < heap_size and  arr [ r ] > arr [ large ] )
				large = r ;
				
			if ( large != x  )
			{
				swap ( arr [ x ] , arr [ large ] ) ;
				heapify ( large ) ;
			}
		}
		int  extract_max ()  // return the minimum element and remove it ;
		{
			int root = arr [ 0 ] ;
			arr [ 0 ] = arr [ heap_size - 1 ] ;
			heap_size -- ;
			heapify (0 ) ;
			return root ;
		}
		void delete_ind ( int i  ) // this function delete the element at inndex i ;
		{
			increase_val ( i , INT_MAX ) ;
			extract_max () ;
		}
		void show ( )// this function shows the heap 
		{
			for ( int i = 0 ; i < heap_size ; i ++ )
				cout << arr [ i ] << " " ;
		}
} ;


int main() {
	
	
	max_heap h(11); 
    h.insert(3); 
    h.insert(2); 
    //h.delete_ind (1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    h.show() ;
    cout << endl ;
    h.delete_ind (1); 
      h.show() ;
    cout << endl ;
    cout << h.extract_min() << " "; 
    cout << h.get_mini() << " "; 
    h.decrease_val(2, 1); 
    cout << h.get_mini(); 
	
	// your code goes here
	return 0;
}
