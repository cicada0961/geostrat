#ifndef GEOSTRAT_PAYS_H
#define GEOSTRAT_PAYS_H

#include "ressources.h"
#include "armee.h"

typedef struct {
    char name[50];
    char dirigeant[50];
    int stabilite;
    int en_guerre;
    int allie_id;

    Ressources res;
    Armee armee;

}Pays;

void initialiser_pays(Pays pays[], char *nom, char *dirigeant, int stab, int petrole, int techno, int nourriture, float pib, int population,
    int soldats, int chars, int avions, int missiles, int guerre, int allie, int *taille);

void afficher_tout_pays(Pays pays[], int* taille);
void afficher_pays(Pays p);
void appliquer_evenement(Pays *p, int type_evenement);
void corriger_valeur(Pays *p);
void simuler_tour(Pays pays[], int nb_pays);
void event_aleatoire(Pays pays[], int nb_pays);
void recap_tour(Pays pays[], int nb_pays, int nb_tour);
void afficher_classement_pib(Pays pays[], int nb_pays);
void transfert_aide(Pays *donneur, Pays *receveur, int petrole, float pib_aide);
void stats_mondiales(Pays pays[], int nb_pays, float *pib_total, int *pop_totale, int *pays_en_guerre);

int fin_du_monde(Pays pays[], int nb_pays);
Pays* trouver_plus_fort(Pays pays[], int nb_pays);

#endif //GEOSTRAT_PAYS_H