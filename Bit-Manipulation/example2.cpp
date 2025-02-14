#include <iostream>

int setBit(int num, int pos)
{
    return num | (1 << pos);
}

int clearBit(int num, int pos)
{
    return num & ~(1 << pos);
}

int main()
{
    int num = 5; // 101 in binary

    std::cout << "Before setting bit at position 1: " << num << std::endl;
    num = setBit(num, 1);
    std::cout << "After setting bit at position 1: " << num << std::endl; // Becomes 7 (111)

    std::cout << "Before clearing bit at position 2: " << num << std::endl;
    num = clearBit(num, 2);
    std::cout << "After clearing bit at position 2: " << num << std::endl; // Becomes 3 (011)

    return 0;
}
