#include<iostream>
#include<vector>
using namespace std;
// Time complexity: O(n)
// Space complexity: O(1)
// Moore's Voting Algorithm
// 1. Initialize ans=0 and freq=0
// 2. Traverse through the array
// 3. If freq=0 then assign ans=nums[i]
// 4. If ans=nums[i] then increment freq
// 5. Else decrement freq
// 6. Return ans

int majorityElement(vector<int>&nums){
    int n=nums.size();
    int freq=0;
    int ans=0;

    for(int i=0;i<n;i++ ){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}
int main(){
    vector<int>nums={2,2,2,2,2,1,1,1,1};

    cout<<majorityElement(nums)<<endl;
    return 0;


};