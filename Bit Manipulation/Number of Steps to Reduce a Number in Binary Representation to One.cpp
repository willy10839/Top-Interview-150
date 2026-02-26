/*Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1. 
*/

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // 從最後一位開始往前跑，直到剩下一位 (index 0)
        for (int i = s.length() - 1; i > 0; i--) {
            int current_bit = (s[i] - '0') + carry;
            
            if (current_bit == 1) { // 奇數情況：加 1 再除以 2，共 2 步
                steps += 2;
                carry = 1; // 產生進位
            } else { // 偶數情況 (0+0 或 1+1進位變成0)：直接除以 2，共 1 步
                steps += 1;
                // carry 維持原樣 (如果是1+1進位，carry 依舊是 1)
            }
        }
        
        // 最後處理最前面那一位 (s[0])
        // 如果最後 carry 是 1，代表原本的 "1" 變成了 "10"，需要多走一步除以 2
        return steps + carry;
    }
};