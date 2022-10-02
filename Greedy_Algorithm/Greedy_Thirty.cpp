#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

bool compare (int i, int j)
{
    return j < i;
}

bool isZero(int *arr, int len)
{
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            flag++;
        }
    }

    if (flag != 0)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

int main()
{
    std::string str;
    std::cin >> str;
    
    int len = str.size();

    int *digit = new int [len];
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        int num = str[i]-48;
        sum += num;
        digit[i] = num;
    }

    if (sum % 3 == 0 && isZero(digit, len))
    {
        std::sort(digit, digit+len, compare);
        for (int i = 0; i < len; i++)
        {
            std::cout << digit[i];
        }
    }

    else 
    {
        std::cout << "-1";
    }
    
    return 0;
}
