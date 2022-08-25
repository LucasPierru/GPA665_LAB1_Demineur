#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "Array.h"
using namespace std;

class Display {
	private : 
		int const minXY{ 10 }, maxX{ 18 }, maxY{ 75 };
		int mX{ }, mY{ }, mChoice{}, mNbMine{}, x{}, y{}, level{}, p{}, n{}, endGame{}, restart{}, flagMine{}, confirm{}, mineCovered{};
		Array::CaseChampMine** mArray2D;
		Array array;
		//�num�ration des niveaux de difficult� du jeu.
		enum NiveauDifficulte {
			ndTresFacile,
			ndFacile,
			ndMoyen,
			ndDifficile,
			ndTresDifficile
		};
		//�num�ration des diff�rents codes ascii utilis� dans le code
		enum AsciiCode {
			Q=81,
			q=113,
			E=69,
			e=101,
			M=77,
			m=109,
			upLeftCorner=201,
			horizontalLine = 205,
			upRightCorner = 187,
			verticalLine = 186,
			bottomLeftCorner = 200,
			bottomRightCorner = 188,
			mine = 42,
			space= 32,
			nbMineAdjuste = 48,
			greyZone=177
		};
	public : 
		//Fonction main qui g�re le jeu.
		void startSimulation();
		//Fonction qui renvoie le niveau de jeu.
		int levelSimulation();
		//Fonction qui v�rifie si une valeur est bien
		//comprise entre 2 bornes
		bool checkValue(int min, int max, int value);
		//Fonction qui affiche la grille de jeu
		void gridDisplay();
		//Fonction qui affiche la partie commande et qui demande
		//une commande � entrer
		void command();
		//Fonction permettant d'explorer la grille.
		//On choisit une case � d�couvrir.
		void commandExplore();
		//Fonction qui permet d'indentifier des mines
		void commandMine();
		//Fonction qui affiche toutes les mines lorsqu'on
		//explore une case avec une mine
		void explosion();
		//Fonction qui r�cup�re le charact�re � afficher suivant
		//les informations que le tableau 2D contient
		void getCharacter(int x, int y);
		//Fonction r�cursive qui lib�re toutes les cases vides
		//lorsqu'on explore une case vide
		void freeZone(int x, int y);
		void countCovered();
		bool checkWin();
};
