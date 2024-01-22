#pragma once

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>

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
  double totalTimeSum = 0.0;


public:
  Studentas();

  Studentas(const Studentas &other);
  Studentas &operator=(const Studentas &other);
  friend std::ostream &operator<<(std::ostream &out, const Studentas &A);
  friend std::istream& operator>>(std::istream& in, Studentas& a);

  
  void SetNamuDarbuNum(int skaicius) { namuDarbai.resize(skaicius); };
  inline void SetVardas(std::string V) { vardas = V; };
  inline void SetPavarde(std::string P) { pavarde = P; };
  inline void SetNamuDarbai(std::vector<int> ND) { namuDarbai = ND; };
  inline void SetEgzaminas(int E) { egzaminas = E; };
  vector<int>& GetNamuDarbai() { return namuDarbai; };
  int GetGalutinis() { return galutinis; };
  string GetVardas() const { return vardas; };
  friend bool operator<(const Studentas &A, const Studentas &B) { return A.GetVardas() < B.GetVardas(); };
using hrClock = std::chrono::high_resolution_clock;
  

  ~Studentas();

  void GeneruotiStudenta(Studentas &studentas);

  int ExptSkaiciuChecker(int &Pasirinkimas, int Skaicius);

  void DuomenųĮvedimas(int namuDarbųSkaicius, bool generuotiSkc);

  void OutputToUserFile(const std::string& fileName, const std::vector<Studentas>& studentai);

  void SkaiciuotiGalutiniBala();

  double Vidurkis() const;

  double Mediana() const;

  void print(bool vidurkis) const;

  };
