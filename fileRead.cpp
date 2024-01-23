#include "fileRead.h"

void SkaitytiIsFailo(std::string failoVardas, std::list<Studentas>& grupe, std::chrono::duration<double>& SortingAndFileTime) {
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
                    std::cerr << "Pazymio nera\n";
                }
            }

            if (!laikPaz.empty()) {
                tempStudent.SetEgzaminas(laikPaz.back());
                laikPaz.pop_back();
                tempStudent.SetNamuDarbai(laikPaz);
                tempStudent.SkaiciuotiGalutiniBala();
                grupe.push_back(tempStudent);
                cout << tempStudent;


                // Savo varianto optimizavimas stipriai pagerino duomenu rusiavima. 
                // studentai5000.txt atliktas per 11 sekundziu vs. mano seno kodo 897 sekundiu.

                std::vector<Studentas> MinStudentai;
                std::vector<Studentas> MaxStudentai;
                auto SortingAndFileStart = std::chrono::high_resolution_clock::now();
                if (tempStudent.GetGalutinis() < 5.0) {
                    std::ofstream MinStudentaiFile("MinStudentai.txt", std::ios::app);
                    MinStudentaiFile << tempStudent;
                    MinStudentaiFile.close();
                }
                else {
                    std::ofstream MaxStudentaiFile("MaxStudentai.txt", std::ios::app);
                    MaxStudentaiFile << tempStudent;
                    MaxStudentaiFile.close();
                }

                auto SortingAndFileEnd = std::chrono::high_resolution_clock::now();
                SortingAndFileTime += SortingAndFileEnd - SortingAndFileStart;


            }
        }
        else {
            break;
        }
    }
    failas.close();

}