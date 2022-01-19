#include <iostream>
#include <vector>
#include <algorithm>

typedef struct student {
  std::string         imie;
  std::string         nazwisko;
  std::vector<double> oceny;
} student;

typedef struct group {
  std::string          nazwa;
  std::vector<student> studenci;
} group;

double average_of(student s) {
    double out = 0;
    for(auto const el : s.oceny) {
        out += el;
    }
    return out/s.oceny.size();
}

template<class T>
T median(std::vector<T> v) {
    std::sort(v.begin(), v.end());
    if(v.size()%2 == 0) {
        return (v[v.size()/2-1]+v[v.size()/2])/2;
    }
    return v[v.size()/2-1];
}

group best_group(std::vector<group> v) {
    double m = 0;
    group best;
    for(auto const el : v) {
        std::vector<double> all_averages;
        for(auto const el2 : el.studenci) {
            all_averages.push_back(average_of(el2));
        }
        if(m < median(all_averages)) {
            m = median(all_averages);
            best = el;
        }
    }
    return best;
}

int main() {
    student a{"a", "a", {3, 3, 3, 3, 3, 3, 3}};
    student b{"b", "b", {5, 5, 5, 5, 5, 5, 5}};
    student c{"c", "c", {4, 4, 4, 4, 4, 4, 4}};
    student d{"d", "d", {2, 2, 2, 2, 2, 2, 2}};
    group g1{"g1", {}};
    g1.studenci.push_back(a);
    g1.studenci.push_back(b);
    g1.studenci.push_back(c);
    group g2{"g2", {}};
    g2.studenci.push_back(b);
    g2.studenci.push_back(c);
    g2.studenci.push_back(d);
    group g3{"g3", {}};
    g3.studenci.push_back(a);
    g3.studenci.push_back(b);
    g3.studenci.push_back(d);
    std::vector<group> v{g1, g2, g3};
    group g = best_group(v);
    std::cout << g.nazwa << "\n";
}
