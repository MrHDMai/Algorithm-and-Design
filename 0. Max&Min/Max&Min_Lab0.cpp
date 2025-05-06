#include <iostream>

using namespace std;

int main() {
    int input_count;  // Number of integers to process
    cin >> input_count;

    int current_min = 0;  // Initialize with default values
    int current_max = 0;

    if (input_count > 0) {
        // Read first number to initialize min/max
        cin >> current_min;
        current_max = current_min;

        // Process remaining numbers
        for (int i = 1; i < input_count; ++i) {
            int number;
            cin >> number;
            
            if (number < current_min) {
                current_min = number;
            } else if (number > current_max) {
                current_max = number;
            }
        }
    }

    // Output results
    cout << current_max << ";" << current_min << endl;
    return 0;
}