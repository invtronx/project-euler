#include <iostream>

bool IsPrime(int n)
{
    if (n <= 2)
        return n == 2;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i < n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int length = 1;
    int percent = 100;
    int count = 0;
    int n = 1;

    while (percent >= 10) {
        ++n;    // advance right -- enter a bigger spiral
        length += 2;

        n += length - 2;    // advance up -- top-right corner
        count += IsPrime(n);

        n += length - 1;    // advance left -- top-left corner
        count += IsPrime(n);

        n += length - 1;    // advance down -- bottom-left corner
        count += IsPrime(n);

        n += length - 1;    // advance right -- bottom-right corner

        // calculate percentage of primes
        int total = 1 + 4 * (length / 2);
        percent = count * 100 / total;
    }
    std::cout << "length of square spiral = " << length << std::endl;

    return 0;
}
