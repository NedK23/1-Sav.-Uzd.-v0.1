#include "fileRead.h"

void SkaitytiIsFailo(std::string failoVardas, std::list<Studentas>& grupe, std::chrono::duration<double>& SortingTime, std::chrono::duration<double>& FileEnterTime) {
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
            tempStudent.SetNamuDarbuNum(n);
            std::vector<int> laikPaz;
            int pazymys;
            while (my_buffer >> pazymys) {
                if (pazymys >= 0 && pazymys < 11) {
                    laikPaz.push_back(pazymys);
                }
                else {
                    std::cerr << "Pazymis sugadintas\n";
                }
            }

            if (!laikPaz.empty()) {
                tempStudent.SetEgzaminas(laikPaz.back());
                laikPaz.pop_back();
                tempStudent.SetNamuDarbai(laikPaz);
                tempStudent.SkaiciuotiGalutiniBala();
                grupe.push_back(tempStudent);
                cout << tempStudent;

                std::vector<Studentas> MinStudentai;
                std::vector<Studentas> MaxStudentai;
                auto SortingStart = std::chrono::high_resolution_clock::now();
                for (auto& tempStudent : grupe) {
                    if (tempStudent.GetGalutinis() < 5.0) {
                        MinStudentai.push_back(tempStudent);
                    }
                    else {
                        MaxStudentai.push_back(tempStudent);
                    }
                }
                auto SortingEnd = std::chrono::high_resolution_clock::now();
                SortingTime += SortingEnd - SortingStart;

                auto FileEnterStart = std::chrono::high_resolution_clock::now();
                std::ofstream MinStudentaiFile("MinStudentai.txt");
                for (const auto& tempStudent : MinStudentai) {
                    MinStudentaiFile << tempStudent;
                }
                MinStudentaiFile.close();

                std::ofstream MaxStudentaiFile("MaxStudentai.txt");
                for (const auto& tempStudent : MaxStudentai) {
                    MaxStudentaiFile << tempStudent;
                }
                MaxStudentaiFile.close();

                std::ofstream OpenResult("Res.txt");
                for (auto& tempStudent : grupe) {
                    OpenResult << tempStudent;
                }
                OpenResult.close();

                auto FileEnterEnd = std::chrono::high_resolution_clock::now();
                FileEnterTime += FileEnterEnd - FileEnterStart;

            }



        }
        else {
            break;
        }
    }
    failas.close();

}