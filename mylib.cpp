#include "mylib.h"

Studentas::Studentas() {}

  Studentas::Studentas(const Studentas &other) {
    vardas = other.vardas;
    pavarde = other.pavarde;
    namuDarbai = other.namuDarbai;
    egzaminas = other.egzaminas;
    galutinis = other.galutinis;
  }

Studentas& Studentas::operator=(const Studentas &other) {
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
  std::ostream& operator<<(std::ostream &out, const Studentas &A) {
    out << A.vardas << " ; " << A.pavarde << " | ";
    for (auto &i : A.namuDarbai)
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
    in >> k; a.namuDarbai.push_back(k);
  }
  in >> a.egzaminas;
  a.Vidurkis();
  return in;
}


  int Studentas::ExptSkaiciuChecker(int &Pasirinkimas) { // tikrinimas ar yra skaicius 1 ar 2,
    while (true) {                            // naudojamas switch case palengvinimui
      try {
        std::cin >> Pasirinkimas;

        if (std::cin.fail() || (Pasirinkimas != 1 && Pasirinkimas != 2)) {
          throw std::invalid_argument(
              "Neteisingas pasirinkimas. Įveskite 1 arba 2.");
        }

        return Pasirinkimas;
      } catch (const std::invalid_argument &e) {
        cout << e.what() << std::endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
  }

  void Studentas::DuomenųĮvedimas(int namuDarbųSkaicius, bool generuotiBalus) {
    cout << "Iveskite studento varda: ";
    cin >> vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> pavarde;
    cout << "Priskirti namu darbus atsitiktinai? 1 = Y; 2 = N: ";
    int GeneravimoPasirinkimas;
    GeneravimoPasirinkimas = ExptSkaiciuChecker(GeneravimoPasirinkimas);

    switch (GeneravimoPasirinkimas) {
    case 1:
      generuotiBalus = true;
      break;
    case 2:
      generuotiBalus = false;
      break;
    default:
      return;
      break;
    }
    namuDarbai.resize(namuDarbųSkaicius);

    if (generuotiBalus) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> baluRozinis(1, 10);

      for (int i = 0; i < namuDarbųSkaicius; ++i) {
        namuDarbai[i] = baluRozinis(gen);
      }

      egzaminas = baluRozinis(gen);
    } else {
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

    vector<int> temp(namuDarbai);   // jeigu ND nepriskiriu prie temp
    sort(temp.begin(), temp.end()); // vectoriaus, programa neveiks

    int n = temp.size();
    return n % 2 == 0 ? (temp[n / 2 - 1] + temp[n / 2]) / 2.0 : temp[n / 2];
  }

  void Studentas::print(bool vidurkis) const {
    /*
    if (namuDarbai.empty()) {
        std::cerr << "Klaida: Studento " << vardas << " " << pavarde << "
    duomenys nepilni." << std::endl; return;
    }
    */
    cout << std::setw(15) << vardas << std::setw(15) << pavarde;

    if (vidurkis)
      std::cout << std::setw(20) << std::fixed << std::setprecision(2)
                << galutinis << std::endl;
    else
      std::cout << std::setw(20) << std::fixed << std::setprecision(2)
                << Mediana() << std::endl;
  }
