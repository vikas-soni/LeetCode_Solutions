class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // if we could use more memory, we could have looped through input array
        // and copied all non zero elements into a new array and fill rest with 0.
        // but we are not allowed to make a new copy.
        // what we will do is to keep 2 index now.. 1 will be slow and another will be a regular
        // whenever we see a zero, we dont increment the slow index
        // esle we copy data from another index location to the slow index location.
        // at end fill rest of the left index values with 0.
        int slow=0,fast=0;
        int len=nums.size();
        for(int i=0;i<len;++i)
        {
            if(nums[i] == 0)
                continue;
            nums[slow]=nums[i];
            ++slow;
        }
        // at end fill rest of the left index values with 0.
        for(int j=slow;j<len;++j)
        {
            nums[j]=0;
        }
    }
};