#include<vector>
#include<cstring>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        // there are multiple ways to solve this problem.
        // one technique is to take all substrings in s which is of length(p)
        // then sort that substring and sort p and compare both.
        // complexity of this algo is sizeof(s)*sizeof(p)log(sizeof(p))
        // This algorithm times out for some tests.
        // hence we will use hash table to speedup
        int s_len = s.size();
        int p_len = p.size();
        std::vector<int> result;
        // corner cases
        if((s_len==0) || (p_len==0) ||(s_len<p_len))
        {
            return result;
        }
        
        //create a fixed array of size 27 instead of hash table as we already know the size
        int my_hash[27];
        
        // populate hash with data of p
        std::memset(my_hash,0,sizeof(my_hash));
        
        for(auto char_p:p)
        {
            ++my_hash[char_p-'a'];
        }
        
        string substr("");
        bool is_anagram=true;
        for(int i=0;i<=(s_len-p_len);++i)
        {
            // reset
            is_anagram=true;
            
            // decrment hash count for each char from temp_hash only first time
            if(i==0)
            {
                for(int j=0;j<p_len;++j)
                {
                    --my_hash[s[j]-'a'];
                }
            }
            else
            {
                // we have to only account for 2 charcters
                ++my_hash[s[i-1]-'a'];
                --my_hash[s[i+p_len-1]-'a'];
            }
            
            // now check if any entry is non zero
            for(int j=0;j<27;++j)
            {
                if(my_hash[j]!=0)
                {
                    is_anagram = false;
                    break;
                }
            }
            if(is_anagram)
                result.push_back(i);
        }
        return result;
    }
};