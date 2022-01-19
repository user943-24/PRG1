#include <iostream>
#include <vector>

#define vecstr std::vector<std::string>

vecstr filter_palindromes(vecstr v) {
    vecstr out;
    for(auto const el : v) {
        bool check = true;
        for(unsigned i = 0; i < el.size()/2; ++i) {
            if(el[i] != el[el.size()-1-i]) {
                check = false;
            }
        }
        if(check) {
            out.push_back(el);
        }
    }
    return out;
}

int main() {
    vecstr test{"kajak", "test", "sedes"};
    test = filter_palindromes(test);
    for(auto const el : test) {
        std::cout << el << "\n";
    }
}
