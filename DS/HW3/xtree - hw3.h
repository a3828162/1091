// xtree internal header
using std::swap;
#define red Color::Red
#define black Color::Black
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
       if (node->parent == myHead)
       {
           return;
       }
       if (node->parent->parent == myHead)
       {
           return;
       }

       NodePtr p = node->parent, g = node->parent->parent, uncle = p == g->left ? g->right : g->left;

       if (p->color == Color::Black)
           return;

       if (uncle->color == Color::Red)
       {

           p->color = Color::Black;
           uncle->color = Color::Black;
           if (g->parent != myHead)
               g->color = Color::Red;

           if (g->parent->color == Color::Red)
               reBalance(g);
       }
       else
       {
               if (node == p->left && p == g->left && uncle->color == Color::Black) //LLB
               {
                 //  cout << "1" << endl;
                   LLRotation(node->parent);
                   node->parent->color = Color::Black;
                   node->parent->right->color = Color::Red;
               }
               else if (node == p->right && p == g->left && uncle->color == Color::Black) //LRB
               {
                 //  cout << "2" << endl;
                   LRRotation(node);
                   node->color = Color::Black;
                   node->right->color = Color::Red;
               }
               else if (node == p->right && p == g->right && uncle->color == Color::Black) //RRB
               {
                 //  cout << "3" << endl;
                   RRRotation(node->parent);
                   node->parent->color = Color::Black;
                   node->parent->left->color = Color::Red;
               }
               else if (node == p->left && p == g->right && uncle->color == Color::Black) //RLB
               {
                 //  cout << "4" << endl;
                   RLRotation(node);
                   node->color = Color::Black;
                   node->left->color = Color::Red;
               }
       }
   }

   // rotate right at g, where p = g->left and node = p->left
   //void set< Kty >::LLbRotation( TreeNode< value_type > *node )
/*¥k±Û*/   void LLRotation( TreeNode< value_type > *p )
   {
       NodePtr g = p->parent;
       p->parent = p->parent->parent;
       if (g->parent->isNil == 1)
           myHead->parent = p;
       else if (g == g->parent->left)
           g->parent->left = p;
       else if (g == g->parent->right)
           g->parent->right = p;
       g->left = p->right;

       if(p->right!=myHead)
           p->right->parent = g;

       g->parent = p;
       p->right = g;
   }

   // LR rotation; p = g->left and node = p->right
   void LRRotation( TreeNode< value_type > *node )
   {
       //NodePtr p = node->parent, g = node->parent->parent;
       RRRotation(node);
       LLRotation(node);
   }

   // RL rotation; p = g->right and node = p->left
   void RLRotation( TreeNode< value_type > *node )
   {
       LLRotation(node);
       RRRotation(node);
   }

   // rotate left at g, where p = g->right and node = p->right
   //void set< Kty >::RRbRotation( TreeNode< value_type > *node )
/*¥ª±Û*/  void RRRotation( TreeNode< value_type > *p )
   {
       NodePtr g = p->parent;
       p->parent = p->parent->parent;
       if (g->parent->isNil == 1)
           myHead->parent = p;
       else if (g == g->parent->left)
           g->parent->left = p;
       else if (g == g->parent->right)
           g->parent->right = p;
       g->right = p->left;

       if(p->left!=myHead)
           p->left->parent = g;

       g->parent = p;
       p->left = g;
   }

   // erase node provided that the degree of node is at most one
   void eraseDegreeOne( TreeNode< value_type > *node )
   {
       NodePtr ptr = node;
       NodePtr P = node->parent;
       NodePtr child = node->left->isNil ? node->right : node->left;

       if (ptr->color == black &&  P->isNil)
       {
           child->color = black;
           myHead->parent = child;
           child->parent = myHead;
           delete ptr;
           --mySize;
           return;
       }

       ptr == P->left ? P->left = child : P->right = child;
       if (!child->isNil) child->parent = P;

       if (ptr->color == black && child->color == black && !P->isNil) fixUp(child, P);

       if (ptr->color == black && child->color == red) child->color = black;

       delete ptr;
       --mySize;
   }

   // rebalance for deletion
   void fixUp( TreeNode< value_type > *N, TreeNode< value_type > *P )
   {
       NodePtr s = N == P->left ? P->right : P->left;

       if (s->color == red && N == P->left)
       {
           swap(P->color, s->color);
           RRRotation(s);
       }
       if (s->color == red && N == P->right)
       {
           swap(P->color, s->color);
           LLRotation(s);
       }

       s = N == P->left ? P->right : P->left;

       if (s->color == black && s->right->color == black && s->left->color == red && N == P->left)
       {
           swap(s->color, s->left->color);
           LLRotation(s->left);
       }
       if (s->color == black && s->left->color == black && s->right->color == red && N == P->right)
       {
           swap(s->color, s->right->color);
           RRRotation(s->right);
       }

       s = N == P->left ? P->right : P->left;

       if (s->color == black && s->right->color == red && N == P->left)
       {
           swap(P->color, s->color);
           s->right->color = black;
           RRRotation(s);
           return;
       }
       if (s->color == black && s->left->color == red && N == P->right)
       {
           swap(P->color, s->color);
           s->left->color = black;
           LLRotation(s);
           return;
       }

       if (s->color == black && s->right->color == black && s->left->color == black && P->color == red)
       {
           swap(s->color, P->color);
           return;
       }

       if (s->color == black && s->right->color == black && s->left->color == black && P->color == black)
       {
           s->color = red;
           if (P->parent != myHead)
               fixUp(P, P->parent);
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
       TreeNode< value_type >* insert_point = scaryVal.myHead->parent;
       TreeNode< value_type >* index = scaryVal.myHead->parent;
       TreeNode< value_type >* head = scaryVal.myHead;
       while (index != head)
       {
           insert_point = index;

           if (index->myval == val) return;
           
           keyCompare(val, index->myval) ? index = index->left : index = index->right;
       }
       TreeNode< value_type >* NewNode = new TreeNode<value_type>{ head,head,head,Color::Red,false,val };

       if (scaryVal.mySize == 0)
       {
           NewNode->color = Color::Black;
           scaryVal.myHead->parent = scaryVal.myHead->left = scaryVal.myHead->right = NewNode;
           scaryVal.mySize++;
           return;
       }

       keyCompare(val, head->left->myval) ? head->left = NewNode : head->right = NewNode;

       keyCompare(val, insert_point->myval) ? insert_point->left = NewNode : insert_point->right = NewNode;

       NewNode->parent = insert_point;

       scaryVal.mySize++;
       scaryVal.reBalance(NewNode);
   }

   // Removes from the set container a single element whose value is val
   // This effectively reduces the container size by one, which are destroyed.
   // Returns the number of elements erased.
   size_type erase( const key_type &val )
   {
       TreeNode< value_type >* Delete_Node = scaryVal.myHead->parent;
       TreeNode< value_type >* index = scaryVal.myHead->parent;
 
       while (index != scaryVal.myHead)
       {
           Delete_Node = index;
           if (val == index->myval)
               break;

           keyCompare(val, index->myval) ? index = index->left : index = index->right;
       }

       if (index == scaryVal.myHead) return 0;

       if (!Delete_Node->left->isNil && !Delete_Node->right->isNil)
       {
           TreeNode< value_type >* copy = Delete_Node->right;
           while (copy->left != scaryVal.myHead)
               copy = copy->left;
           Delete_Node->myval = copy->myval;
           Delete_Node = copy;
       }

       if (scaryVal.myHead->left == Delete_Node)
           scaryVal.myHead->left = Delete_Node->parent;
       if (scaryVal.myHead->right == Delete_Node)
           scaryVal.myHead->right = Delete_Node->parent;       

       scaryVal.eraseDegreeOne(Delete_Node);

       return 1;
   }

private:
   key_compare keyCompare;
   ScaryVal scaryVal;
};

#endif // XTREE

/*NodePtr sibing = 0;

while (N != myHead->parent && N->color == Color::Black)
{
    if (N == P->left)
    {
        sibing = P->right;
        if (sibing->color == Color::Red)
        {
            sibing->color = Color::Black;
            P->color = Color::Red;
            RRRotation(sibing);
            sibing = P->right;
        }

        if (sibing->left->color == Color::Black && sibing->right->color == Color::Black)
        {
            sibing->color = Color::Red;
            N = P;
            P = P->parent;
        }
        else
        {
            if (sibing->right->color == Color::Black)
            {
                sibing->left->color = Color::Black;
                sibing->color = Color::Red;
                LLRotation(sibing->left);
                sibing = P->right;
            }
            sibing->color = P->color;
            P->color = Color::Black;
            sibing->right->color = Color::Black;
            RRRotation(sibing);
            N = myHead->parent;
            break;
        }
    }
    else
    {
        sibing = P->left;
        if (sibing->color == Color::Red)
        {
            sibing->color = Color::Black;
            P->color = Color::Red;
            LLRotation(sibing);
            sibing = P->left;
        }

        if (sibing->left->color == Color::Black && sibing->right->color == Color::Black)
        {
            sibing->color = Color::Red;
            N = P;
            P = P->parent;
        }
        else
        {
            if (sibing->left->color == Color::Black)
            {
                sibing->right->color = Color::Black;
                sibing->color = Color::Red;
                RRRotation(sibing->right);
                sibing = P->left;
            }

            sibing->color = P->color;
            P->color = Color::Black;
            sibing->left->color = Color::Black;
            LLRotation(sibing);
            N = myHead->parent;
            break;
        }
    }
}
N->color = Color::Black;*/

/*ptr->left != myHead ? child = ptr->left : child = ptr->right;

if (child != myHead)
    child->parent = ptr->parent;

if (ptr->parent == myHead)
    myHead->parent = child;
else if (ptr == ptr->parent->left)
    ptr->parent->left = child;
else if (ptr == ptr->parent->right)
    ptr->parent->right = child;

if( ptr->color == Color::Black )
   fixUp( child, ptr->parent );

delete ptr;
mySize--;*/