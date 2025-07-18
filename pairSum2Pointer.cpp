#include<iostream>
#include<vector>
using namespace std;



// 2pointer approach
// Time complexity: O(n)
// start from 0 and end from n-1
// if sum of start and end is greater than target then decrement end
// if sum of start and end is less than target then increment start
// if sum of start and end is equal to target then return start and end



vector<int>pairSum(vector<int>nums,int target) {
    vector<int>result;
    int n=nums.size();

    int i = 0;int j = n-1;

    while(i<j){
        int pairSum=nums[i]+nums[j];
        if (pairSum>target){
            j--;
        }
        else if(pairSum<target){
            i++;
        }
        else{
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}
int main(){
    vector<int>nums={2,5,11,17,21};
    int target=28;

    vector<int>result=pairSum(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    cout<<target<<endl;

    return 0;
};
