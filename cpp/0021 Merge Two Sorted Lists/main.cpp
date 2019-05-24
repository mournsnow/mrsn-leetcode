#include "cpp_util.h"

class Solution
{
public:
    void appendNode(ListNode *&merged, ListNode *&walk, ListNode *append)
    {
        if (nullptr == merged)
        {
            merged = append;
            walk = append;
        }
        else
        {
            walk->next = append;
            walk = append;
        }
    }

    ListNode* popFront(ListNode *&node)
    {
        if (nullptr == node)
        {
            return nullptr;
        }

        ListNode *front = node;

        node = node->next;

        return front;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *merged = nullptr;
        ListNode *walk = nullptr;
        ListNode *first = l1;
        ListNode *second = l2;

        while ((nullptr != first) && (nullptr != second))
        {
            if (first->val <= second->val)
            {
                ListNode *front = popFront(first);

                appendNode(merged, walk, front);
            }
            else
            {
                ListNode *front = popFront(second);

                appendNode(merged, walk, front);
            }
        }

        while ((nullptr == first) && (nullptr != second))
        {
            ListNode *front = popFront(second);

            appendNode(merged, walk, front);
        }
        while ((nullptr != first) && (nullptr == second))
        {
            ListNode *front = popFront(first);

            appendNode(merged, walk, front);
        }

        return merged;
    }
};

int main()
{
    Solution solution;

    vector<int> intList1 = {1, 2, 4};
    ListNode* list1 = ListNode::createList(intList1);

    vector<int> intList2 = {1, 3, 4};
    ListNode* list2 = ListNode::createList(intList2);

    printf("List 1 = [%s]\n", cpp_util::toString(list1).c_str());
    printf("List 2 = [%s]\n", cpp_util::toString(list2).c_str());

    ListNode *merged = solution.mergeTwoLists(list1, list2);

    printf("Merged list = [%s]\n", cpp_util::toString(merged).c_str());

    return 0;
}

