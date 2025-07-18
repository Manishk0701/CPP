#include<iostream>
#include <limits.h>
using namespace std;

int main(){
    int nums[]={5,15,25,-15,-56,78,98,45,12,45};
    int size = sizeof(nums)/sizeof(nums[0]);
    
    int smallest=INT_MAX;

    for (int i = 0; i < size; i++){
        if (nums[i] < smallest){
            smallest = nums[i];
        }
    }

    cout << "The smallest number is " << smallest << endl;
    return 0;

}