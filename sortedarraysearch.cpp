// 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4



#include <bits/stdc++.h>
using namespace std;

int rotatedarray(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if the target is found
        if (arr[mid] == target)
            return mid;

        // Check if the left half is sorted
        if (arr[start] <= arr[mid]) {
            if (arr[start] <= target && target <= arr[mid]) {
                end = mid - 1; // Target is in the left half
            } else {
                start = mid + 1; // Target is in the right half
            }
        } else {
            // Right half is sorted
            if (arr[mid] <= target && target <= arr[end]) {
                start = mid + 1; // Target is in the right half
            } else {
                end = mid - 1; // Target is in the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    int result = rotatedarray(arr, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}