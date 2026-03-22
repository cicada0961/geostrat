#ifndef GEOSTRAT_PAYS_H
#define GEOSTRAT_PAYS_H

#include "ressources.h"
#include "armee.h"

/* Représente un pays avec ses données politiques, économiques et militaires */
typedef struct {
    char name[50];        /* Nom du pays */
    char dirigeant[50];   /* Nom du dirigeant */
    int stabilite;        /* Stabilité politique sur 100 */
    int en_guerre;        /* 1 si en guerre, 0 si en paix */
    int allie_id;         /* Index du pays allié (-1 si aucun) */

    Ressources res;       /* Ressources économiques et naturelles */
    Armee armee;          /* Force militaire */

}Pays;

/* Initialise un pays et l'ajoute au tableau, incrémente taille */
void initialiser_pays(Pays pays[], char *nom, char *dirigeant, int stab, int petrole, int techno, int nourriture, float pib, int population,
    int soldats, int chars, int avions, int missiles, int guerre, int allie, int *taille);

/* Affiche tous les pays du tableau */
void afficher_tout_pays(Pays pays[], int* taille);

/* Affiche la fiche détaillée d'un pays */
void afficher_pays(Pays p);

/* Applique un événement aléatoire sur un pays (crise, boom, guerre...) */
void appliquer_evenement(Pays *p, int type_evenement);

/* Remet à zéro toutes les valeurs négatives d'un pays */
void corriger_valeur(Pays *p);

/* Simule un tour de jeu pour tous les pays */
void simuler_tour(Pays pays[], int nb_pays);

/* Déclenche un événement aléatoire sur un pays aléatoire */
void event_aleatoire(Pays pays[], int nb_pays);

/* Affiche un tableau récapitulatif à la fin d'un tour */
void recap_tour(Pays pays[], int nb_pays, int nb_tour);

/* Affiche le classement des pays par PIB (du plus faible au plus riche) */
void afficher_classement_pib(Pays pays[], int nb_pays);

/* Transfère du pétrole et du PIB d'un pays donneur vers un pays receveur */
void transfert_aide(Pays *donneur, Pays *receveur, int petrole, float pib_aide);

/* Calcule les statistiques mondiales (PIB total, population totale, pays en guerre) */
void stats_mondiales(Pays pays[], int nb_pays, float *pib_total, int *pop_totale, int *pays_en_guerre);

/* Retourne 1 si tous les pays sont en guerre (fin du monde), 0 sinon */
int fin_du_monde(Pays pays[], int nb_pays);

/* Retourne un pointeur vers le pays avec la plus grande puissance militaire */
Pays* trouver_plus_fort(Pays pays[], int nb_pays);

#endif //GEOSTRAT_PAYS_H