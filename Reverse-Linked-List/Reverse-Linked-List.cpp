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
    ListNode* reverseList(ListNode* head) {
        
        // boundary conditions
        if((head == nullptr)||(head->next == nullptr))
            return head;

        // now for 3 or more nodes
        ListNode *prev_node = nullptr,*current_node = head, *temp_node = nullptr;
        
        while((current_node != nullptr))
        {
            temp_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = temp_node;
        }
        head = prev_node;
        return head;
    }
};