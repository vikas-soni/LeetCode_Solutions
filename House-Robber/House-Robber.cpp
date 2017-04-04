#include<algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        // this question can be solved using top down or bottom up aproach.
        // Lets try bottoms up this time
        // in bottoms up approach we will find rob() for each value from 0 to len(nums)
        int len = nums.size();
        if(len==0)
            return 0;
        int *max_money = new int[len];
        // max money for when there is only 1 house
        max_money[0]=nums[0];
        // max money when there are 1st 2 house
        max_money[1]=std::max(nums[0],nums[1]);
        // max money when there are more than 2 house
        // max money till current house i is either the money in that house + max money till two house before that house OR max money till one house before
        for(int i=2;i<len;++i)
        {
            max_money[i] = std::max(nums[i]+max_money[i-2],max_money[i-1]);
        }
        return max_money[len-1];
        //return 0;
    }
};