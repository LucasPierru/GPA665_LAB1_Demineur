#include "Array.h"

void Array::createArray2D()
{
	Array2D = (CaseChampMine**)malloc(sizeof(CaseChampMine*) * (dimX));
	/* Alloue chacun des espaces contigus du tableau d’entier */
	for (i = 0; i < dimX; i++)
	{
		Array2D[i] = (CaseChampMine*)malloc(sizeof(CaseChampMine) * (dimY));
	}
	for (int x = 0; x < dimX; x++) {
		for (int y = 0; y < dimY; y++) {
			Array2D[x][y].Info = 0;
			Array2D[x][y].Display = greyZone;
		}
	}
}

void Array::initArray()
{
	minePos();
	mineCount();
}

void Array::setX(int x)
{
	dimX = x;
}

void Array::setY(int y)
{
	dimY = y;
}

void Array::setLevel(int level)
{
	mLevel = level;
}

Array::CaseChampMine** Array::getArray2D()
{
	return Array2D;
}

void Array::deleteArray()
{
	/* Libere l’espace mémoire des entiers */
	for (i = 0; i < dimX; i++)
	{
		free(Array2D[i]);
	}
	/* Libere l’espace memoire des pointeurs d’entier */
	free(Array2D);
	/* Met le pointeur a nul */
	Array2D = NULL;
}

void Array::getNbMine(int *mnbMine)
{
	switch (mLevel) {
	case ndTresFacile:
		*mnbMine = dimX * dimY * tf/percent;
		break;
	case ndFacile:
		*mnbMine = dimX * dimY * f/percent;
		break;
	case ndMoyen:
		*mnbMine = dimX * dimY * m / percent;
		break;
	case ndDifficile:
		*mnbMine = dimX * dimY * d / percent;
		break;
	case ndTresDifficile:
		*mnbMine = dimX * dimY * td / percent;
		break;
	}
	nbMine = *mnbMine;
}

void Array::minePos()
{
	for (int i = 0; i < nbMine; i++) {
		posX = randomize(dimX);
		posY = randomize(dimY);
		if (Array2D[posX][posY].Info == -1) {
			i -= 1;
		}
		else {
			Array2D[posX][posY].Info = -1;//la valeur -1 correspond à une mine.
		}
	}
}

void Array::mineCount()
{
	int count{};
	for (int i = 0; i < dimX; i++) {
		for (int j = 0; j < dimY; j++) {
			count = 0;
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; y <= j + 1; y++) {
					if ((x != i || y != j) && (x>=0 && y>=0 && x<dimX && y<dimY)) {
						if (Array2D[x][y].Info==-1) {
							count++;
						}
					}
				}
			}
			if (Array2D[i][j].Info != -1) {
				Array2D[i][j].Info = count;
			}
		}
	}
}

int Array::randomize(int mUpper) const
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(mLower, mUpper);

	return distribution(generator);
}
