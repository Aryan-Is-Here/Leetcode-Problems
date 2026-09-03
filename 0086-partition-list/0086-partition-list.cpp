/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0) , * head2 = new ListNode(0);
        ListNode* curr1 = head1 , * curr2 = head2 , * temp = head;
        while(temp) {
            if(temp -> val < x) {
                curr1 -> next = temp;
                curr1 = curr1 -> next;
            }
            else {
                curr2 -> next = temp;
                curr2 = curr2 -> next;
            }
            temp = temp -> next;
        }
        curr2 -> next = nullptr;
        curr1 -> next = head2 -> next;
        head1 = head1 -> next;
        return head1;
    }
};