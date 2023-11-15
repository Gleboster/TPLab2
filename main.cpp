#include <iostream>

int main() {
    int* a = new int[]{1, 2 ,3};

    int* b = a;
    a = new int[4];

    for(int i =0 ; i < 4 ; i++){
        if(i < 3)
            a[i] = b[i];
        else
            a[i] = 0;
    }



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
