#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

bool compare(std::pair <int,int> a, std::pair <int,int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int,int>> vec;
    std::vector<std::pair<int,int>> confirmed;

    for (int i = 0; i < N; i++)
    {
        int a,b;
        std::cin >> a >> b;
        vec.push_back(std::pair<int,int>(a,b));
    }

    std::sort(vec.begin(), vec.end(), compare);

    confirmed.push_back(vec.at(0));

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec.at(i).first >= confirmed.back().second)
        {
            confirmed.push_back(vec.at(i));
        }
    }

    std::cout << confirmed.size() << std::endl;
}
