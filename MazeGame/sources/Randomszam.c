#include <stdio.h>
#include <stdlib.h>
#include "Randomszam.h"

int Randomszam(int min, int max)
{
	++max;
	return rand() % (max - min) + min;
}
