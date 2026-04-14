# 🧠 Pattern 2: Two Pointers
## "Divide, Conquer, and Converge"

Two Pointers is like two friends standing at opposite ends of a street, walking towards each other to meet. By coordinating their steps, they can find specific locations (pairs or properties) much faster than one person checking every house one by one.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Is the array **Sorted** (or can it be sorted)?
- Am I looking for a **Pair** or **Triplet** with a specific sum/property?
- Do I need to **swap** elements from ends to middle (e.g., Reverse)?
- Am I trying to find a "target" by increasing/decreasing values proportionally?

**Keywords:** "Sorted array", "Pair sum", "Find target", "Reverse", "In-place", "Remove duplicates".

---

### 💡 Key Points to Keep in Mind
1. **The Starting Positions:**
   - **Opposite Ends:** `left = 0`, `right = n-1` (used for Sum, Reverse, Palindrome).
   - **Same Direction:** `slow = 0`, `fast = 0` (used for removing duplicates, finding cycles).
2. **The Sorted Advantage:** This pattern almost always depends on the array being sorted. If it's not sorted, you often sort it first (**O(n log n)** + **O(n)**).
3. **The Movement Logic:** 
   - If `currentSum < target`, we need a **larger** sum $\rightarrow$ `left++`.
   - If `currentSum > target`, we need a **smaller** sum $\rightarrow$ `right--`.
4. **Time Complexity:** Usually **O(n)** because each element is visited at most once by either pointer.
5. **Space Complexity:** **O(1)** as we only store two integer indices.

---

### 🏗️ Logic Builder: The 3-Step Process
1. **The Placement:** Set your pointers (usually `i = 0` and `j = n-1`).
2. **The Condition:** Start a `while (i < j)` loop.
3. **The Step:** 
   - Evaluate the current pointers.
   - If you found the answer, return it.
   - If not, decide which pointer to move based on the target comparison.

---

### 🚶 Dry Run: Finding Pair with Sum = 15
**Sorted Array:** `[1, 4, 6, 8, 10, 12]` | **Target:** 15

| Step | i (0) | j (n-1) | arr[i] | arr[j] | Sum | Action | *Why?* |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 5 | 1 | 12 | 13 | `i++` | 13 < 15. We need more weight. Move the left pointer up. |
| 2 | 1 | 5 | 4 | 12 | 16 | `j--` | 16 > 15. Too heavy. Move the right pointer down. |
| 3 | 1 | 4 | 4 | 10 | 14 | `i++` | 14 < 15. Still too light. Move left up. |
| 4 | 2 | 4 | 6 | 10 | 16 | `j--` | 16 > 15. Too heavy. Move right down. |
| 5 | 2 | 3 | 6 | 8 | 14 | `i++` | 14 < 15. Move left up. |
| 6 | 3 | 3 | - | - | - | **End** | `i` is no longer `< j`. No pair found. |

---

### ❓ Answering the "Why This and That"

#### Q: Why can't we just use a nested loop ($O(n^2)$)?
**A:** You can! But if an array has 100,000 elements, $n^2$ is 10 billion operations (slow). Two Pointers is 100,000 operations (instant). 

#### Q: Why does this only work on Sorted Arrays for Sum problems?
**A:** If the array is unsorted, moving `i++` doesn't guarantee the sum will increase. In a sorted array, we **know** `arr[i+1] >= arr[i]`, giving us predictable control over the sum.

#### Q: What if I have to find a Triplet (a + b + c = K)?
**A:** Fix one element `a` using a simple loop, then use **Two Pointers** on the remaining part of the array to find `b + c = K - a`. This turns an $O(n^3)$ problem into $O(n^2)$.

---

> [!IMPORTANT]
> **Master Rule:** If you see "Sorted" and "Pair", your brain should immediately scream "Two Pointers!".
