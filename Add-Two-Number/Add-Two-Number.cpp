/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // question here is actually little easy as the numbers are already in reverse order.
        // This makes carry propogation very easy as we need to propograte carry in forward direction.
        
        // make sure both lists are not null
        if((l1== nullptr)||(l2==nullptr))
        {
            assert(0 && "node l1 or l2 is null");
        }
        
        // we have been given a struct for the linked list. hence we can not use stl list.
        //Lets create a head pointer for our result linked list
        ListNode *result_head = new ListNode(0);
        ListNode *current_node = result_head;
        int sum=0,carry=0,total=0;
        ListNode *previous_node;
        // do initial calculation
        total = l1->val+l2->val;
        sum = total%10;
        carry=total/10;
        current_node->val = sum;
        l1=l1->next;
        l2=l2->next;
        // now continue the loop until at least one of the linked list is non finished or carry is non 0
        while((l1!=nullptr) || (l2!=nullptr)|| carry)
        {
            total = carry;
            // nullptr checks are imp in linked lists
            if(l1!=nullptr)
                total = total+l1->val;
            if(l2!=nullptr)
                total = total+l2->val;
            
            sum = total%10;
            carry = total/10;
            ListNode *next_node = new ListNode(0);
            current_node->next = next_node;
            current_node = current_node->next;
            current_node->val = sum;
            if(l1!=nullptr)
                l1=l1->next;
            if(l2!=nullptr)
                l2=l2->next;
        }
        return result_head;
    }
};