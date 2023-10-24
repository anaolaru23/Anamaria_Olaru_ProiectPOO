#include <iostream>
using namespace std;

//domeniul fOtbAl

//clasa 1
class echipaFotbal {
public:
	string nume;
	int numarJucatori;
	float pretBilet;
	const int anInfiintareEchipa;
	static float TVAbilet;
	int* varsteJucatori;

	//initializare, constructor 1 clasa 1
	echipaFotbal() : anInfiintareEchipa(1905) {    
		this->nume = "Galatasaray";
		this->numarJucatori = 11;
		this->pretBilet = 2000.0;
		this->varsteJucatori = new int[this->numarJucatori];
		for (int i = 0; i < this->numarJucatori; i++) {
			this->varsteJucatori[i] = 18 + i;
		}

	}

	//constructor 2 clasa 1
	echipaFotbal(string nume) : anInfiintareEchipa(1905) {
		this->nume = nume;
		this->numarJucatori = 11;
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

	void afisare() {
		cout << nume << " este una din cele mai bune echipe de fotbal." << endl << "Acesta are " << this->numarJucatori << " jucatori." << endl << 
			"Pretul unui bilet la meci este de " << pretBilet << " lei. " << endl << nume << " a fost infiintata in anul " << anInfiintareEchipa
			<< ", iar " << "TVA-ul unui bilet este de " << TVAbilet << "%." << endl << "Varstele jucatorilor sunt: " ;
		for (int i = 0; i < numarJucatori; i++) {
			cout<<this-> varsteJucatori[i]<< "\n"; 
		}
		cout << endl;
	}

	//functie statica clasa 1
	static void setTVA(float TVAnou) {
		TVAbilet = TVAnou;
	}


};

	//initializare atribut static clasa 1
	float echipaFotbal::TVAbilet = 19;

	
//clasa 2
	class jucator {
	public:
		string nume;
		string echipa;
		float salariu;
		const int anulNasterii;
		int numarTricouriPurtate;
		int* istoricNumerePurtate;
		static int aniContract;


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
		jucator(string nunme, string echipa, float salariu, int numarTricouriPurtate, int* istoricNumerePurtate) : anulNasterii(1992) {
			this->nume = nume;
			this->echipa = echipa;
			this->salariu = salariu;
			this->numarTricouriPurtate = numarTricouriPurtate;
			this->istoricNumerePurtate = new int[this->numarTricouriPurtate];
			for (int i = 0; i < numarTricouriPurtate; i++) {
				this->istoricNumerePurtate[i] = istoricNumerePurtate[i];
			}

		}

		void afisare() {
			cout << "Numele jucatorului este " << nume << ". Echipa pentru care joaca este " << echipa << "." << endl << nume << " are un salariu de " <<
			salariu << " euro. " << endl << "Anul in care s-a nascut este " << anulNasterii << ". " << endl<< "Contractul cu echipa poate fi de maxim " 
				<< aniContract << " ani." << endl <<"A purtat " << numarTricouriPurtate << " tricouri reprezentative si a avut numerele "; 
			for (int i = 0; i < numarTricouriPurtate; i++) {
				cout << this->istoricNumerePurtate[i] << endl;

			}
			cout << endl;

		}

		//functie statica, clasa 2
		static void setContract(int contractNou) {
			aniContract = contractNou;
		}

	};

		// initializare atribut static clasa 2
		int jucator::aniContract = 7;


		//clasa 3
		class stadion {
		public:
			string nume;
			int numarLocuriTotal;
			int numarPeluze;
			int* locuriPeluza;
			static int rangStadion;
			const int anConstructie;

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
				for (int i = 0; i < numarPeluze; i++) {
					this->locuriPeluza[i] = 12000 + i;
				}
			}

			//constructor 3 clasa 3
			stadion(string nume, int numarLocuriTotal, int* locuriPeluza) : anConstructie(2007) {
				this->nume = nume;
				this->numarLocuriTotal = numarLocuriTotal;
				this->numarPeluze = numarPeluze;
				this->locuriPeluza = new int[this->numarPeluze];
				for (int i = 0; i < numarPeluze; i++) {
					this->locuriPeluza[i] = locuriPeluza[i];
				}
			}

			void afisare() {
				cout << "Numele stadionului este " << nume << "." << endl << "Numarul total de locuri este de " << numarLocuriTotal << " de persoane."<< endl <<
					"Numarul peluzelor este " << numarPeluze;
				cout << ", iar numarul de locuri pe peluza este de  ";
				for (int i = 0; i < numarPeluze; i++) {
					cout << this->locuriPeluza[i] << endl;
				};
				cout << "persoane." << endl << "Anul constructiei stadionului este " << anConstructie << endl << "Fiind vorba doar de stadioane europene, ragul este de " <<
					rangStadion << "." << endl;
				cout << endl;
			}

			//functie statica clasa 3
			static void setRang(int rangNou) {
				rangStadion = rangNou;
			}

		};

		//initializare atribut static clasa 3
		int stadion::rangStadion = 4;


		void main() {
			//apelare obiecte clasa 1

			int* varste = new int[11];
			for (int i = 0; i < 11; i++) {
				varste[i] = 20 + i;
			}

			echipaFotbal echipa1(11, 3000, varste, "Arsenal");
			echipa1.setTVA(20);
			echipa1.afisare();

			echipaFotbal echipa2("Tottenham");
			echipa2.afisare();

			echipaFotbal echipa3;
			echipa3.afisare();


			//apelare obiecte clasa 2

			jucator jucator1;
			jucator1.afisare();

			int* nrTricouriPurtate = new int[3];
			for (int i = 0; i < 3; i++) {
				nrTricouriPurtate[i] = 13 + i;
			}
			jucator jucator2("Declan Rcie", "Arsenal", 100000, 3, nrTricouriPurtate);
			jucator2.setContract(6);
			jucator2.afisare();

			jucator jucator3("Heung-Min Son");
			jucator3.afisare();

		
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
				stadion3.setRang(5);
				stadion3.afisare();
		};







