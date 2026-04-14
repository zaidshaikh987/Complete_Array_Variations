# 🧠 Pattern 3: Sliding Window
## "The Slinky or Accordion Move"

Sliding Window is like a frame that moves across your data. Sometimes it stays the same size, and sometimes it stretches or shrinks like an accordion to find exactly what you're looking for without starting over from scratch every time.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Am I dealing with a **Contiguous Subarray** or Substring?
- Is there a **Window** of size `K`?
- Do I need to find the **Longest**, **Shortest**, or **Optimal** segment?
- Can I "update" the result as I move by just adding one new element and removing one old one?

**Keywords:** "Subarray", "Substring", "Consecutive", "Maximum/Minimum sum of size K", "Longest window with condition".

---

### 💡 Key Points to Keep in Mind
1. **Fixed vs. Variable Window:** 
   - **Fixed:** Always size `K`. Just `add right, remove left`.
   - **Variable:** Size changes based on a condition (e.g., sum < K).
2. **The "Subtract-Add" Trick:** Instead of re-summing the window, just subtract the element that left and add the element that joined.
3. **The While Loop (Shrinking):** In variable windows, once the condition is broken, use a `while` loop to shrink the left side until it's valid again.
4. **Time Complexity:** **O(n)**. Even with a nested `while`, each pointer (left and right) only travels from `0` to `n-1` exactly once.

---

### 🏗️ Logic Builder: The Stretch & Shrink Process
1. **Expand (The Right Pointer):** Keep moving the `right` pointer to include new elements.
2. **Evaluate:** Is the current window valid? (e.g., `sum <= target`).
3. **Shrink (The Left Pointer):** If invalid, move the `left` pointer until the window becomes valid again.
4. **Record:** Update your `maxLen` or `minLen` at every valid step.

---

### 🚶 Dry Run: Longest Subarray with Sum ≤ 8
**Array:** `[3, 1, 2, 7, 4, 1, 1]` | **K:** 8

| Step | Right | left | window | sum | maxLen | *Intuition* |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 0 | [3] | 3 | 1 | 3 ≤ 8. Valid. |
| 2 | 1 | 0 | [3, 1] | 4 | 2 | 4 ≤ 8. Valid. |
| 3 | 2 | 0 | [3, 1, 2] | 6 | 3 | 6 ≤ 8. Valid. |
| 4 | 3 | 0 | [3, 1, 2, 7] | 13 | 3 | 13 > 8! **Shrink Left.** |
| 5 | 3 | 1 | [1, 2, 7] | 10 | 3 | 10 > 8! **Shrink Left.** |
| 6 | 3 | 2 | [2, 7] | 9 | 3 | 9 > 8! **Shrink Left.** |
| 7 | 3 | 3 | [7] | 7 | 3 | 7 ≤ 8. Finally! |
| 8 | 4 | 3 | [7, 4] | 11 | 3 | 11 > 8! **Shrink Left.** |
| 9 | 4 | 4 | [4] | 4 | 3 | 4 ≤ 8. Valid. |

---

### ❓ Answering the "Why This and That"

#### Q: Why is this better than the Brute Force $O(n^2)$?
**A:** Brute force recalculates the sum of every possible subarray. Sliding Window "reuses" the previous sum. It's like dragging a heavy box (window) instead of picking up and re-packing it at every step.

#### Q: Why do we use a `while` loop inside the `for` loop? Doesn't that make it $O(n^2)$?
**A:** No! Over the entire execution, the `left` pointer only moves forward. It never goes back. So, `right` moves `n` times and `left` moves at most `n` times. Total operations: $2n \approx O(n)$.

#### Q: When is Sliding Window NOT the answer?
**A:** If you have **negative numbers** and are looking for a specific sum. Negative numbers break the "shrink to reduce sum" logic. For those, you need **Prefix Sum + Hashing**.

---

> [!IMPORTANT]
> **Master Rule:** If it's **contiguous** and the condition is **monotonic** (adding elements only makes it more "broken" or more "valid"), use Sliding Window!
