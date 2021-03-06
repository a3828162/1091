// algorithm standard header

#ifndef ALGORITHM
#define ALGORITHM

namespace MyNamespace
{

   template< typename RanIt, typename Ty, typename Pr >
   inline void pushHeapByIndex( RanIt first, ptrdiff_t hole, ptrdiff_t top, Ty &val, Pr pred )
   {
       auto parent = (hole - 1) / 2;
       while (hole != top)
       {
           if (!pred(val, first[parent]))
           {
               first[hole] = first[parent];
               hole = parent;
               parent = (hole - 1) / 2;
           }
           else break;
       }

       first[hole] = val;
   }

   // push *(last - 1) onto heap at [first, last - 1), using pred
   template< typename RanIt, typename Pr >
   inline void push_heap( RanIt first, RanIt last, Pr pred )
   {
      ptrdiff_t count = last - first;
      if( count >= 2 )
      {
         --last;
         typename RanIt::value_type val = *last;
         --count;
         pushHeapByIndex( first, count, 0, val, pred );
      }
   }

   template< typename RanIt, typename Ty, typename Pr >
   inline void popHeapHoleByIndex( RanIt first, ptrdiff_t hole, ptrdiff_t bottom, Ty &val, Pr pred )
   { 
       auto top = hole;
       auto children = (hole + 1) * 2;
       while (bottom > children)
       {
           if (pred(first[children], first[children - 1])) --children;
           first[hole] = first[children], hole = children;
           children = (hole + 1) * 2;
       }
       if (children-- == bottom) first[hole] = first[children], hole = children;

      pushHeapByIndex( first, hole, top, val, pred );
   }

   // pop *first to *(last - 1) and reheap, using pred
   template< typename RanIt, typename Pr >
   inline void pop_heap( RanIt first, RanIt last, Pr pred )
   {
      if( last - first >= 2 )
      {
         --last;
         typename RanIt::value_type val = *last;

         // pop *first to *(last - 1) and reheap, using pred
         // precondition: first != last
         *last = *first;
         popHeapHoleByIndex( first, 0, last - first, val, pred );
      }
   }

   // make [first, last) into a heap, using pred
   template< typename RanIt, typename Pr >
   inline void make_heap( RanIt first, RanIt last, Pr pred )
   {
      ptrdiff_t bottom = last - first;
      ptrdiff_t hole = bottom / 2;
      while( hole > 0 )
      {
         // reheap top half, bottom to top
         --hole;
         typename RanIt::value_type val = *( first + hole );
         popHeapHoleByIndex( first, hole, bottom, val, pred );
      }
   }
}

#endif // ALGORITHM