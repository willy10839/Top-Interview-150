/*
iven an array of integers nums sorted in non-decreasing order, find the starting and
ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst){
        int left=0, right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                index=mid;
                if(isFirst){
                    right=mid-1;
                } else{
                    left=mid+1;
                }
            } else if(nums[mid]<target){
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=findBound(nums, target, true);
        int right=findBound(nums, target, false);
        return {left, right};
    }

};