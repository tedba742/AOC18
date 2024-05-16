#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>

bool hasDuplicate(const std::vector<int>& data) {
    std::unordered_set<int> seen;
    
    for (int num : data) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}

int main(){
    std::fstream file{"input.txt"};
    std::string line{""};
    int currentFrequency{0};
    std::vector<int> visitiedFrequencies{};
    while (getline(file, line))
    {
    int value = std::stoi(line.substr(1));

        if(line[0] == '+'){
            currentFrequency+= value;
            visitiedFrequencies.emplace_back(currentFrequency);
        } else {
            currentFrequency-= value;
            visitiedFrequencies.emplace_back(currentFrequency);

        }        
        
    }
    
    std::cout << currentFrequency << std::endl;
}