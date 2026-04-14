//  - Reverse an Array

// Pattern 1 : Two Pointers ( Opposite ends + Swapping)

void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}



/*
Swap / partition        → Opposite ends
Sum / difference        → Same direction
Count with duplicates   → Same direction + bulk count
Optimize (min/max)      → Opposite ends, never stop early
Remove / compress       → Read–Write
Transform + reorder     → Opposite ends + merge
*/


/*
STEP 1️⃣: Ask ONLY this question first
❓ “What am I trying to DO?”

There are only 4 possible answers in array problems:

What the problem wants	Category
Just check something	Validation
Find if something exists	Matching
Count how many	Counting
Find best / max / min	Optimization
*/

/*opposite-end two pointers require sorted order.*/

/*Two pointers need monotonic behavior.
Unsorted arrays do not have it.*/

/*When a sorted array allows predictable increase/decrease of a difference, use same-direction two pointers and stop on match.*/