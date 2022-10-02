#include <iostream>
#include <cstdlib>

int main()
{
    int price;
    std::cin >> price;

    int change = 1000 - price;

    int arr[6] = {500 , 100, 50, 10, 5, 1};
    int flag = 0;
    int sum = 0;
    while (change > 0)
    {
        if (change == 0)
        {
            break;
        }
        sum += change / arr[flag];
        change %= arr[flag];
        flag++;
    }

    std::cout << sum;
}
