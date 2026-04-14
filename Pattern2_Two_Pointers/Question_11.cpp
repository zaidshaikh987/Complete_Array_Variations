// - Sort Array by Parity (Segregate Even and Odd Numbers)

// Pattern 1 : Two Pointers ( Opposite ends + Swapping)

void sortArrayByParity(vector<int>& arr) {
    int left = 0;                      // Pointer starting from left
    int right = arr.size() - 1;        // Pointer starting from right

    while (left < right) {

        // If current left element is even, it's correctly placed
        if (arr[left] % 2 == 0) {
            left++;
        }
        // If current right element is odd, it's correctly placed
        else if (arr[right] % 2 != 0) {
            right--;
        }
        // Left has odd and right has even → wrong places
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;                   // Both positions fixed
            right--;
        }
    }
}
