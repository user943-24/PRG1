#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

// v1 contains v2

template <class Os, class R> Os &operator<<(Os &os, const R &r) {
    for (const auto &e : r)
        os << e << ' ';
    return os << '\t';
}

template <class T>
constexpr bool contains_all(const std::vector<T> &v1, const std::vector<T> &v2) {
    if(v1.size() < v2.size())
        return false;
    std::vector<T> cv1 = v1;
    std::vector<T> cv2 = v2;
    std::sort(cv1.begin(), cv1.end());
    std::sort(cv2.begin(), cv2.end());
    return std::includes(cv1.begin(), cv1.end(), cv2.begin(), cv2.end());
}

int main() {
    std::vector<std::string> a_str{"hello", "world", "smt", "stas"};
    std::vector<std::string> b_str{"world", "hello"};
    if(contains_all(a_str, b_str))
        std::cout << "true\n";
    else
        std::cout << "false\n";

    std::vector<double> a{6, 4, 2, 4, 1};
    std::vector<double> b{6};
    if(contains_all(a, b))
        std::cout << "true\n";
    else
        std::cout << "false\n";

    std::cout << a << '\n';
}
