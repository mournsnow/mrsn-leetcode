#include "cpp_util.h"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (nullptr == head)
        {
            return false;
        }

        ListNode *step1 = head;
        ListNode *step2 = head;

        while ((nullptr != step2->next) && (nullptr != step2->next->next))
        {
            step1 = step1->next;
            step2 = step2->next->next;

            if (step1 == step2)
            {
                return true;
            }
        }

        return false;
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

    bool list1Cyclic = solution.hasCycle(list1);
    bool list2Cyclic = solution.hasCycle(list2);
    bool list3Cyclic = solution.hasCycle(list3);

    printf("List 1 cyclic = [%d]\n", list1Cyclic);
    printf("List 2 cyclic = [%d]\n", list2Cyclic);
    printf("List 3 cyclic = [%d]\n", list3Cyclic);

    return 0;
}

