#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int countTwos = 0;
    int countThrees = 0;

    while (std::getline(file, line)) {
        std::unordered_map<char, int> letterCounts;
        
        for (char ch : line) {
            letterCounts[ch]++;
        }

        bool hasTwo = false;
        bool hasThree = false;

        for (const auto& pair : letterCounts) {
            if (pair.second == 2) {
                hasTwo = true;
            }
            if (pair.second == 3) {
                hasThree = true;
            }
        }

        if (hasTwo) {
            countTwos++;
        }
        if (hasThree) {
            countThrees++;
        }
    }

    file.close();
    int checksum = countTwos * countThrees;

    std::cout << "Checksum: " << checksum << std::endl;

    return 0;
}
