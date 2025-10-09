# 📊 Universal Array Problem Sheet

A clean, organized list of array patterns and problems for interviews and practice. Headings and spacing are optimized for readability.

---

## Table of Contents

1. [Array Patterns and Problems](#array-patterns-and-problems)
2. [Pattern 1: Basic Traversal & Simple Operations](#pattern-1-basic-traversal--simple-operations)
3. [Pattern 2: Two Pointers](#pattern-2-two-pointers)
4. [Pattern 3: Sliding Window](#pattern-3-sliding-window)
5. [Pattern 4: Prefix & Suffix Computations](#pattern-4-prefix--suffix-computations)
6. [Pattern 5: Hashing (Frequency Counting)](#pattern-5-hashing-frequency-counting)
7. [Pattern 6: Partitioning & Sorting In-Place](#pattern-6-partitioning--sorting-in-place)
8. [Pattern 7: Array Rotations & Rearrangements](#pattern-7-array-rotations--rearrangements)
9. [Pattern 8: Kadane's Algorithm & Variations](#pattern-8-kadanes-algorithm--variations)
10. [Pattern 9: Binary Search on Arrays](#pattern-9-binary-search-on-arrays)
11. [Pattern 10: Binary Search on "Answer Space"](#pattern-10-binary-search-on-answer-space)
12. [Pattern 11: Matrix (2D Array) Problems](#pattern-11-matrix-2d-array-problems)
13. [Pattern 12: Advanced/Miscellaneous](#pattern-12-advancedmiscellaneous)

---

## Array Patterns and Problems

### Pattern 1: Basic Traversal & Simple Operations

**🟢 Easy**
- Find the Maximum/Minimum Element
- Find the Second Largest/Smallest Element
- Find the Sum & Average of all Elements
- Linear Search: Find the index of a given element
- Count Occurrences of a Given Element
- Check if an Array Contains a Specific Element
- Find the Floor/Ceil of a number in a Sorted Array

---

### Pattern 2: Two Pointers

A powerful technique using two pointers to iterate, either from opposite ends, the same end (fast/slow), or from different arrays.

**🟢 Easy**
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

**🟡 Medium**
- Move all Zeros to the End
- Rearrange Positive and Negative Numbers Alternately
- Container With Most Water
- 3-Sum Problem (all unique triplets summing to target)
- 3-Sum Closest
- Remove Duplicates from Sorted Array II (allow at most two duplicates)
- Two-Sum in a Rotated Sorted Array
- All Unique Pairs with Sum = k (handle duplicates)
- Partition Array by Condition (stable vs unstable)

**🟠 Hard**
- Trapping Rain Water
- 4-Sum Problem
- K-Sum Problem (generalize to k > 4)
- Minimize/Maximize Pair Sum under Constraints
- Circular Two-Pointer Variants (wrap-around arrays)

---

### Pattern 3: Sliding Window

Used for problems involving contiguous subarrays. A "window" of a certain size slides over the array to find an optimal solution.

**🟢 Easy — Fixed Window Problems**
- Maximum Sum Subarray of Size K
- Minimum Sum Subarray of Size K
- Average of Subarray of Size K
- Maximum Consecutive Ones
- Subarray of Size K with Maximum/Minimum Average
- Count of Subarrays of Size K with Sum > X

**🟡 Medium — Variable Window Problems**
- Smallest Subarray with Sum ≥ S
- Longest Substring Without Repeating Characters
- Longest Subarray with Sum ≤ K
- Fruit Into Baskets
- Longest Subarray with at Most K Distinct Elements
- Subarrays with Sum = K (Positive Numbers)
- Longest Subarray with Equal 0s and 1s *(0→-1 trick)*
- Longest Subarray with at Most K Zeros *(Flip Problem)*
- Count of Subarrays with At Most K Distinct Integers

**🟠 Hard — Advanced Sliding Window Optimizations**
- Sliding Window Maximum (Deque-based)
- Sliding Window Minimum (Deque-based)
- Minimum Window Substring
- Permutation in String
- Count of Anagrams in String
- Longest Repeating Character Replacement
- Longest Subarray with At Most K Zeros *(Flip)*
- Subarray with Exactly K Distinct Integers
- K-size Window Median *(Heaps/multiset)*

---

### Pattern 4: Prefix & Suffix Computations

Pre-calculate values (like sums/products) from the beginning (prefix) or end (suffix) of the array.

**🟢 Easy**
- Find the Union of Two Sorted Arrays
- Find the Intersection of Two Sorted Arrays

**🟡 Medium**
- Product of Array Except Self (No Division)
- Subarray Sum Equals K (Count subarrays)
- Largest Subarray with 0 Sum
- Longest Subarray with a Given Sum K (handles negatives)

**🟠 Hard**
- Count Number of Subarrays with Given XOR K
- Maximum Product Subarray

---

### Pattern 5: Hashing (Frequency Counting)

Use hash map or set for frequencies, duplicates, or searching for elements in O(1) average time.

**🟢 Easy**
- Check if an Array has Duplicate Elements
- Find the Most Frequent Element
- Two-Sum (on an unsorted array)
- Find the Missing Number in [1, n]
- Find the Number that Appears Once (others appear twice)

**🟡 Medium**
- Find the First Non-Repeating Element
- Find the First Repeating Element
- Longest Consecutive Sequence
- Majority Element (> n/2 times)
- Majority Element II (> n/3 times)
- Top K Frequent Elements

---

### Pattern 6: Partitioning & Sorting In-Place

Rearrange elements based on a condition or pivot without extra space.

**🟢 Easy**
- Swap the First and Last Elements
- Segregate 0s and 1s
- Sort an Array of 0s and 1s Without Sorting Algorithm

**🟡 Medium**
- Dutch National Flag Problem (Sort 0s, 1s, 2s)
- Partition Array Around a Pivot
- Find the Repeating and Missing Number

---

### Pattern 7: Array Rotations & Rearrangements

Shift or reorder elements in a specific sequence.

**🟢 Easy**
- Left/Right Rotate Array by One Position
- Left/Right Rotate Array by K Elements

**🟡 Medium**
- Next Permutation
- Replace Every Element with the Next Greatest Element
- Leaders in an Array

---

### Pattern 8: Kadane's Algorithm & Variations

Dynamic programming approach for maximum sum contiguous subarray.

**🟢 Easy**
- Find the Subarray with Maximum Sum (Kadane's Algorithm)

**🟡 Medium**
- Print the Subarray with Maximum Sum
- Maximum Product Subarray

---

### Pattern 9: Binary Search on Arrays

Essential for searching in sorted data structures in O(log n) time.

**🟢 Easy**
- Binary Search for an element X in Sorted Array
- Implement Lower/Upper Bound
- Search Insert Position
- Count Occurrences of a Number in Sorted Array
- Find First and Last Occurrence

**🟡 Medium**
- Search in Rotated Sorted Array I & II
- Find Minimum in Rotated Sorted Array
- Find Peak Element
- Single Element in a Sorted Array

---

### Pattern 10: Binary Search on "Answer Space"

Binary search on the range of possible answers to find the optimal condition.

**🟡 Medium**
- Find the Square Root/Nth Root of a Number

**🟠 Hard**
- Koko Eating Bananas
- Minimum Days to Make M Bouquets
- Capacity to Ship Packages within D Days
- Aggressive Cows
- Book Allocation Problem / Split Array - Largest Sum
- Median of Two Sorted Arrays
- Kth Element of Two Sorted Arrays

---

### Pattern 11: Matrix (2D Array) Problems

Extend array concepts to two dimensions.

**🟢 Easy**
- Find the Row with Maximum 1s

**🟡 Medium**
- Set Matrix Zeros
- Rotate Matrix by 90 Degrees
- Print Matrix in Spiral Manner
- Search in a 2D Matrix
- Pascal's Triangle

---

### Pattern 12: Advanced/Miscellaneous

Often combine multiple patterns or require unique insight.

**🟡 Medium**
- Stock Buy and Sell (max profit, one transaction)
- Merge Overlapping Subintervals

**🟠 Hard**
- Merge Two Sorted Arrays Without Extra Space
- Count Inversions
- Reverse Pairs
- Find the Duplicate Number in [1, n] (size n+1)

---
