#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Paire_char
{
	char premier;
	char deuxieme;
};

char carre[7][6] = 
{
	{'A','D','F','G','V','X'},
	{'c','1','o','f','w','j'},
	{'y','m','t','5','b','4'},
	{'i','7','a','2','8','s'},
	{'p','3','0','q','h','x'},
	{'k','e','u','l','6','d'},
	{'v','r','g','z','n','9'}
};

void traduction(int permut[], const char *argv, int const taille){
	for (int i = 0; i < taille; ++i)
	{
		permut[i]=(int)argv[i]-48;
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

struct Paire_char code(char const lettre){
	struct Paire_char res;
	int trouve=0;
	for (int i = 1; i < 7 && trouve!=1; ++i)
	{
		for (int j = 0; j < 6; ++j)
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

void chiffrement(char const *permut, char const *message){
	// init de la permutation et verification
	int taille_permut=strlen(permut);
	int permutation[taille_permut];
	traduction(permutation, permut, taille_permut);
	if (verification(permutation, taille_permut) !=0 || taille_permut==0)
	{
		printf("La permutation rentrée n'est pas valide, vérifiez que votre permutation de taille n contient bien TOUS les entiers de 1 à n\n");
		return;
	}
	int taille_message=strlen(message);
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
}

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
	return carre[i][j];
}

void dechiffrement(char const *permut, char const *chiffre){
	int taille_permut=strlen(permut);
	int permutation[taille_permut];
	traduction(permutation, permut, taille_permut);
	int taille_chiffre = strlen(chiffre);
	if (verification(permutation, taille_permut)!=0 || taille_permut==0)
	{
		printf("La permutation rentrée n'est pas valide, vérifiez que votre permutation de taille n contient bien TOUS les entiers de 1 à n\n");
		return;
	}
	if (taille_chiffre%taille_permut!=0)
	{
		printf("Le message rentré ne peut pas etre un message chiffré avec la permutation rentrée\n");
		return;
	}
	char message[taille_chiffre/2];
	int nbr_lignes=taille_chiffre/taille_permut;
	for (int i = 0; i < taille_chiffre; i+=2)
	{
		int un=nbr_lignes * (permutation[i%taille_permut]-1) + (i/taille_permut);
		int deux=nbr_lignes * (permutation[(i+1)%taille_permut]-1) + ((i+1)/taille_permut);
		char premier=chiffre[un];
		char deuxieme= chiffre[deux];
		message[i/2]=correspondance(premier, deuxieme);
	}
	message[taille_chiffre/2]='\0';
	printf("%s\n", message);
}

int main(int argc, char const *argv[])
{
	if (strcmp(argv[1], "-c")==0){
		chiffrement(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "-d")==0)
	{
		dechiffrement(argv[2], argv[3]);
	}
	else{
		printf("relancez le programme en choisissant le chiffrement '-c' ou le dechiffrement '-d'\n");
	}
}