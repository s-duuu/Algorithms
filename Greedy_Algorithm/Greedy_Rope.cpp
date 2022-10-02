#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    int *arr = new int [N];
    for (int i = 0; i < N; i++)
    {
        std::cin>> arr[i];
    }

    std::sort(arr, arr+N);
    std::reverse(arr, arr+N);

    std::vector<int> weight;

    for (int i = 0; i < N; i++)
    {
        weight.push_back(arr[i]*(i+1));
    }

    std::sort(weight.begin(), weight.end());
    std::reverse(weight.begin(), weight.end());

    std::cout << weight.front();
}
