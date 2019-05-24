#include "cpp_util.h"

class Solution
{
public:
    void quickSort(vector<int> &array)
    {
        quickPartition(array, 0, array.size());
    }

    void quickPartition(vector<int> &array, const int &start, const int &end)
    {
        printf("Quick partition, [start, end] = [%d, %d]\n", start, end);

        if (start + 1 >= end)
        {
            return;
        }

        if (start + 1 == end - 1)
        {
            if (array[start] > array[end - 1])
            {
                swap(array[start], array[end - 1]);
            }
            return;
        }

        int pivotIndex = cpp_util::randomBetween(start, end - 1);

        swap(array[pivotIndex], array[end - 1]);

        int lowIndex = start;
        int highIndex = end - 1;

        printf("Quick partition, pivot index = [%d], low = [%d], high = [%d]\n", pivotIndex, lowIndex, highIndex);

        while (lowIndex < highIndex)
        {
            if (array[end - 1] < array[lowIndex])
            {
                printf("Before swap, low = [%d], high = [%d], array = [%s]\n", lowIndex, highIndex, cpp_util::toString(array).c_str());

                --highIndex;

                swap(array[lowIndex], array[highIndex]);

                printf("After swap, low = [%d], high = [%d], array = [%s]\n", lowIndex, highIndex, cpp_util::toString(array).c_str());
            }
            else
            {
                ++lowIndex;
            }
        }

        swap(array[highIndex], array[end - 1]);

        printf("After partition, low = [%d], high = [%d], array = [%s]\n", lowIndex, highIndex, cpp_util::toString(array).c_str());

        quickPartition(array, start, highIndex);
        quickPartition(array, highIndex + 1, end);
    }
};

int main()
{
    Solution solution;

    //vector<int> array = {3, 5, 2, 4, 9, 6, 8};
    vector<int> array = {3, 5, 12, 4, -3, 9, 6, 8, 44, 29, -17, 33, -66};

    printf("Unsorted array = [%s]\n", cpp_util::toString(array).c_str());

    solution.quickSort(array);

    printf("Sorted array = [%s]\n", cpp_util::toString(array).c_str());

    return 0;
}

