#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

char correspondance(char const premier, char const deuxieme){
	int i=-1;
	int j=-1;
	for (int k=0; k < 6 && (i==-1 || j==-1); ++k)
	{
		if (carre[0][k]==premier)
		{
			i=k+1;
		}
		if (carre[0][k]==deuxieme)
		{
			j=k;
		}
	}
	if (i == -1 && j == -1)
	{
		return '\0'; // caractere arbitraire pour signifier qu'il y a un probleme
	}
	return carre[i][j];
}

int dechiffrement(int const *permutation, int const taille_permut, char const *chiffre, int taille_chiffre){
	char message[taille_chiffre/2];
	int nbr_lignes=taille_chiffre/taille_permut;
	for (int i = 0; i < taille_chiffre; i+=2)
	{
		int un=nbr_lignes * (permutation[i%taille_permut]-1) + (i/taille_permut);
		int deux=nbr_lignes * (permutation[(i+1)%taille_permut]-1) + ((i+1)/taille_permut);
		char premier=(char)toupper((int)chiffre[un]);
		char deuxieme= (char)toupper((int)chiffre[deux]);
		message[i/2]=correspondance(premier, deuxieme);
		if (message[i/2] == '\0')
		{
			return 1;
		}
	}
	message[taille_chiffre/2]='\0';
	printf("%s\n", message);
	return 0;
}