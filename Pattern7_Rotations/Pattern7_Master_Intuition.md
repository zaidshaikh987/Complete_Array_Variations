# 🧠 Pattern 7: Array Rotations & Rearrangements
## "The Array Carousel"

Array Rotation and Rearrangement is like shifting chairs in a circle. Each chair (element) has a new destination, and the challenge is to move everyone to their correct spot without making a mess or using an entire second room (extra space).

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Am I shifting the array by a distance `K` (**Rotation**)?
- Do I need the "alphabetical" next version of the array (**Next Permutation**)?
- Am I reordering elements based on their neighbors' properties (e.g., **Leaders**)?
- Is the goal to "recycle" the same array space?

**Keywords:** "Rotate left/right", "K positions", "Next permutation", "Rearrange", "Shifting".

---

### 💡 Key Points to Keep in Mind
1. **The Modulo Trick:** If you rotate an array of size `N` by `K` positions, rotating it `N` times brings it back to the start. So, always use `K = K % N`.
2. **The 3-Reversal Triple Threat:** To rotate an array by `K` without extra space:
   - Reverse the first part.
   - Reverse the second part.
   - Reverse the whole thing.
3. **Circular Indexes:** `(currentIdx + K) % N` gives you the new position in a circular shift.
4. **Space Constraint:** Many rearrangement problems are trivial with $O(n)$ space. The Real Challenge is doing it in **O(1) space**.

---

### 🏗️ Logic Builder: The Rotation Reversal Logic
1. **The Setup:** Calculate `K = K % N`.
2. **The Reversal:** 
   - Reverse `arr[0...N-K-1]`.
   - Reverse `arr[N-K...N-1]`.
   - Reverse `arr[0...N-1]`.
3. **The Result:** Your array is now shifted right by `K`!

---

### 🚶 Dry Run: Rotating `[1, 2, 3, 4, 5]` Right by `K=2`
1. **Calculate K:** `2 % 5 = 2`.
2. **Part 1 (0 to 2):** Reverse `[1, 2, 3]` $\rightarrow$ `[3, 2, 1, 4, 5]`.
3. **Part 2 (3 to 4):** Reverse `[4, 5]` $\rightarrow$ `[3, 2, 1, 5, 4]`.
4. **Whole Array:** Reverse `[3, 2, 1, 5, 4]` $\rightarrow$ `[4, 5, 1, 2, 3]`.

**Final:** `[4, 5, 1, 2, 3]` (Correct shifted version!) ✅

---

### ❓ Answering the "Why This and That"

#### Q: Why use the Reversal Trick instead of shifting one by one?
**A:** Shifting one by one `K` times takes $O(K \times N)$ time. For large $K$ and $N$, this is extremely slow. The Reversal method takes exactly $O(N)$ time, always. It's the most efficient way to rotate.

#### Q: How does "Next Permutation" work?
**A:** It’s a "Rearrangement" problem. You find the first "dip" from the right, swap it with the smallest larger number on its right, and then sort (reverse) the rest to get the absolute next lexicographical version. It’s like finding the next number in a dictionary.

#### Q: What if I have to rotate a Matrix?
**A:** A Matrix is just a 2D array. Shifting it usually involves **Transposing** (swapping rows and columns) and then **Reversing** rows. It’s the same "rearrangement" intuition but with two dimensions!

---

> [!IMPORTANT]
> **Master Rule:** For linear shifts, remember the **Reversal Trick**. For logical reordering, try to find a mathematical pattern in the indices!
