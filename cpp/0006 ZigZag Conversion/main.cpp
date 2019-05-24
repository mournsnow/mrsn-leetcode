#include "cpp_util.h"

#define STRING_BUFFER_SIZE 101

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (1 == numRows)
        {
            return s;
        }

        assert(numRows >= 2);

        const int stringLength = s.size();
        const int loopCount = numRows * 2 - 2;

        string output;

        for (int row = 1; row <= numRows; ++row)
        {
            const int rowIndex = row - 1;

            for (int index = rowIndex; index < stringLength; index += loopCount)
            {
                output += s[index];

                if ((row != 1) && (row != numRows))
                {
                    const int secondIndex = index + (loopCount - 2 * rowIndex);

                    if (secondIndex < stringLength)
                    {
                        output += s[secondIndex];
                    }
                }
            }
        }

        return output;
    }
};

int main()
{
    return 0;
}
