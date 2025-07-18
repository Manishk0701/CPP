#include<iostream>
#include<vector>
using namespace std;

// time complexity: O(n)
// space complexity: O(1)

// Kadane's Algorithm
// 1. Initialize maxSum and currentSum to the first element of the array
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();
    
    int maxSum = maxSubArray(nums);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}