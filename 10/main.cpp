#include <iostream>
#include <vector>
#include <utility>

bool is_letter(char &a) {
    return a > 96 && a < 123;
}

int main() {
    std::vector<std::pair<char, char>> v;
    std::vector<std::string> tmp_v;
    for(;;) {
        std::string tmp;
        std::getline(std::cin, tmp);
        if(tmp == "stop")
            break;
        if(tmp.size() != 3 || !is_letter(tmp[0]) || !is_letter(tmp[2])) {
            std::cout << "[Wrong input, it's going to be ignored]\n";
            continue;
        }
        tmp_v.push_back(tmp);
    }

    for(auto const el : tmp_v) {
        if(el[0] > el[2])
            v.push_back(std::make_pair(el[2], el[0]));
        else
            v.push_back(std::make_pair(el[0], el[2]));
    }

    for(auto const el : v) {
        for(unsigned i=el.first; i <= el.second; i++)
            std::cout << char(i);
        std::cout << "\n";
    }
}
