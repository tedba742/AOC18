#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

int main() {
    std::fstream file{"input.txt"};
    std::string line{""};
    std::vector<int> frequencyChanges;
    int currentFrequency{0};
    std::unordered_set<int> seenFrequencies;
    
    while (getline(file, line)) {
        int value = std::stoi(line);
        frequencyChanges.push_back(value);
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    seenFrequencies.insert(currentFrequency);
    while (true) {
        for (int value : frequencyChanges) {
            currentFrequency += value;
            if (seenFrequencies.find(currentFrequency) != seenFrequencies.end()) {
                std::cout << "First frequency reached twice: " << currentFrequency << std::endl;
                return 0;
            }
            seenFrequencies.insert(currentFrequency);
        }
    }
    
}
