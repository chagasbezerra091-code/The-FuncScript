// stdbool.cc - Compatível com C++
#include <iostream>

using bool = bool;  // Em C++ bool já existe
const bool true_val = true;
const bool false_val = false;

// Exemplo de uso
int main() {
    bool flag = true_val;
    if (flag) {
        std::cout << "Flag é true!\n";
    } else {
        std::cout << "Flag é false!\n";
    }
    return 0;
}
