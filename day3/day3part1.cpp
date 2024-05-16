#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

struct PieceOfFabric {
    int id;
    int inchesFromLeftEdge;
    int inchesFromTopEdge;
    int width;
    int height;
};

PieceOfFabric parseClaim(const std::string& claim) {
    PieceOfFabric piece;
    char ch;
    std::istringstream iss(claim);
    iss >> ch >> piece.id >> ch >> piece.inchesFromLeftEdge >> ch >> piece.inchesFromTopEdge >> ch >> piece.width >> ch >> piece.height;
    return piece;
}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    const int fabricSize = 1000;
    std::vector<std::vector<int>> fabric(fabricSize, std::vector<int>(fabricSize, 0));

    while (std::getline(file, line)) {
        PieceOfFabric piece = parseClaim(line);
        
        for (int i = 0; i < piece.width; ++i) {
            for (int j = 0; j < piece.height; ++j) {
                fabric[piece.inchesFromLeftEdge + i][piece.inchesFromTopEdge + j]++;
            }
        }
    }

    file.close();

    int overlapCount = 0;
    for (int i = 0; i < fabricSize; ++i) {
        for (int j = 0; j < fabricSize; ++j) {
            if (fabric[i][j] > 1) {
                overlapCount++;
            }
        }
    }

    std::cout << "Number of overlapping square inches: " << overlapCount << std::endl;

    return 0;
}
