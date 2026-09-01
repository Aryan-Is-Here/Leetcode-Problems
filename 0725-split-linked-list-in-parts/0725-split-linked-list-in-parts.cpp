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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0 ;
        ListNode * curr = head , * prev = nullptr;
        while(curr) {
            curr = curr -> next;
            count++;
        }
        int rem = count % k , group = count / k;
        vector<ListNode*> ans(k);
        int j = 0;
        curr = head;
        while(rem--) {
            int i = 0;
            ListNode* temp = curr;
            while(i < (group + 1)) {
                i++;
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = NULL;
            ans[j] = temp;
            j++;
            k--;
        }
        if(!curr) return ans;
        while(k--) {
            int i = 0;
            ListNode* temp = curr;
            while(i < group) {
                i++;
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = NULL;
            ans[j] = temp;
            j++;
        }
        return ans;
    }
};