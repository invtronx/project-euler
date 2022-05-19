#ifndef __PRIME_GENERATOR_H
#define __PRIME_GENERATOR_H

class PrimeGenerator {
public:
    explicit PrimeGenerator(uint64_t n);

    const std::vector<uint64_t> &GetPrimes() const;
    bool IsPrime(uint64_t n) const;

private:
    std::vector<uint64_t> primes;
    std::vector<bool> isPrime;
};

#endif  // __PRIME_GENERATOR_H

