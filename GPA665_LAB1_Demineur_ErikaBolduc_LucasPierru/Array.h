#pragma
#include <random>
#include <chrono>

class Array
{
	//D�clarations et initialisation des variables.
	private:
		int dimX{}, dimY{}, i{}, posX{}, posY{}, mLevel{}, nbMine{};
		int const mLower = 0, percent = 100;
		enum asciiCode {
			greyZone=177
		};
		//�num�ration des niveaux de difficult� du jeu.
		enum NiveauDifficulte {
			ndTresFacile,
			ndFacile,
			ndMoyen,
			ndDifficile,
			ndTresDifficile
		};
		//�num�ration du pourcentage de mine en fonction du niveau de difficult�.
		enum MinePercentage {
			tf=5,
			f=10,
			m=15,
			d=20,
			td=25
		};

	public:
		//Structure des tableaux 2D permettant l'affichage de la grille du d�mineur.
		typedef struct {
			int Info;
			unsigned char Display;
		} CaseChampMine;
		//Fonction cr�ant le tableau 2D et initialise les valeurs � 0.
		void createArray2D();
		//Fonction d'initialisation qui appelle 2 fonction.
		//pour le calcul de du nombre de mines et la position de celle-ci.
		void initArray();
		//setter de la taille en x de la grille.
		void setX(int x);
		//setter de la taille en y de la grille.
		void setY(int y);
		//setter du niveau de jeu.
		void setLevel(int level);
		//getter pour le tableau 2D.
		CaseChampMine** getArray2D();
		//Fonction pour lib�rer la m�moire du tableau.
		void deleteArray();
		//getter du nombre de mine.
		void getNbMine(int *nbMine);
		//Fonction qui calcul un x et un y al�atoire pour une mine.
		void minePos();
		//Fonction qui calcul le nombre de mine en fonction de la
		//difficult� choisi.
		void mineCount();
		//Fonction qui renvoi un chiffre al�atoire avec en
		//param�tre unune limite � ne pas depasser.
		int randomize(int mUpper) const;

	private:
		CaseChampMine** Array2D{ nullptr };


};

