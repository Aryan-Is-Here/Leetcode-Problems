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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0 , n2 = 0;
        ListNode *curr1 = headA , *curr2 = headB;
        while(curr1) {
            n1++;
            curr1 = curr1 -> next;
        }
        while(curr2) {
            n2++;
            curr2 = curr2 -> next;
        }
        curr1 = headA , curr2 = headB;
        if (n1 > n2) for(int i = 0 ; i < n1 - n2 ; i++) curr1 = curr1 -> next;
        else for(int i = 0 ; i < n2 - n1 ; i++) curr2 = curr2 -> next;
        while (curr1 != curr2) {
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        return curr1;
    }
};