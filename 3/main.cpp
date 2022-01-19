#include <iostream>
#include <vector>

#define vecd std::vector<double>

double dot_product(vecd v1, vecd v2) {
    double out = 0;
    if(v1.size() != v2.size()) {
        throw "Not equal in size";
    }
    for(unsigned i = 0; i < v1.size(); ++i) {
        out += v1[i]*v2[i];
    }
    return out;
}

int main() {
    vecd a{1, 2, 3};
    vecd b{-1, -2, -3};
    double res;
    try {
        res = dot_product(a, b);
    } catch(char const *msg) {
        std::cerr << msg << "\n";
    }
    std::cout << res << "\n";
}
