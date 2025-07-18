#include<iostream>
using namespace std;
// time complexity: O(n)
// space complexity: O(1)
int singlenumber(int nums[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int nums[n]; // Create an array of size n
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int single = singlenumber(nums, n);
    cout << "The single number is: " << single << endl;

    return 0;
}