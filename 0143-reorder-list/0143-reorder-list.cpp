
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;

        ListNode* temp = head;

        while (temp != NULL) {
            v.push_back(temp);
            temp = temp->next;
        }

        int i = 0;
        int j = v.size() - 1;

        while (i < j) {
            v[i]->next = v[j];
            i++;

            if (i == j)
                break;

            v[j]->next = v[i];
            j--;
        }

        v[i]->next = NULL;
    }
};
