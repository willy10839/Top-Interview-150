/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
should be set to NULL.

Initially, all next pointers are set to NULL.

Example:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to
its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.
*/

//BFS
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // 當前層的節點個數
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if(i==size-1){
                    node->next=NULL;
                } else{
                    node->next=q.front();
                }

                // 將下一層節點放入隊列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
        }
        }
    return root;
    }
};

// Faster method
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* curr = root;
        // 外部迴圈：處理每一層
        while (curr->left) {
            Node* temp = curr;
            // 內部迴圈：連結當前層的下一層
            while (temp) {
                // 1. 連結自己的左右子節點
                temp->left->next = temp->right;
                
                // 2. 連結「自己右子節點」與「下一個節點的左子節點」
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }
                
                temp = temp->next;
            }
            // 往下走一層
            curr = curr->left;
        }
        return root;
    }
};