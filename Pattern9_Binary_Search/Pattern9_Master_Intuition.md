# 🧠 Pattern 9: Binary Search on Arrays
## "Divide and Conquer the Sorted World"

Binary Search is like looking for a word in a physical dictionary. You don't start at page 1. You open it in the middle, see if your word is earlier or later, and throw away half of the books you don't need. You repeat this until you land on the exact page.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Is the input array **Sorted** (or can it be treated as sorted)?
- Am I looking for a single element, a boundary, or a transition point?
- Is the required time complexity **O(log n)**?
- Can I decide, after looking at the middle element, that my answer **cannot** be in one half?

**Keywords:** "Find in sorted", "Rotated sorted array", "Find mountain peak", "First and last occurrence", "Search insert position".

---

### 💡 Key Points to Keep in Mind
1. **The Range:** You need two boundaries—`low` and `high`.
2. **The Mid-Point:** Use `mid = low + (high - low) / 2` to avoid integer overflow (don't use `(low+high)/2`).
3. **The Elimination:** The logic is always about deciding which half to **discard**.
4. **Loop Exit:** Usually `while (low <= high)`, but sometimes `while (low < high)` for finding boundaries or peak elements.
5. **Efficiency:** For 1 billion elements, Linear Search takes 1 billion steps. Binary Search takes only **30**!

---

### 🏗️ Logic Builder: The Half-Discard Process
1. **Initialization:** `low = 0`, `high = n - 1`.
2. **The Midpoint:** `mid = low + (high - low) / 2`.
3. **The Comparison:** 
   - If `arr[mid] == target`, return `mid`.
   - If `arr[mid] < target`, move to the right half: `low = mid + 1`.
   - If `arr[mid] > target`, move to the left half: `high = mid - 1`.
4. **The "Check":** If `low > high`, the element doesn't exist.

---

### 🚶 Dry Run: Finding `target = 9` in `[-1, 0, 3, 5, 9, 12]`
**Initial:** `low = 0`, `high = 5`

| Step | low | high | mid | arr[mid] | Comparison | *Intuition* |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 5 | 2 | 3 | 3 < 9 | Target is larger. Throw away left half. `low = 3`. |
| 2 | 3 | 5 | 4 | 9 | 9 == 9 | **FOUND!** |

**Result:** index 4.

---

### ❓ Answering the "Why This and That"

#### Q: Why does this work in a "Rotated" sorted array?
**A:** In a rotated sorted array (e.g., `[4, 5, 6, 7, 0, 1, 2]`), at least one half of the array is **always** perfectly sorted. You check which half is sorted, and then check if the target lies within that sorted range. If not, it MUST be in the other half. It’s the same "discard half" logic with an extra check.

#### Q: How do I find the "First Occurrence" of a number?
**A:** When you find `arr[mid] == target`, instead of stopping, you record the answer and keep searching the **left** side (`high = mid - 1`) to see if there's an even earlier version. 

#### Q: When does Binary Search fail?
**A:** When the array is unsorted and there's no "monotonic" property (meaning looking at the middle doesn't tell you anything about the halves).

---

> [!IMPORTANT]
> **Master Rule:** If you see any version of "Sorted" or "Searching" in $O(\log n)$, your brain should immediately think **Binary Search**!
