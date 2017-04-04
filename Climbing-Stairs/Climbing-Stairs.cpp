#include<unordered_map>
class Solution {
public:
    std::unordered_map<int,int> my_map;
    int climbStairs(int n) {
        
        // these type of question can be solved using a bottoms up appraoch (tabular)
        // or top down approach (recursion)
        // Lets try using recursion
        // total number of ways by which we can climb step n is equal to total number of ways
        // which we can climb to n-1 plus n-2
        
        if(n<=2)
            return n;
        // check if the result of climbStairs(n) is already present
        std::unordered_map<int,int>::iterator it = my_map.find(n);
        // if so we do not need to recalculate it
        if(it!=my_map.end())
            return it->second;
        
        int total = climbStairs(n-1)+climbStairs(n-2);
        // now cache this result as we can use it for some repeated calculations
        // for example lets say inpt is 20.
        // climbStairs(20) = climbStairs(19)+climbStairs(18);
        // climbStairs(19) = climbStairs(18)+climbStairs(17);
        // we see that both 19 and 20 needs value of 18 and both will recalculate it which will
        // be a waste of time.
        my_map[n]=total;
        return total;
        
        // we can also use bottoms up approach with o(n) as time complexity
    }
};