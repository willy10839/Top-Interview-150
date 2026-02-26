/*
You are given an integer array arr. Sort the integers in the array in ascending order by
the number of 1's in their binary representation and in case of two or more integers have
the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

*/

//Soultion 1 using Map to store each number of bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> bitmap;
        for(auto a:arr){
            // calculate numbers of bit for given value
            int bit= __builtin_popcount(a);
            bitmap[bit].insert(a);
        }
        vector<int> ans;
        for(auto p:bitmap){
            for(auto val:p.second){
                ans.push_back(val);
            }
        }
        return ans;
    }
};

//Soultion 2 using customer compare to sort the array
class Solution {
public:
    static bool compare(int a, int b){
        int counta=__builtin_popcount(a);
        int countb=__builtin_popcount(b);

        if(counta==countb){
            return a<b;
        }
        return counta<countb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};