#include <iostream>
using namespace std;

//domeniul fOtbAl

	//clasa 1
class echipaFotbal {
private:
	string nume;
	int numarJucatori;
	float pretBilet;
	const int anInfiintareEchipa;
	static float TVAbilet;
	int* varsteJucatori;

public:

	//initializare, constructor 1 clasa 1
	echipaFotbal() : anInfiintareEchipa(1905) {
		this->nume = "Galatasaray";
		this->numarJucatori = 8;
		this->pretBilet = 2000.0;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++) {
			this->varsteJucatori[i] = 16 + i;
		}
	}

	//constructor 2 clasa 1
	echipaFotbal(string nume) : anInfiintareEchipa(1945) {
		this->nume = nume;
		this->numarJucatori = 6;
		this->pretBilet = 2000.0;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++) {
			this->varsteJucatori[i] = 18 + i;
		}
	}
	//constructor 3 clasa 1
	echipaFotbal(int numarJucatori, float pretBilet, int* varsteJucatori, string nume) : anInfiintareEchipa(1905) {
		this->numarJucatori = numarJucatori;
		this->pretBilet = pretBilet;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < numarJucatori; i++) {
			this->varsteJucatori[i] = varsteJucatori[i];
		}
		this->nume = nume;
	}

	//constructor de copiere
	echipaFotbal(echipaFotbal& e) : anInfiintareEchipa(e.anInfiintareEchipa) {
		this->nume = e.nume;
		this->numarJucatori = e.numarJucatori;
		this->pretBilet = e.pretBilet;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < e.numarJucatori; i++) {
			this->varsteJucatori[i] = e.varsteJucatori[i];
		}
	}

	//get-eri clasa 1
	string getNume() {
		return this->nume;
	}
	int getNumarJucatori() {
		return this->numarJucatori;
	}
	float getPretBilet() {
		return this->pretBilet;
	}
	const int getAnInfiintareEchipa() {
		return this->anInfiintareEchipa;
	}
	static float getTVAbilet() {
		return TVAbilet;
	}
	int* getVarsteJucatori() {
		return this->varsteJucatori;
	}

	//set-eri clasa 1 
	void setNume(const string& nume) {
		this->nume = nume;
	}

	void setNumarJucatori(const int& numarJucatori) {
		this->numarJucatori = numarJucatori;
	}

	void setPretBilet(const float& pretBilet) {
		this->pretBilet = pretBilet;
	}
	void static setTVA(const float& TVAnou) {
		TVAbilet = TVAnou;                             
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

	//destructor clasa 1
	~echipaFotbal() {
		if (this->varsteJucatori != NULL) {
			delete[]this->varsteJucatori;
		}
	}

		void afisare() {
			cout << this->nume << " este una din cele mai bune echipe de fotbal." << endl << "Acesta are " << this->numarJucatori << " jucatori." << endl <<
				"Pretul unui bilet la meci este de " << this->pretBilet << " lei. " << endl << this->nume << " a fost infiintata in anul " << this->anInfiintareEchipa
				<< ", iar " << "TVA-ul unui bilet este de " << TVAbilet << "%." << endl << "Varstele jucatorilor sunt: ";
			for (int i = 0; i < numarJucatori; i++) {
				cout << this->varsteJucatori[i] << "\n";
			}
			cout << endl;
		}

		//functie statica clasa 1 , de modificat
		static void TVA(float TVAnou) {
			TVAbilet = TVAnou;
		}

		//apelare in clasa functii prietena
		friend void functie1(const echipaFotbal& nume);

		friend void functie2(const echipaFotbal& numarJucatori);
	};

	//initializare atribut static clasa 1
	float echipaFotbal::TVAbilet = 19;

	//funcții prietena clasa 1
	void functie1(const echipaFotbal& nume) {
		cout << "Aceasta este o echipa foarte cunoscuta." << endl;
	}

	void functie2(const echipaFotbal& numarJucatori) {
		cout << "Numarul jucatorilor noi este de 5." << endl;
	}

	//clasa 2
	class jucator {
	private:
		string nume;
		string echipa;
		float salariu;
		const int anulNasterii;
		int numarTricouriPurtate;
		int* istoricNumerePurtate;
		static int aniContract;

	public:
		//initializare, constructor 1, clasa 2
		jucator() : anulNasterii(1992) {
			this->nume = "Sérgio Oliveira";
			this->echipa = "Galatasaray";
			this->salariu = 62308.0;
			this->numarTricouriPurtate = 5;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < this->numarTricouriPurtate; i++) {
				this->istoricNumerePurtate[i] = 25 + i;
			}
		}

		//constructor 2, clasa 2
		jucator(string nume) : anulNasterii(1992) {
			this->nume = nume;
			this->echipa = "Galatasaray";
			this->salariu = 62308.0;
			this->numarTricouriPurtate = 5;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < this->numarTricouriPurtate; i++) {
				this->istoricNumerePurtate[i] = 25 + i;
			}
		}

		//constructor 3, clasa 2
		jucator(string nume, string echipa, float salariu, int numarTricouriPurtate, int* istoricNumerePurtate) : anulNasterii(1992) {
			this->nume = nume;
			this->echipa = echipa;
			this->salariu = salariu;
			this->numarTricouriPurtate = numarTricouriPurtate;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < numarTricouriPurtate; i++) {
				this->istoricNumerePurtate[i] = istoricNumerePurtate[i];
			}
		}

		//constructor de copiere, clasa 2
		jucator(jucator& j) : anulNasterii(j.anulNasterii) {
			this->nume = j.nume;
			this->echipa = j.echipa;
			this->salariu = j.salariu;
			this->numarTricouriPurtate = j.numarTricouriPurtate;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < j.numarTricouriPurtate; i++) {
				this->istoricNumerePurtate[i] = j.istoricNumerePurtate[i];
			}

		}

		//get-eri clasa 2
		string getNume() {
			return this->nume;
		}
		string getEchipa() {
			return this->echipa;
		}
		float getSalariu() {
			return this->salariu;
		}
		const int getAnulNasterii() {
			return this->anulNasterii;
		}
		int getNumarTricouriPurtate() {
			return this->numarTricouriPurtate;
		}
		int* getIstoricNumerePurtate() {
			return this->istoricNumerePurtate;
		}
		static int getAniContract() {
			return aniContract;
		};

		//set-eri clasa 2
		void setNume(const string& nume) {
			this->nume = nume;
		}
		void setEchipa(const string& echipa) {
			this->echipa = echipa;
		}
		void setSalariu(const float& salariu ) {
			this->salariu = salariu;
		}
		void setIstoricNumerePurtate(int* istoricNumerePurtateVechi) {
			if (istoricNumerePurtate != NULL) {
				delete[] this->istoricNumerePurtate;
				this->istoricNumerePurtate = NULL;
			}
			this->istoricNumerePurtate = new int[numarTricouriPurtate]; 
			for (int i = 0; i < numarTricouriPurtate; i++) {
			this->istoricNumerePurtate[i] = istoricNumerePurtateVechi[i];
			}
		}
		void static setAniContract (const int& AniContract) {
			aniContract = AniContract;
		}

		//destructor clasa 2
		~jucator() {
			if (this->istoricNumerePurtate != NULL) {
				delete[]this->istoricNumerePurtate;
				this->istoricNumerePurtate = NULL; 
			}
		}

		void afisare() {
			cout << "Numele jucatorului este " << nume << ". Echipa pentru care joaca este " << echipa << "." << endl << nume << " are un salariu de " <<
				salariu << " euro. " << endl << "Anul in care s-a nascut este " << anulNasterii << ". " << endl << "Contractul cu echipa poate fi de maxim "
				<< aniContract << " ani." << endl << "A purtat " << numarTricouriPurtate << " tricouri reprezentative si a avut numerele ";
			for (int i = 0; i < numarTricouriPurtate; i++) {
				cout << this->istoricNumerePurtate[i] << endl;

			}
			cout << endl;

		}

		//functie statica, clasa 2
		static void setContract(int contractNou) {
			aniContract = contractNou;
		}

		//apelare in clasa functii prietena
		friend void functie3(const jucator& nume);
		friend void functie4(const jucator& pretBilet);
	};

	// initializare atribut static clasa 2
	int jucator::aniContract = 7;

	//funcții prietena clasa 2
	void functie3(const jucator& nume) {
		cout << "Jucatorul este pe locul 1 in clasament." << endl;
	}
	void functie4(const jucator& pretBilet) {
		cout << "Pretul biletului este de neratat." << endl;
	}

	//clasa 3
	class stadion {
	private:
		string nume;
		int numarLocuriTotal;
		int numarPeluze;
		int* locuriPeluza;
		static int TVApretBilet;
		const int anConstructie;

	public:

		//initializare, constructor 1, clasa 3
		stadion() : anConstructie(2007) {
			this->nume = "Ali Sami Yen Stadium";
			this->numarLocuriTotal = 52280;
			this->numarPeluze = 4;
			this->locuriPeluza = new int[this->numarPeluze];
			for (int i = 0; i < numarPeluze; i++) {
				this->locuriPeluza[i] = 12000 + i;
			}
		
		}

		//constructor 2 clasa 3
		stadion(string nume) : anConstructie(2007) {
			this->nume = nume;
			this->numarLocuriTotal = 52280;
			this->numarPeluze = 4;
			this->locuriPeluza = new int[this->numarPeluze];
			for (int i = 0; i < this->numarPeluze; i++) {
				this->locuriPeluza[i] = 12000 + i;
			}
		}

		//constructor 3 clasa 3
		stadion(string nume, int numarLocuriTotal, int* locuriPeluza) : anConstructie(2007) {
			this->nume = nume;
			this->numarLocuriTotal = numarLocuriTotal;
			this->numarPeluze = 3;
			this->locuriPeluza = new int[this->numarPeluze];
			for (int i = 0; i < this->numarPeluze; i++) {
				this->locuriPeluza[i] = locuriPeluza[i];
			}
		}

		//constructor de copiere clasa 3
		stadion(stadion& s) : anConstructie(s.anConstructie) {
			this->nume = s.nume;
			this->numarLocuriTotal = s.numarLocuriTotal;
			this->numarPeluze = 3;
			this->locuriPeluza = new int[this->numarPeluze];
			for (int i = 0; i < s.numarPeluze; i++) {
				this->locuriPeluza[i] = s.locuriPeluza[i];
			}
		}

		//get-eri clasa 3 
		string getNume() {
			return this->nume;
		}
		int getNumarLocuriTotal() {
			return this->numarLocuriTotal;
		}
		int* getLocuriPeluza() {
			return this->locuriPeluza;
		}
		static int getTVApretBilet() {
			return TVApretBilet;
		}
		const int getAnConstructie() {
			return this->anConstructie;
		}
		
		//set-eri clasa 3
		void setNume(const string& nume) {
			this->nume = nume;
		}
		void setNumarLocuriTotal(const int& numarLocuriTotal) {
			this->numarLocuriTotal = numarLocuriTotal;
		}

		void setLocuriPeluza(const int* locuriPeluzaNoi){
			if (this->locuriPeluza != NULL) {
				delete[] this->locuriPeluza;
				this->locuriPeluza = NULL;
			}
			this->locuriPeluza = new int[numarLocuriTotal];
			for (int i = 0; i < numarLocuriTotal; i++) {
				this->locuriPeluza[i] = locuriPeluzaNoi[i];      
			}
		}
		
		void static setTVApretBilet(const int& TVAnou) {
			TVApretBilet = TVAnou;                            
		}

		//descructor clasa 3
		~stadion() {
			if (locuriPeluza != NULL) {
				delete[] this->locuriPeluza;
				this->locuriPeluza = NULL;
			}
		}
		void afisare() {
			cout << "Numele stadionului este " << nume << "." << endl << "Numarul total de locuri este de " << numarLocuriTotal<< " de persoane." << endl <<
				"Numarul peluzelor este " << numarPeluze;
			cout << ", iar numarul de locuri pe peluza este de  ";
			for (int i = 0; i < numarPeluze; i++) {
				cout << this->locuriPeluza[i] << endl;
			};
			cout << "persoane." << endl << "Anul constructiei stadionului este " << anConstructie << endl << "TVA-ul unui bilet este de: " <<
				TVApretBilet << "%." << endl;
			cout << endl;
		}

		//functie statica clasa 3
		void static setTVApretBilet(int TVAnou) {
			if (TVAnou <= 4) {
				TVApretBilet = TVAnou;
			}
		}

		//apelare functie friend in clasa
		friend void functie5(const stadion& nume);
		friend void functie6(const stadion& numarLocuriTotal);

	};

	//initializare atribut static clasa 3
	int stadion::TVApretBilet = 19;

	//functii prietena clasa 3
	void functie5(stadion& nume) {
		cout << nume.getNume() << " este un stadion foarte cunoscut la nivel international." << endl;
	}
	void functie6(stadion& numarLocuriTotal) {
		cout << numarLocuriTotal.getNumarLocuriTotal() << " este un numar remarcabil de locuri intr-un stadion." << endl << endl;
	}


	void main() {
		//apelare obiecte clasa 1
		int* varste = new int[6];
		for (int i = 0; i < 6; i++) {
			varste[i] = 16 + i;
		}

		echipaFotbal echipa1(11, 3000, varste, "Arsenal");
		echipa1.setTVA(20);
		echipa1.afisare();

		echipa1.setVarsteJucatori(new int[6] {18, 16, 22, 23, 19, 24});
		echipa1.afisare();

		echipaFotbal echipa2("Tottenham");
		echipa2.afisare();

		echipaFotbal echipa3;
		echipa3.afisare();

		functie1(echipa1); //functia friend
		functie2(echipa1);

		cout << "Echipa 1" << endl;
		echipa1.getNume();
		cout << "Echipa 1 are doar jucatori de top." << endl;
		echipa1.getNumarJucatori();
		cout << "Biletul este la reducere." << endl;
		echipa1.getPretBilet();
		cout << "Anul infiintarii echipei este de neuitat." << endl;
		echipa1.getAnInfiintareEchipa();
		cout << "TVA-ul ramane de 19%." << endl;
		echipa1.getTVAbilet();
		cout << "Cel mai tanar jucator poate fi de 16 ani." << endl;
		echipa1.getVarsteJucatori();
		
		//apelare obiecte clasa 2
		jucator jucator1;
		jucator1.afisare();

		int* nrTricouriPurtate = new int[3];
		for (int i = 0; i < 3; i++) {
			nrTricouriPurtate[i] = 13 + i;
		}
		jucator jucator2("Declan Rice", "Arsenal", 100000, 3, nrTricouriPurtate);
		jucator2.setContract(6);
		jucator2.afisare();

		jucator jucator3("Heung-Min Son");
		jucator3.afisare();

		functie3(jucator1); // functia friend
		functie4(jucator1); 

		jucator1.getNume();
		jucator1.getEchipa();
		jucator1.getAniContract();
		jucator1.getAnulNasterii();
		jucator1.getIstoricNumerePurtate();
		jucator1.getNumarTricouriPurtate();
		jucator1.getSalariu();

		//apelare obiect clasa 3
		stadion stadion1;
		stadion1.afisare();

		stadion stadion2("Tottenham Hotspur Stadium");
		stadion2.afisare();

		int* locuriPeluza1 = new int[3];
		for (int i = 0; i < 3; i++) {
			locuriPeluza1[i] = 200 + i;
		}
		stadion stadion3("Arsenal", 60704, locuriPeluza1);
		//stadion3.setTVApretBilet(19);                  
		stadion3.afisare();

		functie5(stadion1); // functia friend
		functie6(stadion1);

		stadion1.getAnConstructie();
		stadion1.getLocuriPeluza();
		stadion1.getNumarLocuriTotal()
		stadion1.getNume();
		stadion1.getTVApretBilet();
		stadion1.getTVApretBilet();
	};

	
	


