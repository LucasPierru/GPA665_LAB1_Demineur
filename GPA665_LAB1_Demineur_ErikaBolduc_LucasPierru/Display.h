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
		//énumération des niveaux de difficulté du jeu.
		enum NiveauDifficulte {
			ndTresFacile,
			ndFacile,
			ndMoyen,
			ndDifficile,
			ndTresDifficile
		};
		//énumération des différents codes ascii utilisé dans le code
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
		//Fonction main qui gère le jeu.
		void startSimulation();
		//Fonction qui renvoie le niveau de jeu.
		int levelSimulation();
		//Fonction qui vérifie si une valeur est bien
		//comprise entre 2 bornes
		bool checkValue(int min, int max, int value);
		//Fonction qui affiche la grille de jeu
		void gridDisplay();
		//Fonction qui affiche la partie commande et qui demande
		//une commande à entrer
		void command();
		//Fonction permettant d'explorer la grille.
		//On choisit une case à découvrir.
		void commandExplore();
		//Fonction qui permet d'indentifier des mines
		void commandMine();
		//Fonction qui affiche toutes les mines lorsqu'on
		//explore une case avec une mine
		void explosion();
		//Fonction qui récupère le charactère à afficher suivant
		//les informations que le tableau 2D contient
		void getCharacter(int x, int y);
		//Fonction récursive qui libère toutes les cases vides
		//lorsqu'on explore une case vide
		void freeZone(int x, int y);
		void countCovered();
		bool checkWin();
};
