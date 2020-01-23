#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define mp make_pair
int n;
vector<pair<int,int>> moves{mp(2, 1),mp(-2, 1),mp(-2, -1),mp(2, -1),
                            mp(1, 2),mp(1, -2),mp(-1, -2),mp(-1, 2)};
                            
                            
bool isvalid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    }
    
    return true;
}
void print (vector<vector<int>> a) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
void func(vector<vector<int>> a, int jumps, int x, int y) {
    a[x][y] = jumps;
    //cout<<x<<" "<<y<<" "<<jumps<<"\n";
    if(jumps >= n*n -1) {
        print(a);
        cout<<"voila\n";
        a[x][y]=0;
        return;
    }
    for(auto move:moves){
       int xs = x+move.first;
       int ys = y+move.second;
        if(isvalid(xs, ys) && a[xs][ys] == 0) {
            func(a, jumps + 1, xs, ys);
        }
    }
    a[x][y] = 0;
}
int main() {
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n,0));
    
    if(!func(a, 1, 0, 0)) {
        cout<<"nope Dude\n";
    }
    return 0;
} 
