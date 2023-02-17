#include <iostream>
#include <map>
#include <string>
#include <fstream>

// Declaration of global variables
std::string text;
std::map<char, int> directions = {
    {'(' , 1} ,
    {')' , -1} 
};
int get_floor(std::string text)
{
    int floor_res = 0;
    for (auto &step : text) {
        floor_res += directions[step];
    }
    return floor_res;
}

int get_getCharacterPosition(std::string text)
{
    int floor_res = 0;
    int char_pos = -1;
    for (auto &step : text) {
        floor_res += directions[step];
        if (floor_res == -1) {
            char_pos = &step - &text[0] + 1;
            return char_pos;
        }
    }
    return char_pos;
}
int main(){
    std::ifstream file_input;
    file_input.open("input.txt");
    if (!file_input)
        std::cerr << "Something went wrong while reading the input file.\n";
    
    std::getline(file_input, text);
    // Part 1 result
    std::cout << get_floor(text) << "\n";
    // Part 2 result
    std::cout << get_getCharacterPosition(text) << "\n";
    return 0;
}