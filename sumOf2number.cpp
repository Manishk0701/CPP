#include <iostream>
#include <vector>
using namespace std;

pair<int, int> Sum2number(vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return {i, j}; 
            }
        }
    }
    return {-1, -1};

};

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

    pair<int, int> result = Sum2number(arr, target);
    if (result.first != -1) {
        cout << result.first << " and " << result.second << endl;
    } else {
        cout << "No such pair exists." << endl;
    }

    return 0;
}