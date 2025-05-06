#include <iostream>
#include <vector>

using namespace std;

const int DIGIT_RANGE = 4;     // Digits range from 0 to 3
const int DIGITS_PER_NUMBER = 10;

// Counting sort on digit position `pos`
void countingSort(vector<vector<int>>& arr, int pos) {
    int n = arr.size();
    vector<int> count(DIGIT_RANGE, 0);
    vector<vector<int>> output(n, vector<int>(DIGITS_PER_NUMBER));

    // Count the occurrences of each digit at position `pos`
    for (const auto& number : arr) {
        ++count[number[pos]];
    }

    // Compute prefix sums for stable sort
    for (int i = 1; i < DIGIT_RANGE; ++i) {
        count[i] += count[i - 1];
    }

    // Build output array from back to front for stability
    for (int i = n - 1; i >= 0; --i) {
        int digit = arr[i][pos];
        int index = --count[digit];
        output[index] = move(arr[i]);
    }

    // Copy back the sorted result
    arr = move(output);
}

// Radix sort from least significant digit to most significant
void radixSort(vector<vector<int>>& arr) {
    for (int pos = DIGITS_PER_NUMBER - 1; pos >= 0; --pos) {
        countingSort(arr, pos);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(DIGITS_PER_NUMBER));

    for (auto& number : arr) {
        for (int& digit : number) {
            cin >> digit;
        }
    }

    radixSort(arr);

    for (const auto& number : arr) {
        for (int digit : number) {
            cout << digit << ";";
        }
        cout << '\n';
    }

    return 0;
}
