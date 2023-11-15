
#ifndef LAB2_MATHSORTING_H
#define LAB2_MATHSORTING_H

#endif //LAB2_MATHSORTING_H


#include <cmath>

int roundToPowerOfTwo(int x) {
    int power = static_cast<int>(ceil(log2(x)));
    int result = static_cast<int>(pow(2, power));
    return result;
}
