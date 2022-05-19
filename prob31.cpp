#include <iostream>

int main(void)
{
    constexpr int ncoins = 0x08;
    constexpr int coins[] {1, 2, 5, 10, 20, 50, 100, 200};
    constexpr int target = 200;

    int ways[ncoins][target + 1];
    for (int i = 0; i < ncoins; i++)
        ways[i][0] = 0x01;

    for (int cidx = 0; cidx < ncoins; cidx++) {
        for (int tar = 1; tar <= target; tar++) {
            ways[cidx][tar] = (cidx > 0) ? ways[cidx - 1][tar] : 0x00;
            if (tar >= coins[cidx])
                ways[cidx][tar] += ways[cidx][tar - coins[cidx]];
        }
    }

    std::cout << ways[ncoins - 1][target] << std::endl;

    return 0;
}

