//Lab01 Insertion sort 
//9.20.22

#include <iostream>
#include <vector> 

using namespace std;

void insertion(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {  // Start from index 1
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {  // Correct condition to j >= 0
            v[j + 1] = v[j];
            j--;  // Decrement j
        }
        v[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;  // Read n first to determine vector size
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    insertion(v);
    for (auto& sorted : v) {
        cout << sorted << " ";
    }
    cout << endl;
}