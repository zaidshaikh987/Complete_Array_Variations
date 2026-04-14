# 🧠 Pattern 6: Partitioning & Sorting In-Place
## "The Master Organizer"

Partitioning is like Sorting Bins. You have a pile of objects (numbers) and you need to put them in specific containers (left, middle, right) based on their properties (0s, 1s, 2s) without creating new piles. It’s all about swapping things until the chaos becomes order.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Do I need to group elements by a **condition** (e.g., even/odd, pos/neg)?
- Is the constraint **O(1) Extra Space**?
- Does the problem involve a **Pivot** (like Quicksort)?
- Are the values limited to a small, known set (e.g., 0, 1, and 2)?

**Keywords:** "In-place", "Segregate", "Dutch National Flag", "Three-way partitioning", "Move to front/end", "Pivot".

---

### 💡 Key Points to Keep in Mind
1. **The Swap Strategy:** Since we can't use extra space, our primary tool is the `swap(arr[i], arr[j])`.
2. **Standard 2-Pointer Partition:** 
   - `left` index for "valid" elements.
   - `right` index for "unknown" or "invalid" elements.
3. **Dutch National Flag (3-Pointer):** 
   - `low` (boundary for 0s).
   - `mid` (the scanner).
   - `high` (boundary for 2s).
4. **Stable vs. Unstable:** Partitioning usually doesn't preserve the relative order of equal elements (unstable). If that's needed, you often need extra space.

---

### 🏗️ Logic Builder: The Scan-and-Swap Process
1. **The Boundary Setup:** Set pointers for your different categories (e.g., `zeroIdx`, `twoIdx`).
2. **The Scanner:** Use a loop (often `mid`) to traverse the array.
3. **The Logic:**
   - If current element belongs to the "Front": Swap with `low` boundary and move both pointers.
   - If current element belongs to the "End": Swap with `high` boundary and move ONLY the `high` boundary (re-scan the swapped element).
   - If current element is "Middle": Just move the scanner.

---

### 🚶 Dry Run: Segregating 0s, 1s, and 2s (DNF)
**Array:** `[2, 0, 2, 1, 1, 0]`

| Step | low | mid | high | arr[mid] | Action | Resulting Array |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 0 | 5 | 2 | Swap mid, high. `high--` | `[0, 0, 2, 1, 1, 2]` |
| 2 | 0 | 0 | 4 | 0 | Swap mid, low. `low++, mid++` | `[0, 0, 2, 1, 1, 2]` |
| 3 | 1 | 1 | 4 | 0 | Swap mid, low. `low++, mid++` | `[0, 0, 2, 1, 1, 2]` |
| 4 | 2 | 2 | 4 | 2 | Swap mid, high. `high--` | `[0, 0, 1, 1, 2, 2]` |
| 5 | 2 | 2 | 3 | 1 | `mid++` | `[0, 0, 1, 1, 2, 2]` |
| 6 | 2 | 3 | 3 | 1 | `mid++` | **DONE!** |

---

### ❓ Answering the "Why This and That"

#### Q: Why can't I just sort the array?
**A:** Sorting is $O(n \log n)$. Partitioning specific values like 0s, 1s, and 2s can be done in **O(n)** time. For large datasets, this is a massive optimization.

#### Q: Why don't we increment `mid` when we swap with `high`?
**A:** Because the element we swapped from the `high` position is an "unknown". We haven't scanned it yet! We need to look at it in the next iteration to decide where it belongs.

#### Q: What if I have more than 3 categories?
**A:** 3-Way Partitioning is the limit for simple pointer-based in-place sorting. For more categories, you usually end up doing multiple passes or using Hashing.

---

> [!IMPORTANT]
> **Master Rule:** If you need to reorder an array based on **value categories** without using extra memory, think **In-Place Partitioning**!
