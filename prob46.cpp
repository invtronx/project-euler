#include <iostream>
#include <vector>
#include <cstdint>
#include "PrimeGenerator.h"

std::vector<bool> GenSquares(uint64_t n)
{
    std::vector<bool> isSquare(n + 1, false);

    for (int x = 1; x * x <= n; x++)
        isSquare[x * x] = true;

    return isSquare;
}

int main()
{
    constexpr uint64_t N = 10000000;

    PrimeGenerator gen = PrimeGenerator(N);
    std::vector<uint64_t> primes { gen.GetPrimes() };

    std::vector<bool> isSquare { GenSquares(N) };

    uint64_t ans = 0x00;
    bool found = false;

    for (uint64_t odd = 0x03, pval; odd <= N && !found; odd += 2) {
        if (gen.IsPrime(odd))
            continue;
        bool squareFound = false;
        for (int i = 0; (pval = primes[i]) < odd && !squareFound; i++) {
            uint64_t rem = odd - pval;
            if (rem % 2 == 0 && isSquare[rem / 2])
                squareFound = true;
        }
        if (!squareFound)
            ans = odd, found = true;
    }

    if (found) {
        std::cout << "Answer = " << ans << std::endl;

        for (int i = 0; primes[i] < ans; i++) {
            uint64_t rem = (ans - primes[i]) / 2;
            std::cout << "= " << primes[i] << " + 2 * ( " << rem << " )\n";
        }
        std::cout << "NOTE: The value in parentheses may be off by 1." << std::endl;
    } else {
        std::cout << "Answer not found. Try a higher limit." << std::endl;
    }

    return 0;
}

