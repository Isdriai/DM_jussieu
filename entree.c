#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "tools.h"

int length_permut(char const permut[]){
	int tmp = strlen(permut);
	int res=1;
	for (int i = 0; i < tmp; ++i)
	{
		if (permut[i]==',')
		{
			res++;
		}
	}
	return res;
}

void traduction(int permut[], const char *argv, int const taille){ // à modifier
	int pos=0;
	int pui=0;
	int tmp=0;
	for (int i = 0; i < taille; ++i)
	{
		if (argv[i]==',')
		{
			permut[pos]=tmp;
			pos++;
			pui=0;
			tmp=0;
		}
		else {
			tmp+=((int)argv[i]-48)*(int)pow(10.0, (double)pui);
			pui++;
		}
	}
}

int verification(int const permutation[], int const taille){
	int verif=(taille*(taille+1))/2;
	for (int i = 0; i < taille; ++i)
	{
		verif-=permutation[i];
	}
	return verif;
}