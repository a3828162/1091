// xhash internal header

#ifndef XHASH
#define XHASH

#include <list>
using std::list;

// CLASS TEMPLATE VectorVal
template< typename ValueType >
class VectorVal
{
public:
   using value_type = ValueType;
   using pointer    = value_type *;

   VectorVal()
      : myFirst(),
        myLast(),
        myEnd()
   {
   }

   pointer myFirst; // pointer to beginning of array
   pointer myLast;  // pointer to current end of sequence
   pointer myEnd;   // pointer to end of array
};

template< typename Iter >
struct HashVec
{
   using value_type = Iter;
   using size_type  = size_t;

   HashVec()
      : myData()
   {
   }

   // set the elements stored here to cells copies of val
   void assignGrow( const size_type cells, const value_type val )
   {
	   value_type* str = new value_type[cells]();
	   if (myData.myFirst != nullptr) delete[] myData.myFirst;
	   for (size_t i = 0; i < cells; ++i) str[i] = val;
	   myData.myFirst = str;
	   myData.myEnd = myData.myLast = str + cells;
   }

   ~HashVec()
   {
      if( myData.myFirst != nullptr )
         delete[] myData.myFirst;
   }

   VectorVal< value_type > myData;
};

// CLASS TEMPLATE Hash
template< typename Traits >
class Hash // hash table -- list with vector of iterators for quick access
{
protected:
   using MyList         = list< typename Traits::value_type >;
   using KeyCompare     = typename Traits::key_compare;

public:
   using key_type       = typename Traits::key_type;
   using value_type     = typename MyList::value_type;
   using size_type      = typename MyList::size_type;

   using iterator       = typename MyList::const_iterator;
   using const_iterator = typename MyList::const_iterator;

   static const size_type MinBuckets = 8; // must be a positive power of 2

protected:
   Hash( const KeyCompare &parg ) // construct empty hash table
      : traitsObj( parg ),
        myList(),
        myVec(),
        mask( MinBuckets - 1 ),
        maxidx( MinBuckets )
   {     
      myVec.assignGrow( MinBuckets * 2, myList.end() );
   }

public:
   // Returns the number of elements in the unordered_set container.
   size_type size() const
   {
      return myList.size();
   }

   // Returns the number of buckets in the unordered_set container.
   size_type bucket_count() const
   {
      return maxidx;
   }

   // Returns the bucket number where the element with value keyVal is located.
   size_type bucket( const key_type& keyVal ) const
   {
      return traitsObj( keyVal ) & mask;
//    return traitsObj.operator()( keyVal ) & mask;
//    return traitsObj( keyVal ) % maxidx;
   }

   // Returns the number of elements in bucket n.
   size_type bucket_size( size_type n ) const
   {
	   auto it = myVec.myData.myFirst[n * 2];
	   size_t R = 0;
	   if (it == myList.end()) return R;
	   while (1)
	   {
		   ++R;
		   if (it == myVec.myData.myFirst[n * 2 + 1]) return R;
		   ++it;
	   }
	   return R;
   }

   // Inserts a new element in the unordered_set.
   // The element is inserted only if it is not equivalent to any other element
   // already in the container ( elements in an unordered_set have unique values ).
   // This effectively increases the container size by one.
   void insert( const value_type &val )
   {
	   if (find(val) != myList.end()) return;
	   if (myList.size() >= maxidx)
	   {
		   if (maxidx >= 512) maxidx *= 2;
		   else maxidx *= 8;
		   mask = maxidx - 1;
		   MyList copy(myList);
		   myList.clear();
		   myVec.assignGrow(maxidx * 2, myList.end());
		   for (auto i = copy.begin(); i != copy.end(); ++i) putIn(*i);
	   }

	   putIn(val);

   }

   // Removes from the unordered_set a single element.
   // This effectively reduces the container size by one.
   void erase( const key_type &keyVal )
   {

   }

   // Searches the unordered_set for an element with keyVal as value and
   // returns an iterator to it if found, otherwise it returns myList.end()
   iterator find( const key_type &keyVal )
   {
	   auto it = myVec.myData.myFirst[bucket(keyVal) * 2];
	   while (it != myList.end() && *it != keyVal && it != myVec.myData.myFirst[bucket(keyVal) * 2 + 1]) ++it;
	   if (it == myList.end()) return myList.end();
	   else
	   {
		   if (*it == keyVal) return it;
		   else return myList.end();
	   }
   }

private:
   // put a new element in the unordered_set when myVec is large enough
   void putIn( const value_type &val )
   {
	   auto it = myVec.myData.myFirst[bucket(val) * 2];
	   myList.insert(it, val);
	   if (it == myList.end()) --myVec.myData.myFirst[bucket(val) * 2], --myVec.myData.myFirst[bucket(val) * 2 + 1];
	   else --myVec.myData.myFirst[bucket(val) * 2];
   }

protected:
   Traits traitsObj;          // traits to customize behavior
   MyList myList;             // list of elements, must initialize before myVec
   HashVec< iterator > myVec; // "vector" of list iterators for buckets:
                              // each bucket is 2 iterators denoting
                              // the closed range of elements in the bucket,
                              // or both iterators set to end() if the bucket is empty.
   size_type mask;            // the key mask, equals maxidx - 1
   size_type maxidx;          // current maximum key value, must be a power of 2
};

#endif // XHASH