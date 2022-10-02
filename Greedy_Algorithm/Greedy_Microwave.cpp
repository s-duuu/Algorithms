#include <iostream>
#include <cstdlib>

int main()
{
    // second input
    int T;
    std::cin >> T;

    int arr[3] = {300, 60, 10};

    int num[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        num[i] += T / arr[i];
        T %= arr[i];
    }

    if (T != 0)
    {
        std::cout << "-1";
    }

    else
    {
        std::cout << num[0] << " " << num[1] << " " << num[2];
    }
}
