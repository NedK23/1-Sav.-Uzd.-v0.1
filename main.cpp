#include "fileRead.h"
#include "mylib.h"
#include <chrono>


int main() {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Studentas> studentai;
  Studentas obj;

  // Mielai pakeisčiau tikrinimą į switch case expt funkcija,
  // bet dėl jokios priežasties jis nenori čia veikti :)
  // skaitytiIsFailo buvo pakeistas į int.

  std::cout << "Ar norite nuskaityti duomenis is failo? ( Y | N): ";
  std::string skaitytiIsFailo;
  cin >> skaitytiIsFailo;

  if (skaitytiIsFailo == "y" || skaitytiIsFailo == "Y") {
    auto DataReadingStart = std::chrono::high_resolution_clock::now();
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

    auto DataReadingEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> DataReadingTime = DataReadingEnd - DataReadingStart;
    std::cout << "Duomenu skaitymo laikas: " << DataReadingTime.count() << " seconds" << std::endl;
    
  } else {
    std::cout << "Automatiškai generuoti studentus? (1 = Y/ 2 = N): ";
    int Pasrk2;
    obj.ExptSkaiciuChecker(Pasrk2, 2);
    
    //==============================================
    
    switch (Pasrk2) {
    case 1: {
      int nrStudentu;
      std::cout << "Iveskite studentu skaiciu: ";
      std::cin >> nrStudentu;
      
      studentai.resize(nrStudentu);
      auto GenStart = std::chrono::high_resolution_clock::now();
      
      for (auto &studentas : studentai) {
        obj.GeneruotiStudenta(studentas);
      }
      
      auto GenEnd = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> GenTime = GenEnd - GenStart;
      std::cout << "Duomenu nuskaitymo laikas: " << GenTime.count() << " seconds" << std::endl;
      
      std::string userFileName;
      std::cout << "Įrašykite sukurtiamo failo pavadinima: ";
      std::cin >> userFileName;
      
      auto FileInputStart = std::chrono::high_resolution_clock::now();
      
      //==============================================
      obj.OutputToUserFile(userFileName, studentai);
      //==============================================
      auto FileInputEnd = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> FileInputTime = FileInputEnd - FileInputStart;
      std::cout << "Failo Irašymo laikas: " << FileInputTime.count() << " seconds" << std::endl;
      
      
      break;
      }
    case 2:
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

    std::cout
        << "Kaip skaiciuoti galutini balą? - (vidurkis - 1, mediana - 2): ";
    int SkaiciavimoPsr;
    obj.ExptSkaiciuChecker(SkaiciavimoPsr, 2);
  
    //==============================================
    
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
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> totalTime = end - start;
  std::cout << "Visas programos veikimo laikas: " << totalTime.count() <<    " seconds" << std::endl;

  return 0;
}
