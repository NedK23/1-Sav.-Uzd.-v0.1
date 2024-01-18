#include "fileRead.h"

void SkaitytiIsFailo(std::string failoVardas, std::vector<Studentas> &grupe) {
  std::ifstream failas(failoVardas);
  if (!failas.is_open()) {
    std::cerr << "Nepavyko atidaryti failo." << std::endl;
    return;
  }


  std::string header;
  getline(failas, header);

  while (failas) {
    if (!failas.eof()) {
      std::string eilute;
      std::getline(failas, eilute);
      std::stringstream my_buffer(eilute);
      Studentas tempStudent;

      std::string temp;
      my_buffer >> temp;
      tempStudent.SetVardas(temp);

      my_buffer >> temp;
      tempStudent.SetPavarde(temp);

      int n;
      my_buffer >> n;
      tempStudent.NustatytiNamuDarbuSkaiciu(n);

      std::vector<int> laikPaz;
      int pazymys;
      while (my_buffer >> pazymys) {
        if (pazymys >= 0 && pazymys < 11) {
          laikPaz.push_back(pazymys);
        } else {
          std::cerr << "Pazymis sugadintas\n";
        }
      }

      if (!laikPaz.empty()) {
        tempStudent.SetEgzaminas(laikPaz.back());
        laikPaz.pop_back();
        tempStudent.SetNamuDarbai(laikPaz);
        tempStudent.SkaiciuotiGalutiniBala();
        grupe.push_back(tempStudent);
      }
    } else {
      break;
    }
  }
  failas.close();
}