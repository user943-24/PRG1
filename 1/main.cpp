#include <iostream>
#include <vector>

double average_of(std::vector<double> v) {
    double av;
    for(auto const x : v) {
        av += x;
    }
    return av/v.size();
}

int main () {
    std::vector<double> v{1, 2, 3, 4, 5, 6};
    std::cout << average_of(v) << "\n";
}
