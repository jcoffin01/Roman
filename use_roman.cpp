#include <iostream>
#include "roman.h"

int main() {
    auto loc = std::locale(std::locale(), new roman<char>);
    std::cout.imbue(loc);

    for (int i = 1; i <= 100; i++) {
        std::cout << i << "\t";
        if (i % 10 == 0)
            std::cout << "\n";
    }
}
