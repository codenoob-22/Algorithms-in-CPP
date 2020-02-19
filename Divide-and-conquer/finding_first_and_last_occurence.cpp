#include <bits/stdc++.h>
using namespace std;
    
int findfirst(int k, vector<int> a, int left, int right) {
    if( left > right) return -1;
    if(left == right) return left;
    int mid = left + (right - left)/2;
    if(a[mid] > k) {
        return findfirst(k, a, left, mid);
    }
    if(a[mid] < k) {
        return findfirst(k, a, mid + 1, right);
    }
    
    if(a[mid] == k && a[mid - 1] == k) {
        return findfirst(k, a, left, mid);
    }
    
    return mid;
}

int findlast(int k, vector<int> a, int left, int right) {
    if( left > right) return -1;
    if(left == right) return left;
    int mid = left + (right - left)/2;
    if(a[mid] > k) {
        return findfirst(k, a, left, mid);
    }
    if(a[mid] < k) {
        return findfirst(k, a, mid + 1, right);
    }
    
    if(a[mid] == k && a[mid + 1] == k) {
        return findfirst(k, a, mid + 1, right);
    }
    
    return mid;
}
int main() {
    int n; cin>>n;
    vector<int> a(n);
    int k; cin>>k;
    
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int m = findfirst(k, a, 0, n - 1);
    cout << m<< " "<< findlast(k, a, m, n - 1);
	return 0;
}
