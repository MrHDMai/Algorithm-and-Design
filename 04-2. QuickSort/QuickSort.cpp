#include<iostream>
#include<vector>

using namespace std;

void insertion(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key){
            swap(v[i],v[j]);
            --j;
        }
        v[j + 1] = key;
    }
}

int partition(vector<int>& v, int low, int high){
    int pvt = v[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if (v[j] < pvt){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i + 1],v[high]);
    return i + 1;
}

int main(){
	int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin >> v[i];
    }
	insertion(v);
    for(auto& val : v){
        cout << "Insertion: " << val << endl;
    }
}