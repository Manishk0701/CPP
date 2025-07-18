#include <iostream>
#include <string>
using namespace std;

int minFlips(string bits, int k) {
    int n = bits.size();
    int flips = 0; // Count of flips
    int flipEffect = 0; // Tracks the effect of previous flips
    int* isFlipped = new int[n](); // Array to track flip effects at each position

    for (int i = 0; i < n; i++) {
        // Update the flip effect based on the current position
        flipEffect ^= isFlipped[i];

        // If the current bit is '0' after considering the flip effect
        if ((bits[i] == '0' && flipEffect % 2 == 0) || (bits[i] == '1' && flipEffect % 2 == 1)) {
            // If flipping is not possible (remaining bits are less than k)
            if (i + k > n) {
                delete[] isFlipped; // Free allocated memory
                return -1; // Impossible to make all bits '1'
            }

            // Perform a flip
            flips++;
            flipEffect ^= 1; // Add flip effect for the next k bits

            // Mark the end of the flip effect
            if (i + k < n) {
                isFlipped[i + k] ^= 1;
            }
        }
    }

    delete[] isFlipped; // Free allocated memory
    return flips;
}

int main() {
    string bits;
    int k;

    cin >> bits >> k;

    int result = minFlips(bits, k);

    if (result == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}