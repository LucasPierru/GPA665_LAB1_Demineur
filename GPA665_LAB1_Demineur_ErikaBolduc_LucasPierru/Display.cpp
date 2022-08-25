#include "Display.h"


void Display::startSimulation()
{
	while (mChoice != Q && mChoice != q) {
		endGame = 0;
		mNbMine = 0;
		confirm = 0;
		level = 0;
		system("CLS");
		//Choisir niveau
		cout << "Entrez le niveau de difficulte voulu : \n1. Tres facile\n2. Facile\n3. Moyen\n4. Difficile\n5. Tres difficile\n(Q)uitter" << endl;
		mChoice = _getch();
		levelSimulation();
		//Choisir taille
		cout << "Entrez une valeur en x entre " << minXY << " et " << maxX << " : ";
		cin >> mX;
		while (!checkValue(minXY, maxX, mX)) {
			cout << "La valeur nest pas bonne. Entrez une valeur en x entre " << minXY << " et " << maxX << " : ";
			cin >> mX;
		}
		cout << "Entrez une valeur en y entre " << minXY << " et " << maxY << " : ";
		cin >> mY;
		while (!checkValue(minXY, maxY, mY)) {
			cout << "La valeur nest pas bonne. Entrez une valeur en y entre " << minXY << " et " << maxY << " : ";
			cin >> mY;
		}
		array.setX(mX);
		array.setY(mY);
		array.setLevel(level);
		array.createArray2D();
		array.getNbMine(&mNbMine);
		array.initArray();
		mArray2D = array.getArray2D();
		

		while (mChoice != Q && mChoice != q && endGame==0 && !checkWin()) {
			gridDisplay();
			if (endGame == 0) {//si le jeu n'est pas finie, on demande une commande
				command();
			}
			if (mChoice == E || mChoice == e) {
				commandExplore();
			}
			else if (mChoice == M || mChoice == m) {
				commandMine();
			}
		}
		gridDisplay();
		if (mChoice == q || mChoice == Q) {
			cout << "Voulez-vous vraiment quitter?\n 1. Oui\n 2. Non\n";
			cin >> confirm;
			if (confirm == 2) {
				mChoice = e;
			}
		}
		else if (checkWin()) {
			cout << "Bravo! Vous avez gagne!!! Voulez-vous recommencer?\n 1. Recommencer\n 2. Quitter\n";
			cin >> restart;
			if (restart == 2) {
				mChoice = Q;
			}
		}
		else {
			cout << "Voulez-vous recommencer?\n 1. Recommencer\n 2. Quitter\n";
			cin >> restart;
			if (restart == 2) {
				mChoice = Q;
			}
		}
		array.deleteArray();
	}
	::exit(0);
}

int Display::levelSimulation()
{
	if (mChoice == Q || mChoice == q) {
		::exit(0);
	}
	level = mChoice - 49;
	return level;
}

bool Display::checkValue(int min, int max, int value)
{
	if (value >= min && value <= max) {
		return true;
	}
	else {
		return false;
	}
}

void Display::gridDisplay()
{
	system("cls");
	p = 0, n = 0;
	cout << "  ";
	for (int i = 1; i <= mY; i++) {
		if (i % 10 == 0 && i != 0) {
			p++;
		}
		cout << p;
	}
	cout << endl << "  ";
	for (int i = 1; i <= mY; i++) {
		n++;
		if (i % 10 == 0 && i != 0) {
			n = 0;
		}
		cout << n;
	}
	cout << endl << " " << (char)upLeftCorner;
	//Ligne du haut
	for (int i = 0; i < mY; i++) {
		cout << (char)horizontalLine;
	}
	cout << (char)upRightCorner << endl;
	//Centre
	for (int i = 0; i < mX; i++) {
		cout << (char)('A' + i);
		cout << (char)verticalLine;
		for (int j = 0; j < mY; j++) {
			cout << mArray2D[i][j].Display;
		}
		cout << (char)verticalLine << endl;
	}
	//Ligne du bas
	cout << " " << (char)bottomLeftCorner;
	for (int i = 0; i < mY; i++) {
		cout << (char)horizontalLine;
	}
	cout << (char)bottomRightCorner << endl;
}

void Display::command()
{
	cout <<flagMine <<" mine(s) identifiee(s) sur " << mNbMine;
	cout << "\t\t(Q)uitter/(M)ine/(E)xplorer" << endl;
	cout << "Commande : ";
	mChoice = _getch();
}

void Display::commandExplore()
{
	cout << "Entrez une valeur en x entre " << 1 << " et " << mX << " : ";
	cin >> x;
	while (!checkValue(1, mX, x)) {
		cout << "La valeur nest pas bonne. Entrez une valeur en x entre " << 1 << " et " << mX << " : ";
		cin >> x;
	}
	cout << "Entrez une valeur en y entre " << 1 << " et " << mY << " : ";
	cin >> y;
	while (!checkValue(1, mY, y)) {
		cout << "La valeur nest pas bonne. Entrez une valeur en y entre " << 1 << " et " << mY << " : ";
		cin >> y;
	}
	getCharacter(x - 1, y - 1);
	
	if (mArray2D[x - 1][y - 1].Info == -1) {
		explosion();
	}
	else if (mArray2D[x - 1][y - 1].Info == 0) {
		freeZone(x - 1, y - 1);
	}
}

void Display::commandMine()
{
	cout << "Entrez une valeur en x entre " << 1 << " et " << mX << " : ";
	cin >> x;
	while (!checkValue(1, mX, x)) {
		cout << "La valeur nest pas bonne. Entrez une valeur en x entre " << 1 << " et " << mX << " : ";
		cin >> x;
	}
	cout << "Entrez une valeur en y entre " << 1 << " et " << mY << " : ";
	cin >> y;
	while (!checkValue(1, mY, y)) {
		cout << "La valeur nest pas bonne. Entrez une valeur en y entre " << 1 << " et " << mY << " : ";
		cin >> y;
	}
	mArray2D[x - 1][y - 1].Display = M;
	flagMine++;
}

void Display::explosion()
{
	for (int i = 0; i < mX; i++) {
		for (int j = 0; j < mY; j++) {
			if (mArray2D[i][j].Info == -1) {
				mArray2D[i][j].Display = mine;
			}
		}
	}
	endGame = 1;
}

void Display::getCharacter(int x, int y)
{
	if (mArray2D[x][y].Info == -1) {
		mArray2D[x][y].Display = mine;
	}
	else if (mArray2D[x][y].Info == 0) {
		mArray2D[x][y].Display = space;
	}
	else {
		mArray2D[x][y].Display = (unsigned char)(mArray2D[x][y].Info + nbMineAdjuste);
	}
}

void Display::freeZone(int x, int y)
{
	getCharacter(x, y);
	for (int i = x - 1; i <= x + 1; i++) {//avec ces deux boucles on verifie chaque case autour.
		for (int j = y - 1; j <= y + 1; j++) {
			if (checkValue(0, mX-1, i) && checkValue(0, mY-1, j)) {
				if (mArray2D[i][j].Info == 0 && mArray2D[i][j].Display != space) {
					freeZone(i, j);
					getCharacter(i, j);
				}
				else {
					getCharacter(i, j);
				}
			}
		}
	}
}

void Display::countCovered()
{
	mineCovered = 0;
	for (int i = 0; i < mX; i++) {
		for (int j = 0; j < mY; j++) {
			if (mArray2D[i][j].Display == greyZone && mArray2D[i][j].Info!=-1) {
				mineCovered++;
			}
		}
	}
}

bool Display::checkWin()
{
	countCovered();
	if (mineCovered == 0) {
		return true;
	}
	else {
		return false;
	}
}


