#include <iostream>
#include <vector>

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
   
    dp[0][0] = grid[0][0];
    
    for(int i = 1 ; i < n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    
    for(int i = 1 ; i < m; i++) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}
 // driver function
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }

    cout<<minPathsum(grid)<<"\n";
}