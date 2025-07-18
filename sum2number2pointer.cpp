#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> Sum2number(vector<int>& arr, int target) {
    int l = 0; 
    int r = arr.size() - 1; 

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) {
            return {l, r}; 
        } else if (sum < target) {
            l++; // Move the left pointer to the right
        } else {
            r--; // Move the right pointer to the left
        }
    }

    return {-1, -1}; // Return -1, -1 if no such pair is found
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target: ";
    int target;
    cin >> target;

    // Sort the array (required for the two-pointer technique)
    sort(arr.begin(), arr.end());

    pair<int, int> result = Sum2number(arr, target);
    if (result.first != -1) {
        cout << "Indexes " << result.first << " and " << result.second << endl;
    } else {
        cout << "No such pair exists." << endl;
    }

    return 0;
}