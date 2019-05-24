#include "cpp_util.h"

class Solution
{
public:
    /* Math solution */
    /*
     * Iteration    1   2   3   4   5
     * 1 egg   ->   1 + 1 + 1 + 1 + 1  ...
     * 2 egg   ->   1 + 2 + 3 + 4 + 5  ...
     * 3 egg   ->   1 + 2 + 4 + 7 + 11 ...
     * 4 egg   ->   1 + 2 + 4 + 8 + 15 ...
     * 5 egg   ->   1 + 2 + 4 + 8 + 16 ...
     *              ^
     *              Keep this array and do iteration and keep handleFloors as the sum
     *              of the value from last iteration and the last element in this array
     */
    int solution1(const int &numEggs, const int &numFloors)
    {
        int handleFloors = 1;
        int times = 1;
        int *floorsHandledWithEggs = new int[numEggs];

        fill_n(floorsHandledWithEggs, numEggs, 1);

        printf("Iteration [%d], handles = [%d], floors array = [%s]\n", times, handleFloors, cpp_util::toString(floorsHandledWithEggs, numEggs).c_str());

        while (numFloors > handleFloors)
        {
            ++times;

            for (int addIndex = numEggs - 1; addIndex > 0; --addIndex)
            {
                floorsHandledWithEggs[addIndex] = floorsHandledWithEggs[addIndex - 1] + floorsHandledWithEggs[addIndex];
            }

            handleFloors += floorsHandledWithEggs[numEggs - 1];

            printf("Iteration [%d], handles = [%d], floors array = [%s]\n", times, handleFloors, cpp_util::toString(floorsHandledWithEggs, numEggs).c_str());
        }

        delete[] floorsHandledWithEggs;

        return times;
    }

    int superEggDrop(int K, int N)
    {
        return solution1(K, N);
    }
};

int main()
{
    Solution solution;

    int times = 0;

    /* ans: 2 */
    //times = solution.superEggDrop(1, 2);
    /* ans: 3 */
    //times = solution.superEggDrop(2, 6);
    /* ans: 4 */
    times = solution.superEggDrop(3, 14);

    printf("Minimum drop times = [%d]\n", times);

    return 0;
}

