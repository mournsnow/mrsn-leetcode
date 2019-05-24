#include "cpp_util.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (nullptr == head)
        {
            return nullptr;
        }

        bool cyclic = false;
        int steps = 0;
        ListNode *step1 = head;
        ListNode *step2 = head;

        while ((nullptr != step2->next) && (nullptr != step2->next->next))
        {
            ++steps;

            step1 = step1->next;
            step2 = step2->next->next;

            if (step1 == step2)
            {
                cyclic = true;
                break;
            }
        }

        if (false == cyclic)
        {
            return nullptr;
        }

        step1 = head;
        step2 = head;

        for (int index = 0; index < steps; ++index)
        {
            step2 = step2 -> next;
        }

        for (int index = 0; index < steps + 1; ++index)
        {
            if (step1 == step2)
            {
                return step1;
            }

            step1 = step1->next;
            step2 = step2->next;
        }

        return nullptr;
    }
};

int main()
{
    Solution solution;

    vector<int> intList1 = {3, 2, 0, 4};
    ListNode* list1 = ListNode::createList(intList1);

    ListNode *walk = list1;
    while (nullptr != walk->next)
    {
        walk = walk->next;
    }
    walk->next = list1->next;

    vector<int> intList2 = {1, 2};
    ListNode* list2 = ListNode::createList(intList2);

    walk = list2;
    while (nullptr != walk->next)
    {
        walk = walk->next;
    }
    walk->next = list2;

    vector<int> intList3 = {1};
    ListNode* list3 = ListNode::createList(intList3);

    ListNode* cycle = nullptr;

    /* 2 */
    cycle = solution.detectCycle(list1);
    printf("List 1 cycle node = [%d]\n", cycle->val);

    /* 1 */
    cycle = solution.detectCycle(list2);
    printf("List 2 cycle node = [%d]\n", cycle->val);

    /* nullptr */
    cycle = solution.detectCycle(list3);
    printf("List 3 cycle node = [%p]\n", cycle);

    return 0;
}

