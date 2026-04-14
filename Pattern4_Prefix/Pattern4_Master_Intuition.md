# 🧠 Pattern 4: Prefix & Suffix Computations
## "The Cumulative Scorekeeper"

Prefix/Suffix computation is like keeping a rolling total while shopping. You don't need to re-add everything in your cart to find the total; you just look at your "running total" and add the next item. It allows you to "see" the history or future of the array at any point in $O(1)$.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Do I need to perform **multiple queries** on ranges?
- Am I looking for a **Subarray Sum**?
- Does the answer at index `i` depend on **all elements before it** (Prefix) or **all elements after it** (Suffix)?
- Can I pre-calculate a property to avoid a nested loop?

**Keywords:** "Range Sum Query", "Product except self", "Total sum until i", "Subarray sum equals K", "Equilibrium index".

---

### 💡 Key Points to Keep in Mind
1. **The Difference Trick:** `sum(L, R) = prefixSum[R] - prefixSum[L-1]`. This turns an $O(n)$ search into an $O(1)$ lookup!
2. **Handle Index 0:** Often you need a dummy `0` at `prefixSum[0]` to handle ranges starting from the very first element.
3. **Space vs. Time:** You use $O(n)$ extra space to store the prefix array, but you save massive time on queries.
4. **Don't Forget Suffix:** Some problems (like "Product except self") require processing from right-to-left as well.

---

### 🏗️ Logic Builder: The Precomputation Process
1. **The Array Setup:** Create `prefix[n+1]` or update in-place.
2. **The Forward Pass:** `prefix[i] = prefix[i-1] + arr[i]`.
3. **The Application:** Use the precomputed values to answer a specific question (e.g., `if (prefixSum[i] == target)`).

---

### 🚶 Dry Run: Range Sum Queries
**Array:** `[10, 20, 30, 5, 15]` | **Queries:** Sum of indices [1, 3] and [0, 2]

**Prefix Array Creation:**
| Index | 0 | 1 | 2 | 3 | 4 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| arr | 10 | 20 | 30 | 5 | 15 |
| **prefix** | **10** | **30** | **60** | **65** | **80** |

**Query 1: [1, 3]**
Formula: `prefix[3] - prefix[0]` (subtract the part before index 1)
Calculation: `65 - 10 = 55`.
*Check: 20 + 30 + 5 = 55.* ✅

**Query 2: [0, 2]**
Formula: `prefix[2]` (Nothing before index 0 to subtract)
Calculation: `60`.
*Check: 10 + 20 + 30 = 60.* ✅

---

### ❓ Answering the "Why This and That"

#### Q: Why use Prefix Sum when I can just use a loop for the range?
**A:** If you have **one** query, a loop is fine. But if you have **1,000,000 queries**, the loop method is $O(Q \times N)$, while Prefix Sum is $O(N + Q)$. For large $Q$, Prefix Sum is millions of times faster.

#### Q: How is this different from Sliding Window?
**A:** Sliding window works when the window moves (dynamic). Prefix Sum works when you need to "snap" a total for any arbitrary range at any time (static or precomputed).

#### Q: Why does the "Product Except Self" use both Prefix and Suffix?
**A:** Because for index `i`, you need the product of everything to its **left** AND everything to its **right**. A single pass can only give you one side. By using both, you get the full picture without $O(n^2)$.

---

> [!IMPORTANT]
> **Master Rule:** If you see "Range Sum" or "Subarray Sum" queries, **prefix sum** should be your first thought!
