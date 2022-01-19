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

int main() {
    student s{"imie", "nazwisko", {2, 3, 4, 4, 3, 5, 2}};
    std::cout << average_of(s) << "\n";
}
