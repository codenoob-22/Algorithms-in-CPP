// introducing quickselect algorithm -- find kth smallest element in an array
// gets O(n) as average time complexity
//needs to be improved *-*
#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &a, int left, int right) {
    int x = a[right];
    int i = l;
    for(int j = l; j < right; j++) {
        if(a[j] <= x) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}

void kthsmallest(vector<int> a, int left, int right, k) {
    if(left >= right) return INT_MAX;
    
    int i = partition(a, left, right);
    if(i > k - 1) {
        return kthsmallest(a, left, i - 1);
    }
    if(i < k - 1) {
        return kthsmallest(a, i, right);
    }
    return a[i];
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	
	for(int i =0; i < n; i++) {
	    cin>>a[i];
	}
	
	cout<<kthsmallest(a, 0, n - 1, k);
	return 0;
}
