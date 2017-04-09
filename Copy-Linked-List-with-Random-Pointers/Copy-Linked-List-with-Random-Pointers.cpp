/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 #include<unordered_map>
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        // when we do a deep copy, we need copy all the pointers properly
        // creating new node and copying label and next pointers is easy and direct.
        // if labels are unique, then we can have a hash table where key is node label and value is
        // random pointer label.
        // But since label might be repeated, we need to think of other solution
        // best way is to keep table of new node pointer corresponding to each old node pointer
        
        if(head == nullptr)
            return nullptr;
        std::unordered_map<RandomListNode*,RandomListNode*> my_map;
        //iterate over all the node of original list, create a corresponding new node and keep a table of both
        for(RandomListNode* curr=head;curr!=nullptr;curr=curr->next)
        {
            my_map.emplace(curr,new RandomListNode(curr->label));
        }
        
        // now fill the next and random pointers of new list
        for(RandomListNode* curr=head;curr!=nullptr;curr=curr->next)
        {
            std::unordered_map<RandomListNode*,RandomListNode*>::iterator it=my_map.find(curr);
            it->second->next = my_map[it->first->next];
            it->second->random = my_map[it->first->random];
        }
        return my_map[head];
    }
};