#include<assert.h>
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
    void deleteNode(ListNode* node) {
        // we have been given only the node itself. no head pointer
        assert(node!=nullptr && " input node cant be a nullptr");
        
        // also if its a tail node, we do not need to do anything
        if(node->next == nullptr)
            return;
        
        // Now to delete this node, we can first copy the value of next node in the given node
        // and then delete the next node.
        node->val = node->next->val;
        // save the node to free the memory. else there will be memory leaks
        ListNode *to_free = node->next;
        node->next = node->next->next;
        delete to_free;
    }
};