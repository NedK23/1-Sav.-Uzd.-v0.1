#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <set>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;

class studentas {
 
  string vard, pav;
  string genr;
  int n = 3;
  int paz[15];
  int egz;
  double Vidrez;
  double Medrez;

public:
  studentas() {
    
    cout << "Ivesk studento varda: ";
    cin >> vard;
    cout << "Ivesk pavarde: ";
    cin >> pav;
    cout << "Kiek namu darbu? (max 15) ";
    cin >> n;
    cout << "Generuoti balus atsitiktinai? y/n";
    cin >> genr;

    if (genr == "y" || genr == "Y") {
      for (int i = 0; i < n; i++) {
        int random = 0 + rand() % (10 - 0 + 1);
        paz[i] = random;
        cout << i + 1 << " Namu darbo pazymys: " << paz[i] << endl;
      }
      int random = 0 + rand() % (10 - 0 + 1);
      egz = random;
      cout << "Egzamino rezultatas: " << egz << endl; 
    } 

    else {
      for (int i = 0; i < n; i++) {
        cout << "ivesk " << i + 1 << " Namu darbo pazymi! ";
        cin >> paz[i];
      }
      cout << "ivesk egzamino pazymi: ";
      cin >> egz;
    }
  }

  studentas(const studentas &temp) { // Kopijavimo konstruktorius
    vard = temp.vard;
    pav = temp.pav;
    egz = temp.egz;

    for (int i = 0; i < n; i++) {
      paz[i] = temp.paz[i];
    }
  }

  studentas &operator=(const studentas &temp) { // Priskyrimo operatorius
    if (this == &temp)
      return *this;
    vard = temp.vard;
    pav = temp.pav;
    egz = temp.egz;

    for (int i = 0; i < n; i++) {
      paz[i] = temp.paz[i];
    }
    return *this;
  }

  ~studentas() { // Destruktorius
    vard.clear();
    pav.clear();
    egz = 0;
    Vidrez = 0;
    Medrez = 0;
    for (int i = 0; i < n; i++) {
      paz[i] = 0;
    }
  }
  void MedSkaiciavimas() {
    if (n == 0)
      throw std::domain_error("Negalima skaiciuoti medianos tusciam masyvui");

    sort(paz, paz + n);

    int vid = n / 2;
    Medrez = n % 2 == 0 ? (paz[vid] + paz[vid - 1] / 2.0) : paz[vid];
  }
  void VidSkaiciavimas() {

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += paz[i];
    }
    int vid = sum / n;
    Vidrez = 0.4 * vid + 0.6 * egz;
  }
  void Vidprint() { // Duomenų išvedimo metodas (perdengtas cout)
    printf("|%-10s|%10s|", vard.c_str(), pav.c_str());
    printf("%.2f\n", Vidrez);
  }
  void Medprint() { // Duomenų išvedimo metodas (perdengtas cout)
    printf("|%-10s|%10s|", vard.c_str(), pav.c_str());
    printf("%.2f\n", Medrez);
  }
  // ============================================================
};
int main() {
  srand(time(0));

  int n = 3;
  string pasrk;

  studentas obj[n];

  cout << "Resultatus apskaiciuoti Vidurkiu ar Mediana? (v/m) " << endl;
  cin >> pasrk;

  if (pasrk == "m") {
    printf("|%-10s|%10s|%10s", "Vardas", "Pavarde", "Galutinis (Med.)\n");
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
      obj[i].MedSkaiciavimas();
      obj[i].Medprint();
    }
  }

  else {
    printf("|%-10s|%10s|%10s", "Vardas", "Pavarde", "Galutinis (vid.)\n");
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
      obj[i].VidSkaiciavimas();
      obj[i].Vidprint();
    }
  }

  return 0;
}