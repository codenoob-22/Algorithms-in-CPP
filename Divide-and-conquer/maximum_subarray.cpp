//question link - https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int> nums, int left, int right) {
        
        if(left >= right) return nums[left];
        int sum = 0;
        int left_max=INT_MIN, right_max=INT_MIN;
        int mid = left + (right - left)/2;
        for(int i = mid; i >= left; i--) {
           sum += nums[i];
            if(left_max < sum) {
                left_max = sum;
            }
        }
        
        sum = 0;
        for(int i = mid + 1; i <=right; i++) {
            sum += nums[i];
            if(right_max < sum) {
                right_max = sum;
            }
        }
        
        int left_right = max(maximum(nums, mid + 1, right), maximum(nums, left, mid));
        
        return max(left_right, left_max + right_max);
    }
   
int main(){
int n; cin>>n;
vector<int> nums(n);
for(int i = 0; i < n; i++) {
  cin>>nums[i];
}

cout<< maximum(nums, 0, n - 1);
return 0;
}
