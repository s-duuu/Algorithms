#include <iostream>
#include <cstdlib>

int main()
{
    double sum = 0;
    for (int i = 0; i < 8; i++)
    {
        double num;
        std::cin >> num;
        sum += num;
    }

    std::cout << sum/8 << std::endl;

    return 1;
}