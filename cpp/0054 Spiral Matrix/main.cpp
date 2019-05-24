#include "cpp_util.h"

enum class DIRECTION : int {RIGHT, DOWN, LEFT, UP, DUMMY};

class Solution
{
public:
    bool isEnd(const int &height, const int &width, const DIRECTION &direction, const int &walkY, const int &walkX)
    {
        DIRECTION nextDirection = DIRECTION(((int)direction + 1) % (int)DIRECTION::DUMMY);

        if ((false == isWalkable(height, width, direction, walkY, walkX)) && (false == isWalkable(height, width, nextDirection, walkY, walkX)))
        {
            return true;
        }

        return false;
    }

    bool isWalkable(const int &height, const int &width, const DIRECTION &direction, const int &walkY, const int &walkX)
    {
        int offset = 0;

        switch(direction)
        {
            case DIRECTION::RIGHT:
                offset = walkY;

                return (walkX < width - 1 - offset);

                break;
            case DIRECTION::DOWN:
                offset = width - 1 - walkX;

                return (walkY < height - 1 - offset);

                break;
            case DIRECTION::LEFT:
                offset = height - 1 - walkY;

                return (walkX > offset);

                break;
            case DIRECTION::UP:
                offset = walkX + 1;

                return (walkY > offset);

                break;
            default:
                assert(false);
                break;
        }
    }

    void walkToNext(const int &height, const int &width, DIRECTION &direction, int &walkY, int &walkX)
    {
        switch(direction)
        {
            case DIRECTION::RIGHT:
                if (false == isWalkable(height, width, direction, walkY, walkX))
                {
                    direction = DIRECTION::DOWN;
                    walkToNext(height, width, direction, walkY, walkX);
                }
                else
                {
                    ++walkX;
                }
                break;
            case DIRECTION::DOWN:
                if (false == isWalkable(height, width, direction, walkY, walkX))
                {
                    direction = DIRECTION::LEFT;
                    walkToNext(height, width, direction, walkY, walkX);
                }
                else
                {
                    ++walkY;
                }
                break;
            case DIRECTION::LEFT:
                if (false == isWalkable(height, width, direction, walkY, walkX))
                {
                    direction = DIRECTION::UP;
                    walkToNext(height, width, direction, walkY, walkX);
                }
                else
                {
                    --walkX;
                }
                break;
            case DIRECTION::UP:
                if (false == isWalkable(height, width, direction, walkY, walkX))
                {
                    direction = DIRECTION::RIGHT;
                    walkToNext(height, width, direction, walkY, walkX);
                }
                else
                {
                    --walkY;
                }
                break;
            default:
                assert(false);
                break;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> spiral;

        if (0 == matrix.size())
        {
            return spiral;
        }

        DIRECTION direction = DIRECTION::RIGHT;

        const int height = matrix.size();
        const int width = matrix[0].size();

        int walkY = 0;
        int walkX = 0;

        while (false == isEnd(height, width, direction, walkY, walkX))
        {
            //printf("[y, x] = [%d, %d]\n", walkY, walkX);

            spiral.push_back(matrix[walkY][walkX]);

            walkToNext(height, width, direction, walkY, walkX);
        }
        //printf("[y, x] = [%d, %d]\n", walkY, walkX);

        spiral.push_back(matrix[walkY][walkX]);

        return spiral;
    }
};

int main()
{
    Solution solution;

    //vector<vector<int>> matrix = {{1, 2, 3},
    //                              {4, 5, 6},
    //                              {7, 8, 9}};

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};

    vector<int> spiral = solution.spiralOrder(matrix);

    printf("Spiral = [%s]\n", cpp_util::toString(spiral).c_str());

    return 0;
}

