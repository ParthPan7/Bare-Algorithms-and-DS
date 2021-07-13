 
# Heaps and Heap Sort Algorithm 
Credits : https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf
 
 ## Heap is an implmentation of priority queue.
 Operations on Priority queue Data Structures:
 1) insert_ele( S , e ) : Inserting new element in a heap data structure in a set of elements S.
 2) max (S) : returning maximum element from heap's set S.
 3) extract_max(S) : removing and returning maximum element from set S.
 4) increse_val ( s, ele, i ) : increasing value of element ele in Set S of heap by value of i.
 
 ## Heap Types:
 Min Heap and Max Heap :
 Max Heap : key/value of parent node >= key value of their child nodes.
 Min Heap : key/value of parent node <= key value of their child nodes.
 
 ## Representation of a Heap:
 Arrays : complete binary tree
 root of tree : lies at array index location 1 ( index  = 1).
 left_of_node(i) : 2i
 right_of_node(i) : 2i+1
 parent_of_node(i) : i/2
 
 
 ## Crucial Operation for implmenting Heap Construction:
 
 1) Max_Heapify : correcting the violation against max_heapify and reforming the max / min heap
 2) construct_max_heap ( S ) : construction of max heap from unordered number list [uses MaxHeapify].
 3) Heap sort : uses [MaxHeapify].
 
 Max_heapify( S, i):
    L <- left_of_node(i)
    R <- right_of_node(i)
 
    Largest = NONE
 
    // compare with left node
    if L <= size_of(S) and S(i) < S(L):
        Largest = L
    else :
        Largest = i
 
    // comparing larger out of 2 from with right
    if R <= size_of(S) and S(R) > S(Largest):
        Largest = R
 
    if Largest != i:
        swap( S(i), S(Largest))
        Max_Heapify( S, Largest)
 
 Construct_Max_Heap( S )
    N = size_of(S)
    for i = N/2 to 1:
    // from i = N/2+1 because left(i) = 2*i = 2*(N/2+1) = N + 2 > N so they are leaves of tree with no children
        Max_Heapify(S,i)

### Heap Sort for decreasing sequences 
 
  Heap_Sort( L ):
   N = size_of(L)
   Construct_Max_Heap( L )
   R = []   
   while size_of(L) >= 1 :
        ele = pop_back(L)
	insert_back(R, ele)

   return R				
	

