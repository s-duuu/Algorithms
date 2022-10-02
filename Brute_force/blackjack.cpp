#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int *arr = new int [N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    std::vector<int> candidates;

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                if (arr[i] + arr[j] + arr[k] <= M)
                {
                    candidates.push_back(arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }

    std::sort(candidates.begin(), candidates.end());
    std::reverse(candidates.begin(), candidates.end());

    std::cout << candidates.at(0);

    return 0;
}