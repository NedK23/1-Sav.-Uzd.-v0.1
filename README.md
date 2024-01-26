**1-SysProg.-Sav.-Uzd-v1.0.1-release**

Atlikta pirma užduotis, nuo v0.1 iki v1.0;

*pagal tos versijos reikalavimus
Programa atlieka:

įvestų Studentu duomenų visualų išvedima *v0.1
įvedima ir išvedima į failus *v0.1
Studentu duomenų generavimas *v0.2

Pagrindinių funkcijų Instrukcija:
1. Įjungus programą, jūsų bus paklausta ar skaityti iš failo, įveskite y arba n.
1.2. Sutikus skaityti iš failo iveskite PILNA failo pavadinima (pvz. kursiokai.txt).

2. "Automatiskai generuoti studentus? (1 = Y/ 2 = N):" spauskite 1 jeigu TAIP, 2 jeigu NE.
2.2. Iveskite norimą skaičių atsitiktiniam studentų generavimui.
2.3. Baigus generavimui iveskite faila kur norite išsaugoti resultatus.
2.3. Resultatai bus atvaizduojami ekrane, jūsų užvardintame faile ir, MaxStudentai, MinStudentai failuose.

3. Jeigu pasirinkote 2, t.y NE, jūsų prašys ranka įvesti studentų duomenis.
3.1. Pasirinkite kiek iš viso namų darbų turės studentai.
3.2. Pasirinkite studentų skaičių.
3.3. Užpildykite namų darbus ranka, arba atsitiktinai sugeneruokite balus.

Makefile naudojimas:
1. Ijunkite URCT console (pvz. MSYS32 URCT64)
2. Einate į Makefile directorija.
3. konsolėje įrašykite 'make'
4. directorijoje dabar tūri būti main.exe failas.

Versijos pakeitimai:
v0.1:
įvestų Studentu duomenų iš failo arba pagal vartotojo nuožiūra visualų išvedima.

v0.2:
Iterpta rušiavimo funkcija į Max arba Min (Studentai su galutiniu balu <5).
Pridetas visai atsitiktinų studentu duomenų generavimas į failus.
vectoriai pakeisti į list tipo duomenis.
Atlikta Vectorių vs. list tipo analizė, txt faile "LaikoAnalize.txt".

v1.0: 
Skaitimo iš failų optimizacija.
Parengtas Makefile.
v1.0.1:
Aptvarkymas.




