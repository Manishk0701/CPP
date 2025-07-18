#include<iostream>
#include<vector>
#include<climits> // Required for INT_MAX
using namespace std;

int stocksell(vector<int>& data) {
    int n = data.size();
    int profit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (data[i] < minPrice) {
            minPrice = data[i]; // Update the minimum price
        } else {
            profit = max(profit, data[i] - minPrice); // Calculate the maximum profit
        }
    }
    return profit;
}

int main() {
    vector<int> data = {10, 5, 3, 2, 6, 8, 1};

    int n = data.size();
    int maxProfit = stocksell(data);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
