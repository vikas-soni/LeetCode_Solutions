class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // brute force solution will be to look at all possible subarrays and find their sum
        // time complexity = nC1+nC2+nC3 ----- nCn =~ 2^n
        // SO it has exponential time complexity
        // when we see exponential time complexity, most probably it can be solved by dynamic programming
        //using n^2. This question is solved in O(n).
        int len = nums.size();
        if(len==0)
            return 0;
        if(len==1)
            return nums[0];
            
        int max_till_here = 0;
        int current_max = INT_MIN;
        for(auto num:nums)
        {
            // max till a given index will be either the number at the given index or num+max till last index
            max_till_here = std::max(num,max_till_here+num);
            // finally find the current overall maximum
            current_max = std::max(current_max,max_till_here);
        }
        return current_max;
    }
};