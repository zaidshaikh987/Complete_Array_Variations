// -  - Segregate 0s and 1s

// Pattern 1 : Two Pointers ( Opposite ends + Swapping)

void segregateZeroOne(vector<int>& arr) {
    int left = 0;                      // Pointer for left side
    int right = arr.size() - 1;        // Pointer for right side

    while (left < right) {

        // Left pointer is fine if it is already 0
        if (arr[left] == 0) {
            left++;
        }
        // Right pointer is fine if it is already 1
        else if (arr[right] == 1) {
            right--;
        }
        // Left has 1 and right has 0 → wrong places
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;                   // Both positions fixed
            right--;
        }
    }
}


