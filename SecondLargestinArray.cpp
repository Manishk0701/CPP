#include<iostream>
#include<vector>    
using namespace std;
#include <climits>
#include<algorithm>


int SecondLargest(vector <int> & arr ){
    int n = arr.size();
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    return second;

}

int main(){
    vector<int > nums= {2, 4, 5, 6, 7, 8, 9, 10};
    cout<<SecondLargest(nums);
}