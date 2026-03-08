/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].
*/

//Method 1
//Map to travese all
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        int ans=0;
        for(auto c:counts){
            int key=c.first;
            int val=c.second;
            if(counts.count(key+1)){
                ans=max(ans, val+counts[key+1] );
            }
        }
        return ans;
    }
};

//Method 2
//Sort + sliding window
//Faster than method 1
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0, ans=0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>1){
                j+=1;
            }
            if (nums[i] - nums[j] == 1) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};
