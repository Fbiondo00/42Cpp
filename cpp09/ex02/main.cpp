#include "PmergeMe.hpp"

// ./PmergeMe `jot -r 6000 1 100000 | sort -u | head -n 3000 | tr '\n' ' '`
// ./PmergeMe `seq 1 3000 | tr '\n' ' '`

//--
// ./PmergeMe `seq 1 3000 | tr '\n' ' '`
// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr '\n' ' '`
int main(int argc, char **argv)
{
    try
    {
        // Initialize containers
        std::deque<int> dequeNumbers;
        std::vector<int> vectorNumbers;
        
        // Parse and validate input
        PmergeMe::parseInput(argc, argv, dequeNumbers, vectorNumbers);
        
        // Create the sorter and load the sequence
        PmergeMe sorter;
        sorter.loadSequence(dequeNumbers, vectorNumbers);
        
        // Sort using both containers
        sorter.sortDeque();
        sorter.sortVector();
        
        // Display results
        sorter.displayResults();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}




/*


## Sorting Algorithm Visualization

Let's walk through sorting the sequence `4 10 9 20 18 8 11 2`:

### Starting Point
```
Initial sequence: [4, 10, 9, 20, 18, 8, 11, 2]
```

### Step 1: Create Pairs
Group elements into adjacent pairs:
```
(4, 10)  (9, 20)  (18, 8)  (11, 2)
```

### Step 2: Order Each Pair Internally
Sort each pair so smaller element is first:
```
(4, 10)  (9, 20)  (8, 18)  (2, 11)
   ✓        ✓       ↺        ↺
```
Pairs after ordering:
```
(4, 10)  (9, 20)  (8, 18)  (2, 11)
```

### Step 3: Extract Larger Elements for Recursive Sort
```
Larger elements: [10, 20, 18, 11]
Smaller elements (set aside): [4, 9, 8, 2]
```

### Step 4: Recursively Sort Larger Elements

#### Level 1 Recursion Begins
```
Sequence to sort: [10, 20, 18, 11]
```

#### Level 1, Step 1: Create Pairs
```
(10, 20)  (18, 11)
```

#### Level 1, Step 2: Order Pairs
```
(10, 20)  (11, 18)
   ✓        ↺
```

#### Level 1, Step 3: Extract Larger Elements
```
Larger elements: [20, 18]
Smaller elements (set aside): [10, 11]
```

#### Level 2 Recursion Begins
```
Sequence to sort: [20, 18]
```

#### Level 2, Step 1: Create Pairs
```
(20, 18)
```

#### Level 2, Step 2: Order Pairs
```
(18, 20)
   ↺
```

#### Level 2 Base Case Reached
With only one pair, we have our sorted result:
```
Level 2 sorted result: [18, 20]
```

### Step 5: Building Back Up Through Recursion Levels

#### Level 1 Continuation
Starting with Level 2 result:
```
Main chain: [18, 20]
```

Pending smaller elements from Level 1:
```
[10, 11] (from pairs (10,20) and (11,18))
```

Insert these elements according to Jacobsthal sequence:
1. Insert 10 (binary search → before 18):
```
[10, 18, 20]
 ↑
```

2. Insert 11 (binary search → between 10 and 18):
```
[10, 11, 18, 20]
     ↑
```

#### Level 0 Continuation (Original Level)
Starting with Level 1 result:
```
Main chain: [10, 11, 18, 20]
```

Pending smaller elements from initial pairs:
```
[4, 9, 8, 2] (from pairs (4,10), (9,20), (8,18), (2,11))
```

Insert these elements according to Jacobsthal sequence:

After inserting at the Jacobsthal positions (1 and 3), we still have positions 2 and 4 remaining to complete our insertion of all elements.
In the Ford-Johnson algorithm's implementation, the remaining positions can be handled in different ways. In the common implementation:

We first insert at all the Jacobsthal positions (1, 3)
Then we insert at the remaining positions (2, 4) in ascending order

So the complete insertion order becomes: 1, 3, 2, 4


1. First insert element from position 1: Insert 4
```
[4, 10, 11, 18, 20]
 ↑
```

2. Next insert element from position 3: Insert 8
```
[4, 8, 10, 11, 18, 20]
    ↑
```

3. Next insert element from position 2: Insert 9
```
[4, 8, 9, 10, 11, 18, 20]
       ↑
```

4. Finally insert element from position 4: Insert 2
```
[2, 4, 8, 9, 10, 11, 18, 20]
 ↑
```

### Final Result
```
Sorted sequence: [2, 4, 8, 9, 10, 11, 18, 20]
```



*/