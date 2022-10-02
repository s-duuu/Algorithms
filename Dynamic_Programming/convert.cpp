#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> dp(N+1);

    dp[1] = 0;
    
    for (int i = 2; i <= N; i++)
    {
        dp.at(i) = dp.at(i-1) + 1;
        
        if (i % 2 != 0 && i % 3 != 0)
        {
            dp[i] = dp[i-1]+1;
        }

        else if (i % 2 == 0 && i % 3 == 0)
        {
            dp[i] = std::min(dp[i/2]+1, dp[i-1]+1);
        }

        else if (i % 2 == 0)
        {
            dp[i] = std::min(dp[i/2]+1, dp[i-1]+1);
        }

        else if (i % 3 == 0)
        {
            dp[i] = std::min(dp[i/3]+1, dp[i-1]+1);
        }
    }

    std::cout << dp[N];

    return 0;
}