/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

#include <unordered_set>

class Solution
{
  public:
    /// @brief Hashtable
    /// @param head
    /// @return
    bool hasCycle(ListNode* head)
    {
        if (!head)
            return false;
        std::unordered_set<ListNode*> nodes;
        while (head->next)
        {
            if (nodes.insert(head).second == false) // insertion failed
                return true;
            head = head->next;
        }
        return false;
    }
/*
    /// @brief Slow and fast pointers
    /// @param head
    /// @return
    bool hasCycle(ListNode* head)
    {
        if (!head || head->next == nullptr || head->next->next == nullptr)
            return false;
        const ListNode* slow = head;
        const ListNode* fast = head->next;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                return true;
            if (!fast)
                return false;
            fast = fast->next;
            if (slow == fast)
                return true;
            if (!fast)
                return false;
        }
        return false;
    }
// */
};
