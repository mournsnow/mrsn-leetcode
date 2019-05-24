#include "cpp_util.h"

class Solution
{
public:
    vector<int> solution3(vector<int>& nums, int target)
    {
        vector<int> output;
        unordered_map<int, int> numIndexHash;

        for (int index = 0; index < (int)nums.size(); ++index)
        {
            const int &counterpart = target - nums[index];

            if ((numIndexHash.end() != numIndexHash.find(counterpart)) && (index != numIndexHash[counterpart]))
            {
                output.push_back(numIndexHash[counterpart]);
                output.push_back(index);

                return output;
            }

            numIndexHash[nums[index]] = index;
        }

        return output;
    }

    vector<int> solution2(vector<int>& nums, int target)
    {
        vector<int> output;
        unordered_map<int, int> numIndexHash;

        for (int index = 0; index < (int)nums.size(); ++index)
        {
            numIndexHash[nums[index]] = index;
        }

        for (int index = 0; index < (int)nums.size(); ++index)
        {
            const int &counterpart = target - nums[index];

            if ((numIndexHash.end() != numIndexHash.find(counterpart)) && (index != numIndexHash[counterpart]))
            {
                output.push_back(index);
                output.push_back(numIndexHash[counterpart]);

                return output;
            }
        }

        return output;
    }

    vector<int> solution1(vector<int>& nums, int target)
    {
        vector<int> output;

        for (int start = 0; start < (int)nums.size(); ++start)
        {
            for (int end = start+1; end < (int)nums.size(); ++end)
            {
                if (target == nums[start] + nums[end])
                {
                    output.push_back(start);
                    output.push_back(end);

                    return output;
                }
            }
        }

        return output;
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        //return solution1(nums, target);
        //return solution2(nums, target);
        return solution3(nums, target);
    }
};

int main()
{
    Solution solution;

    /* target: 9, ans: {0, 1} */
    //vector<int> inputArray = {2, 7, 11, 15};

    /* target: 6, ans: {1, 2} */
    vector<int> inputArray = {3, 2, 4};

    printf("Input Array = [%s]\n", cpp_util::toString(inputArray).c_str());

    vector<int> outputArray = solution.twoSum(inputArray, 6);

    printf("Output Array = [%s]\n", cpp_util::toString(outputArray).c_str());

    return 0;
}

