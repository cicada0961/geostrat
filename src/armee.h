#ifndef GEOSTRAT_ARMEE_H
#define GEOSTRAT_ARMEE_H

/* Représente la force militaire d'un pays */
typedef struct {
    int soldats;    /* Nombre de soldats */
    int chars;      /* Nombre de chars */
    int avions;     /* Nombre d'avions */
    int missiles;   /* Nombre de missiles */
    int puissance;  /* Score de puissance calculé (pondération de chaque unité) */
}Armee;

/* Calcule le score de puissance militaire selon le nombre d'unités */
void calculer_puissance(Armee *a);

/* Retourne une chaîne décrivant le rang militaire selon le score de puissance */
char* get_statut_militaire(int puissance);

#endif //GEOSTRAT_ARMEE_H