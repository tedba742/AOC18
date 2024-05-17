#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>
#include <map>
#include <set>

struct Point {
    int x, y;
};

int manhattanDistance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

std::vector<Point> readCoordinates(const std::string& filename) {
    std::vector<Point> coordinates;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string x, y;
        std::getline(ss, x, ',');
        std::getline(ss, y, ',');

        Point p = {std::stoi(x), std::stoi(y)};
        coordinates.push_back(p);
    }

    return coordinates;
}

int main() {
    const std::string filename = "input.txt";
    std::vector<Point> coordinates = readCoordinates(filename);

    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    for (const auto& point : coordinates) {
        if (point.x < minX) minX = point.x;
        if (point.y < minY) minY = point.y;
        if (point.x > maxX) maxX = point.x;
        if (point.y > maxY) maxY = point.y;
    }

    std::map<int, int> areaSizes;
    std::set<int> infiniteAreas;

    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            Point current = {x, y};
            int minDistance = INT_MAX;
            int closestId = -1;
            bool tie = false;

            for (int i = 0; i < coordinates.size(); ++i) {
                int distance = manhattanDistance(current, coordinates[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestId = i;
                    tie = false;
                } else if (distance == minDistance) {
                    tie = true;
                }
            }

            if (!tie) {
                areaSizes[closestId]++;
                if (x == minX || x == maxX || y == minY || y == maxY) {
                    infiniteAreas.insert(closestId);
                }
            }
        }
    }

    int largestFiniteArea = 0;
    for (const auto& area : areaSizes) {
        if (infiniteAreas.find(area.first) == infiniteAreas.end()) {
            if (area.second > largestFiniteArea) {
                largestFiniteArea = area.second;
            }
        }
    }

    std::cout << "The size of the largest finite area is: " << largestFiniteArea << std::endl;
    return 0;
}
