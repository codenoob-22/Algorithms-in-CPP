
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <iostream>
#include <vector>
using namespace std;

int numRollsToTarget(int d, int f, int target) {
    vector<vector<long int>> dp(target + 1, vector<long int>(d + 1, 0));
    for(int i = 1; i <= min(f,target); i++) {
        dp[i][1] = 1;
    }
    long int mod = 1e9 + 7;
    for(int i = 2; i <= target; i++) {
        for(int j = 2; j <= d; j++) {
            for(int k = 1; k <= f && k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][j - 1])%(mod);
            } 
        }
    }
    for(int i = 0; i <= target; i++) {
        for(int j = 0; j <= d; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[target][d];
}


int main() {
    int d, f, target;
    cin>>d>>f>target;
    cout<<numRollsToTarget(d, f, target);
    return 0;
}
