#pragma
#include <random>
#include <chrono>

class Array
{
	//Déclarations et initialisation des variables.
	private:
		int dimX{}, dimY{}, i{}, posX{}, posY{}, mLevel{}, nbMine{};
		int const mLower = 0, percent = 100;
		enum asciiCode {
			greyZone=177
		};
		//énumération des niveaux de difficulté du jeu.
		enum NiveauDifficulte {
			ndTresFacile,
			ndFacile,
			ndMoyen,
			ndDifficile,
			ndTresDifficile
		};
		//énumération du pourcentage de mine en fonction du niveau de difficulté.
		enum MinePercentage {
			tf=5,
			f=10,
			m=15,
			d=20,
			td=25
		};

	public:
		//Structure des tableaux 2D permettant l'affichage de la grille du démineur.
		typedef struct {
			int Info;
			unsigned char Display;
		} CaseChampMine;
		//Fonction créant le tableau 2D et initialise les valeurs à 0.
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
		//Fonction pour libérer la mémoire du tableau.
		void deleteArray();
		//getter du nombre de mine.
		void getNbMine(int *nbMine);
		//Fonction qui calcul un x et un y aléatoire pour une mine.
		void minePos();
		//Fonction qui calcul le nombre de mine en fonction de la
		//difficulté choisi.
		void mineCount();
		//Fonction qui renvoi un chiffre aléatoire avec en
		//paramètre unune limite à ne pas depasser.
		int randomize(int mUpper) const;

	private:
		CaseChampMine** Array2D{ nullptr };


};

