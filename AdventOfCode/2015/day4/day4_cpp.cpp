#include <iostream>
#include <string>
#include "md5.h"

int main()
{
    std::string key = "bgvyzdsv";
    std::string coin;
    int number = 1;
    while (true)
    {
        coin = MD5(key + std::to_string(number)).hexdigest();
        if (coin.substr(0, 5) == "00000"){
            break;
        }
        number++;
    }
    // Part 1 result
    std::cout << "The coin is: " << coin << " with number: " << number << "\n";
    number = 1;
    while (true)
    {
        coin = MD5(key + std::to_string(number)).hexdigest();
        if (coin.substr(0, 6) == "000000"){
            break;
        }
        number++;
    }
    // Part 1 result
    std::cout << "The coin is: " << coin << " with number: " << number << "\n";
     
    return 0;
}