#include <array>
#include <iostream>
#include <numeric>
#include <string>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;

class studentas {
  string vard, pav;
  int n = 2;
  int paz1;
  int paz2;
  int paz3;
  int egz;
  double rez;

public:
  studentas() { // Duomenų įvedimo metodas (perdengtas cin)
    cout << "Ivesk studento varda: ";
    cin >> vard;
    cout << "Ivesk pavarde: ";
    cin >> pav;
    cout << "ivesk 3 Namu darbu pazymius! ";
    cin >> paz1 >> paz2 >> paz3;
    cout << "ivesk egzamino pazymi: ";
    cin >> egz;
  }

  studentas(const studentas &temp) { // Kopijavimo konstruktorius
    vard = temp.vard;
    pav = temp.pav;
    paz1 = temp.paz1;
    paz2 = temp.paz2;
    paz3 = temp.paz3;
    egz = temp.egz;
  }

  studentas &operator=(const studentas &temp) { // Priskyrimo operatorius
    if (this == &temp)
      return *this;
    vard = temp.vard;
    pav = temp.pav;
    paz1 = temp.paz1;
    paz2 = temp.paz2;
    paz3 = temp.paz3;
    egz = temp.egz;
    return *this;
  }

  ~studentas() { // Destruktorius
    vard.clear();
    pav.clear();
    egz = 0;
    rez = 0;
    paz1 = 0;
    paz2 = 0;
    paz3 = 0;
  }
  void Skaiciavimas() {
    for (int i = 0; i < n; i++) {
      int vid = (paz1 + paz2 + paz3) / 3;
      rez = 0.4 * vid + 0.6 * egz;
    }
  }

  void print() { // Duomenų išvedimo metodas (perdengtas cout)
    printf("|%-10s|%10s|", vard.c_str(), pav.c_str());
    printf("%.2f\n", rez);
  }
  // ============================================================
};
int main() {
  int n = 2;
  studentas obj[n];

  printf("|%-10s|%10s|%10s", "Vardas", "Pavarde", "Pazymys (vid.)");
  cout << endl;
  cout << "-------------------------------------------\n";
  for (int i = 0; i < n; i++) {
    obj[i].Skaiciavimas();
    obj[i].print();
  }
  return 0;
}