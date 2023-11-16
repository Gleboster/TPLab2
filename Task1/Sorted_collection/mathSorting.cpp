#include "mathSorting.h"

namespace Sorting {
    int roundToPowerOfTwo(int x) {
        int power = static_cast<int>(ceil(log2(x)));
        int result = static_cast<int>(pow(2, power));
        return result;
    }
}