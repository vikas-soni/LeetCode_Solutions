class Solution {
public:
    bool canWinNim(int n) {
        //=========================== Sol 1 (doesnt works for very large number due to memory allocation limits)=====================
        /*
        // will solve this using 1d dynamic programming bottom up approach
        //create an array of size n+1
        int *win = new int[n+1];
        // we know initial results for few stones
        win[1] = win[2] = win[3] = 1;
        win[4] = 0;
        
        // now we will start finding result for each coin upto n.
        for(int num_stones=5;num_stones<=n;++num_stones)
        {
            // player 1 can pick 1,2 or 3 stones. Hence player 2 can pick (num_stones-1), (num_stones-2) or (num_stones-3)
            // now since player 1 is clever, he will try to pick num stones in such a way that player 2 always loses
            // if player 1 can make sure that there is atleast 1 way (out of picking 1,2 or 3 stones) by which he can make player 2 lose,
            // then player 1 will pick that stone to make player 2 lose.
            if((win[num_stones-1] == 0) || (win[num_stones-2] == 0) || (win[num_stones-3] == 0))
            {
                win[num_stones] = 1;
            }
            else
            {
                win[num_stones] = 0;
            }
        }
        return win[n];
        */
        //================================================================================================================================
        
        //=================== Solution 2 ===========================================================================================
        // since there was a pattern after looking results of first few stones, we can just use a simple equation
        return !(n%4 == 0);
    }
};