#include<unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        // we can simply use a hash table and put counts of each number there
        std::unordered_map<int,int> my_map;
        int max_count = 0,majority_elem=0;
        for(auto num:nums)
        {
            ++my_map[num];
            if(my_map[num] > max_count)
            {
                max_count = my_map[num];
                majority_elem = num;
            }
        }
        if(max_count > (nums.size()/2))
            return majority_elem;
        else
            return -1;
    }
};