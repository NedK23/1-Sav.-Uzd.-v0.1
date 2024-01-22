#include "mylib.h"
#include <chrono>

Studentas::Studentas() {}

Studentas::Studentas(const Studentas& other) {
    vardas = other.vardas;
    pavarde = other.pavarde;
    namuDarbai = other.namuDarbai;
    egzaminas = other.egzaminas;
    galutinis = other.galutinis;
}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
        galutinis = other.galutinis;
    }
    return *this;
}
Studentas::~Studentas() {
    vardas.clear();
    pavarde.clear();
    namuDarbai.clear();
    egzaminas = 0;
    galutinis = 0;
}
std::ostream& operator<<(std::ostream& out, const Studentas& A) {
    out << A.vardas << " ; " << A.pavarde << " | ";
    for (auto& i : A.namuDarbai)
        out << i << " | ";
    out << A.egzaminas << " | ";
    out << " Galutinis = " << A.galutinis << endl;
    return out;
}
std::istream& operator>>(std::istream& in, Studentas& a) {
    in >> a.vardas;
    in >> a.pavarde;
    a.namuDarbai.clear();
    for (int i = 0; i < 5; i++) {
        int k;
        in >> k;
        a.namuDarbai.push_back(k);
    }
    in >> a.egzaminas;
    a.Vidurkis();
    return in;
}
void Studentas::OutputToUserFile(const std::string& fileName, const std::list<Studentas>& studentai) {
    std::ofstream userFile(fileName + ".txt", std::ios::app);

    if (!userFile.is_open()) {
        std::cerr << "Unable to open file: " << fileName << ".txt" << std::endl;
        return;
    }
    for (const auto& studentas : studentai) {
        userFile << studentas;
    }

    userFile.close();
}
void Studentas::GeneruotiStudenta(Studentas& studentas) {

    std::vector<Studentas> studentai;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> N(0, 9);
    int static i = 0; i += 1;
    studentas.SetVardas("Vardas" + std::to_string(i));
    studentas.SetPavarde("Pavarde" + std::to_string(i));

    int namuDarbuSkaicius = 5;
    studentas.SetNamuDarbuNum(namuDarbuSkaicius);

    studentas.SetNamuDarbai(vector<int>(namuDarbuSkaicius));
    for (int j = 0; j < namuDarbuSkaicius; ++j) {
        studentas.GetNamuDarbai()[j] = N(gen) + 1;
    }

    studentas.SetEgzaminas(N(gen) + 1);
    studentas.SkaiciuotiGalutiniBala();
    studentai.push_back(studentas);

    std::vector<Studentas> MinStudentai;
    std::vector<Studentas> MaxStudentai;

    for (auto& studentas : studentai) {
        if (studentas.GetGalutinis() < 5.0) {
            MinStudentai.push_back(studentas);
        }
        else {
            MaxStudentai.push_back(studentas);
        }
    }

    std::ofstream MinStudentaiFile("MinStudentai.txt", std::ios::app);
    for (const auto& studentas : MinStudentai) {
        MinStudentaiFile << studentas;
    }
    MinStudentaiFile.close();

    std::ofstream MaxStudentaiFile("MaxStudentai.txt", std::ios::app);
    for (const auto& studentas : MaxStudentai) {
        MaxStudentaiFile << studentas;
    }
    MaxStudentaiFile.close();

    std::ofstream OpenResult("Res.txt", std::ios::app);
    for (auto& studentas : studentai) {
        OpenResult << studentas;
    }
    OpenResult.close();


}

int Studentas::ExptSkaiciuChecker(int& Pasirinkimas, int Skaicius) {
    while (true) {
        try {
            std::cin >> Pasirinkimas;

            if (std::cin.fail() || (Pasirinkimas < 1 || Pasirinkimas > Skaicius)) {
                throw std::invalid_argument(
                    "Neteisingas pasirinkimas. Įveskite nuo 1 iki " +
                    std::to_string(Skaicius) + ".");
            }

            return Pasirinkimas;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Studentas::DuomenųĮvedimas(int namuDarbųSkaicius, bool generuotiSkc) {
    cout << "Iveskite studento varda: ";
    cin >> vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> pavarde;
    cout << "Priskirti namu darbus atsitiktinai? 1 = Y; 2 = N: ";
    int GeneravimoPasirinkimas;
    GeneravimoPasirinkimas = ExptSkaiciuChecker(GeneravimoPasirinkimas, 2);

    switch (GeneravimoPasirinkimas) {
    case 1:
        generuotiSkc = true;
        break;
    case 2:
        generuotiSkc = false;
        break;
    default:
        return;
        break;
    }
    namuDarbai.resize(namuDarbųSkaicius);

    if (generuotiSkc) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> N(1, 10);

        for (int i = 0; i < namuDarbųSkaicius; ++i) {
            namuDarbai[i] = N(gen);
        }

        egzaminas = N(gen);
    }
    else {
        for (int i = 0; i < namuDarbųSkaicius; ++i) {
            cout << "Iveskite " << i + 1 << " namu darbo pazymi: ";
            cin >> namuDarbai[i];
        }

        cout << "Iveskite egzamino pazymi: ";
        cin >> egzaminas;
    }

    SkaiciuotiGalutiniBala();
}

void Studentas::SkaiciuotiGalutiniBala() {
    double vidurkis = Vidurkis();
    galutinis = Mediana();
    galutinis = 0.4 * vidurkis + 0.6 * egzaminas;
}

double Studentas::Vidurkis() const {
    if (namuDarbai.empty())
        return 0;

    double suma = std::accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0);
    return suma / namuDarbai.size();
}

double Studentas::Mediana() const {
    if (namuDarbai.empty())
        return 0;

    vector<int> temp(namuDarbai);
    sort(temp.begin(), temp.end());

    int n = temp.size();
    return n % 2 == 0 ? (temp[n / 2 - 1] + temp[n / 2]) / 2.0 : temp[n / 2];
}

void Studentas::print(bool vidurkis) const {

    if (namuDarbai.empty()) {
        std::cerr << "Klaida: Studento " << vardas << " " << pavarde
            << "duomenys nepilni." << std::endl;
        return;
    }

    cout << std::setw(15) << vardas << std::setw(15) << pavarde;

    if (vidurkis)
        std::cout << std::setw(20) << std::fixed << std::setprecision(2)
        << galutinis << std::endl;
    else
        std::cout << std::setw(20) << std::fixed << std::setprecision(2)
        << Mediana() << std::endl;
}