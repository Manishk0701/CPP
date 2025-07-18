#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int findPeakElement(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        int left = (mid > 0) ? arr[mid - 1] : INT_MIN;
        int right = (mid < arr.size() - 1) ? arr[mid + 1] : INT_MIN;

        if (arr[mid] >= left && arr[mid] >= right) {
            return mid; // Found peak
        } else if (arr[mid] < right) {
            low = mid + 1; // Move to right half
        } else {
            high = mid - 1; // Move to left half
        }
    }
    return -1; // Should not happen for valid input
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    int peakIndex = findPeakElement(arr);

    // Validate if it's a peak
    int left = (peakIndex > 0) ? arr[peakIndex - 1] : INT_MIN;
    int right = (peakIndex < arr.size() - 1) ? arr[peakIndex + 1] : INT_MIN;

    bool isPeak = arr[peakIndex] >= left && arr[peakIndex] >= right;

    cout << (isPeak ? "true" : "false") << endl; // Expected: true
    return 0;
}
