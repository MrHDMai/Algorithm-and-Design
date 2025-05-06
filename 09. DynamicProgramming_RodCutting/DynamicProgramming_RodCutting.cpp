#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void extendedBottomUpCutRod(int* prices, int length)
{
    vector<int> revenue(length + 1, 0);  // revenue[i] stores the max revenue for rod of length i
    vector<int> cuts(length + 1, 0);     // cuts[i] stores the first cut length for max revenue

    for (int j = 1; j <= length; ++j) {
        int maxRev = INT_MIN;

        // Try all first cut positions i from 1 to j
        for (int i = 1; i <= j; ++i) {
            if (maxRev < prices[i] + revenue[j - i]) {
                maxRev = prices[i] + revenue[j - i];
                cuts[j] = i;  // Store best first cut for rod of length j
            }
        }

        revenue[j] = maxRev;
    }

    // Output the maximum revenue
    cout << "Maximum Revenue: " << revenue[length] << endl;

    // Output the cuts used to get maximum revenue
    cout << "Cuts: ";
    while (length > 0) {
        cout << cuts[length] << " ";
        length -= cuts[length];
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    // Allocate price array (1-based index)
    int* prices = new int[n + 1];
    prices[0] = 0;

    cout << "Enter the prices for lengths 1 to " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i];
    }

    extendedBottomUpCutRod(prices, n);

    delete[] prices;
    return 0;
}
