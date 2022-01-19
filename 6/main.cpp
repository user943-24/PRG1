#include <iostream>
#include <vector>

typedef struct student {
    std::string imie;
    std::string nazwisko;
    std::vector<double> oceny;
} student;

double average_of(student s) {
    double out = 0;
    for(auto const el : s.oceny) {
        out += el;
    }
    return out/s.oceny.size();
}

student get_best_student(std::vector<student> v) {
    student best;
    double m = 0;
    for(auto const el : v) {
        double tmp = average_of(el);
        if(m < tmp) {
            m = tmp;
            best = el;
        }
    }
    return best;
}

int main() {
    student a{"a", "a", {2, 3, 4, 4, 3, 5, 2}};
    student b{"b", "b", {2, 5, 5, 5, 5, 5, 5}};
    student c{"c", "c", {2, 3, 2, 2, 2, 3, 5}};
    std::vector<student> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    std::cout << get_best_student(v).imie << "\n";
}
