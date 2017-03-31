#include<stack>
class MinStack {
public:
    /** initialize your data structure here. */
    // keep a stack of pair of value and min till here
    std::stack<std::pair<int,int>> my_stack;
    
    MinStack() {
        // nothing to initialize
    }
    
    void push(int x)
    {
        std::pair<int,int> pair_to_push;
        // if stack is empty, then x is the minimum value
        if(my_stack.empty())
        {
            pair_to_push = pair<int,int>(x,x);
        }
        else
        {
            // get the min from top of stack
            int min_till_now = my_stack.top().second;
            // compare it with x to decide who will ne new minimum
            if(x<min_till_now)
            {
                pair_to_push = pair<int,int>(x,x);
            }
            else
            {
                pair_to_push = pair<int,int>(x,min_till_now);
            }
        }
        my_stack.push(pair_to_push);
        return;
    }
    
    void pop() {
        my_stack.pop();
        return;
    }
    
    int top() {
        return my_stack.top().first;
        
    }
    
    int getMin() {
        return my_stack.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */