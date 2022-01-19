#include <iostream>
#include <vector>
#include <string>

#define vecstr std::vector<std::string>

vecstr split(std::string s) {
    vecstr out;
    size_t last = 0;
    for(;;) {
        size_t end = s.find(" ", last);
        if(end == std::string::npos) {
            out.push_back(s.substr(last));
            break;
        }
        out.push_back(s.substr(last, end-last));
        last = end+1;
    }
    return out;
}

int main() {
    vecstr test;
    std::string a{"Ala ma kota"};
    test = split(a);
    for(auto const el: test) {
        std::cout << el << "\n";
    }
}
