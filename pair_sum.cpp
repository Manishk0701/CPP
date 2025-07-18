// by Bruteforce approach
// Time complexity: O(n^2)
// 



#include<iostream>
#include<vector>
using namespace std;

vector<int>pairSum(vector<int>nums,int target) {
    vector<int>result;
    int n=nums.size();
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;   
}

int main(){
    vector<int>nums={2,5,11,17,21};
    int target=16;

    vector<int>result=pairSum(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    cout<<target<<endl;

    return 0;
};



