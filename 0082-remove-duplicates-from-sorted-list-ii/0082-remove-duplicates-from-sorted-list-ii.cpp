
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* temp = &dummy;

        while (temp->next != NULL && temp->next->next != NULL) {
            if (temp->next->val == temp->next->next->val) {
                int x = temp->next->val;

                while (temp->next != NULL && temp->next->val == x) {
                    temp->next = temp->next->next;
                }
            }
            else {
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
