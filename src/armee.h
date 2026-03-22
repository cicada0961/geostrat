#ifndef GEOSTRAT_ARMEE_H
#define GEOSTRAT_ARMEE_H

typedef struct {
    int soldats;
    int chars;
    int avions;
    int missiles;
    int puissance;
}Armee;

void calculer_puissance(Armee *a);
char* get_statut_militaire(int puissance);

#endif //GEOSTRAT_ARMEE_H