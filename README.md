# 📊 Universal Array Problem Sheet

Clean, organized list of array patterns and problems for interviews and practice. Headings and spacing are optimized for readability.

---

## 🚀 Array Patterns and Problems

### 🧩 Pattern 1: Basic Traversal & Simple Operations
These are foundational problems that involve iterating through the array with a single pass.

#### 🟢 Easy
- Find the Maximum/Minimum Element
- Find the Second Largest/Smallest Element
- Find the Sum & Average of all Elements
- Linear Search: Find the index of a given element.
- Count Occurrences of a Given Element
- Check if an Array Contains a Specific Element
- Find the Floor/Ceil of a number in a Sorted Array

---

### 🔗 Pattern 2: Two Pointers
This powerful technique involves using two pointers to iterate through the array, either from opposite ends, the same end (fast/slow), or from different arrays.

#### 🟢 Easy
- Reverse an Array
- Segregate 0s and 1s
- Sort Array by Parity (Even and Odd)
- Remove Duplicates from a Sorted Array
- Two-Sum (Sorted array, target = k)
- Count Pairs with Given Sum (Sorted array)
- Find a Pair with Given Difference k
- Find Pair with Sum Closest to Zero
- Check if an Array is Sorted
- Squares of a Sorted Array

#### 🟡 Medium
- Move all Zeros to the End
- Rearrange Positive and Negative Numbers Alternately
- Container With Most Water
- 3-Sum Problem
- 3-Sum Closest
- Remove Duplicates from Sorted Array II
- Two-Sum in a Rotated Sorted Array
- All Unique Pairs with Sum = k
- Partition Array by Condition

#### 🟠 Hard
- Trapping Rain Water
- 4-Sum Problem
- K-Sum Problem (Generalize to k > 4)
- Minimize/Maximize Pair Sum under Constraints
- Circular Two-Pointer Variants

---

### 🪟 Pattern 3: Sliding Window
Used for contiguous subarrays where a "window" slides over the array to find an optimal solution.

#### 🟢 EASY — Fixed Window Problems
💡 **Core Idea:** Move a window of fixed size **K** → Add right element, remove left element.

| Problem | Concept | Notes |
| :--- | :--- | :--- |
| Maximum Sum Subarray of Size K | Sum | Classic fixed window base problem |
| Minimum Sum Subarray of Size K | Sum | Just track min instead of max |
| Average of Subarray of Size K | Average | Compute rolling average |
| Maximum Consecutive Ones | Count | Count continuous 1s |
| Subarray of Size K Max/Min Average | Average | Rolling calculation |

#### 🟡 MEDIUM — Variable Window Problems
💡 **Core Idea:** Expand right until condition breaks → Shrink left until valid again.

| Problem | Concept | Notes |
| :--- | :--- | :--- |
| Smallest Subarray with Sum ≥ S | Shrink window | Minimize length |
| Longest Substring Without Repeating Chars | Distinct | Classic hashmap use |
| Longest Subarray with Sum ≤ K | Sum-based | Maintain valid sum |
| Fruit Into Baskets | 2 Distinct | Maximize elements |
| Longest Subarray with at Most K Distinct | Generalized | Important extension |
| Longest Subarray with Equal 0s and 1s | Trick | 0 → -1 trick |
| Longest Subarray with at Most K Zeros | Flip | Sliding window replacement |

#### 🟠 HARD — Advanced Optimizations
💡 **Core Idea:** Window + optimization using Deque, Hashmap, or Multi-set.

| Problem | Concept | Notes |
| :--- | :--- | :--- |
| Sliding Window Maximum | Deque | O(n) using Monotonic Queue |
| Minimum Window Substring | Character freq | Hardest window problem |
| Permutation in String | Freq match | Rolling frequency compare |
| Longest Repeating Char Replacement | Freq + Shrink | Maximize same characters |
| Subarray with Exactly K Distinct | Counting trick | Exactly(K) = AtMost(K) - AtMost(K-1) |
| K-size Window Median | Bi-Heap/Multiset | Competitive level |

---

### ➕ Pattern 4: Prefix & Suffix Computations
Pre-calculate values to answer queries efficiently in O(1) or O(n).

#### 🟢 Easy
- Find the Union of Two Sorted Arrays
- Find the Intersection of Two Sorted Arrays

#### 🟡 Medium
- Product of Array Except Self (No Division)
- Subarray Sum Equals K (Count)
- Largest Subarray with 0 Sum
- Longest Subarray with a Given Sum K

#### 🟠 Hard
- Count Number of Subarrays with Given XOR K
- Maximum Product Subarray

---

### 🔑 Pattern 5: Hashing (Frequency Counting)
Ideal for problems involving frequencies, duplicates, or O(1) lookups.

#### 🟢 Easy
- Check for Duplicate Elements
- Find the Most Frequent Element
- Two-Sum (Unsorted)
- Find the Missing Number [1, n]
- Find the Number that Appears Once

#### 🟡 Medium
- First Non-Repeating Element
- First Repeating Element
- Longest Consecutive Sequence
- Majority Element (> n/2)
- Majority Element II (> n/3)
- Top K Frequent Elements

---

### 🌗 Pattern 6: Partitioning & Sorting In-Place
Rearranging elements based on a condition without extra space.

#### 🟢 Easy
- Swap the First and Last Elements
- Segregate 0s and 1s
- Sort 0s and 1s without sort algorithm

#### 🟡 Medium
- Dutch National Flag Problem (0s, 1s, 2s)
- Partition Array Around a Pivot
- Find the Repeating and Missing Number

---

### 🔄 Pattern 7: Array Rotations & Rearrangements
Shifting or reordering elements in a specific sequence.

#### 🟢 Easy
- Left/Right Rotate an Array by One
- Left/Right Rotate an Array by K

#### 🟡 Medium
- Next Permutation
- Replace Every Element with Next Greatest
- Leaders in an Array

---

### ⚡ Pattern 8: Kadane's Algorithm & Variations
Dynamic programming approach for maximum contiguous subarrays.

#### 🟢 Easy
- Maximum Subarray Sum (Kadane's)

#### 🟡 Medium
- Print the Maximum Subarray Sum
- Maximum Product Subarray

---

### 🎯 Pattern 9: Binary Search on Arrays
O(log n) searching in sorted or partially sorted data.

#### 🟢 Easy
- Standard Binary Search
- Lower Bound / Upper Bound
- Search Insert Position
- Count Occurrences in Sorted Array
- First and Last Occurrence

#### 🟡 Medium
- Search in Rotated Sorted Array I & II
- Find Minimum in Rotated Sorted Array
- Find Peak Element
- Single Element in a Sorted Array

---

### 🏔️ Pattern 10: Binary Search on "Answer Space"
Perform binary search on the range of possible answers to find the optimal result.

#### 🟡 Medium
- Find Square Root of a Number
- Find Nth Root of a Number

#### 🟠 Hard
- Koko Eating Bananas
- Minimum Days for M Bouquets
- Capacity to Ship Packages in D Days
- Aggressive Cows
- Book Allocation / Split Array Largest Sum
- Median / Kth Element of Two Sorted Arrays

---

### 🧱 Pattern 11: Matrix (2D Array)
Extending array concepts to two dimensions.

#### 🟢 Easy
- Row with Maximum Number of 1s

#### 🟡 Medium
- Set Matrix Zeros
- Rotate Matrix by 90 Degrees
- Spiral Traversal of Matrix
- Search in a 2D Matrix (Sorted)
- Pascal's Triangle

---

### 🔮 Pattern 12: Advanced/Miscellaneous
Combining patterns or requiring unique algorithmic insights.

#### 🟡 Medium
- Stock Buy and Sell (Max Profit)
- Merge Overlapping Subintervals

#### 🟠 Hard
- Merge Two Sorted Arrays Without Extra Space
- Count Inversions
- Reverse Pairs
- Find the Duplicate Number [1, n]
