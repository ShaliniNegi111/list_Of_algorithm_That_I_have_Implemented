#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct Node 
{
	ll data , height ; 
	Node * left ,* right ; 
	Node ( ll data )
	{
		this-> data = data ;
		left = right = NULL ;
		height = 0 ; 
		
	}
};
ll GetHeight (  Node * node )
{
	if ( node == NULL )
		return 0 ; 
	return node -> height ; 
}
ll GetBalance  (  Node * node )
{
	if ( node == NULL )
		return 0 ; 
	return GetHeight ( node -> left ) - GetHeight ( node -> right )  ; 
}

Node * RightRotate ( Node * A )
{
	Node * B = A-> left ; 
	Node *BR = B -> right ; 
	
	B -> right = A ;
	A -> left = BR ; 
	
   B -> height = 1 + max ( GetHeight ( B-> left ) , GetHeight ( B -> right ) ) ;
   A -> height = 1 + max ( GetHeight ( A-> left ) , GetHeight ( A -> right ) ) ;
   return B ; 
   
}

Node * LeftRotate ( Node * A  )
{
	Node * B = A-> right ; 
	Node *BL = B -> left  ; 
	
	B -> left  = A ;
	A -> right = BL  ; 
	
   B -> height = 1 + max ( GetHeight ( B-> left ) , GetHeight ( B -> right ) ) ;
   A -> height = 1 + max ( GetHeight ( A-> left ) , GetHeight ( A -> right ) ) ;
   return B ; 
}
Node * Insert ( Node * node , ll key )   
{
	if ( node == NULL )
		return new Node ( key ) ; 
	if ( node -> data < key )
		node -> right = Insert ( node -> right , key ) ; 
	else node -> left = Insert ( node -> left , key ) ; 
	
	node -> height = 1 + max ( GetHeight ( node -> left ) , GetHeight ( node -> right ) ) ; 
	ll balance = GetBalance ( node ) ; 
	if ( balance >1 and key < node -> left -> data  )
		return RightRotate ( node ) ; 
	if ( balance < -1 and key > node -> right -> data )
		return LeftRotate ( node ) ;
	if ( balance > 1 and key > node -> left -> data )
	{
		node -> left = LeftRotate ( node -> left ) ; 
		return RightRotate ( node ) ; 
	}
	if ( balance <  -1 and key <  node -> right-> data )
	{
		node -> right  = RightRotate ( node -> left ) ; 
		return LeftRotate ( node ) ; 
	}
	
	return node ; 
	
}

void Preorder ( Node * root )
{
	if ( root == NULL )
		return ; 
	cout << root -> data << " " ; 
	Preorder ( root -> left ) ; 
	Preorder ( root -> right ) ; 
}
int main() {
	
	ll n ;
	cin >> n ; 
	Node * root = NULL ; 
	for ( ll i = 0 ; i < n ; i ++ )
	{
		ll x ; 
		cin >> x ; 
		root = Insert ( root , x ) ; 
	}
	Preorder ( root ) ; 
	// your code goes here
	return 0;
}
