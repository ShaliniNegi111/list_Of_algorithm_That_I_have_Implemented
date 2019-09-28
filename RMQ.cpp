// Range Minimum Query 
// space complexity -> O ( n ) 
// Time complexity -> 
// for construction of Tree -> O ( n ) ; 
// For Query -> O ( log n ) ; 
#include <bits/stdc++.h>
using namespace std;
int Segment_Tree [ 10001 ]  ; 
int arr [ 10001 ] ; 
void construct  ( int idx  , int low , int high )
{
	if ( low == high )
	{
		Segment_Tree [ idx  ] = arr [ low ] ; 
		return  ; 
	}
	int mid = ( low + high ) / 2 ; 
	construct ( 2 * idx + 1 , low ,   mid ) ;
	construct ( 2 *idx + 2 , mid + 1 , high ) ;  
	Segment_Tree [ idx  ] = min ( Segment_Tree [ 2 * idx + 1 ] , Segment_Tree [ 2 * idx + 2 ] ) ;
}
 
   
int query (  int idx , int RangeLow , int RangeHigh , int SegmentLow , int SegmentHigh )
{
		if ( RangeLow <= SegmentLow and SegmentHigh <= RangeHigh  )
			return Segment_Tree [ idx ] ; 
		if (SegmentHigh < RangeLow or RangeHigh < SegmentLow )
			return INT_MAX ;
		int mid = ( SegmentLow + SegmentHigh ) / 2 ;
		return min ( query ( 2 * idx + 1 , RangeLow , RangeHigh , SegmentLow , mid ) , query ( 2 * idx + 2 , RangeLow , RangeHigh , mid + 1 , SegmentHigh ) ) ; 
}
 
/*void update ( int idx , int low , int high , int key , int val )
{
	if ( key >= low and key <= high )
	{
		Segment_Tree [ idx ] = min ( val , Segment_Tree [ idx ] ) ; 
		int mid =( low + high ) / 2 ; 
		update ( 2 * idx + 1 , low , mid , key , val ) ; 
		update ( 2 * idx + 2  , mid + 1 , high , key , val ) ; 
	}
}*/
int main() {
	
	
	int n  , t ; 
	cin >> n >> t ; 
	for ( int i = 0 ; i < n ; i ++ )
		cin >> arr [ i ] ; 
	construct ( 0 , 0 , n - 1 ) ; 
	while ( t-- )
	{
		int x , y ;
		cin >> x >> y ; 
		cout << query (  0 , x , y  , 0  , n - 1   ) << endl ;  ;
	}
	// your code goes here
	return 0;
}
