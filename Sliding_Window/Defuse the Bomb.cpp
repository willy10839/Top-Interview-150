/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular
array code of length of n and a key k.
To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous -k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

 

Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers.
The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
*/

//Brute force
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> tmp=code;
        for(int i=0;i<n;i++){
            if(k==0){
                code[i]=0;
            } else if(k>0){
                int sum=0;
                for(int j=1;j<=k;j++){
                    sum+=tmp[(i+j)%n];
                }
                code[i]=sum;
            } else{
                int sum=0;
                for(int j=-1;j>=k;j--){
                    sum+=tmp[(i+j+n)%n];
                }
                code[i]=sum;
            }
        }
        return code;
    }
};

//Sliding Window
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> res(n,0);
        if(k==0) return res;

        int start = (k > 0) ? 1 : n + k;
        int end = (k > 0) ? k : n - 1;

        int currentSum=0;
        for(int i=start; i<=end;i++){
            currentSum+=code[i%n];
        }
        for (int i = 0; i < n; i++) {
            res[i]=currentSum;
            currentSum -= code[start % n];
            currentSum += code[(end + 1) % n];
            
            start++;
            end++;
        }
        return res;
    }
};