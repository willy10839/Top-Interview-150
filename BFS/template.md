```
void bfs(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // 當前層的節點個數
        // 遍歷「這一層」的所有節點
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // [處理當前節點邏輯]
            // cout << node->val;

            // 將下一層節點放入隊列
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        // [這一層結束，可以增加 level 計數或切換方向]
    }
}

int bfs(Node* start, Node* target) {
    queue<Node*> q;
    unordered_set<Node*> visited; // 防止重複訪問

    q.push(start);
    visited.insert(start);
    int step = 0; // 紀錄路徑長度

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            if (cur == target) return step; // 找到目標

            // 擴散：遍歷所有相鄰節點
            for (Node* neighbor : cur->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        step++; // 擴散完一層，步數 +1
    }
    return -1; // 找不到路徑
}
```