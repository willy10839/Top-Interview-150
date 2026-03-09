int slidingWindow(vector<int>& nums) {
    int left = 0, right = 0;
    int current_state = 0; // 視窗內的累計值或狀態
    int ans = 0;           // 最終結果

    while (right < nums.size()) {
        // [進窗]：處理右端元素
        current_state += nums[right];

        // [收縮]：當視窗滿足條件，嘗試縮小左界以尋找最佳解
        while (/* 視窗狀態滿足條件 */) {
            ans = ...; // 更新結果
            
            // [出窗]：移除左端元素
            current_state -= nums[left];
            left++;
        }
        
        right++; // [擴窗]
    }
    return ans;
}