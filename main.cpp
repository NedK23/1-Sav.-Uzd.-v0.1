#include "mylib.h"
#include "fileRead.h"



// Perrašom koda, geresne struktūra, nes praeitame kode vartotojui nebūvo galima
// įrašyti savų duomenų, nesugadinant skaitymo iš failo, ir vice versa :)))


int main() {
  std::vector<Studentas> studentai;
  //system("dir *.txt"); // ant Replit ši komanda neviekia, tad nežinau ar ji čia tinka
  Studentas obj;

  // Mielai pakeisčiau tikrinimą į switch case expt funkcija,
  // bet dėl jokios priežasties jis nenori čia veikti :)
  // skaitytiIsFailo buvo pakeistas į int.

  std::cout << "Ar norite nuskaityti duomenis is failo? ( Y | N): ";
  std::string skaitytiIsFailo;
  cin >> skaitytiIsFailo;

  if (skaitytiIsFailo == "y" || skaitytiIsFailo == "Y") {
    std::string failoVardas;
    std::cout << "Iveskite failo varda: ";
    std::cin >> failoVardas;

    std::ifstream failas(failoVardas);
    if (!failas.is_open()) {
      std::cerr << "Nepavyko atidaryti failo." << std::endl;
      return 1;
    }
    
    SkaitytiIsFailo(failoVardas, studentai);
    std::sort(studentai.begin(), studentai.end());
    failas.close();
  } else {
    int namuDarbuSkaicius;
    std::cout << "Iveskite namu darbu skaiciu: ";
    std::cin >> namuDarbuSkaicius;

    int studentuSkaicius;
    std::cout << "Iveskite studentu skaiciu: ";
    std::cin >> studentuSkaicius;

    studentai.resize(studentuSkaicius);

    for (auto &studentas : studentai) {
      studentas.DuomenųĮvedimas(namuDarbuSkaicius, true);
    }
  }
  /*
  Result: Studentai surikiuoti ABCele, galutinis balas sufurmuotas 2 skč po kablelio
           Vardas       Pavardė    Galutinis (Vid.)
  ----------------------------------------------------------
               A1      Pavardė1                8.90
               B2      Pavardė2                6.30
               C3      Pavardė3                8.90
               D4      Pavardė4                6.30
               E5      Pavardė5                8.60
 */

  std::cout << "Kaip skaiciuoti galutini balą? - (vidurkis - 1, mediana - 2): ";
  int SkaiciavimoPsr;
  obj.ExptSkaiciuChecker(SkaiciavimoPsr);

  switch (SkaiciavimoPsr) {
  case 1:
    std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė"
              << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    std::cout << "----------------------------------------------------------"
              << std::endl;

    for (const auto &studentas : studentai) {
      studentas.print(true);
    }
    break;
  case 2:
    std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė"
              << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "----------------------------------------------------------"
              << std::endl;

    for (const auto &studentas : studentai) {
      studentas.print(false);
    }
    break;
  default:
    std::cerr << "Netinkamas pasirinkimas." << std::endl;
    return 1;
    break;
  }
  return 0;
}
