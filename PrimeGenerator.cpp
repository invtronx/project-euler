#include <vector>
#include <cstdint>
#include "PrimeGenerator.h"

PrimeGenerator::PrimeGenerator(uint64_t n)
{
    isPrime = std::vector<bool>(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    primes.push_back(0x02);

    uint64_t startAt;
    for (uint64_t x = 4; x <= n; x += 2)
        isPrime[x] = false;
    for (uint64_t x = 3; startAt = x, x * x <= n; x += 2) {
        if (!isPrime[x])
            continue;
        primes.push_back(x);
        for (uint64_t y = x * x; y <= n; y += x)
            isPrime[y] = false;
    }
    for (uint64_t x = startAt; x <= n; x++)
        if (isPrime[x])
            primes.push_back(x);
}

const std::vector<uint64_t> &PrimeGenerator::GetPrimes() const
{
    return primes;
}

bool PrimeGenerator::IsPrime(uint64_t n) const
{
    return isPrime[n];
}

