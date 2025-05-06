#include<vector>
#include<iostream>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> l(n1), r(n2);
    
    for(int i = 0; i < n1; i++)
        l[i] = v[left + i];
    for(int j = 0; j < n2; j++)
        r[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            v[k] = l[i];
            i++;
        } else {
            v[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = l[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = r[j];
        j++;
        k++;
    }
}

void sort(vector<int>& v, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        sort(v, left, mid);
        sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

void check(vector<int>& v, int left, int right){
    if(v.size() == 0){
        cout << "Nothing to sort" << endl;
        return;
    }
    sort(v, left, right);
}

int main(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin >> v[i];
    }
    check(v,0,v.size()-1);
    for(auto& ms : v){
        cout <<"Merge Sort: " << ms << endl;
    }
}