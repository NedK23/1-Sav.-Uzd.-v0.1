#include "fileRead.h"
#include "mylib.h"
#include <chrono>
#include <list>


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::list<Studentas> studentai;
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
        std::chrono::duration<double> SortingTime;
        std::chrono::duration<double> FileEnterTime;
        SkaitytiIsFailo(failoVardas, studentai, SortingTime, FileEnterTime);
        studentai.sort();
        failas.close();

        auto DataReadingEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> DataReadingTime = DataReadingEnd - DataReadingStart;
        std::cout << "Duomenu skaitymo laikas: " << DataReadingTime.count() << " seconds" << std::endl;
        std::cout << "Rusiavimo laikas: " << SortingTime.count() << " seconds" << std::endl;
        std::cout << "Isvedimas i failus laikas: " << SortingTime.count() << " seconds" << std::endl;

    }
    else {
        std::cout << "Automatiškai generuoti studentus? (1 = Y/ 2 = N): ";
        int Pasrk2;
        obj.ExptSkaiciuChecker(Pasrk2, 2);

        //==============================================

        switch (Pasrk2) {
        case 1: {
            int nrStudentu;
            std::cout << "Iveskite studentu skaiciu: ";
            std::cin >> nrStudentu;


            auto GenStart = std::chrono::high_resolution_clock::now();
            studentai.emplace_back();

            // In the for loop
            for (int i = 0; i < nrStudentu; i++) {
                Studentas studentas;  // Create a new student object for each iteration
                obj.GeneruotiStudenta(studentas);
                studentai.push_back(studentas);  // Add the generated student to the list
            }

            auto GenEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> GenTime = GenEnd - GenStart;
            std::cout << "Duomenu generavimo laikas: " << GenTime.count() << " seconds" << std::endl;

            std::string userFileName;
            std::cout << "IraSykite sukurtiamo failo pavadinima: ";
            std::cin >> userFileName;

            auto FileInputStart = std::chrono::high_resolution_clock::now();

            //==============================================
            std::list<Studentas> studentaiList(studentai.begin(), studentai.end());
            obj.OutputToUserFile(userFileName, studentaiList);
            //==============================================
            auto FileInputEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> FileInputTime = FileInputEnd - FileInputStart;
            std::cout << "Failo Irasymo laikas: " << FileInputTime.count() << " seconds" << std::endl;


            break;
        }
        case 2:
            int namuDarbuSkaicius;
            std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> namuDarbuSkaicius;

            int studentuSkaicius;
            std::cout << "Iveskite studentu skaiciu: ";
            std::cin >> studentuSkaicius;

            studentai.push_back(Studentas());

            for (auto& studentas : studentai) {
                studentas.DuomenųĮvedimas(namuDarbuSkaicius, true);
            }
        }

        std::cout
            << "Kaip skaiciuoti galutini bala? - (vidurkis - 1, mediana - 2): ";
        int SkaiciavimoPsr;
        obj.ExptSkaiciuChecker(SkaiciavimoPsr, 2);

        //==============================================

        switch (SkaiciavimoPsr) {
        case 1:
            std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė"
                << std::setw(20) << "Galutinis (Vid.)" << std::endl;
            std::cout << "----------------------------------------------------------"
                << std::endl;

            for (const auto& studentas : studentai) {
                studentas.print(true);
            }
            break;
        case 2:
            std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė"
                << std::setw(20) << "Galutinis (Med.)" << std::endl;
            std::cout << "----------------------------------------------------------"
                << std::endl;

            for (const auto& studentas : studentai) {
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
    std::cout << "Visas programos veikimo laikas: " << totalTime.count() << " seconds" << std::endl;

    return 0;
}