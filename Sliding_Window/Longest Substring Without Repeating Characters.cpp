/*
Given a string s, find the length of the longest substring without duplicate characters.
Input: s = "abcabcbb"
Output: 3
Input: s = "pwwkew"
Output: 3
*/

//Method 1
// Remove the set until find the duplicate ones
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n=s.length(), i=0, j=0;
        int ans=0;
        for (int j = 0; j < n; j++) {
            while(set.count(s[j])){
                set.erase(s[i]);
                i+=1;
            }
            set.insert(s[j]);
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};

//Method 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 使用 128 大小的陣列存儲字元最後出現的索引，初始化為 -1
        vector<int> last_index(128, -1);
        int n = s.length();
        int ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // 如果當前字元出現過，且在目前的視窗範圍內
            if (last_index[s[right]] >= left) {
                // 直接將 left 跳到重複字元上次出現位置的下一個
                left = last_index[s[right]] + 1;
            }

            // 更新字元最後出現的位置
            last_index[s[right]] = right;
            
            // 計算當前視窗長度並更新最大值
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};