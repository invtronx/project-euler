# How many n-digit positive integers exist which are also an nth power?

def count_required_numbers(power):      # also digits
    count = 0
    print(power, end = ": ")
    for x in range(1, 10):
        y = x ** power
        if len(str(y)) == power:
            count += 1
            print(x, "~", y, end = ", ")
    print()
    return count


def main():
    power = 1
    count = 0
    current_count = 1       # Anything non-zero works

    while current_count > 0:
        current_count = count_required_numbers(power)
        count += current_count
        power += 1

    print(count)

    return None

if __name__ == '__main__':
    main()

