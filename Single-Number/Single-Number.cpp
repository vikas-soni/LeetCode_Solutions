#include<assert.h>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // i always like to check for input correctness
        if(nums.size()==0)
        {
            assert(0 && "lenght of input array is 0");
            
        }
        // we can use property of logical operator XOR here
        // We know that A xor A = 0, A xor 0 = A
        // if we xor all elements in the array, the result will be the single number
        // eg: Lets say array has 3 elements (1,2,1)
        // so 1 xor 2 xor 1 = 1 xor 1 xor 2 = (1 xor 1) xor 2 = 0 xor 2 = 2
        int result = 0;
        for(auto num:nums)
        {
            result = result ^ num;
        }
        return result;
    }
};