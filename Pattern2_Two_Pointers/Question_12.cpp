// - Remove Duplicates from a Sorted Array

// Pattern 0 : Two Pointers (Read & Write / Overwrite Technique)

int removeDuplicates(vector<int>& arr) {

    // If array is empty, no unique elements
    if (arr.size() == 0) {
        return 0;
    }

    int write = 0;   // Index of last unique element

    // Start reading from second element
    for (int read = 1; read < arr.size(); read++) {

        // If current element is different from last unique one
        if (arr[read] != arr[write]) {
            write++;                     // Move write position
            arr[write] = arr[read];     // Overwrite with new unique value
        }
    }

    // Number of unique elements
    return write + 1;
}
