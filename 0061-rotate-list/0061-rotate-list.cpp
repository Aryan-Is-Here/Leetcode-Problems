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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || !k) return head;
        ListNode * curr = head , *last;
        int count = 0;
        while(curr) {
            count++;
            curr = curr -> next;
        }
        k = k % count;
        if (k == 0) return head;
        count = count - k;
        curr = head;
        while(count--) {
            last = curr;
            curr = curr -> next;
        }
        last -> next = nullptr;
        ListNode* rev = curr;
        while(rev -> next != NULL) rev = rev -> next;
        rev -> next = head;
        return curr;
    }
};