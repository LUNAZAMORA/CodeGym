#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>

std::vector<std::string> dimensions_list;
int get_paper_for_each_present(std::string present_dimensions)
{
   int l, w, h; 
   sscanf(present_dimensions.c_str(), "%dx%dx%d", &l, &w, &h);
   std::vector<int> sides = {l*w , w*h , h*l};
   int extra = *std::min_element(sides.begin(), sides.end());
   int surface_area = 2*sides[0] + 2*sides[1] + 2*sides[2] ;
   return extra + surface_area;
}

int get_feet_of_ribbon(std::string present_dimensions)
{
   int l, w, h; 
   sscanf(present_dimensions.c_str(), "%dx%dx%d", &l, &w, &h);
   std::vector<int> sides = {l, w, h};
   int volume = l*w*h;
   int index = std::max_element(sides.begin(), sides.end()) - sides.begin();
   sides.erase(sides.begin() + index);
   int wrap = 2*sides[0] + 2*sides[1] ;
    return volume + wrap;

}
int main()
{
    std::ifstream file_input;
    file_input.open("input.txt");
    std::string line;
    while (file_input >> line) {
        dimensions_list.push_back(std::move(line));
    }
    int result1 = 0;
    for (auto &present : dimensions_list) {
        result1 += get_paper_for_each_present(present);
    }
    std::cout << result1 << "\n";
    int result2 = 0;
    for (auto &present : dimensions_list) {
        result2 += get_feet_of_ribbon(present);
    }
    std::cout << result2 << "\n";
    file_input.close();
    return 0;
}