#include <iostream>
#include <cstdlib>
#include <algorithm>

void BinarySearch(int *trees, int low, int high, int M, int N)
{
    if (low > high)
    {
        return;
    }

    else 
    {
        int mid = (low + high) / 2;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    int *trees = new int [N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> trees[i];
    }

    std::sort(trees, trees + N);

}