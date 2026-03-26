# 二分搜尋 (Binary Search) 判斷邏輯筆記

二分搜尋的細節（`while` 條件、`mid` 更新）取決於你定義的 **搜尋區間 (Search Space)**。

---

## 1. 閉區間體系：`[left, right]`
最經典的寫法，適用於「找一個確定的目標值（Target）」。

- **初始值**：`left = 0`, `right = nums.size() - 1`
- **循環條件**：`while (left <= right)`
- **邏輯意義**：當 `left == right` 時，區間內仍有一個元素，必須檢查。
- **更新方式**：
  - 如果 `nums[mid] < target`：`left = mid + 1`
  - 如果 `nums[mid] > target`：`right = mid - 1`
- **結束狀態**：`left > right`（指標錯開，代表沒找到）。

---

## 2. 左閉右開體系：`[left, right)`
適用於「找邊界（如 `lower_bound`）」或「比較相鄰元素（如 `findPeakElement`）」。

- **初始值**：`left = 0`, `right = nums.size()` (或 `size - 1` 但不檢查最後一項)
- **循環條件**：`while (left < right)`
- **邏輯意義**：當 `left == right` 時，區間已空（例如 `[5, 5)`），直接跳出。
- **更新方式**：
  - `left = mid + 1`
  - `right = mid` (因為 `mid` 已經檢查過，而右開區間本來就不含 `right`)
- **結束狀態**：`left == right`（兩針重合，該位置即為答案）。

---

## 3. 快速分辨對照表

| 情境 | `while (left <= right)` | `while (left < right)` |
| :--- | :--- | :--- |
| **搜尋目標** | 找某個特定的數值 | 找符合條件的邊界 / 峰值 |
| **何時結束** | 指標錯開 (`left > right`) | 指標重合 (`left == right`) |
| **Right 更新** | `right = mid - 1` | `right = mid` |
| **優點** | 直觀，不容易漏掉元素 | 避免 `mid + 1` 越界，適合比較相鄰項 |

---

## 4. 實戰建議 (Find Peak Element 例外)
當題目需要比較 `nums[mid]` 與 `nums[mid + 1]` 時：
**必用 `while (left < right)`。**

```cpp
int left = 0, right = nums.size() - 1;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
        right = mid; // 往坡度高的地方走，且 mid 可能是峰值
    } else {
        left = mid + 1; // 往右走
    }
}
return left; // 最終 left 會停在峰值

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