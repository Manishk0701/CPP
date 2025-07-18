#include<iostream>
#include<vector>
using namespace std;
// time complexity: O(n^2)
// space complexity: O(1)
// Bruteforce approach
// 1. Traverse through the array
// 2. For each element, traverse through the array
// 3. If the frequency of the element is greater than n/2, return the element
// 4. Else return -1
// 5. Return -1


int majorityElement(vector<int>& nums) {
    int n = nums.size();

    for (int val:nums) {
        int freq=0;

        for(int el : nums){
            if ( el == val){
                freq++;
            }
        }
        if( freq > n/2 ){
            return val;
        }
    }
    return -1;

    }
int main(){
    vector<int>nums={2,2,2,1,1,1,1};

    cout<<majorityElement(nums)<<endl;
    return 0;


};