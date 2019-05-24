#include "cpp_util.h"

class Solution
{
public:
    /* Time: O(n), Space: O(1) */
    int solution1(vector<int> &nums)
    {
        int temp1 = 0;
        int temp2 = 0;

        for (const int &value : nums)
        {
            temp1 ^= value;
            temp1 &= ~temp2;
            temp2 ^= value;
            temp2 &= ~temp1;

            //printf("Value = [%d], Temp 1 = [%d], temp 2 = [%d]\n", value, temp1, temp2);
        }

        return temp1;
    }

    /* Time: O(n), Space: O(1) */
    int solutionFor4(vector<int> &nums)
    {
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;

        for (const int &value : nums)
        {
            temp1 ^= value;
            temp1 &= ~temp2;
            temp1 &= ~temp3;
            temp2 ^= value;
            temp2 &= ~temp1;
            temp2 &= ~temp3;
            temp3 ^= value;
            temp3 &= ~temp1;
            temp3 &= ~temp2;

            //printf("Value = [%d], Temp 1 = [%d], temp 2 = [%d], temp 3 = [%d]\n", value, temp1, temp2, temp3);
        }

        return temp1;
    }

    int singleNumber(vector<int>& nums)
    {
        return solution1(nums);
        //return solutionFor4(nums);
    }
};

int main()
{
    Solution solution;

    ///* 3 */
    //vector<int> inputArray = {2, 2, 2, 2, 3};

    /* 3 */
    vector<int> inputArray = {2, 2, 2, 3};

    ///* 3 */
    //vector<int> inputArray = {2, 2, 3, 2};

    ///* 99 */
    //vector<int> inputArray = {0, 1, 0, 1, 0, 1, 99};

    printf("Input Array = [%s]\n", cpp_util::toString(inputArray).c_str());

    int singleNumber = solution.singleNumber(inputArray);

    printf("Single number = [%d]\n", singleNumber);

    return 0;
}

