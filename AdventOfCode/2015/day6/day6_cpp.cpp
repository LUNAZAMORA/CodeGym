#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<bool>> lights_lit;
std::vector<std::vector<int>> lights_lit_2;
std::vector<std::string> commands;
void perform_command(std::string command)
{
    std::istringstream ss(command);
    std::string operation;
    ss >> operation;
    if (operation == "turn")
        ss >> operation;
    std::string from, through, to;
    ss >> from >> through  >> to;
    std::istringstream stream_from(from);
    std::istringstream stream_to(to);

    //std::cout << "from: " << from << " to: " << to << "\n";
    
    int y_from = 0, x_from = 0, y_to = 0, x_to = 0;
    std::string str_from, str_to;

    std::getline(stream_from, str_from, ',');
    y_from = std::stoi(str_from);
    std::getline(stream_from, str_from, ',');
    x_from = std::stoi(str_from);

    //std::cout << "y_from: " << y_from << " x_from: " << x_from << "\n";

    std::getline(stream_to, str_to, ',');
    y_to = std::stoi(str_to);
    std::getline(stream_to, str_to, ',');
    x_to = std::stoi(str_to);

    //std::cout << "y_to: " << y_to << " x_to: " << x_to << "\n";

    if (operation == "on") {
        for (int row = y_from; row <= y_to; row++) {
            for (int col = x_from; col <= x_to; col++) {
                lights_lit[row][col] = true;
                lights_lit_2[row][col] += 1;
            }
        }
    } else if (operation == "off") {
        for (int row = y_from; row <= y_to; row++) {
            for (int col = x_from; col <= x_to; col++) {
                lights_lit[row][col] = false;
                if (lights_lit_2[row][col] > 0)
                    lights_lit_2[row][col] -= 1;
            }
        }
    } else if (operation == "toggle") {
        for (int row = y_from; row <= y_to; row++) {
            for (int col = x_from; col <= x_to; col++) {
                lights_lit[row][col] = (lights_lit[row][col] == true) ? false : true;
                lights_lit_2[row][col] += 2;
            }
        }
    }

}

int main()
{
    std::ifstream file_input;
    file_input.open("input.txt");
    std::string line;
    while (std::getline(file_input, line)) {
        commands.push_back(std::move(line));
    }
    for (int j = 0; j < 1000; j++) {
        std::vector<bool> col;
        for (int i = 0; i < 1000; i++) {
            col.push_back(false);
        }
        lights_lit.push_back(std::move(col));
    }
    for (int j = 0; j < 1000; j++) {
        std::vector<int> col;
        for (int i = 0; i < 1000; i++) {
            col.push_back(0);
        }
        lights_lit_2.push_back(std::move(col));
    }
    std::vector<std::string> test_cases = {"turn on 0,0 through 999,999", "toggle 0,0 through 999,0", "turn off 499,499 through 500,500"};
    for (auto command :commands)
        perform_command(command);

    int count1 = 0, count2 = 0;
    for (auto &row : lights_lit) {
        for (auto col : row) {
            if (col) 
                count1++;
        }
    }
    for (auto &row : lights_lit_2) {
        for (auto &col : row) {
            count2 += col;
        }
    }
    // Part 1 Result
    std::cout << count1 << "\n";
    // Part 2 Result
    std::cout << count2 << "\n";

    file_input.close();
    return 0;
}