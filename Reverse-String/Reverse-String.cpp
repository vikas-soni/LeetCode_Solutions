class Solution {
public:
    string reverseString(string s) {
        
        // the most simple way would be to simply use std::reverse
        std::reverse(s.begin(),s.end());
        return s;
    }
};