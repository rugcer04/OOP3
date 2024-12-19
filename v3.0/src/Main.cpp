#include "../include/Lib.h"
#include "../include/Stud.h"
#include "../include/Timer.h"
#include "../include/Studentas.h"

int main() {
    char konteinerioPasirinkimas;
    while (true) {
        cout << "Norite naudoti vector (V) ar list (L)? ";
        cin >> konteinerioPasirinkimas;
        konteinerioPasirinkimas = toupper(konteinerioPasirinkimas);

        if (konteinerioPasirinkimas == 'V' || konteinerioPasirinkimas == 'L') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
    }

    //Darbas su vektoriumi
    if (konteinerioPasirinkimas == 'V') {
        vector<Studentas> studentai;
        char duomenuIvedimoBudas = pasirinktiDuomenuIvedima();
    
        //Ivesti rankiniu budu
        if (duomenuIvedimoBudas == 'I') {
            ivedimasRanka(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra ir surusiuojame
            char parametras = pasirinktiRusiavimoParametra();
            rusiuotiStudentus(studentai, parametras);

            //pasirenkame kaip pateikti rezultatus (faile ar terminale)
            pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);   
        }

        //Nuskaitymas is failo
        else if (duomenuIvedimoBudas == 'F') {
            //system("dir *.txt");
            //Nuskaitome faila
            nuskaitytiIsFailo(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Skirstyti studentus i vargsiukus ir kietiakus, surusiavimas pagal pasirinkta parametra ir isvesti i failus pagal pasirinkta strategija
            duomenuIsvedimasPagalStrategija(studentai, pasirinkimas); 

        }

        //Failu generavimas
        else if (duomenuIvedimoBudas == 'G') {
            vector<int> studentuDydziai = {1000, 10000, 100000, 1000000, 10000000};
            char pasirinkimas;

            for (int n : studentuDydziai) {
                studentai.clear();
                string failoPavadinimas = "studentai" + to_string(n) + ".txt";

                Timer t2;
                generuotiFaila(n, failoPavadinimas);
                cout << "Failo su " << n << " įrašų generavimo laikas: " << t2.elapsed() << " s\n" << endl;        
            }

        } else if (duomenuIvedimoBudas == 'D') {
            //Zmogus z;
            Studentas s1, s2;
            cout << "\nNaudojamas įvesties operatorius (įvedimas ranka): " << endl;
            cin >> s1;
            s1.skaiciuotiGalutiniVidurkiu();

            cout << "\nNaudojamas įvesties operatorius (įvedimas iš eilutės)" << endl;
            stringstream eilute("Jonas Jonaitis 6 9 4 8 6");
            eilute >> s2;
            s2.skaiciuotiGalutiniVidurkiu();

            cout << "\nNaudojamas išvesties operatorius:" << endl;
            ofstream failas("test.txt");
            cout << s1 << endl;
            cout << s2 << endl;
            failas << s2;
            failas.close();

            // kopijavimo konstruktorius
            Studentas s3(s1);
            cout << "\nNaudojamas kopijavimo konstruktorius: " << endl;
            cout << s1 << endl;
            cout << s3 << endl;

            // kopijavimo operatorius
            s2 = s1;
            cout << "\nNaudojamas kopijavimo operatorius: " << endl;
            cout << s1 << endl;
            cout << s2 << endl;

            // ifstream in("test.txt");
            // Studentas a;
            // in >> a;
            // a.skaiciuotiGalutiniVidurkiu();
            // ofstream failas("reztest.txt");
            // failas << a;
        }
        

    //Darbas su sarasu
    } else if (konteinerioPasirinkimas == 'L') {
        list<Studentas> studentai;
        char duomenuIvedimoBudas = pasirinktiDuomenuIvedima();
    
        //Ivesti rankiniu budu
        if (duomenuIvedimoBudas == 'I') {
            ivedimasRanka(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra ir surusiuojame
            char parametras = pasirinktiRusiavimoParametra();
            rusiuotiStudentus(studentai, parametras);

            //Pasirenkame kaip pateikti rezultatus (faile ar terminale)
            pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);
        }

        //Nuskaitymas is failo
        else if (duomenuIvedimoBudas == 'F') {
            //system("dir *.txt");
            //Nuskaitome faila
            nuskaitytiIsFailo(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Skirstyti studentus i vargsiukus ir kietiakus, surusiavimas pagal pasirinkta parametra ir isvesti i failus pagal pasirinkta strategija
            duomenuIsvedimasPagalStrategija(studentai, pasirinkimas);
        }

        //Failu generavimas
        else if (duomenuIvedimoBudas == 'G') {
            list<int> studentuDydziai = {1000, 10000, 100000, 1000000, 10000000};
            char pasirinkimas;

            for (int n : studentuDydziai) {
                studentai.clear();
                string failoPavadinimas = "studentai" + to_string(n) + ".txt";

                Timer t2;
                generuotiFaila(n, failoPavadinimas);
                cout << "Failo su " << n << " įrašų generavimo laikas: " << t2.elapsed() << " s\n" << endl;        
            }

        } else if (duomenuIvedimoBudas == 'D') {
            Studentas s1, s2;
            cout << "\nNaudojamas įvesties operatorius (įvedimas ranka): " << endl;
            cin >> s1;
            s1.skaiciuotiGalutiniVidurkiu();

            cout << "\nNaudojamas įvesties operatorius (įvedimas iš eilutės)" << endl;
            stringstream eilute("Jonas Jonaitis 6 9 4 8 6");
            eilute >> s2;
            s2.skaiciuotiGalutiniVidurkiu();

            cout << "\nNaudojamas išvesties operatorius:" << endl;
            ofstream failas("test.txt");
            cout << s1 << endl;
            cout << s2 << endl;
            failas << s2;
            failas.close();

            // kopijavimo konstruktorius
            Studentas s3(s1);
            cout << "\nNaudojamas kopijavimo konstruktorius: " << endl;
            cout << s1 << endl;
            cout << s3 << endl;

            // kopijavimo operatorius
            s2 = s1;
            cout << "\nNaudojamas kopijavimo operatorius: " << endl;
            cout << s1 << endl;
            cout << s2 << endl;
        }
    }
    
    system("pause");
    
    return 0;
}