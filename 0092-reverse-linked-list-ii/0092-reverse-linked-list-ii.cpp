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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int count = 1;
        ListNode *curr = head , *prev = nullptr , *next;
        while(count < left) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        ListNode *temp = prev , *temp1 = curr;
        prev = nullptr;
        while(count <= right) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(temp) temp -> next = prev;
        else head = prev;
        temp1 -> next = curr;
        return head;
    }
};