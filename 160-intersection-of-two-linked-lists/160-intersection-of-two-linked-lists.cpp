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
    map<ListNode*, bool> visited;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        do{
            if(headA != NULL && visited[headA]){
                return headA;
            }
            visited[headA] = true;
            if(headB != NULL &&  visited[headB]){
                return headB;
            }
            visited[headB] = true;
            if(headA != NULL)
            headA = headA->next;
            if(headB != NULL)
            headB = headB->next;
            
        }while(headA != NULL || headB != NULL);
        
        return NULL;
    }
};