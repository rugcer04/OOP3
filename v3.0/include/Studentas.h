#ifndef  STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "../include/Zmogus.h"

// studento klase
class Studentas : public Zmogus{
   private:
      //string vardas_;
      //string pavarde_;
      vector<int> namudarbai_;
      int egzaminas_;
      double galutinis_;

   public:
      // konstruktoriai
      Studentas(){ };
      //Studentas() : Zmogus("", ""), egzaminas_(0), galutinis_(0) {}
      Studentas(const string& vardas, const string& pavarde, const vector<int>& namudarbai, double egzaminas);
      Studentas(const string& vardas, const string& pavarde, int ndSkaicius);
      Studentas(const Studentas& kitas); //kopijavimo konstruktorius
      // destruktorius
      ~Studentas();

      // operatoriai
      friend ostream& operator<< (ostream& os, const Studentas& s);
      friend istream& operator>> (istream& is, Studentas& s);
      Studentas& operator=(const Studentas& kitas);

      // seteriai
      void setVardas(const string& vardas) { vardas_ = vardas; }
      void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
      void setNamuDarbai(const vector<int>& namudarbai) { namudarbai_ = namudarbai;}
      void setEgzaminas(const int& egzaminas) { egzaminas_ = egzaminas; }
      void setGalutinis(const double& galutinis){ galutinis_ = galutinis;}

      // geteriai
      //inline string getVardas() const { return vardas_; }
      //inline string getPavarde() const { return pavarde_; }
      inline vector<int> getNamudarbai() const { return namudarbai_; }
      inline int getEgzaminas() const { return egzaminas_; }
      inline double getGalutinis() const { return galutinis_; }

      // implementuoti virtualus geteriai
      string getVardas() const override { return vardas_; }
      string getPavarde() const override { return pavarde_; }

      // metodai
      void skaiciuotiGalutiniVidurkiu();
      void skaiciuotiGalutiniMediana();

};

#endif