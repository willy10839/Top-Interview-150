/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size=q.size();
            vector<int> tmp(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int index=leftToRight ? i : (size - 1 - i);
                tmp[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(tmp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};