// Count Pairs with Given Sum (sorted array)

// Pattern 2 : Two Pointers ( Same Direction – Comparison + Duplicate Handling)

int countPairsWithSum(vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size() - 1;
    int count = 0;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum < k) {
            left++;
        }
        else if (sum > k) {
            right--;
        }
        else {
            if (arr[left] != arr[right]) {

                int leftValue = arr[left];
                int rightValue = arr[right];

                int leftCount = 0;
                int rightCount = 0;

                while (left < right && arr[left] == leftValue) {
                    leftCount++;
                    left++;
                }

                while (right >= left && arr[right] == rightValue) {
                    rightCount++;
                    right--;
                }

                count += leftCount * rightCount;
            }
            else {
                int totalElements = right - left + 1;
                count += (totalElements * (totalElements - 1)) / 2;
                break;
            }
        }
    }

    return count;
}
