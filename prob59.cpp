#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
std::vector<T> Read(const std::string &fname)
{
    std::ifstream in (fname);
    std::vector<T> tokens;
    T val;

    while (in >> val, !in.eof())
        tokens.push_back(val);

    in.close();
    return tokens;
}

int main()
{
    const std::string INPUT_FILE = "resources/prob59.in";
    const std::string COMMON_WORDS_FILE = "resources/common.txt";

    std::vector<int> encoded (Read<int>(INPUT_FILE));
    std::vector<std::string> words (Read<std::string>(COMMON_WORDS_FILE));

    std::string decoded;
    decoded.resize(encoded.size());

    const int PERMUTATIONS = 26 * 26 * 26;
    for (int i = 0; i < PERMUTATIONS; i++) {
        int key[] {'a' + i / 676, 'a' + (i % 676) / 26, 'a' + i % 26};
        int sum = 0;

        for (int j = 0; j < encoded.size(); j++)
            sum += decoded[j] = encoded[j] ^ key[j % 3];

        int count = 0;
        for (std::string word: words)
            count += decoded.find(word) != std::string::npos;
        
        if (count > 30) {
            std::cout << "Decoded Text:\n\n" << decoded << "\n\n";
            std::cout << "ASCII Sum = " << sum << '\n';
        }
    }

    return 0;
}
