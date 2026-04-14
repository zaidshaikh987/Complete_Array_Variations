# 📊 Universal Array Problem Sheet

Clean, organized list of array patterns and problems for interviews and practice. Headings and spacing are optimized for readability.

---
## Array Patterns and Problems

### Pattern 1: Basic Traversal & Simple Operations

These are foundational problems that involve iterating through the array with a single pass.
#### 🟢 Easy

 - Find the Maximum/Minimum Element
 - Find the Second Largest/Smallest Element
 - Find the Sum & Average of all Elements
 - Linear Search: Find the index of a given element.
 - Count Occurrences of a Given Element
 - Check if an Array Contains a Specific Element
 - Find the Floor/Ceil of a number in a Sorted Array


### Pattern 2: Two Pointers
This powerful technique involves using two pointers to iterate through the array, either from opposite ends, the same end (fast/slow), or from different arrays.

#### 🟢 Easy

 - Reverse an Array
 - Segregate 0s and 1s
 - Sort Array by Parity (Segregate Even and Odd Numbers)
 - Remove Duplicates from a Sorted Array
 - Two-Sum (on a sorted array, target = k)
 - Count Pairs with Given Sum (sorted array)
 - Find a Pair with Given Difference k
 - Find Pair with Sum Closest to Zero (minimum absolute sum pair)
 - Check if an Array is Sorted
 - Squares of a Sorted Array (merge negatives & positives)

#### 🟡 Medium

 - Move all Zeros to the End
 - Rearrange Positive and Negative Numbers Alternately
 - Container With Most Water
 - 3-Sum Problem (all unique triplets summing to target)
 - 3-Sum Closest
 - Remove Duplicates from Sorted Array II (allow at most two duplicates)
 - Two-Sum in a Rotated Sorted Array
 - All Unique Pairs with Sum = k (handle duplicates)
 - Partition Array by Condition (stable vs unstable)

#### 🟠 Hard

 - Trapping Rain Water
 - 4-Sum Problem
 - K-Sum Problem (generalize to k > 4)
 - Minimize/Maximize Pair Sum under Constraints
 - Circular Two-Pointer Variants (wrap-around arrays)

_____________________________________________________________________________________
___________________________________________________________________________________

### Pattern 3: Sliding Window
This pattern is used for problems involving contiguous subarrays. A "window" of a certain size slides over the array to find an optimal solution.

### 🟢 EASY — Fixed Window Problems

💡 **Core Idea:**  
Move a window of fixed size **K** → Add right element, remove left element.

| Problem | Concept | Notes |
|----------|----------|-------|
| - Maximum Sum Subarray of Size K | Sum | Classic fixed window base problem |
| - Minimum Sum Subarray of Size K | Sum | Just track min instead of max |
| - Average of Subarray of Size K | Average | Compute rolling average |
| - Maximum Consecutive Ones | Count | Count continuous 1s in fixed or variable window |
| - Subarray of Size K with Maximum Average / Minimum Average | Average | Similar to above |
| - Count of Subarrays of Size K with Sum > X *(optional)* | Conditional | Builds pattern understanding |

🧠 **Master these first** — they build muscle memory for window movement.

---

### 🟡 MEDIUM — Variable Window Problems

💡 **Core Idea:**  
Expand right until condition breaks → Shrink left until condition is valid again.  
This pattern dominates interview questions.

| Problem | Concept | Notes |
|----------|----------|-------|
| - Smallest Subarray with Sum ≥ S | Shrinking window | Minimize window length for sum ≥ S |
| - Longest Substring Without Repeating Characters | Distinct elements | Classic string problem |
| - Longest Subarray with Sum ≤ K | Sum-based | Keep window valid with sum ≤ K |
| - Fruit Into Baskets | At most 2 distinct | Same as “Longest Substring with ≤ 2 distinct chars” |
| - Longest Subarray with at Most K Distinct Elements | Generalized version | Important extension |
| - Subarrays with Sum = K (Positive Numbers) | Sum-based | Works if all elements are +ve |
| - Longest Subarray with Equal 0s and 1s *(0→-1 trick)* | Prefix-based hybrid | Common logic mix |
| - Longest Subarray with at Most K Zeros *(Flip Problem)* | Replacement allowed | Variation of consecutive 1s |
| - Count of Subarrays with At Most K Distinct Integers *(Optional)* | Counting variant | Builds on window shrinking concept |

🧠 Understand **"expand–shrink" logic once** — rest are small tweaks of it.

---

### 🟠 HARD — Advanced Sliding Window Optimizations

💡 **Core Idea:**  
Window + optimization using data structures like **deque**, **hashmap**, or **frequency array**.

| Problem | Concept | Notes |
|----------|----------|-------|
| - Sliding Window Maximum | Deque-based | Maintain max in O(n) |
| - Sliding Window Minimum | Deque-based | Similar, maintain min |
| - Minimum Window Substring | Character freq | Shrink window to minimum valid |
| - Permutation in String | Frequency match | Check if s1’s permutation in s2 |
| - Count of Anagrams in String | Frequency + fixed window | Count all valid substrings |
| - Longest Repeating Character Replacement | Expand–shrink + frequency | Replace ≤ k chars to maximize same chars |
| - Longest Subarray with At Most K Zeros *(Flip)* | Variable window with condition | Common real-world pattern |
| - Subarray with Exactly K Distinct Integers *(Optional)* | Window counting trick | Rare but elegant variant |
| - K-size Window Median *(Optional, advanced)* | Heaps or multiset | Competitive programming level |

🧠 These are **FAANG-level** — master easy + medium first.

____________________________________________________________________________________
____________________________________________________________________________________

### Pattern 4: Prefix & Suffix Computations
This involves pre-calculating values (like sums or products) from the beginning (prefix) or end (suffix) of the array to answer queries efficiently.
#### 🟢 Easy

 - Find the Union of Two Sorted Arrays
 - Find the Intersection of Two Sorted Arrays
#### 🟡 Medium

 - Product of Array Except Self (No Division)
 - Subarray Sum Equals K (Count # of subarrays)
 - Largest Subarray with 0 Sum
 - Longest Subarray with a Given Sum K (handles negatives)
#### 🟠 Hard

 - Count Number of Subarrays with Given XOR K
 - Maximum Product Subarray (Kadane's variation, but also tracks min product)
### Pattern 5: Hashing (Frequency Counting)
Using a hash map or a hash set is ideal for problems involving frequencies, duplicates, or searching for elements in O(1) average time.
#### 🟢 Easy

 - Check if an Array has Duplicate Elements
 - Find the Most Frequent Element
 - Two-Sum (on an unsorted array)
 - Find the Missing Number in a Range [1, n]
 - Find the Number that Appears Once (while others appear twice)
#### 🟡 Medium

 - Find the First Non-Repeating Element
 - Find the First Repeating Element
 - Longest Consecutive Sequence
 - Majority Element (> n/2 times)
 - Majority Element II (> n/3 times)
 - Top K Frequent Elements
### Pattern 6: Partitioning & Sorting In-Place
These problems involve rearranging elements based on a condition or pivot without using extra space. The Dutch National Flag is a classic example.
#### 🟢 Easy

 - Swap the First and Last Elements
 - Segregate 0s and 1s
 - Sort an Array of 0s and 1s Without a Sorting Algorithm
#### 🟡 Medium

 - Dutch National Flag Problem (Sort an array of 0s, 1s, and 2s)
 - Partition Array Around a Pivot (Quicksort partition step)
 - Find the Repeating and Missing Number
### Pattern 7: Array Rotations & Rearrangements
Problems focused on shifting or reordering elements in a specific sequence.
#### 🟢 Easy

 - Left/Right Rotate an Array by One Position
 - Left/Right Rotate an Array by K Elements
#### 🟡 Medium

 - Next Permutation
 - Replace Every Element with the Next Greatest Element
 - Leaders in an Array
### Pattern 8: Kadane's Algorithm & Variations
A dynamic programming approach to find the maximum sum of a contiguous subarray. It can be adapted for other similar problems.
#### 🟢 Easy

 - Find the Subarray with the Maximum Sum (Kadane's Algorithm)
#### 🟡 Medium

 - Print the Subarray with the Maximum Sum
 - Maximum Product Subarray
### Pattern 9: Binary Search on Arrays
Essential for searching in sorted (or partially sorted) data structures in O(log n) time.
#### 🟢 Easy

 - Binary Search for an element X in a Sorted Array
 - Implement Lower Bound / Upper Bound
 - Search Insert Position
 - Count Occurrences of a Number in a Sorted Array
 - Find First and Last Occurrence of an Element
#### 🟡 Medium

 - Search in a Rotated Sorted Array I
 - Search in a Rotated Sorted Array II (with duplicates)
 - Find Minimum in Rotated Sorted Array
 - Find Peak Element
 - Single Element in a Sorted Array
### Pattern 10: Binary Search on "Answer Space"
A more advanced technique where you perform a binary search on the range of possible answers to find the optimal one that satisfies a given condition.
#### 🟡 Medium

 - Find the Square Root of a Number
 - Find the Nth Root of a Number
#### 🟠 Hard

 - Koko Eating Bananas
 - Minimum Days to Make M Bouquets
 - Capacity to Ship Packages within D Days
 - Aggressive Cows
 - Book Allocation Problem / Split Array - Largest Sum
 - Median of Two Sorted Arrays
 - Kth Element of Two Sorted Arrays
### Pattern 11: Matrix (2D Array) Problems
Problems that extend array concepts to two dimensions.
#### 🟢 Easy

 - Find the Row with the Maximum Number of 1s
#### 🟡 Medium

 - Set Matrix Zeros
 - Rotate Matrix by 90 Degrees
 - Print the Matrix in a Spiral Manner
 - Search in a 2D Matrix (sorted rows and columns)
 - Pascal's Triangle
### Pattern 12: Advanced/Miscellaneous
These problems often combine multiple patterns or require a unique insight.
#### 🟡 Medium

 - Stock Buy and Sell (find max profit for one transaction)
 - Merge Overlapping Subintervals

#### 🟠 Hard

 - Merge Two Sorted Arrays Without Extra Space
 - Count Inversions
 - Reverse Pairs
 - Find the Duplicate Number in an Array [1, n] of size n+1
 
 
