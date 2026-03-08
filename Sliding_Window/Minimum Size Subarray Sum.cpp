/*
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0, ans=INT_MAX, n=nums.size();
        int current=0;
        while(j<n){
            current+=nums[j];
            int diff;
            while(current>=target){
                diff=j-i+1;
                ans=min(ans, diff);
                current-=nums[i];
                i+=1;
            }
            j+=1;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};