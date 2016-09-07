#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "tools.h"

struct Paire_char code(char const lettre){
	struct Paire_char res;
	int trouve=0;
	for (int i = 1; i < 7 && trouve!=1; ++i)
	{
		for (int j = 0; j < 6 && trouve!=1; ++j)
		{
			if ((char)tolower((int)lettre)==carre[i][j])
			{
				res.premier=carre[0][i-1];
				res.deuxieme=carre[0][j];
				trouve=1;
			}
		}
	}
	return res;
}

void affiche(char const *chiffre, int const taille){
	for (int i = 0; i < taille; ++i)
	{
		if ((int)chiffre[i]==0)
		{
			printf("X");
		}
		else{
			printf("%c", chiffre[i]);
		}
	}
	printf("\n");
}

void chiffrement(int const *permutation, int const taille_permut, char const *message, int const taille_message){
	int nbr_lignes=ceil(taille_message*2.0/ taille_permut);
	int taille_tot=nbr_lignes*taille_permut;
	char *chiffre=calloc(taille_tot, sizeof(char));
	// calloc va initialiser la zone mémoire avec des 0 dont on va se servir pour l'affichage
	for (int i = 0; i < taille_message; ++i)
	{
		struct Paire_char trad=code(message[i]);
		chiffre[(permutation[((i*2)%taille_permut)]-1) * nbr_lignes + (i*2/taille_permut)]=trad.premier;
		chiffre[(permutation[((i*2+1)%taille_permut)]-1) * nbr_lignes + ((i*2+1)/taille_permut)]=trad.deuxieme;
	}
	affiche(chiffre, taille_tot);
	free(chiffre);
}