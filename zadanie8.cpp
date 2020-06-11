#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void tree(int number) {
    std::vector<std::string> vec(number);
    std::string first_line(number - 1, ' ');
    first_line.push_back('*');

    vec[0] = first_line;
    std::cout << vec[0] << '\n';

    std::transform(vec.begin() + 1, vec.end(), vec.begin() + 1, [&first_line](std::string& n) {
        first_line.erase(0, 1), first_line.append(2, '*');
        n = first_line;
        n.push_back('\n');
        std::cout << n;
        return n;
    });
}

int main(){
    tree(10);
    return 0;
}