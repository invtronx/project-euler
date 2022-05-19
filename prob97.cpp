#include <iostream>
#include <cstdint>

int main()
{
    const uint64_t MOD = 10000000000;   // 10^10
    const uint64_t EXP2 = 7830457;
    const uint64_t FACTOR = 28433;
    // Evaluate: (FACTOR * (2 ^ EXP2) + 1) % MOD

    uint64_t num = 0x01;

    for (int i = 0; i < EXP2; i++)
        num = (2 * num) % MOD;
    num = (num * FACTOR) % MOD;
    num = (num + 1) % MOD;

    std::cout << "Answer: " << num << std::endl;

    return 0;
}

