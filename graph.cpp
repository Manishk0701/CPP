#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    long long minCables = N - 1;
    long long maxCables = (N * (N + 1)) / 2;

    if (M < minCables || M > maxCables) {
        cout << -1 << endl; // Not possible
        return 0;
    }

    // Calculate the minimum data consumption factor
    long long maxFactor = (M + N - 1) / N; // Equivalent to ceil(M / N)
    cout << maxFactor << endl;

    return 0;
}