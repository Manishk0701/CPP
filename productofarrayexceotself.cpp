#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0), prefix(n, 1), suffix(n, 1);

    // Calculate prefix products
    prefix[0] = 1; // first element of prefix is 1
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    //value of prefix[i] is the product of all elements to the left of i
    // value = 1*2*3*4=24
    // value = 1*2*3=6
    // value = 1*2 = 2
    // value = 1=1

    // Calculate suffix products
    suffix[n - 1] = 1;  // last element of suffix is 1
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    //value of suffix[i] is the product of all elements to the right of i
    // value = 2*3*4*1=24
    // value = 3*4*1=12
    // value = 4*1 = 4
    // value = 1=1

    // Calculate result by multiplying prefix and suffix products
    for (int i = 0; i < n; i++) {
        result[i] = prefix[i] * suffix[i];
    }
    // value = prefix[i] * suffix[i]
    // value = 1*4=4
    // value = 2*3=6
    // value = 6*2=12
    // value = 24*1=24



    return result;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}