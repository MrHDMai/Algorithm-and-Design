#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * @brief Calculates the maximum subarray sum that crosses the midpoint.
 * 
 * @param arr The array of integers.
 * @param left The left index of the range.
 * @param mid The midpoint index.
 * @param right The right index of the range.
 * @return Maximum subarray sum that crosses the midpoint.
 */
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    // Calculate max sum of subarray ending at or before mid
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    // Calculate max sum of subarray starting at or after mid
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    // Return combined sum crossing mid
    return leftSum + rightSum;
}

/**
 * @brief Recursive function to find the maximum subarray sum using divide and conquer.
 * 
 * @param arr The input array.
 * @param left Starting index of the subarray.
 * @param right Ending index of the subarray.
 * @return Maximum subarray sum in the range [left, right].
 */
int maxSubarraySum(const vector<int>& arr, int left, int right) {
    if (left > right)
        return INT_MIN;

    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftMax = maxSubarraySum(arr, left, mid - 1);
    int rightMax = maxSubarraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max({leftMax, rightMax, crossMax});
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& num : arr) {
        cin >> num;
    }

    int result = maxSubarraySum(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}
