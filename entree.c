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

int traduction(int permut[], const char *argv, int const taille){ // à modifier
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
			int argv_tmp = (int)argv[i];
			if (argv_tmp < 48 || argv_tmp > 57)
			{
				return 1;
			}
			tmp+=((int)argv[i]-48)*(int)pow(10.0, (double)pui);
			pui++;
		}
	}
	return 0;
}

int fact(int x){
	int res = 1;
	for (int i = 2; i <= x; ++i)
	{
		res*=i;
	}
	return res;
}

int verification(int const permutation[], int const taille){
	int verif_produit= fact(taille);
	int verif_somme= (taille*(taille+1))/2;
	for (int i = 0; i < taille; ++i)
	{
		int permut_tmp = permutation[i];
		if (permut_tmp <= 0 || permut_tmp > taille)
		{
			printf("coucou\n");
			return 1;
		}
		verif_produit /= permut_tmp;
		verif_somme -= permut_tmp;
	}
	return verif_somme || (verif_produit-1); // retourne 0 si tout se passe bien
}

/*int verification(int const permutation[], int const taille){
	int *verif = calloc(taille, sizeof(int));
	for (int i = 0; i < taille; ++i)
	{
		int jump = permutation[i]-1;
		if (jump < 0 || jump >= taille)
		{
			verif[jump] == 1;
		}
	}
	for (int i = 0; i < taille; ++i)
	{
		if (verif[i] == 0)
		{
			return 1;
		}
	}
	free(verif);
	return 0;
}*/