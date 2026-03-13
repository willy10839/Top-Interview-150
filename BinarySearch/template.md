```
int binarySearch(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 閉區間 [left, right]

    while (left <= right) {
        // 防止溢位的寫法，等同於 (left + right) / 2
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // 找到目標，回傳索引
        } else if (nums[mid] < target) {
            left = mid + 1; // 目標在右側
        } else {
            right = mid - 1; // 目標在左側
        }
    }
    return -1; // 沒找到
}
```