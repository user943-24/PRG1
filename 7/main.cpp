#include <iostream>
#include <vector>

typedef struct student {
  std::string         imie;
  std::string         nazwisko;
  std::vector<double> oceny;
} student;

typedef struct group {
  std::string          nazwa;
  std::vector<student> studenci;
} group;

void push_to_group(group *g, student s) {
    (*g).studenci.push_back(s);
}

int main() {
    student a{"a", "a", {2, 3, 4, 4, 3, 5, 2}};
    student b{"b", "b", {2, 5, 5, 5, 5, 5, 5}};
    student c{"c", "c", {2, 3, 2, 2, 2, 3, 5}};
    group g{"nazwa grupy", {}};
    push_to_group(&g, a);
    push_to_group(&g, b);
    push_to_group(&g, c);
    for(auto const el : g.studenci) {
        std::cout << el.imie << "\n";
    }
}
