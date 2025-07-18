#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1; // Target is in the left half
            } else {
                left = mid + 1; // Target is in the right half
            }
        }
        // Otherwise, the right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
    }

    return -1; //
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int target = 0; // Element to be searched

    cout << search(nums, target) << endl; // Output: 4
    return 0;
}