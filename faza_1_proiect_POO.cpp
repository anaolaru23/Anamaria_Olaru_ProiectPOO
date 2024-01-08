#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//domeniu fOtbAl

//clasa 1
class echipaFotbal
{
private:
	string numeEchipa;
	float pretBilet;
	static float TVAbilet;
	const int anInfiintareEchipa;
	int numarJucatori;
	int* varsteJucatori;

public:
	//constructor 1, calasa 1
	echipaFotbal() : anInfiintareEchipa(1905)
	{
		this->numeEchipa = "Galatasaray";
		this->pretBilet = 1500;
		this->numarJucatori = 11;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++)
		{
			this->varsteJucatori[i] = 16 + i;
		}
	}
	//constructor 2, clasa 1
	echipaFotbal(string numeEchipa) : anInfiintareEchipa(1891)
	{
		this->numeEchipa = numeEchipa;
		this->pretBilet = 2000;
		this->numarJucatori = 6;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++)
		{
			this->varsteJucatori[i] = 18 + i;
		}
	}
	//constructor 3, clasa 1
	echipaFotbal(string numeEchipa, float pretBilet, int numarJucatori, int* varsteJucatori, const int anInfiintareEchipa) : anInfiintareEchipa(anInfiintareEchipa)
	{
		this->numeEchipa = numeEchipa;
		this->pretBilet = pretBilet;
		this->numarJucatori = numarJucatori;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++)
		{
			this->varsteJucatori[i] = varsteJucatori[i];
		}
	}
	//constructor de copiere, clasa 1
	echipaFotbal(const echipaFotbal& e) : anInfiintareEchipa(e.anInfiintareEchipa)
	{
		this->numeEchipa = e.numeEchipa;
		this->pretBilet = e.pretBilet;
		this->numarJucatori = e.numarJucatori;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++)
		{
			this->varsteJucatori[i] = e.varsteJucatori[i];
		}
	}
	//operatori
	echipaFotbal& operator=(const echipaFotbal& e) 
	{
		if (this != &e) 
		{
			if (varsteJucatori != NULL)
			{
				delete[] varsteJucatori;
			}
			this->numeEchipa = e.numeEchipa;
			this->pretBilet = e.pretBilet;
			this->numarJucatori = e.numarJucatori;
			this->varsteJucatori = new int[this->numarJucatori];
			for (int i = 0; i < this->numarJucatori; i++)
			{
				this->varsteJucatori[i] = e.varsteJucatori[i];
			}
			return *this;
		}
	}
	echipaFotbal operator++(int i)
	{
		echipaFotbal pretNou = *this;
		pretNou.pretBilet = this->pretBilet + 10;
		return pretNou;
	}
	bool operator! ()
	{
		return this->numarJucatori > 5;
	}
	friend ostream& operator<< (ostream& out, const echipaFotbal& e)
	{
		out << "\nNume echipa: " << e.numeEchipa << "\nPret bilet: " << e.pretBilet << "\nTVA bilet: " << e.TVAbilet <<
			"\nAn infiintare echipa: " << e.anInfiintareEchipa << "\nNumar jucatori: " << e.numarJucatori << "\nVarste jucatori: ";
		for (int i = 0; i < e.numarJucatori; i++)
		{
			out << e.varsteJucatori[i] << " ";
		}
		cout << endl;
		return out;
	}
	friend istream& operator>> (istream& in, echipaFotbal& e)
	{
		cout << "\nNume echipa: "; in >> e.numeEchipa;
		cout << "\nPret bilet: "; in >> e.pretBilet; 
		cout << "\nNumar jucatori: "; in >> e.numarJucatori;
		cout << "\nVarste jucatori: ";
		if (e.varsteJucatori != NULL)
		{
			delete[] e.varsteJucatori;
		}
		e.varsteJucatori = new int[e.numarJucatori];
		for (int i = 0; i < e.numarJucatori; i++)
		{
			in >> e.varsteJucatori[i];
		}
		cout << endl;
		return in;
	}

	//scriere in fisier
	friend ofstream& operator<<(ofstream& scrie, const echipaFotbal& f) 
	{
		scrie << f.numeEchipa << "\n" << f.pretBilet <<"\n" << f.numarJucatori
			<< "\n";
		for (int i = 0; i < f.numarJucatori; i++)
		{
			scrie << f.varsteJucatori[i] << " ";
		}
		cout << endl;
		return scrie;
	}
	//citire in fisier
	friend ifstream& operator>> (ifstream& citire, echipaFotbal& f)
	{
		cout << "\n"; citire >> f.numeEchipa;
		cout << "\n"; citire >> f.pretBilet;
		cout << "\n"; citire >> f.numarJucatori;
		if (f.varsteJucatori != NULL)
		{
			delete[] f.varsteJucatori;
		}
		f.varsteJucatori = new int[f.numarJucatori];
		for (int i = 0; i < f.numarJucatori; i++)
		{
		citire >> f.varsteJucatori[i];
		}
		cout << endl;
		return citire;
	}

	//get-eri clasa 1
	string getNumeEchipa()
	{
		return this->numeEchipa;
	}
	float getPretBilet()
	{
		return this->pretBilet;
	}
	static float getTVAbilet()
	{
		return TVAbilet;
	}
	const int getAnInfiintareEchipa()
	{
		return this->anInfiintareEchipa;
	}
	int getNumarJucatori()
	{
		return this->numarJucatori;
	}
	int getVarsteJucatori(int index)
	{
		return this->varsteJucatori[index];
	}

	//set-eri clasa 1
	void setNumeEchipa(const string& numeEchipa) 
	{
		this->numeEchipa = numeEchipa;
	}
	void setPretBilet(const float& pretBilet) 
	{
		this->pretBilet = pretBilet;
	}
	void setNumarJucatori(const int& numarJucatori)
	{
		this->numarJucatori = numarJucatori;
	}
	void setVarsteJucatori(int* varsteNoi)
	{
		if (this->varsteJucatori != NULL)
		{
			delete[] this->varsteJucatori;
		}
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++)
		{
			this->varsteJucatori[i] = varsteNoi[i];
		}
	}

	void afisare() 
	{
		cout << "\nNume echipa: " << this->numeEchipa << "\nPret bilet: " << this->pretBilet << "\nTVA bilet: " << TVAbilet <<
			"\nAnul infiintarii echipei: " << anInfiintareEchipa << "\nNumarul jucatorilor: " << this->numarJucatori << "\nVarstele jucatorilor sunt: ";
		for(int i=0; i<this->numarJucatori; i++)
		{
			cout << this->varsteJucatori[i] << " ";
		}
		cout << endl;
	}
	//functie statica
	static void setTVA(float TVA) {
		TVAbilet = TVA;
	}
	//destructor clasa 1
	~echipaFotbal()
	{
		if (varsteJucatori != NULL)
		{
			delete[] varsteJucatori;
		}
	}

	//fct friend clasa
	friend void functie1(echipaFotbal nume);
	friend void functie2(echipaFotbal pretBilet);
};

	//initializare atribut static
	float echipaFotbal::TVAbilet = 19;

	//functie friend 1 clasa 1
	void functie1(echipaFotbal nume) 
	{
		cout << "\nNumele echipei: " << nume.getNumeEchipa();
	}
	//functie friend 2 clasa 1
	void functie2(echipaFotbal pretBilet)
	{
		cout << "\nPretul nou al biletului este: " << pretBilet.getPretBilet();
	}

	//clasa 2
class jucator
{
private:
	string nume;
	float salariu;
	const int anulNasterii;
	int numarTricouriPurtate;
	int* istoricNumerePurtate;
	static int aniContract;
public:
	//constructor 1 clasa 2
	jucator() : anulNasterii(1992)
	{
		this->nume = "Sérgio Oliveira";
		this->salariu = 6500;
		this->numarTricouriPurtate = 5;
		this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
		for (int i = 0; i < this->numarTricouriPurtate; i++)
		{
			this->istoricNumerePurtate[i] = 20 + i;
		}
	}
	//constructor 2 clasa 2
	jucator(string nume) : anulNasterii(1992) 
	{
		this->nume = nume;
		this->salariu = 7000;
		this->numarTricouriPurtate = 3;
		this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
		for (int i = 0; i < this->numarTricouriPurtate; i++)
		{
			this->istoricNumerePurtate[i] = 25 + i;
		}
	}
	//constructor 3 clasa 2
	jucator(string nume, float salariu, int numarTricouriPurtate, int* istoricNumerePurtate, const int anulNasterii) : anulNasterii(anulNasterii)//////////////
	{
		this->nume = nume;
		this->salariu = salariu;
		this->numarTricouriPurtate = numarTricouriPurtate;
		this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
		for (int i = 0; i < this->numarTricouriPurtate; i++) 
		{
			this->istoricNumerePurtate[i] = istoricNumerePurtate[i];
		}
 	}
	//constructor de copiere clasa 2
	jucator(const jucator& j) : anulNasterii(j.anulNasterii)
	{
		this->nume = j.nume;
		this->salariu = j.salariu;
		this->numarTricouriPurtate = j.numarTricouriPurtate;
		this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
		for (int i = 0; i < this->numarTricouriPurtate; i++)
		{
			this->istoricNumerePurtate[i] = j.istoricNumerePurtate[i];
		}
	}
	//operatori
	jucator& operator=(const jucator &j)
	{
		if (this != &j)
		{
			if (istoricNumerePurtate != NULL)
			{
				delete[] istoricNumerePurtate;
			}
			this->nume = j.nume;
			this->salariu = j.salariu;
			this->numarTricouriPurtate = j.numarTricouriPurtate;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < this->numarTricouriPurtate; i++)
			{
				this->istoricNumerePurtate[i] = j.istoricNumerePurtate[i];
			}
			return *this;
		}
	}
	void operator+= (const jucator& j)
	{
		this->salariu += j.salariu;
	}
	friend ostream& operator<< (ostream& out, const jucator& j)
	{
		out << "\nNume: " << j.nume << "\nSalariu: " << j.salariu << "\nAnul nasterii: " << j.anulNasterii << "\nNumar de tricouri purtate: "
			<< j.numarTricouriPurtate << "\nAni de contract: " << j.aniContract << "\nIstoricul numerelor de pe tricouri: ";
		for (int i = 0; i < j.numarTricouriPurtate; i++)
		{
			out << j.istoricNumerePurtate[i] << " ";
		}
		cout << endl;
		return out;
	}
	jucator operator++()
	{
		this->salariu++;
		return *this;
	}
	//scriere in fisier
	friend ofstream& operator<< (ofstream& scrie, const jucator& j)
	{
		scrie << "\n" << j.nume << "\n" << j.salariu << "\n" << j.anulNasterii << "\n" << j.numarTricouriPurtate << "\n" << j.aniContract 
			<< "\n";
		for (int i = 0; i < j.numarTricouriPurtate; i++)
		{
			scrie << j.istoricNumerePurtate[i] << " ";
		}
		scrie << endl;
		return scrie;
	}
	//citire in fisier
	friend ifstream& operator>> (ifstream& in, jucator& j)
	{
		in >> j.nume;
		cout << "\n"; in >> j.salariu;
		cout << "\n"; in >> j.numarTricouriPurtate;
		if (j.istoricNumerePurtate != NULL)
		{
			delete[] j.istoricNumerePurtate;
		}
		j.istoricNumerePurtate = new int[j.numarTricouriPurtate];
		for (int i = 0; i < j.numarTricouriPurtate; i++)
		{
			in >> j.istoricNumerePurtate[i];
		}
		cout << endl;
		return in;
	}

	//get-eri clasa 2
	string getNume()
	{
		return this->nume;
	}
	float getSalariu()
	{
		return this->salariu;
	}
	const int getAnulNasterii()
	{
		return this->anulNasterii;
	}
	int getNumarTricouriPurtate()
	{
		return this->numarTricouriPurtate;
	}
	int getIstoricNumere(int index)
	{
		return this->istoricNumerePurtate[index];
	}
	static int getAniContract()
	{
		return aniContract;
	}
	//set-eri clasa 2
	void setNume(const string& nume)
	{
		this->nume = nume;
	}
	void setSalariu(const float& salariu)
	{
		this->salariu = salariu;
	}
	void setNumarTricouri(const int& numarTricouriPurtate)
	{
		this->numarTricouriPurtate = numarTricouriPurtate;
	}
	void setIstoricNumerePuerate(int* istoricNumere)
	{
		if (this->istoricNumerePurtate != NULL)
		{
			delete[] this->istoricNumerePurtate;
		}
		this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
		for (int i = 0; i < this->numarTricouriPurtate; i++)
		{
			this->istoricNumerePurtate[i] = istoricNumere[i];
		}
	}

	void afisare()
	{
		cout << "\nNume jucator: " << this->nume << "\nSalariu jucator: " << this->salariu << "\nAnul nasterii: " << anulNasterii <<
			"\nNumar tricouri purtate: " << this->numarTricouriPurtate << "\nAni contract pentru jucator: " << aniContract <<
			"\nIstoric numere purtate: ";
		for (int i = 0; i < this->numarTricouriPurtate; i++)
		{
			cout << this->istoricNumerePurtate[i] << " ";
		}
		cout << endl;
	}
	//functie statica
	static void setContract(int contractNou) 
	{
		aniContract = contractNou;
	}

	//destructor clasa 2
	~jucator()
	{
		if (istoricNumerePurtate != NULL)
		{
			delete[] istoricNumerePurtate;
		}
	}
	//functii friend in clasa 
	friend void functie3(jucator salariu);
	friend void functie4(jucator numarTricouriPurtaate);
	friend istream& operator>> (istream& in, jucator& j);

};
	//initializare atribut static 
	int jucator::aniContract = 5;

	//functii friend clasa 1
	void functie3(jucator salariu)
	{
		cout << "\nSalariul mediu este de: " << salariu.getSalariu();
	}
	void functie4(jucator numarTricouriPurtaate) 
	{
		cout << "\Numarul de tricouri pe care jucatorul le-a avut pana acum este de " << numarTricouriPurtaate.getNumarTricouriPurtate();
	}
	istream& operator>> (istream& in, jucator& j)
	{
		cout << "\nNume jucator: "; in >> j.nume;
		cout << "\nSalariu jucator: "; in >> j.salariu;
		cout << "\nNumar tricouri purtate: "; in >> j.numarTricouriPurtate;
		if (j.istoricNumerePurtate != NULL)
		{
			delete[] j.istoricNumerePurtate;
		}
		j.istoricNumerePurtate = new int[j.numarTricouriPurtate];
		for (int i = 0; i < j.numarTricouriPurtate; i++)
		{
			cout << "\nIstoricul numarului de pe tricoul " << (i + 1) << ": ";
			in >> j.istoricNumerePurtate[i];
		}
		cout << endl;
		return in;
	}

	//clasa 3
class stadion
{
private:
	string nume;
	int numarLocuriTotal;
	int numarPeluze;
	int* locuriPeluza;
	static float TVApretBilet;
	const int anConstructie;
public:
	//constructor 1 clasa 3
	stadion() : anConstructie(2007) 
	{
		this->nume = "Ali Sami Yen Stadium";
		this->numarLocuriTotal = 4810;
		this->numarPeluze = 4;
		this->locuriPeluza = new int[this->numarPeluze];
		for (int i = 0; i < this->numarPeluze; i++)
		{
			this-> locuriPeluza[i] =  1200 + i;
		}
	}
	//constructor 2 clasa 3
	stadion(string nume) : anConstructie (2006)
	{
		this->nume = nume;
		this->numarLocuriTotal = 6006;
		this->numarPeluze = 4;
		this->locuriPeluza = new int[this->numarPeluze];
		for (int i = 0; i < this->numarPeluze; i++)
		{
			this->locuriPeluza[i] = 1500 + i;
		}
	}
	//constructor 3 clasa 3
	stadion(string nume, int numarLocuriTotal, int numarPeluze, int* locuriPeluza, const int anConstructie) : anConstructie(anConstructie)
	{
		this->nume = nume;
		this->numarLocuriTotal = numarLocuriTotal;
		this->numarPeluze = numarPeluze;
		this->locuriPeluza = new int[this->numarPeluze];
		for (int i = 0; i < this->numarPeluze; i++)
		{
			this->locuriPeluza[i] = locuriPeluza[i];
		}
	}
	//constructor de copiere clasa 3
	stadion(const stadion& s) : anConstructie(s.anConstructie)
	{
		this->nume = s.nume;
		this->numarLocuriTotal = s.numarLocuriTotal;
		this->numarPeluze = s.numarPeluze;
		this->locuriPeluza = new int[this->numarPeluze];
		for (int i = 0; i < this->numarPeluze; i++)
		{
			this->locuriPeluza[i] = s.locuriPeluza[i];
		}
	}
	//operatori
	stadion& operator=(const stadion& s)
	{
		if (this != &s)
		{
			if (locuriPeluza != NULL) 
			{
				delete[] locuriPeluza;
			}
			this->nume = s.nume;
			this->numarLocuriTotal = s.numarLocuriTotal;
			this->numarPeluze = s.numarPeluze;
			this->locuriPeluza = new int[this->numarPeluze];
			for (int i = 0; i < this->numarPeluze; i++)
			{
				this->locuriPeluza[i] = s.locuriPeluza[i];
			}
			return *this;
		}
	}
	friend ostream& operator<< (ostream& consola, stadion& s)
	{
		consola << "\nNume stadion: " << s.nume << "\nNumar total de locuri: " << s.numarLocuriTotal << "\nNumar peluze: " << s.numarPeluze
			<< "\nTVA pret bilet: " << s.TVApretBilet << "\nAn constructie stadion: " << s.anConstructie;
		for (int i = 0; i < s.numarPeluze; i++)
		{
			cout << "\nNumerele aferente locurilor de pe peluza: " << (i + 1) << ": ";
			consola << s.locuriPeluza[i] << " ";
		}
		cout << endl;
		return consola;
	}
	friend istream& operator>> (istream& in, stadion& s)
	{
		cout << "\nNume stadion: "; in >> s.nume;
		cout << "\nNumar total de locuri: "; in >> s.numarLocuriTotal;
		cout << "\Numar peluze: "; in >> s.numarPeluze;
		if (s.locuriPeluza != NULL)
		{
			delete[] s.locuriPeluza;
		}
		s.locuriPeluza = new int[s.numarPeluze];
		for (int i = 0; i < s.numarPeluze; i++)
		{
			cout << "\nLocurile de pe peluza " << (i + 1) << ": ";
			in >> s.locuriPeluza[i];
		}
		cout << endl;
		return in;
	}
	bool operator! ()
	{
		return this->numarPeluze < 5;
	}

	//fisier binar

	void scrieInBinar()
	{
		ofstream f("fisier.binar", ios::binary);
		f.write((char*)&numarLocuriTotal, sizeof(numarLocuriTotal));
		f.write((char*)&numarPeluze, sizeof(numarPeluze));
		for (int i = 0; i < numarPeluze; i++)
		{

			f.write((char*)&locuriPeluza[i], sizeof(locuriPeluza[i]));
		}
		int lenght = this->nume.length();
		f.write((char*)&lenght, sizeof(lenght));
		f.write(this->nume.c_str(), lenght + 1);
		f.close();
	}
	void citesteInBinar()
	{
		ifstream f("fisier.binar", ios::binary);
		f.read((char*)&numarLocuriTotal, sizeof(numarLocuriTotal));
		f.read((char*)&numarPeluze, sizeof(numarPeluze));
		if (locuriPeluza != NULL)
		{
			delete[] locuriPeluza;
		}
		locuriPeluza = new int[numarPeluze];
		for (int i = 0; i < numarPeluze; i++)
		{
			f.read((char*)&locuriPeluza[i], sizeof(locuriPeluza[i]));
		}
		int lenght = 0;
		f.read((char*)&lenght, sizeof(lenght));
		char* nume = new char[lenght + 1];
		f.read(nume, lenght+1);
		delete[] nume;
		f.close();
	}

	//get-eri clasa 3
	string getNume()
	{
		return this->nume;
	}
	int getNumarLocuri()
	{
		return this->numarLocuriTotal;
	}
	int getNumarPeluze()
	{
		return this->numarPeluze;
	}
	int getLocuriPeluza(int index)
	{
		return this->locuriPeluza[index];
	}
	static float getTVA()
	{
		return TVApretBilet;
	}
	const int getAnCOnstructie()
	{
		return this->anConstructie;
	}
	//set-eri clasa 3
	void setNume(const string& nume)
	{
		this->nume = nume;
	}
	void setLocruiTotal(const int& numarLocuriATotal)
	{
		this->numarLocuriTotal = numarLocuriATotal;
	}
	void setNumarPeluze(const int& numarPeluze)
	{
		this->numarPeluze = numarPeluze;
	}
	void setLocuriPeluza(int* locuriPePeluza)
	{
		if (this->locuriPeluza != NULL)
		{
			delete[] this->locuriPeluza;
		}
		this->locuriPeluza = new int[this->numarPeluze];
		for (int i = 0; i < this->numarPeluze; i++)
		{
			this->locuriPeluza[i] = locuriPePeluza[i];
		}
	}

	void afisare()
	{
		cout << "\nNume stadion: " << this->nume << "\nNumarul total de locuri pe stadion: " << this->numarLocuriTotal <<
			"\nNumarul de peluze: " << this->numarPeluze << "\nTVA-ul biletului: " << TVApretBilet << "\nAn constructie stadion: " <<
			anConstructie;
		for (int i = 0; i < this->numarPeluze; i++)
		{
			cout << "\nNumarul de locuri aferente peluzei" << (i + 1) << ": ";
			cout << this->locuriPeluza[i] << " ";
		}
		cout << endl;
	}
	//functie statica 
	static void setTVAbilet(float TVAnou) 
	{
		TVApretBilet = TVAnou;
	}
	//destructor clasa 3
	~stadion()
	{
		if (locuriPeluza != NULL) 
		{
			delete[] locuriPeluza;
		}
	}
	//functie friend clasa 
	friend void functie5 (stadion nume);
	friend void functie6(stadion numarLocuriTotal);
};
	//initializare atribut static
	float stadion :: TVApretBilet = 19;
	
	//functie friend 1 clasa 3
	void functie5 (stadion nume)
	{
		cout << "\nUn stadion de fotbal foarte cunoscut este stadionul " << nume.getNume();
	}
	void functie6(stadion numnarLocuriTotal)
	{
		cout << "\nNumarul total de locuri pe care le are stadionul este de " << numnarLocuriTotal.getNumarLocuri();
	}

	//clasa 4, relatie has-a
	class meci
	{
	private:
		echipaFotbal echipa1;
		int durataMeci; //in minute
		string oras;
		int meciuri;
		int* nrGoluriDinFiecareMeci; 

	public:
		//constructori clasa 4
		meci()
		{
	
			this->durataMeci = 90;
			this->oras = "Bucuresti";
			this->meciuri = 2;
			this->nrGoluriDinFiecareMeci = new int[this->meciuri];
			for (int i = 0; i < this->meciuri; i++)
			{
				this->nrGoluriDinFiecareMeci[i] = 2 + i;
			}
		}
		meci(int durataMeci, string oras, int meciuri, int* nrGoluriDinFiecareMeci, echipaFotbal echipa1)
		{
			this->durataMeci = durataMeci;
			this->oras = oras;
			this->meciuri = meciuri;
			this->nrGoluriDinFiecareMeci = new int[this->meciuri];
			for (int i = 0; i < this->meciuri; i++)
			{
				this->nrGoluriDinFiecareMeci[i] = nrGoluriDinFiecareMeci[i];
			}
			this->echipa1 = echipa1;
		}
		//constructorul de copiere
		meci(const meci& m)
		{
			this->durataMeci = m.durataMeci;
			this->oras = m.oras;
			this->meciuri = m.meciuri;
			this->nrGoluriDinFiecareMeci = new int[this->meciuri];
			for (int i = 0; i < this->meciuri; i++)
			{
				this->nrGoluriDinFiecareMeci[i] = m.nrGoluriDinFiecareMeci[i];
			}
			this->echipa1 = m.echipa1;
		}

		//operatori
		meci& operator= (const meci& m)
		{
			if (this != &m)
			{
				if (nrGoluriDinFiecareMeci != NULL)
				{
					delete[] nrGoluriDinFiecareMeci;
				}
				this->echipa1 = m.echipa1;
				this->durataMeci = m.durataMeci;
				this->oras = m.oras;
				this->meciuri = m.meciuri;
				this->nrGoluriDinFiecareMeci = new int[this->meciuri];
				for (int i = 0; i < this->meciuri; i++)
				{
					this->nrGoluriDinFiecareMeci[i] = m.nrGoluriDinFiecareMeci[i];
				}
				return *this;
			}
		}
		friend ostream& operator<< (ostream& out, meci& m)
		{
			out << "\nDurata meci: " << m.durataMeci << "\nOras: " << m.oras << "\nMeciuri: " << m.meciuri << "\n" << m.echipa1
				<< "\nNumarul de goluri din fiecare meci: ";
			for (int i = 0; i < m.meciuri; i++)
			{
				out << m.nrGoluriDinFiecareMeci[i] << " ";
			}
			cout << endl;
			return out;
		}
	
		friend istream& operator>> (istream& in, meci& m)
		{
			cout << "\nDurata meci: "; in >> m.durataMeci;
			cout << "\nOras: "; in >> m.oras;
			cout << "\nMeciuri: "; in >> m.meciuri;
			cout << "\n"; in >> m.echipa1;
			cout << "\nNumar de goluri din fiecare meci: ";
			if (m.nrGoluriDinFiecareMeci != NULL)
			{
				delete[] m.nrGoluriDinFiecareMeci;
			}
			m.nrGoluriDinFiecareMeci = new int[m.meciuri];
			for (int i = 0; i < m.meciuri; i++)
			{
				in >> m.nrGoluriDinFiecareMeci[i];
			}
			return in;
		}

		//fisier binar
		void scrieInBinar()
		{
			ofstream f("fisier.binar2", ios::binary);
			f.write((char*)&durataMeci, sizeof(durataMeci));
			f.write((char*)&meciuri, sizeof(meciuri));
			for (int i = 0; i < meciuri; i++)
			{
				f.write((char*)&nrGoluriDinFiecareMeci[i], sizeof(nrGoluriDinFiecareMeci[i]));
			}
			int lenght = this->oras.length();
			f.write((char*)&lenght, sizeof(lenght));
			f.write(this->oras.c_str(), lenght + 1);
			f.close();
		}

		void citesteInBinar()
		{
			ifstream f("fisier.binar2", ios::binary);
			f.read((char*)&durataMeci, sizeof(durataMeci));
			f.read((char*)&meciuri, sizeof(meciuri));
			if (nrGoluriDinFiecareMeci != NULL)
			{
				delete[] nrGoluriDinFiecareMeci;
			}
			nrGoluriDinFiecareMeci = new int[meciuri];
			for (int i = 0; i < meciuri; i++)
			{
				f.read((char*)&nrGoluriDinFiecareMeci[i], sizeof(nrGoluriDinFiecareMeci[i]));
			}
			int lenght = 0;
			f.read((char*)&lenght, sizeof(lenght));
			char* oras = new char[lenght + 1];
			f.read(oras, lenght + 1);
			delete[]oras;
			f.close();
		}

		meci operator++ (int i)
		{
			meci reprizeNoi = *this;
			reprizeNoi.meciuri = this->meciuri + 4;
			return reprizeNoi;
		}

		//get-eri
		int getDurataMeci() 
		{
			return this->durataMeci;
		}
		string getOras()
		{
			return this->oras;
		}
		int getMeciuri()
		{
			return this->meciuri;
		}
		int getnrGoluriDinFiecareMeci(int index)
		{
			return this->nrGoluriDinFiecareMeci[index];
		}
		echipaFotbal getEchipa1()
		{
			return this->echipa1;
		}
		//set-eri
		void setDurataMeci (const int& durataMeci)
		{
			this->durataMeci = durataMeci;
		}
		void setOras(const string& oras)
		{
			this->oras = oras;
		}
		void setnrGoluriDinFiecareMeci(int* nrGoluriDinFiecareMeci)
		{
			if (this->nrGoluriDinFiecareMeci != NULL)
			{
				delete[] this->nrGoluriDinFiecareMeci;
			}
			this->nrGoluriDinFiecareMeci = new int[this->meciuri];
			for (int i = 0; i < this->meciuri; i++)
			{
				this->nrGoluriDinFiecareMeci[i] = nrGoluriDinFiecareMeci[i];
			}
		}
		void setEchipa1(const echipaFotbal& echipa1)
		{
			this->echipa1 = echipa1;
		}
		
		void afisare()
		{
			cout << "\nDarata meci: " << this->durataMeci << "\nOras: " << this->oras << "\nMeciuri: " << this->meciuri << this->echipa1 << "Numar de goluri din fiecare meci: ";
			for (int i = 0; i < this->meciuri; i++)
			{
				cout << this->nrGoluriDinFiecareMeci[i] << " ";
			}
			cout << endl;
		}

		//destructor clasa 4
		~meci()
		{
			if (nrGoluriDinFiecareMeci != NULL)
			{
				delete[] nrGoluriDinFiecareMeci;
			}
		}
	};
	//clasa 5 - prin mostenire
	class academie : public echipaFotbal
	{
	private:
		int varstaMaxima;
		int numarEchipe;
		int* categorieVarste;

	public:
		//constructori
		academie() : echipaFotbal()
		{
			this->varstaMaxima = 16;
			this->numarEchipe = 5;
			this->categorieVarste = new int[this->numarEchipe];
			for (int i=0; i < this->numarEchipe; i++)
			{
				this->categorieVarste[i] = 13 + i;
			}
		
		}
		academie(int varstaMaxima, int numarEchipe, int* categorieVarste) : echipaFotbal()
		{
			this->varstaMaxima = varstaMaxima;
			this->numarEchipe = numarEchipe;
			this->categorieVarste = new int[this->numarEchipe];
			for (int i = 0; i < this->numarEchipe; i++)
			{
				this->categorieVarste[i] = categorieVarste[i];
			}
		}
		//constructor de copiere
		academie(const academie& a) : echipaFotbal(a)
		{
			this->varstaMaxima = a.varstaMaxima;
			this->numarEchipe = a.numarEchipe;
			this->categorieVarste = new int[this->numarEchipe];
			for (int i = 0; i < this->numarEchipe; i++)
			{
				this->categorieVarste[i] = a.categorieVarste[i];
			}
		}
		//operatori
		academie operator=(const academie& a)
		{
			if (this != &a) 
			{
			echipaFotbal::operator=(a);

				if (categorieVarste != NULL)
				{
					delete[] categorieVarste;
				}
				this->varstaMaxima = a.varstaMaxima;
				this->numarEchipe = a.numarEchipe;
				this->categorieVarste = new int[this->numarEchipe];
				for (int i = 0; i < this->numarEchipe; i++)
				{
					this->categorieVarste[i] = a.categorieVarste[i];
				}
			}
			return *this;
		}
		//get-eri
		int getVarstaMaxima()
		{
			return this->varstaMaxima;
		}
		int getNumarEchipe()
		{
			return this->numarEchipe;
		}
		int getCategorieVarste(int index)
		{
			return this->categorieVarste[index];
		}
		//set-eri
		void setVarstaMaxima(const int& varstaMaxima)
		{
			this->varstaMaxima = varstaMaxima;
		}
		void setNumarEchipe(const int& numarEchipe)
		{
			this->numarEchipe = numarEchipe;
		}
		void getCategorieVarste(int* categorieVarste)
		{
			if (this->categorieVarste != NULL)
			{
				delete[] this->categorieVarste;
			}
			this->categorieVarste = new int[this->numarEchipe];
			for (int i = 0; i < this->numarEchipe; i++)
			{
				this->categorieVarste[i] = categorieVarste[i];
			}
		}
		friend ostream& operator<< (ostream& consola, const academie& a)
		{
			consola << "\nACADEMIE: ";
			consola << (echipaFotbal&)a;
			consola << "\nVarsta maxima: " << a.varstaMaxima << "\nNumar echipe: " << a.numarEchipe << "\nCategorie varste: ";
			for (int i = 0; i < a.numarEchipe; i++)
			{
				cout << a.categorieVarste[i] << " ";
			}
			cout << endl;
			return consola;
		}
		void afisare()
		{
			cout << "\nVarsta maxima: " << this->varstaMaxima << "\nNumar echipe: " << this->numarEchipe << "\nCategorie varste: ";
			for (int i = 0; i < this->numarEchipe; i++)
			{
				cout << this->categorieVarste[i] << " ";
			}
			echipaFotbal::afisare();
		}
		//destructor
		~academie()
		{
			if (categorieVarste != NULL)
			{
				delete[] categorieVarste;
			}
		}
	};

	//clasa 6 - mostenire
	class atacant : public jucator
	{
	private:
		string numeEchipa;
		int sezoane;
		int* goluriMarcatePeSezon;
	public:
		//constructori
		atacant() : jucator()
		{
			this->numeEchipa = "Steaua Bucuresti";
			this->sezoane = 4;
			this->goluriMarcatePeSezon = new int[this->sezoane];
			for (int i = 0; i < this->sezoane; i++)
			{
				this->goluriMarcatePeSezon[i] = 14 + i;
			}
		}
		atacant(string numeEchipa, int sezoane, int* goluriMarcatePeSezon) : jucator()
		{
			this->numeEchipa = numeEchipa;
			this->sezoane = sezoane;
			this->goluriMarcatePeSezon = new int[this->sezoane];
			for (int i = 0; i < this->sezoane; i++)
			{
				this->goluriMarcatePeSezon[i] = goluriMarcatePeSezon[i];
			}
		}
		//constructor copiere
		atacant(const atacant& a) : jucator(a)
		{
			this->numeEchipa = a.numeEchipa;
			this->sezoane = a.sezoane;
			this->goluriMarcatePeSezon = new int[this->sezoane];
			for (int i = 0; i < this->sezoane; i++)
			{
				this->goluriMarcatePeSezon[i] = a.goluriMarcatePeSezon[i];
			}
		}
		//operator =
		atacant operator=(const atacant& a)
		{
			if (this != &a)
			{
				atacant::operator=(a);
				if (goluriMarcatePeSezon != NULL)
				{
					delete[] goluriMarcatePeSezon;
				}
				this->numeEchipa = a.numeEchipa;
				this->sezoane = a.sezoane;
				this->goluriMarcatePeSezon = new int[this->sezoane];
				for (int i = 0; i < this->sezoane; i++)
				{
					this->goluriMarcatePeSezon[i] = a.goluriMarcatePeSezon[i];
				}
			}
		}
		//get-eri
		string getNumeEchipa()
		{
			return this->numeEchipa;
		}
		int getSezoane()
		{
			return this->sezoane;
		}
		int setGoluriMarcatePeSezon(int index)
		{
			return this->goluriMarcatePeSezon[index];
		}
		//set-eri
		void setNumeEchipa(const string& numeEchipa)
		{
			this->numeEchipa = numeEchipa;
		}
		void setSezoane(const int& sezoane)
		{
			this->sezoane = sezoane;
		}
		void setGoluriMarcatePeSezon(int* goluriMarcatePeSezon)
		{
			if (this->goluriMarcatePeSezon != NULL)
			{
				delete[] this->goluriMarcatePeSezon;
			}
			this->goluriMarcatePeSezon = new int[this->sezoane];
			for (int i = 0; i < this->sezoane; i++)
			{
				this->goluriMarcatePeSezon[i] = goluriMarcatePeSezon[i];
			}
		}
		friend ostream& operator<< (ostream& consola, const atacant& a)
		{
			consola << (jucator&)a;
			consola << "\nNume echipa: " << a.numeEchipa << "\nSezoane: " << a.sezoane;
			for (int i = 0; i < a.sezoane; i++)
			{
				consola << "\nGoluri marcate in sezonul " << (i+1) << ": ";
				consola << a.goluriMarcatePeSezon[i] << " ";
			}
			cout << endl;
			return consola;
		}
		
		//destructor
		~atacant()
		{
			if (goluriMarcatePeSezon != NULL)
			{
				delete[] goluriMarcatePeSezon;
			}
		}
	};

	//clasa 7 - abstracta 
	class echipaNationalaFotbal
	{
	private:
		string tara;
		int campionateCastigate;
		string capitanEchipa;
	public:
		virtual ~echipaNationalaFotbal () { }
		virtual void metoda() = 0;

		//constructori
		echipaNationalaFotbal()
		{
			this->tara = "Turcia";
			this->campionateCastigate = 15;
			this->capitanEchipa = "Hagi";
		}
		echipaNationalaFotbal(string tara, int campionateCastigate, string capitanEchipa)
		{
			this->tara = tara;
			this->campionateCastigate = campionateCastigate;
			this->capitanEchipa = capitanEchipa;
		}
		friend ostream& operator<< (ostream& consola, echipaNationalaFotbal& e)
		{
			consola << "\nTara: ";
			consola << "\nNumar campionate castigate: ";
			consola << "\nCapitanul echipei este " << ".";
			return consola;
		}
	};


	void main()
	{
		//apelare clasa 1
		echipaFotbal echipa1;
		echipa1.afisare();
		cout << endl;

		echipaFotbal echipa2("Arsenal");
		echipa2.afisare();
		cout << endl;

		int* varste = new int[4];
		for (int i = 0; i < 4; i++)
		{
			varste[i] = 17 + i;
		}
		echipaFotbal echipa3("Tottenham", 1450, 4, varste, 1886);
		echipa3.afisare();
		cout << endl;

		//apelare constructor de copiere clasa 1
		echipaFotbal echipa4(echipa3);
		echipa4.afisare();
		cout << endl;

		//apelare get-eri clasa 1
		cout << "\nNume echipa: " << echipa1.getNumeEchipa();
		cout << "\nPretul biletului: " << echipa2.getPretBilet();
		cout << "\nAnul infiintarii echipei este: " << echipa3.getAnInfiintareEchipa();
		cout << "\nTVA-ul ramane de " << echipa1.getTVAbilet() << "%";
		cout << "\nNumar jucatori: " << echipa1.getNumarJucatori();
		for (int i=0; i < echipa1.getNumarJucatori(); i++)
		{
			cout << "\nVarsta jucator " << (i+1) << ": ";
			cout << echipa1.getVarsteJucatori(i);
		}
		cout << endl;
		
		//apelare functii friend clasa 1
		functie1(echipa1);
		functie2(echipa2);
	

		//apelare operatori clasa 1
		echipaFotbal echipa5;
		echipa5 = echipa4;
		echipa5.afisare();
		cout << endl;

		echipaFotbal echipa6;
		echipa6 = echipa2++;
		echipa6.afisare();
		cout << endl;

		if (!echipa1)
		{
			cout << "Echipa 1 are multi jucatori.";
		}
		else
		{
			cout << "Echipa are un numar mic de jucatori";
		}
		cout << endl;

		cout << echipa1; 
		//cin >> echipa3;
	
		//apelare clasa 2
		jucator jucator1;
		jucator1.afisare();

		jucator jucator2("Heung-Min Son");
		jucator2.afisare();

		int* istoricNumereTricou = new int[3];
		for (int i = 0; i < 3; i++)
		{
			istoricNumereTricou[i] = 21 + i;
		}
		jucator jucator3("Declan Rice", 15000, 3, istoricNumereTricou, 1999);
		jucator3.afisare();

		//apelare constructor de copiere clasa 2
		jucator jucator4(jucator2);
		jucator4.afisare();
		cout << endl;
	
	//apelare get-eri clasa 2
	cout << "Numele jucatorului este: " << jucator1.getNume() << endl;
	cout << "Salariul jucatorului este: " << jucator2.getSalariu() << endl;
	cout << "Anul nasterii jucatorului de fotbal este: " << jucator2.getAnulNasterii() << endl;
	cout << "Numarul de tricouri pe care le-a purtat pana acum jucatorul este de: " << jucator1.getNumarTricouriPurtate() << endl;
	cout << "Jucatorul are un contract de " << jucator3.getAniContract() << " ani." << endl;
	cout << endl;
	cout << "Istoric numere purtate: ";
	for (int i = 0; i < jucator1.getNumarTricouriPurtate(); i++)
	{
		cout << jucator1.getIstoricNumere(i) << " ";
	}
	
	//apelare functii friend
	functie3(jucator3);
	functie4(jucator2);

	//apelare operatori clasa 2
	jucator jucator5;
	jucator5 = jucator2;
	jucator5.afisare();

	jucator3 += jucator2;
	jucator3.afisare();
	cout << endl;
	cout << jucator4;
	jucator jucator6;
	jucator6 = ++jucator2;
	jucator6.afisare();
	cin >> jucator2;  

	//apelare clasa 3
	stadion stadion1;
	stadion1.afisare();

	stadion stadion2("Arsenal");
	stadion2.afisare();

	int* locuriPeluza = new int[3];
	for (int i = 0; i < 3; i++)
	{
		locuriPeluza[i] = 144 + i;
	}
	stadion stadion3("Ali Sami Yen Spor Kompleksi", 7500, 3, locuriPeluza, 2007);
	stadion3.afisare();

	//apelare constructor de copiere clasa 3
	stadion stadion4(stadion3);
	stadion4.afisare();
	cout << endl;

	//apelare get-eri clasa 3
	cout << "Numele stadionului este: " << stadion1.getNume() << endl;
	cout << "Numarul total de locuri pe stadion este: " << stadion1.getNumarLocuri() << endl;
	cout << "Numarul de peluze pe stadion este de " << stadion1.getNumarPeluze() << "." << endl;
	cout << "TVA-ul unui bilet este de " << stadion1.getTVA() << "%." << endl;
	cout << "Anul in care s-a construit stadionul este " << stadion1.getAnCOnstructie() << "." << endl;
	for (int i = 0; i < stadion1.getNumarPeluze(); i++)
	{
		cout << "\nNumarul de locuri aferente peluzei" << (i + 1) << ": ";
		cout << stadion1.getLocuriPeluza(i) << " ";
	}
	cout << endl;

	//apelare functii friend
	functie5(stadion2);
	functie6(stadion3);

	//apelare operatori clasa 3
	stadion stadion5;
	stadion5 = stadion3;
	stadion5.afisare();

	cout << stadion2;
	cout << endl;/////////////// din caz de am prea mult spatiu la afisare dupa ce sterg comentariul la cin, de aici e problema
	//cin >> stadion3;////////////////////////
	if (!stadion1)
	{
		cout << "Stadionul are 4 peluze.";
	}
	else
	{
		cout << "Nu se poate.";
	}
	cout << endl;

	//apelare clasa 4
	meci meci1;
	int* nrGoluriMeciuri = new int[3];
	for (int i = 0; i < 3; i++)
	{
		nrGoluriMeciuri[i] = 2 + i;
	}
	meci meci2(95, "Istanbul", 3, nrGoluriMeciuri, echipa1);
	meci2.afisare();
	//apelare constructor de copiere
	meci meci3(meci2);
	meci3.afisare();

	//apelare operatori
	meci meci4;
	meci4 = meci1;
	meci4.afisare();

	cout << meci4;
	//cin >> meci1;

	////apelare get-eri
	cout << "\nDurata meciului a fost de " << meci2.getDurataMeci() << " minute";
	cout << "\nOrasul in care s-a jucat meciul a fost " << meci1.getOras() << ".";
	cout << "\nMeciuri: " << meci2.getMeciuri();
	//cout << "\nClasa echipa fotbal: " << meci2.getEchipa1();
	cout << "\nNr de goluri din fiecare meci: ";
	for (int i=0; i < meci2.getMeciuri(); i++)
	{
		cout << meci2.getnrGoluriDinFiecareMeci(i) << " ";
	}
	cout << endl;

	//vectori
	echipaFotbal vectorEchipa[2];
	for (int i = 0; i < 2; i++)
	{
		cin >> vectorEchipa[i];
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << vectorEchipa[i] << " " << endl;
	}
	jucator vectorJucator[2];
	for (int i = 0; i < 2; i++)
	{
		cin >> vectorJucator[i];
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << vectorJucator[i] << " " << endl;
	}
	stadion vectorStadion[2];
	for (int i = 0; i < 2; i++)
	{
		cin >> vectorStadion[i];
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << vectorStadion[i] << " " << endl;
	}

	//matrice
	echipaFotbal matriceEchipa[1][2];
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> matriceEchipa[i][j];
		}
	}
	cout << "Matricea Jucator";
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matriceEchipa[i][j];
		}
	}

	//fisiere text  clasa 1
	
	ofstream file("fisier1.txt", ios::out);
	file << echipa4;
	cout << endl;

	ifstream citire("fisier1.txt", ios::in);
	echipaFotbal echipa8;
	cin >> echipa8;
	file << echipa8;  

	//fisiere text clasa 2
	ofstream file2("fisier2.txt", ios::out);
	file2 << jucator3;
	cout << endl;
	
	ifstream citire2("fisier2.txt", ios::in);
	jucator jucator9;
	cin >> jucator9;
	file2 << jucator9;

	//apelare fisier binar 1

	stadion2.scrieInBinar();
	cout << stadion2;

	stadion stadion10;
	stadion5.citesteInBinar();
	cout << stadion10;

	//apelare fisier binar 2
	meci meci10;
	meci10.scrieInBinar();
	cout << meci10;

	meci meci9;
	meci9.citesteInBinar();
	cout << meci9;

	//apelare clasa 5 - mostenire

	academie academie1;
	cout << academie1;
	int* categorie = new int[5];
	for (int i = 0; i < 5; i++)
	{
		categorie[i] = 12 + i;
	}
	academie academie2(17, 5, categorie);
	cout << academie2;
	//apelare constructor de copiere;
	academie academie3(academie2);
	
	//apelare op =
	academie academie4;
	academie4 = academie1;

	//apelare get-eri
	cout << "\nVarsta maxima din academie: " << academie1.getVarstaMaxima() << " ani.";
	cout << "\nNumar de echipe in academie: " << academie1.getNumarEchipe();
	cout << "\nCategoriile de varsta din academie: ";
	for (int i = 0; i < academie1.getNumarEchipe(); i++)
	{
		cout << academie1.getCategorieVarste(i) << " "; 
	}
	cout << endl;
	
	//apelare clasa 6 - mostenire
	atacant atacant1;
	cout << atacant1;
	int* goluri = new int[4];
	for (int i = 0; i < 4; i++)
	{
		goluri[i] = 5 + i;
	}
	atacant atacant2("dinamo", 3, goluri);
	cout << atacant2;
	//apelare get 
	cout << "\nNume echipa: " << atacant1.getNumeEchipa();
	cout << "\nNumarul de sezoane in care a jucat atacantul: " << atacant1.getSezoane();
	for (int i = 0; i < atacant1.getSezoane(); i++)
	{
		cout << "\nGoluri marcate in sezonul " << (i + 1) << ": ";
		cout << atacant1.setGoluriMarcatePeSezon(i);
	}

	//upcasting
	jucator* junior = &atacant1;
	junior->afisare();
};

