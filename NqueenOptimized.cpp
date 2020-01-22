// N queens using search optimization
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e3;
int slash[maxn], backslash[maxn], row[maxn];
int n, N;
// helper funcs
int backslashcode(int i, int j) {
    return i - j + n-1;
}
int slashcode(int i, int j) {
     return i + j;
}
void init(int n) {
       for(int i = 0; i < n; i++){
           row[i] = 0;
       }
       for(int i = 0; i <= 2*n; i++){
           slash[i] = 0;
           backslash[i] = 0;
       }
       
}
//main functions
void print(vector<vector<int>> a) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j  <n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool safe(int i, int x) {
    if(slash[slashcode(i, x)] || backslash[backslashcode(i, x)] || row[i]) {
        return false;
    }
    
    return true;
}
bool func(vector<vector<int>> a, int x) {
    
    if(x >= N) {
        print(a);
        return true;
    }
    for(int i = 0; i < n; i++) {
        if(safe(i, x)) {
            //trying the solution
            slash[slashcode(i, x)] = 1;
            backslash[backslashcode(i, x)] = 1;
            row[i] = 1;
            a[i][x] = 1;
            if(func(a, x + 1)) {
                return true;
            }
            //rejecting the solution
            slash[slashcode(i, x)] = 0;
            backslash[backslashcode(i, x)] = 0;
            row[i] = 0;
            a[i][x] = 0;
        }
    }
    return false;
}
int main() {
	
	cin>>n>>N;
	vector<vector<int>> a(n,vector<int>(n, 0));
	
	if(!func(a, 0)) {
	    cout<<"Nope Bro~!";
	}
	return 0;
}
