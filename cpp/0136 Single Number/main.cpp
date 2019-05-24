#include "cpp_util.h"

class Solution
{
public:
    /* Time: O(n), Space: O(1) */
    int solution1(vector<int> &nums)
    {
        int single = 0;

        for (const int &value : nums)
        {
            single ^= value;
        }

        return single;
    }

    /* Time: O(n^2), Space: O(n) */
    int solution2(vector<int> &nums)
    {
        vector<int> list;

        for (const int &value : nums)
        {
            auto findIter = find(list.begin(), list.end(), value);

            if (list.end() == findIter)
            {
                list.push_back(value);
            }
            else
            {
                list.erase(findIter);
            }
        }

        assert (1 == list.size());

        return list[0];
    }

    /* Time: O(n), Space: O(n) */
    int solution3(vector<int> &nums)
    {
        unordered_map<int, int> hash;

        for (const int &value : nums)
        {
            auto findIter = hash.find(value);

            if (hash.end() != findIter)
            {
                hash.erase(findIter);
            }
            else
            {
                hash.insert(make_pair(value, 1));
            }
        }

        assert (1 == hash.size());

        return hash.begin()->first;
    }

    /* Time: O(n), Space: O(n) */
    int solution4(vector<int> &nums)
    {
        set<int> intSet;
        int listSum = 0;
        int setSum = 0;

        for (const int &value : nums)
        {
            intSet.insert(value);
            listSum += value;
        }

        for (const int &value : intSet)
        {
            setSum += value;
        }

        return setSum * 2 - listSum;
    }

    int singleNumber(vector<int>& nums)
    {
        //return solution1(nums);
        //return solution2(nums);
        //return solution3(nums);
        return solution4(nums);
    }
};

int main()
{
    Solution solution;

    ///* 1 */
    //vector<int> inputArray = {2, 2, 1};

    /* 4 */
    vector<int> inputArray = {4, 1, 2, 1, 2};

    printf("Input Array = [%s]\n", cpp_util::toString(inputArray).c_str());

    int singleNumber = solution.singleNumber(inputArray);

    printf("Single number = [%d]\n", singleNumber);

    return 0;
}

