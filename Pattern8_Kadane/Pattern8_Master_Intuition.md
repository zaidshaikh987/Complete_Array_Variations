# 🧠 Pattern 8: Kadane’s Algorithm & Variations
## "The Reset Button"

Kadane’s is like trying to find the most profitable stretch of days in a stock market. You keep building your wealth (sum), but the moment your current "streak" becomes a net loss (negative), you immediately hit the **RESET** button and start a fresh streak from the next day.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Am I looking for a **Contiguous Subarray** (not just a subsequence)?
- Is the goal to **Maximize or Minimize a Sum**?
- Does the array contain **negative numbers**? (If all are positive, the answer is just the total sum!)

**Keywords:** "Maximum Subarray Sum", "Largest Sum Subarray", "Contiguous sum", "Max absolute sum".

---

### 💡 Key Points to Keep in Mind
1. **The Core Logic:** `currentSum = max(arr[i], currentSum + arr[i])`. This effectively says: "Should I add this to my current streak, or is this element better off starting its own streak?"
2. **The Global Max:** You need a second variable (`maxSoFar`) to remember the best "peak" you ever visited, because the current streak might drop later.
3. **The All-Negative Edge Case:** If all numbers are negative, the maximum sum is simply the largest (least negative) single element.
4. **Variations:** You can modify Kadane’s to find the **Minimum Subarray Sum** or the **Maximum Product Subarray** (though product needs tracking of both min and max because `neg * neg = pos`).

---

### 🏗️ Logic Builder: The Streak-and-Reset Process
1. **The Setup:** `currentSum = 0`, `maxSoFar = INT_MIN`.
2. **The Journey:** Loop through every element `x` of the array.
3. **The Streak:** `currentSum += x`.
4. **The Comparison:** Update `maxSoFar = max(maxSoFar, currentSum)`.
5. **The Reset:** If `currentSum < 0`, set `currentSum = 0`. (A negative prefix is a "dead weight" for any future subarray).

---

### 🚶 Dry Run: Finding Max Subarray Sum
**Array:** `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| Step | x | currentSum | maxSoFar | Action | *Intuition* |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | -2 | -2 $\rightarrow$ 0 | -2 | **Reset** | Loss at start. Reset to 0. |
| 2 | 1 | 1 | 1 | Update Max | 1 is a good start. |
| 3 | -3 | -2 $\rightarrow$ 0 | 1 | **Reset** | 1 - 3 = -2. Streak died. |
| 4 | 4 | 4 | 4 | Update Max | New streak starts at 4. |
| 5 | -1 | 3 | 4 | - | 4 - 1 = 3. Still positive, keep it. |
| 6 | 2 | 5 | 5 | Update Max | 3 + 2 = 5. New Peak! |
| 7 | 1 | 6 | 6 | Update Max | 5 + 1 = 6. Another Peak! |
| 8 | -5 | 1 | 6 | - | Still positive (1), keep it. |
| 9 | 4 | 5 | 6 | - | Sum is 5, but max remains 6. |

**Result:** 6

---

### ❓ Answering the "Why This and That"

#### Q: Why do we reset to 0 if the sum becomes negative?
**A:** Because any subarray starting after a "negative sum block" will always be *smaller* if it includes that block. It's better to start fresh with a sum of 0 than to carry over a negative debt.

#### Q: Can I use this for non-contiguous subsequences?
**A:** No! For non-contiguous, you’d just pick every positive number. Kadane’s is specifically for **contiguous** stretches.

#### Q: Does Kadane's work for 2D Matrices?
**A:** Yes! It’s used in a advanced way to find the "Maximum Sum Submatrix" by compressing rows and applying 1D Kadane's on the resulting columns.

---

> [!IMPORTANT]
> **Master Rule:** If you see "Maximum Contiguous Subarray Sum", don't blink—immediately reach for **Kadane's Algorithm**!
