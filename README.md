# Linklist_duplication_delete_all
the `deleteDuplicates` function takes the head of a sorted singly-linked list and removes all nodes that have duplicate values, leaving only distinct values in the list.  
# Remove Duplicates from Sorted List

This repository contains the C implementation of a function to remove all duplicates from a sorted singly-linked list. It ensures that only distinct values remain in the list, effectively deleting any consecutive nodes that have the same value.

## Description

The `deleteDuplicates` function takes the head of a sorted singly-linked list and removes all nodes that have duplicate values, leaving only distinct values in the list.

## Implementation

```c
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
