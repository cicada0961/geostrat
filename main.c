#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "src/pays.h"

#define NB_PAYS 3   /* Nombre de pays dans la simulation */

int main(void) {
    srand(time(NULL));  /* Initialise le générateur aléatoire avec l'heure actuelle */

    int taille = 0;         /* Nombre de pays initialisés */
    int nb_tour = 1;        /* Tour actuel */
    int tour = 10;          /* Nombre total de tours à simuler */
    int pop_totale;
    int nb_en_guerre;
    float pib_total;

    Pays pays[NB_PAYS];

    /* Initialisation des pays avec leurs caractéristiques de départ */
    initialiser_pays(pays, "Arcturia", "Elara Voss", 75, 3200, 90, 1200, 4200.5, 320,450, 3500, 800, 120, 0, 2, &taille);
    initialiser_pays(pays, "Kaldera", "Malik Drevon", 42, 8500, 45, 600, 890.0, 95,1200, 9000, 400, 350, 1, -1, &taille);
    initialiser_pays(pays, "Veralion", "Seun Adara", 88, 400, 72, 3800, 2100.75, 210,280, 1200, 550, 60, 0, 0, &taille);

    /* Calcul de la puissance militaire initiale de chaque pays */
    for (int i = 0; i < taille; i++) calculer_puissance(&pays[i].armee);

    /* Identification et bonus de la superpuissance de départ */
    Pays *plus_fort = trouver_plus_fort(pays, NB_PAYS);
    printf("La super puissance mondiale est : %s\n\n", plus_fort->name);
    plus_fort->stabilite += 5;

    /* Transfert d'aide d'Arcturia vers Veralion avant le début de la simulation */
    transfert_aide(&pays[0], &pays[2], 500, 200);

    /* Boucle principale de simulation */
    while (nb_tour <= tour) {
        printf("Debut du Tour %d\n", nb_tour);
        simuler_tour(pays, NB_PAYS);
        recap_tour(pays, NB_PAYS, nb_tour);
        /* Vérifie si tous les pays sont en guerre (condition de fin anticipée) */
        if (fin_du_monde(pays, NB_PAYS)) {
            printf("!!! EFFONDREMENT GEOPOLITIQUE MONDIAL - SIMULATION TERMINEE !!!\n");
            break;
        }
        nb_tour++;
    }

    /* Affichage du classement final par PIB */
    printf("\n");
    afficher_classement_pib(pays, NB_PAYS);

    /* Affichage des statistiques mondiales finales */
    stats_mondiales(pays, NB_PAYS, &pib_total, &pop_totale, &nb_en_guerre);
    printf("\nPopulation mondiale : %d millions | Pib mondial : %.2f millliard $ | Nombre de pays en guerre : %d\n", pop_totale, pib_total, nb_en_guerre);

    return 0;
}