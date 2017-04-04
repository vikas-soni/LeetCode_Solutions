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
    bool hasCycle(ListNode *head) {
        // this is most frequently ask simplest question
        // consider that there is a circular lap and 2 people are running on it
        // one person is fast and one is slower. if they are running multiple laps in same circle,
        // there will be a time when fast runner will meet slow runner again.
        // This same concept is used here
        // we take two pointer, 1 is slow and 1 is fast. if they both meet then there is a circle.
        // but if tail is reached without meeting, then there is no circle.
        if((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr))
            return false;
        ListNode *slow=head, *fast=head;
        while((slow !=nullptr) && (fast->next!=nullptr) && (fast->next->next!=nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};