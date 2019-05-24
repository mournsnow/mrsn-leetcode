#include "cpp_util.h"

class Solution
{
public:
    void transpose(vector<vector<int>> &matrix)
    {
        for (int y = 0; y < (int)matrix.size(); ++y)
        {
            for (int x = y + 1; x < (int)matrix.size(); ++x)
            {
                swap(matrix[y][x], matrix[x][y]);
            }
        }
    }

    void flipY(vector<vector<int>> &matrix)
    {
        for (int y = 0; y < (int)matrix.size(); ++y)
        {
            for (int x = 0; x < ((int)matrix.size() + 1) / 2; ++x)
            {
                swap(matrix[y][x], matrix[y][matrix.size() - 1 -x]);
            }
        }
    }

    /* Time: O(n^2), space O(1) */
    void solution2(vector<vector<int>> &matrix)
    {
        transpose(matrix);

        //printf("After transpose = [%s]\n", cpp_util::toString(matrix).c_str());

        flipY(matrix);

        //printf("After flip = [%s]\n", cpp_util::toString(matrix).c_str());
    }

    void swapValue(vector<vector<int>> &matrix, const int &y, const int &x)
    {
        const int &length = matrix.size();

        int swapeeY = length - 1 - x;
        int swapeeX = y;

        //printf("Swap [%d, %d] with [%d, %d]\n", y, x, swapeeY, swapeeX);

        swap(matrix[y][x], matrix[swapeeY][swapeeX]);
    }

    void swapWithLength(vector<vector<int>> &matrix, const int &rotateLength)
    {
        const int &length = matrix.size();
        const int &start = (matrix.size() - rotateLength) / 2;

        //printf("Length = [%d], rotate length = [%d], start = [%d]\n", length, rotateLength, start);

        /* Downward */
        for (int y = start; y < length - 1 - start; ++y)
        {
            swapValue(matrix, y, start);
        }

        /* Rightward */
        for (int x = start; x < length - 1 - start; ++x)
        {
            swapValue(matrix, length - 1 - start, x);
        }

        /* Upward */
        for (int y = length - 1 - start; y > start; --y)
        {
            swapValue(matrix, y, length - 1 - start);
        }
    }

    /* Time: O(n^2), space O(1) */
    void solution1(vector<vector<int>> &matrix)
    {
        for (int rotateLength = matrix.size(); rotateLength > 0; rotateLength -= 2)
        {
            swapWithLength(matrix, rotateLength);

            //printf("After swap with rotateLength [%d] = [%s]\n", rotateLength, cpp_util::toString(matrix).c_str());
        }
    }

    void rotate(vector<vector<int>>& matrix)
    {
        return solution1(matrix);
        //return solution2(matrix);
    }
};

int main()
{
    Solution solution;

    //vector<vector<int>> inputMatrix =
    //{
    //    {1, 2, 3},
    //    {4, 5, 6},
    //    {7, 8, 9}
    //};

    vector<vector<int>> inputMatrix =
    {
        { 5,  1,  9, 11},
        { 2,  4,  8, 10},
        {13,  3,  6,  7},
        {15, 14, 12, 16}
    };

    printf("Input matrix = [%s]\n", cpp_util::toString(inputMatrix).c_str());

    solution.rotate(inputMatrix);

    printf("Rotated matrix = [%s]\n", cpp_util::toString(inputMatrix).c_str());

    return 0;
}

