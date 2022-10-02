#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    int *time = new int [N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> time[i];
    }

    std::sort(time, time+N);
    int multiplier = N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += multiplier*time[i];
        multiplier--;
    }

    std::cout << sum << std::endl;
    return 0;
}
