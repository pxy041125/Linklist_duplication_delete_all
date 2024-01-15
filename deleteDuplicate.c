#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *current = head;

    while (current != NULL) {
        bool isDuplicate = false;
        while (current->next != NULL && current->val == current->next->val) {
            isDuplicate = true;
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }

        if (isDuplicate) {
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
            prev->next = current;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return dummy.next;
}
