class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // My strategy would be to find length of each string and pick the minimum lenght out of that
        // as prefix can not be more than the size of smallest string
        int min=INT_MAX;
        string prefix("");
        // we do not want to do any work for empty vector
        if(strs.empty())
            return prefix;
        // find the size of smalled string
        for(auto str:strs)
        {
            int curr_len=str.size();
            min = (curr_len < min)? curr_len:min;
        }
        // if there is a string of size 0, then we will have a null prefix
        if(min==0)
            return prefix;
        // choosing one string for character comparison    
        string first_string=strs[0];
        // compare all characters at same index for each string
        for(int index=0;index<min;++index)
        {
            for(auto str:strs)
            {
                if(str[index]!=first_string[index])
                {
                    return prefix;
                }
            }
            prefix=prefix+first_string[index];
        }
        return prefix;
    }
};