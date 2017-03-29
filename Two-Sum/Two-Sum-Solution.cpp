#include<assert.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // need to have array of size 2 atleast
        int array_len = nums.size();
        assert(array_len >=2 && "input array length needs to be at least 2");
        
        // pair to store both array data and its index
        std::pair<int,int> data_index_pair;
        // array of pair to store both array data and its index
        std::vector<std::pair<int,int>> data_index_array(array_len);
        
        // fill the new array with pair of array index and array value
        for(int index = 0;index<array_len;++index)
        {
            data_index_array[index] = pair<int,int>(nums[index],index);
        }
        // sort the array based on the value (not index)
        std::sort(data_index_array.begin(),data_index_array.end());
        // create a result array of size 2 with -1 as init data
        std::vector<int> result(2,-1);
        // use 2 index to point start and end of array
        int start_index=0,end_index=array_len-1;
        // loop
        while(end_index>start_index)
        {
            // if the target is found
            if((data_index_array[start_index].first+data_index_array[end_index].first) == target)
            {
                result[0] = data_index_array[start_index].second;
                result[1] = data_index_array[end_index].second;
                break;
            }
            // else move start index to get bigger value
            else if((data_index_array[start_index].first+data_index_array[end_index].first) < target)
            {
                ++start_index;
            }
            // move end index to get a smaller value
            else
            {
                --end_index;
            }
        }
        return result;
    }
};