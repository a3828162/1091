// xtree internal header

#ifndef XTREE
#define XTREE

enum class Color{ Red, Black }; // colors for link to parent

template< typename Ty >
struct TreeNode
{
   using NodePtr = TreeNode *;
   using value_type = Ty;

   NodePtr    left;   // left subtree, or smallest element if head
   NodePtr    parent; // parent, or root of tree if head
   NodePtr    right;  // right subtree, or largest element if head
   Color      color;  // Red or Black, Black if head
   bool       isNil;  // true only if head (also nil) node
   value_type myval;  // the stored value, unused if head
};

// CLASS TEMPLATE TreeVal
template< typename Ty >
class TreeVal
{
public:
   using NodePtr = TreeNode< Ty > *;

   using value_type = Ty;
   using size_type  = size_t;

   TreeVal()
      : myHead( new TreeNode< value_type > ),
        mySize( 0 )
   {
      myHead->left = myHead;
      myHead->parent = myHead;
      myHead->right = myHead;
      myHead->color = Color::Black;
      myHead->isNil = true;
   }

   ~TreeVal()
   {
      clear( myHead->parent );
      delete myHead;
   }

   // Removes all elements from the set object (which are destroyed)
   void clear( TreeNode< value_type > *node )
   {
      if( !node->isNil ) // node is not an external node
      {
         clear( node->left );
         clear( node->right );
         delete node;
      }
   }

   // rebalance for insertion
   void reBalance( TreeNode< value_type > *node )
   {  // node->parent cannot be the root
	   NodePtr p = node->parent, g = node->parent->parent, uncle = g->left;
	   
	   if (node->parent == myHead) return;

	   if (node->parent->parent == myHead) return;

	   if (p == g->left) uncle = g->right;

	   if (p->color == Color::Black) return;

	   if (uncle->color == Color::Red)
	   {
		   p->color = Color::Black;
		   uncle->color = Color::Black;
		   if (g->parent != myHead) g->color = Color::Red;
		   if (g->parent->color == Color::Red) reBalance(g);
	   }
	   else
	   {
		   if (p == g->left && node == p->left && uncle->color == Color::Black)
		   {
			   LLRotation(node->parent);
			   node->parent->color = Color::Black;
			   node->parent->right->color = Color::Red;
		   }
		   if (p == g->left && node == p->right && uncle->color == Color::Black)
		   {
			   RRRotation(node);
			   LLRotation(node);

			   node->color = Color::Black;
			   node->right->color = Color::Black;
		   }
		   if (p == g->right && node == p->left && uncle->color == Color::Black)
		   {
			   LLRotation(node);
			   RRRotation(node);

			   node->color = Color::Black;
			   node->left->color = Color::Red;
		   }
		   if (p == g->right && node == p->right && uncle->color == Color::Black)
		   {
			   RRRotation(node->parent);
			   node->parent->color = Color::Black;
			   node->parent->left->color = Color::Red;
		   }
	   }
   }

   // rotate right at g, where p = g->left and node = p->left
   //void set< Kty >::LLbRotation( TreeNode< value_type > *node )
   void LLRotation( TreeNode< value_type > *p ) 
   {//¥kæ¢
	   NodePtr g = p->parent;
	   p->parent = g->parent;
	   if (g->parent == myHead) myHead->parent = p;
	   else if (g == g->parent->left) g->parent->left = p;
	   else if (g == g->parent->right)g->parent->right = p;

	   g->left = p->right;
	   if (p->right != myHead) p->right->parent = g;

	   p->right = g;
	   g->parent = p;
   }

   // rotate left at g, where p = g->right and node = p->right
   //void set< Kty >::RRbRotation( TreeNode< value_type > *node )
   void RRRotation( TreeNode< value_type > *p )
   { //¥ª±Û
	   NodePtr g = p->parent;
	   p->parent = g->parent;
	   if (g->parent == myHead) myHead->parent = p;
	   else if (g == g->parent->left) g->parent->left = p;
	   else if (g == g->parent->right)g->parent->right = p;

	   g->right = p->left;
	   if (p->left != myHead) p->left->parent = g;

	   p->left = g;
	   g->parent = p;
   }

   // erase node provided that the degree of node is at most one
   void eraseDegreeOne( TreeNode< value_type > *node )
   {
	   NodePtr n = node, p = node->parent, c = node->left;
	   if (c == myHead) c = node->right;

	   if (p == myHead && n->color == Color::Black && c->color == Color::Black)
	   {
		   c->color = Color::Black;
		   myHead->parent = c;
		   c->parent = myHead;
		   delete n;
		   --mySize;
		   return;
	   }

	   if (n == p->left) p->left = c;
	   else p->right = c;
	   if (c != myHead) c->parent = p;

	   if (n->color == Color::Black && c->color == Color::Black && p != myHead) fixUp(c, p);

	   if (n->color == Color::Black && c->color == Color::Red) c->color = Color::Black;

	   delete n;
	   --mySize;
	   return;
   } 

   // rebalance for deletion
   void fixUp( TreeNode< value_type > *N, TreeNode< value_type > *P )
   {
	   NodePtr s = P->left;
	   if (N == P->left) s = P->right;

	   if (s->color == Color::Black && s->right->color == Color::Red && N == P->left)
	   {
		   Color tmp = P->color;
		   P->color = s->color;
		   s->color = tmp;
		   s->right->color = Color::Black;
		   RRRotation(s);
		   return;
	   }
	   if (s->color == Color::Black && s->left->color == Color::Red && N == P->right)
	   {
		   Color tmp = P->color;
		   P->color = s->color;
		   s->color = tmp;		   
		   s->left->color = Color::Black;
		   LLRotation(s);
		   return;
	   }
   }

/*
   // preorder traversal and inorder traversal
   void twoTraversals()
   {
      cout << "Preorder sequence:\n";
      preorder( myHead->parent );

      cout << "\nInorder sequence:\n";
      inorder( myHead->parent );
      cout << endl;
   }

   // preorder traversal
   void preorder( TreeNode< value_type > *node )
   {
      if( node != myHead )
      {
         cout << setw( 5 ) << node->myval << ( node->color == Color::Red ? "R" : "B" );
         preorder( node->left );
         preorder( node->right );
      }
   }

   // inorder traversal
   void inorder( TreeNode< value_type > *node )
   {
      if( node != myHead )
      {
         inorder( node->left );
         cout << setw( 5 ) << node->myval << ( node->color == Color::Red ? "R" : "B" );
         inorder( node->right );
      }
   }
*/

   NodePtr myHead;   // pointer to head node
   size_type mySize; // number of elements
};

// CLASS TEMPLATE Tree
template< typename Traits >
class Tree // ordered red-black tree for map/multimap/set/multiset
{
public:
   using value_type = typename Traits::value_type;

protected:
   using ScaryVal = TreeVal< value_type >;

public:
   using key_type      = typename Traits::key_type;
   using key_compare   = typename Traits::key_compare;

   using size_type       = size_t;

   Tree( const key_compare &parg )
      : keyCompare( parg ),
        scaryVal()
   {
   }

   ~Tree()
   {
   }

   // Extends the container by inserting a new element,
   // effectively increasing the container size by one.
   void insert( const value_type &val )
   {
	   TreeNode< value_type >* insert_node = scaryVal.myHead->parent, * index = scaryVal.myHead->parent;
	   while (index != scaryVal.myHead)
	   {
		   insert_node = index;
		   if (val == index->myval) return;

		   if (keyCompare(val, index->myval))
			   index = index->left;
		   else
			   index = index->right;
	   }

	   TreeNode< value_type >* NewNode = new TreeNode< value_type >{ scaryVal.myHead,scaryVal.myHead,scaryVal.myHead,Color::Red,false,val };

	   if (scaryVal.mySize == 0)
	   {
		   NewNode->color = Color::Black;
		   scaryVal.myHead->parent = scaryVal.myHead->left = scaryVal.myHead->right = NewNode;
		   ++scaryVal.mySize;
		   return;
	   }

	   if (keyCompare(val, scaryVal.myHead->left->myval)) scaryVal.myHead->left = NewNode;
	   if (keyCompare(scaryVal.myHead->right->myval, val)) scaryVal.myHead->right = NewNode;

	   if (keyCompare(val, insert_node->myval)) insert_node->left = NewNode;
	   else insert_node->right = NewNode;

	   NewNode->parent = insert_node;

	   ++scaryVal.mySize;
	   scaryVal.reBalance(NewNode);
   }

   // Removes from the set container a single element whose value is val
   // This effectively reduces the container size by one, which are destroyed.
   // Returns the number of elements erased.
   size_type erase( const key_type &val )
   {
	   TreeNode< value_type >* delete_node = scaryVal.myHead->parent, * index = scaryVal.myHead->parent;

	   while (index != scaryVal.myHead)
	   {
		   delete_node = index;
		   
		   if (index->myval == val) break;

		   if (keyCompare(val, index->myval)) index = index->left;
		   else index = index->right;
	   }

	   if (index == scaryVal.myHead) return 0;

	   if (delete_node->left != scaryVal.myHead && delete_node->right != scaryVal.myHead)
	   {
		   index = delete_node->right;
		   while (index->left != scaryVal.myHead) index = index->left;
		   delete_node->myval = index->myval;
		   delete_node = index;
	   }

	   if (delete_node == scaryVal.myHead->left) scaryVal.myHead->left = delete_node->parent;
	   if (delete_node == scaryVal.myHead->right) scaryVal.myHead->right = delete_node->parent;

	   scaryVal.eraseDegreeOne(delete_node);
	   return 1;
   }

private:
   key_compare keyCompare;
   ScaryVal scaryVal;
};

#endif // XTREE