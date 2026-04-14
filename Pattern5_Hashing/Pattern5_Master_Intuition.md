# 🧠 Pattern 5: Hashing (Frequency Counting)
## "The Instant Lookup Desk"

Hashing is like a massive locker room. Instead of searching every locker for your bag, you have a receipt with the exact locker number. You walk straight to it. In coding, Hashing turns **"searching for something"** from a long walk ($O(n)$) into a single step ($O(1)$).

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Do I need to count how many times each element appears (**Frequency**)?
- Am I checking if an element has been **seen before** (**Duplicates**)?
- Do I need to find a pair where `arr[i] + x = target`?
- Am I mapping one value to another (e.g., Anagrams)?

**Keywords:** "Count unique", "Frequency", "Most frequent", "Subarray with sum 0", "First repeating", "Two Sum (Unsorted)".

---

### 💡 Key Points to Keep in Mind
1. **Time vs. Space Trade-off:** Hashing is the ultimate time-saver. You spend extra memory ($O(n)$ space) to gain incredible speed ($O(1)$ average time).
2. **Frequency Map vs. Seen Set:** 
   - Use a **Map** (`unordered_map<int, int>`) if you need to count occurrences.
   - Use a **Set** (`unordered_set<int>`) if you just need to know if something exists.
3. **The Target Difference:** In problems like "Two Sum", as you visit `x`, you look for `target - x` in the hash map.
4. **Collision Reality:** In high-level languages like C++, `unordered_map` handles collisions for you, but remember that the "average" time is $O(1)$, while "worst-case" (rare) can be $O(n)$.

---

### 🏗️ Logic Builder: The Map-and-Search Process
1. **The Choice:** Decide if you need a Map or a Set.
2. **The Traversal:** Loop through the array.
3. **The Action:** 
   - Check if the "complement" or the "answer" is already in the hash.
   - If found, you're done!
   - If not, add the current element to the hash and move on.

---

### 🚶 Dry Run: Finding the First Repeating Element
**Array:** `[6, 10, 5, 4, 9, 120, 4, 6, 10]`

| Step | Current Element | Hash Set (Seen) | Action | *Intuition* |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 6 | {6} | Add | New element. Keep going. |
| 2 | 10 | {6, 10} | Add | New element. Keep going. |
| 3 | 5 | {6, 10, 5} | Add | New element. Keep going. |
| 4 | 4 | {6, 10, 5, 4} | Add | New element. Keep going. |
| 5 | 9 | {6, 10, 5, 4, 9} | Add | New element. Keep going. |
| 6 | 120 | {6, 10, 5, ..., 120} | Add | New element. |
| 7 | **4** | {6, 10, 5, 4, ...} | **FOUND!** | **4** was already in our "Seen" list. Stop! |

**Result:** 4 is the first element to repeat as we scan left-to-right.

---

### ❓ Answering the "Why This and That"

#### Q: Why not just use two loops $O(n^2)$ to find duplicates?
**A:** Because for an array of size 1,000,000, $n^2$ is 1 trillion operations. Hashing does it in 1 million operations. It’s the difference between waiting weeks and waiting milliseconds.

#### Q: When should I NOT use Hashing?
**A:** If memory is extremely tight (e.g., embedded systems) or if the range of numbers is small and positive—in which case, a simple **frequency array** (using indices as keys) is even faster and more memory-efficient.

#### Q: Why is `unordered_map` faster than `map` in C++?
**A:** `unordered_map` uses **Hash Tables** ($O(1)$ search), while `map` uses **Red-Black Trees** ($O(\log n)$ search). Unless you need the keys to be sorted, always pick `unordered_map`.

---

> [!IMPORTANT]
> **Master Rule:** If the question involves "Counting", "Existence", or "Duplicates", your first weapon should be **Hashing**!
