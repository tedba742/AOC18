#include <string>
#include <iostream>
#include <fstream>
#include <stack>

int fullyReactPolymer(const std::string& polymer) {
    std::stack<char> stack;
    
    for (char unit : polymer) {
        if (!stack.empty() && std::tolower(stack.top()) == std::tolower(unit) && stack.top() != unit) {
            stack.pop();
        } else {
            stack.push(unit);
        }
    }
    
    return stack.size();
}

int main() {
    std::fstream file{"input.txt"};
    std::string polymer{""};
    std::getline(file, polymer);

    int remainingUnits = fullyReactPolymer(polymer);
    std::cout << "Remaining units: " << remainingUnits << std::endl;

    return 0;
}
