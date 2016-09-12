# DM_jussieu
DM d'été de Jussieu M1 SFPN en C

Auteur: Picot Rodolphe												 			 
																	 				 
	Le programme s'utilise de la facon suivante:						 			 
																	 				 
 		Le premier argument est l'option,'-c' pour chiffrer et 			 			 
 		'-d' pour déchiffrer											 			 
																	 				 
 		Le deuxieme argument est la permutation, attention,				 			 
 		La permutaiton doit contenir tous les entiers entre 			 			 
 		1 et N								 			 
																	 				 
 		Le troisieme argument est le message à chifrer/déchiffrer		 			 
																		 			 
 		La ligne de compilation est :										 		 
																		 			 
	 	'gcc -o exe polybe.c -lm'													 
 																					 
 		Exemple d'utilisation: 														 
 																					 
		 ./exe -c 3,1,2,4 attaquesurparisle12 										 	 
																					 
 																					 
 			FFGDFADXDGDFVFXFFVAXFDGVVGXFVFFFFXDFAGDX 								 
 																					 
 		 ./exe -d 3,1,2,4 FFGDFADXDGDFVFXFFVAXFDGVVGXFVFFFFXDFAGDX 					 
 																					 
 			attaquesurparisle129 													 
																					 
	Note: il se peut que le chiffrement rajoute des '9' au message initial,			 
	pour différencier les '9' légitimes des autres, on peut mettre le mot 			 
	"stop" à la fin du message à chiffrer.
