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

int correction_chiffre(char chiffre[], int taille){ // 0 = pas de probleme
	for (int i = 0; i < taille; ++i)
	{
		chiffre[i]=(char)toupper((int)chiffre[i]);
		for (int j = 0; j < 6; ++j)
		{
			if(chiffre[i] == carre[0][j]){
				return 0;
			}
		}
		return 1;
	}
	return 1; // ce n'est pas censé arrivé
}

int correction_message(char message[], int taille){ // 0 = pas de probleme
	for (int i = 0; i < taille; ++i)
	{
		message[i]=(char)tolower((int)message[i]);
		int ascii = (int)message[i];
		if ( ascii < 48 || (ascii > 57 && ascii < 97) || ascii > 122 ) // 48 = 0,   57 = 9, 97 = a,  122 = z en ascii
		{
			printf(" i : %d message : %c  mi %d \n", i , message[i], ascii );
			return 1;
		}
	}
	return 0;
}