# 🧠 Pattern 11: Matrix (2D Array) Problems
## "The Array of Arrays"

A Matrix is like a city grid of apartments. To find someone, you don't just need a door number; you need a **Street** (Row) and a **Cross-Street** (Column). Matrix problems are just 1D array problems applied twice, often requiring you to think about boundaries and coordinate geometry `(i, j)`.

---

### 🔍 How to Recognize This Pattern?
Ask yourself:
- Is the data organized in **Rows and Columns**?
- Am I visiting every cell?
- Do I need to search in a grid that is **Sorted** by row/column?
- Am I rotating, mirroring, or traversing the grid in a specific shape (like a **Spiral**)?

**Keywords:** "2D Array", "Spiral order", "Rotate 90 degrees", "Row with maximum 1s", "Search in Matrix", "Set Zeros".

---

### 💡 Key Points to Keep in Mind
1. **Coordinate Mapping:** Element `at index i` in a flattened version of an `N x M` matrix is at `matrix[i / M][i % M]`. 
2. **Boundary Management:** In Spiral or Diagonal traversal, the most important task is tracking four variables: `top`, `bottom`, `left`, and `right`.
3. **The Staircase Search:** In a matrix sorted by both rows and columns, you can search in **O(R + C)** time by starting at the top-right corner and moving like a staircase.
4. **In-Place Matrix Tricks:** Rotating a matrix in-place usually involves **Transposing** (swapping across the diagonal) and then **Reversing** rows.

---

### 🏗️ Logic Builder: The Cell-by-Cell Processing
1. **Nested Loops:** The default tool for visiting every cell: `for (i to rows) { for (j to cols) { ... } }`.
2. **Boundary Checks:** Always ensure `row >= 0 && row < totalRows` and `col >= 0 && col < totalCols` before accessing `matrix[row][col]`.
3. **State Tracking:** Some problems (like "Set Matrix Zeros") require you to track which rows/cols to update. To save space, try to use the **first row and first column** as markers.

---

### 🚶 Dry Run: Spiral Traversal
**Matrix:**
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
```
**Pointers:** `top=0, bottom=2, left=0, right=2`

| Step | Direction | Range | Result | New Boundary |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Right | col: 0 to 2 | 1, 2, 3 | `top` becomes 1 |
| 2 | Down | row: 1 to 2 | 6, 9 | `right` becomes 1 |
| 3 | Left | col: 1 down to 0 | 8, 7 | `bottom` becomes 1 |
| 4 | Up | row: 1 down to 1 | 4 | `left` becomes 1 |
| 5 | Right | col: 1 to 1 | 5 | `top` becomes 2 |
| **End** | - | `top > bottom` | **Done** | - |

**Result:** `1, 2, 3, 6, 9, 8, 7, 4, 5` ✅

---

### ❓ Answering the "Why This and That"

#### Q: Why not just flatten the matrix into a 1D array?
**A:** You can for searching, but many problems (like "Spiral Order" or "Rotate") depend on the 2D relationship of elements. Flattening destroys that structure and might make the logic harder.

#### Q: How is Matrix Binary Search different?
**A:** If each row is sorted and the first element of a row is greater than the last of the previous, you can treat it as one long **Virtual 1D Array**. If not, you use the "Staircase Search" starting from the corner.

#### Q: Why use the first row/col as markers?
**A:** Because it saves $O(N + M)$ extra space. It’s an advanced optimization where you use the array's own data to store its metadata.

---

> [!IMPORTANT]
> **Master Rule:** For Matrix problems, draw the grid on paper! Visualizing the index movements `(i, j)` is 90% of the battle.
