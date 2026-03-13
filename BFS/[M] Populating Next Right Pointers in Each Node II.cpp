/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
should be set to NULL.

Initially, all next pointers are set to NULL.
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* curr = root;
        // 外部迴圈：處理每一層
        while (curr) {
            Node dummy(0);      // 建立一個虛擬節點，用來接下一層
            Node* tail = &dummy; // tail 指向鏈表末端
            while(curr){
                if(curr->left){
                    tail->next=curr->left;
                    tail=tail->next;
                }
                if(curr->right){
                    tail->next=curr->right;
                    tail=tail->next;
                }
                curr = curr->next; // 移到同層的下一個節點
            }
            // 下一層的開頭就是 dummy.next
            curr = dummy.next;
        }
        return root;
    }
};