#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N, K;
    std::cin >> N >> K;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    int index = N-1;
    int flag = K;
    std::vector<int> nums;
    int sum = 0;
    while (index >= 0)
    {
        sum += flag / arr[index];
        flag = flag % arr[index];
        index--;
    }

    std::cout << sum << std::endl;
    return 0;
}
