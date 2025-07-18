#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // Initialize to a very large value
    int maxProfit = 0;      // Initialize profit to 0

    for (int i = 0; i < prices.size(); i++) {
        // Update the minimum price encountered so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Calculate the profit if sold on the current day
        else {
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}