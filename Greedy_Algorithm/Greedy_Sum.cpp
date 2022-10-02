#include <iostream>
#include <cstdlib>

int main()
{
    long long s;
    std::cin >> s;

    long long total = s;
    long long flag = 1;

    while (true)
    {
        total -= flag;
        if (total < 0)
        {
            flag--;
            std::cout << flag;
            break;
        }
        /*
        else if (total == 0)
        {
            std::cout << flag;
            break;
        }*/
        flag++;
    }

    return 0;
    
}