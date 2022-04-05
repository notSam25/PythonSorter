#include <iostream>

int main() {
    system("find . -name *.py -type f -printf '%p\n' -delete");
    return 0;
}