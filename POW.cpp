#include<iostream>
using namespace std;


double myPow(double x, int n) {
    long binform = n;
            if (n<0){
                x=1/x;
                binform =-binform;
            }
            double ans = 1;

            while(binform > 0){
                if (binform % 2 == 1){
                    ans *= x;
                }
                x *= x ;
                binform /= 2;
            }
            return ans;
}


int main() {
    double x;
    int n;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << x << " raised to the power " << n << " is: " << result << endl;

    return 0;
}