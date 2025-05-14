/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int              val;
    struct ListNode* next;
};

#include <stddef.h>

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* merged;
    struct ListNode* last;
    if (!list1 && !list2)
        return NULL;
    else if (list1 && !list2)
        return list1;
    else if (!list1 && list2)
        return list2;

    if (list1->val < list2->val)
    {
        merged = list1;
        list1 = list1->next;
    }
    else
    {
        merged = list2;
        list2 = list2->next;
    }
    last = merged;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            last->next = list1;
            list1 = list1->next;
        }
        else
        {
            last->next = list2;
            list2 = list2->next;
        }
        last = last->next;
    }
    if (list1)
        last->next = list1;
    else if (list2)
        last->next = list2;
    return merged;
}

int main()
{
    struct ListNode nodes13 = (struct ListNode){.val = 4, .next = NULL};
    struct ListNode nodes12 = (struct ListNode){.val = 2, .next = &nodes13};
    struct ListNode nodes11 = (struct ListNode){.val = 1, .next = &nodes12};

    struct ListNode nodes23 = (struct ListNode){.val = 4, .next = NULL};
    struct ListNode nodes22 = (struct ListNode){.val = 3, .next = &nodes23};
    struct ListNode nodes21 = (struct ListNode){.val = 1, .next = &nodes22};

    struct ListNode* list1 = &nodes11;
    struct ListNode* list2 = &nodes21;
    struct ListNode* merged = mergeTwoLists(list1, list2);
}
