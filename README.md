_This project has been created as part
of the 42 curriculum by razimmer._

## **PUSH_SWAP**

### DESCRIPTION

push_swap is a sorting algorithm project that aims to sort a stack of integers
using a limited set of operations and the smallest possible number of moves.

The program takes a list of integers as input, stores them in stack **A**, and sorts
them in ascending order using an auxiliary stack **B**. Only specific operations
(push, swap, rotate, reverse rotate) are allowed.

For input sizes greater than 5, the program uses a chunk-based indexed sorting algorithm (ksort) to efficiently sort the stack using a minimal number of operations.

### Ksort Overview

**Indexing**

	- Each element in the input stack is assigned an index based on its value in the sorted order.
	- This allows the algorithm to work with relative positions rather than raw values.

**Chunk Partitioning**

	- The stack is processed in chunks of elements.  
	- The chunk size is dynamically calculated as roughly `√n × 1.4`, balancing efficiency and operation count.
	- Elements whose index falls within the current chunk are pushed from stack A to stack B.

**Optimized Rotations**

	- To minimize moves, the algorithm chooses the shortest path to bring elements to the top of stack A or stack B.  
	- Depending on their position, it rotates (`ra`, `rb`) or reverses (`rra`, `rrb`) stacks.

**Progressive Push**

	- Elements are pushed to stack B in order of increasing index.  
	- Special combined rotations (`rr`) are used when beneficial to reduce total operations.

**Pushback Phase**

	- Once all elements are in stack B, the algorithm pushes them back to stack A in the correct order.
	- The largest remaining elements are moved first, again using optimized rotations to minimize moves.


### Small Sort (sorting of 5 elements or less)

**2 elements**

	- A simple swap operation is applied if the elements are out of order.

**3 elements**

	- All possible permutations are handled explicitly using a minimal set of operations
	(`sa`, `ra`, `rra`).
	- The algorithm compares the three values and applies the optimal move sequence for
	each case.

**4 or 5 elements**

	- The smallest element is located and rotated to the top of stack A using the most
	efficient direction.
	- The smallest value is pushed to stack B.
	- This process is repeated once more for 5 elements.
	- The remaining three elements are sorted using the dedicated 3-element strategy.
	- Elements stored in stack B are then pushed back to stack A in the correct order.


## INSTRUCTIONS

### Compilation
Run `make` to build the `push_swap` executable.

### Usage

	./push_swap <list of integers>

	output:
	intructions required to sort the stack seperated by newlines

### Example:

	./push_swap 5 4 1 2

	output:
	ra
	ra
	pb
	sa
	ra
	pa

**Input rules:**

	- Only integers are accepted
	- No duplicates are allowed
	- Values must fit in a 32-bit signed integer
	- Invalid input will result in Error



## RESOURCES

- 42 push_swap subject PDF
- Sorting algorithms: Wikipedia
- Stack data structure: Wikipedia
- Radix sort and chunk-based sorting strategies
- various youtube videos
	- https://www.youtube.com/watch?v=OaG81sDEpVk
	- https://www.youtube.com/watch?v=wRvipSG4Mmk
	- https://www.youtube.com/watch?v=4dMsuxfqufg
	- https://www.youtube.com/watch?v=mIqpsnKmfzw
	- https://www.youtube.com/watch?v=K0XXVSL4wUo


### AI Usage

AI tools were used for:

	- reducing repetitive or tedious tasks.
	- debugging
	- assisting in the creation of this document

All algorithm implementation decisions were made by the author.
