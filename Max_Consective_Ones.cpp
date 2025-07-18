#include <iostream>
#include <algorithm> // For max function
using namespace std;



int main(){
    int arr[7]={1,1,0,1,1,1,0};

    int n = sizeof(arr) / sizeof(arr[0]);

    int curr= 0;
    int maxi= 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            curr++;
        } else {
            curr = 0;
        }
        maxi = max(maxi, curr); // Update the maximum consecutive ones
    }

    cout << "Maximum consecutive ones: " << maxi << endl;

    return 0;
}