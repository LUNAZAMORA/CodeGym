#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

std::pair<int, int> current_house_coordinates;
std::pair<int, int> current_house_coordinates_robot;
std::vector<std::pair<int, int>> houses_visited;

void perform_move(char move, std::pair<int, int> &current_house_coordinates)
{
    int x, y;
    if (move == '^') {// y + 1
        //x = current_house_coordinates[0];
        //y = current_house_coordinates[1] + 1;
        //current_house_coordinates = {x, y};
        current_house_coordinates.second += 1;
    } else if (move == 'v') {// y - 1
        //x = current_house_coordinates[0];
        //y = current_house_coordinates[1] - 1;
        //current_house_coordinates = {x, y};
        current_house_coordinates.second -= 1;
    } else if (move == '>') {// x + 1
        //x = current_house_coordinates[0] + 1;
        //y = current_house_coordinates[1];
        //current_house_coordinates = {x, y};
        current_house_coordinates.first += 1;
    } else if (move == '<') {// x - 1
       //x = current_house_coordinates[0] - 1;
       //y = current_house_coordinates[1];
       //current_house_coordinates = {x, y};
       current_house_coordinates.first -= 1;
    } else{
        std::cout << "ERROR\n";
    }

}

int add_no_repetitions(std::vector<std::pair<int, int>> &houses_visited, std::pair<int, int> &current_house_coordinates)
{
    for (auto elem : houses_visited) {
        if (current_house_coordinates == elem) {
            return 1;
        }
    }
    houses_visited.push_back(current_house_coordinates);
    return 0;
}
int main()
{
    current_house_coordinates = {0, 0};
    std::ifstream file_input;
    file_input.open("input.txt");
    std::string directions;
    std::getline(file_input, directions);

    for (char move: directions) {
        perform_move(move, current_house_coordinates);
        add_no_repetitions(houses_visited, current_house_coordinates);
    }

    // Result of part 1
    std::cout << houses_visited.size() << "\n";


    houses_visited.clear();
    int turn = 0;
    current_house_coordinates = {0, 0};
    current_house_coordinates_robot = {0, 0};
    for (char move: directions) {
        if (turn == 0) {
            perform_move(move, current_house_coordinates);
            add_no_repetitions(houses_visited, current_house_coordinates);
        } else if (turn == 1) {
            perform_move(move, current_house_coordinates_robot);
            add_no_repetitions(houses_visited, current_house_coordinates_robot);
        }
        turn ^= 1;
    }

    // Result of part 2
    std::cout << houses_visited.size() << "\n";
    file_input.close();
    return 0;
}