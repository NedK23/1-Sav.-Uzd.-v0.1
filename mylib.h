#pragma once

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::mt19937;
using std::sort;
using std::string;
using std::vector;

class Studentas {
private:
  string vardas;
  string pavarde;
  vector<int> namuDarbai;
  int egzaminas;
  double galutinis;

public:
  Studentas();

  Studentas(const Studentas &other);
  Studentas &operator=(const Studentas &other);
  friend std::ostream &operator<<(std::ostream &out, const Studentas &A);
  friend std::istream& operator>>(std::istream& in, Studentas& a);

  
  void NustatytiNamuDarbuSkaiciu(int skaicius) { namuDarbai.resize(skaicius); };
  inline void SetVardas(std::string V) { vardas = V; };
  inline void SetPavarde(std::string P) { pavarde = P; };
  inline void SetNamuDarbai(std::vector<int> ND) { namuDarbai = ND; };
  inline void SetEgzaminas(int E) { egzaminas = E; };
  string GetVardas() const { return vardas; };
  friend bool operator<(const Studentas &A, const Studentas &B) { return A.GetVardas() < B.GetVardas(); };
  

  ~Studentas();

  int ExptSkaiciuChecker(int &Pasirinkimas);

  void DuomenųĮvedimas(int namuDarbųSkaicius, bool generuotiBalus);

  void SkaiciuotiGalutiniBala();

  double Vidurkis() const;

  double Mediana() const;

  void print(bool vidurkis) const;

  };
