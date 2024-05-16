#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <queue>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::map<char, std::vector<char>> prerequisites;
    std::unordered_map<char, int> inDegree;
    std::set<char> allSteps;

    while (std::getline(file, line)) {
        char before = line[5];
        char after = line[36];
        prerequisites[before].push_back(after);
        inDegree[after]++;
        allSteps.insert(before);
        allSteps.insert(after);
    }

    std::priority_queue<char, std::vector<char>, std::greater<char>> availableSteps;

    for (char step : allSteps) {
        if (inDegree[step] == 0) {
            availableSteps.push(step);
        }
    }

    std::string order;

    // topological order
    while (!availableSteps.empty()) {
        char current = availableSteps.top();
        availableSteps.pop();
        order += current;

        for (char next : prerequisites[current]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                availableSteps.push(next);
            }
        }
    }

    std::cout << "Order of steps: " << order << std::endl;

    return 0;
}
