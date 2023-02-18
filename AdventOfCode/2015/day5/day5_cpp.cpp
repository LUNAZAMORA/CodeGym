#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>

std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
std::vector<std::string> forbidden = {"ab", "cd", "pq", "xy"};
std::vector<std::string> lines;

bool is_nice(std::string str) 
{
    int vowel_count = 0;
    int twice = 0;
    char prev_c = 0;
    int bad_pair = 0;
    for (auto &c : str) {
        if (c == prev_c)
            twice++;
        if (std::count(vowels.begin(), vowels.end(), c) > 0)
            vowel_count++;
        prev_c = c;
        if (c == 'a' or c == 'c' or c == 'p' or c =='x') {
            if (std::count(forbidden.begin(), forbidden.end(), str.substr(&c- &str[0], 2)) > 0) {
                bad_pair += 1;
                break;
            }

        }
    }
    if (vowel_count >= 3 && twice >= 1 && bad_pair == 0) {
        //std::cout << "vowel count: " << vowel_count << ", twice: " << twice << "\n";
        return true;
    }
        
    return false;
}

bool is_real_nice(std::string str)
{
    int pair_of_two = 0;
    int pair_between = 0;
    std::string pair;
    for (int i = 0; i < str.size(); i++) {
        pair.clear();
        if (i == str.size() - 2)
            break;
        pair.push_back(str[i]);
        pair.push_back(str[i + 1]);
        //std::cout << "pair: " << pair << "\n";
        if (str.substr(i + 2).find(pair) != std::string::npos)
            pair_of_two++;
        if (str.substr(i + 1).find(str[i]) == 1)
            pair_between++;
    }

    if (pair_of_two >= 1 and pair_between >= 1)
        return true;
    return false;
}
int main()
{
    std::ifstream file_input;
    file_input.open("input.txt");
    std::string line;
    int sum = 0;
    while (file_input >> line) {
        lines.push_back(std::move(line));
    }
    for (auto &line : lines) {
        sum += is_nice(line);
    }
    // Part 1 result
    std::cout << sum << "\n";

    sum = 0;
    for (auto &line : lines) {
        sum += is_real_nice(line);
    }
    // Part 2 result
    std::cout << sum << "\n";

    file_input.close();
    return 0;
}