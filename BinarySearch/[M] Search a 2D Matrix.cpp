/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int left=0, right=m*n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            /*
            Row (列)：index / n (看它橫跨了幾個完整的寬度)
            Col (欄)：index % n (剩下的餘數就是該列的第幾個)
            */
            int val=matrix[mid/n][mid%n];
            if(val==target){
                return true;
            } else if(val>target){
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return false;
    }
};