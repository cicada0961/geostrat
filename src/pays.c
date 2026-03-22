#include "pays.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void initialiser_pays(Pays pays[], char *nom, char *dirigeant, int stab, int petrole, int techno, int nourriture, float pib, int population,
    int soldats, int chars, int avions, int missiles, int guerre, int allie, int *taille) {

    strcpy(pays[*taille].name, nom);
    strcpy(pays[*taille].dirigeant, dirigeant);
    pays[*taille].stabilite = stab;
    pays[*taille].en_guerre = guerre;
    pays[*taille].allie_id = allie;

    pays[*taille].res.petrole = petrole;
    pays[*taille].res.tecnologie = techno;
    pays[*taille].res.nourriture = nourriture;
    pays[*taille].res.pib = pib;
    pays[*taille].res.population = population;

    pays[*taille].armee.avions = avions;
    pays[*taille].armee.chars = chars;
    pays[*taille].armee.missiles = missiles;
    pays[*taille].armee.soldats = soldats;
    pays[*taille].armee.puissance = 0;

    (*taille)++;
}

void afficher_pays(Pays p) {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║  Pays      : %-23s║\n", p.name);
    printf("║  Dirigeant : %-23s║\n", p.dirigeant);
    printf("╠══════════════════════════════════════╣\n");
    printf("║  Stabilite  : %3d/100                ║\n", p.stabilite);
    printf("║  Statut     : %-23s║\n", p.en_guerre ? "En guerre ⚔" : "En paix");
    printf("║  PIB        : %8.2f Mds $           ║\n", p.res.pib);
    printf("║  Population : %5d M hab             ║\n", p.res.population);
    printf("╠══════════════════════════════════════╣\n");
    printf("║  RESSOURCES                          ║\n");
    printf("║  Petrole      : %6d barils/jour    ║\n", p.res.petrole);
    printf("║  Technologie  : %3d/100              ║\n", p.res.tecnologie);
    printf("║  Nourriture   : %6d Mt              ║\n", p.res.nourriture);
    printf("╠══════════════════════════════════════╣\n");
    printf("║  ARMEE                               ║\n");
    printf("║  Soldats  : %8d                  ║\n", p.armee.soldats);
    printf("║  Chars    : %8d                  ║\n", p.armee.chars);
    printf("║  Avions   : %8d                  ║\n", p.armee.avions);
    printf("║  Missiles : %8d                  ║\n", p.armee.missiles);
    printf("╚══════════════════════════════════════╝\n");
}

void afficher_tout_pays(Pays pays[], int* taille) {
    for (int i = 0; i < *taille; i++) {
        afficher_pays(pays[i]);
    }
}

void appliquer_evenement(Pays *p, int type_evenement) {
    switch (type_evenement) {
        case 1: {
            printf("%s subit une crise economique.\n", p->name);
            p->res.pib *= 0.8f;
            p->stabilite -= 15;
            p->res.nourriture -= 200;
        } break;
        case 2: {
            printf("%s subit un boom technologique.\n", p->name);
            p->res.tecnologie += 10;
            p->res.pib += 500;
            p->stabilite += 5;
        } break;
        case 3: {
            printf("%s subit un conflit arme.\n", p->name);
            p->en_guerre = 1;
            p->armee.soldats -= 100;
            p->stabilite -= 25;
            p->res.pib -= 300;
        } break;
        case 4: {
            printf("%s obtient un accord de paix.\n", p->name);
            p->en_guerre = 0;
            p->stabilite += 20;
            p->res.pib += 150;
        } break;
        case 5: {
            printf("%s subit une catastrophe naturelle.\n", p->name);
            p->res.nourriture -= 500;
            p->res.population -= 5;
            p->stabilite -= 10;
            p->res.pib -= 200;
        } break;
            default: printf("Aucun evenement connu. Retour.\n");
    }
}

void corriger_valeur(Pays *p) {
    if (p->stabilite < 0) p->stabilite = 0;
    if (p->stabilite > 100) p->stabilite = 100;

    if (p->res.pib < 0.0) p->res.pib = 0.0;
    if (p->res.petrole < 0) p->res.petrole = 0;
    if (p->res.tecnologie < 0) p->res.tecnologie = 0;
    if (p->res.nourriture < 0) p->res.nourriture = 0;
    if (p->res.population < 0) p->res.population = 0;

    if (p->armee.soldats < 0) p->armee.soldats = 0;
    if (p->armee.chars < 0) p->armee.chars = 0;
    if (p->armee.avions < 0) p->armee.avions = 0;
    if (p->armee.missiles < 0) p->armee.missiles = 0;
    if (p->armee.puissance < 0) p->armee.puissance = 0;
}

void simuler_tour(Pays pays[], int nb_pays) {
    for (int i = 0; i < nb_pays; i++) {
        pays[i].res.population = (int)(pays[i].res.population * 1.01);
        pays[i].res.petrole -= 50;
        if (pays[i].en_guerre == 0) pays[i].res.pib *= 1.02;
        else pays[i].res.pib *= 0.97;
        if (pays[i].res.tecnologie > 70) pays[i].res.pib += 100.00;
        if (pays[i].res.petrole == 0) pays[i].stabilite -= 10;
        if (pays[i].stabilite < 20) pays[i].en_guerre = 1;
        corriger_valeur(&pays[i]);
    }
    event_aleatoire(pays, nb_pays);
    for (int i = 0; i < nb_pays; i++) corriger_valeur(&pays[i]);
}

void event_aleatoire(Pays pays[], int nb_pays) {
    int choix_pays = rand() % nb_pays;
    int type_event = rand() % 5 + 1;
    appliquer_evenement(&pays[choix_pays], type_event);
}

void recap_tour(Pays pays[], int nb_pays, int nb_tour) {
    printf("\n=== FIN DU TOUR %d ===\n", nb_tour);
    printf("%-15s %-12s %-6s %-10s %-10s\n", "PAYS", "PIB($MDS)", "STAB", "PEUPLE(M)", "STATUT");
    printf("%-15s %-12s %-6s %-10s %-10s\n", "---------------", "------------", "------", "----------", "----------");
    for (int i = 0; i < nb_pays; i++) {
        printf("%-15s %-12.2f %-6d %-10d %-10s\n",
            pays[i].name,
            pays[i].res.pib,
            pays[i].stabilite,
            pays[i].res.population,
            pays[i].en_guerre ? "En guerre" : "En paix");
    }
    printf("\n\n");
}


void tri_a_bulle(Pays pays[], int nb_pays) {
    for (int i = 0; i < nb_pays - 1; i++) {
        for (int j = 0; j < nb_pays -i - 1; j++) {
            if (pays[j].res.pib > pays[j+1].res.pib) {
                Pays tmp = pays[j];
                pays[j] = pays[j+1];
                pays[j+1] = tmp;
            }
        }
    }
}

void afficher_classement_pib(Pays pays[], int nb_pays) {
    tri_a_bulle(pays, nb_pays);

    printf("=== Classement des pays par pib ===\n");
    for (int i = nb_pays-1; i >= 0; i--) {
        printf("%s | Pib : %.2f\n", pays[i].name, pays[i].res.pib);
    }
}

int fin_du_monde(Pays pays[], int nb_pays) {
    int cmt = 0;
    for (int i = 0; i < nb_pays; i++) {
        if (pays[i].en_guerre == 1) {
            cmt++;
        }
    }
    if (cmt == nb_pays) return 1;
    return 0;
}

Pays* trouver_plus_fort(Pays pays[], int nb_pays) {
    Pays *plus_fort = &pays[0];
    for (int i = 1; i < nb_pays; i++) {
        if (pays[i].armee.puissance > plus_fort->armee.puissance)
            plus_fort = &pays[i];
    }

    return plus_fort;
}

void transfert_aide(Pays *donneur, Pays *receveur, int petrole, float pib_aide) {
    if (donneur->res.petrole < petrole || donneur->res.pib < pib_aide) {
        printf("Ressources insuffisante, aide annulee.\n");
        return;
    }
    donneur->res.petrole -= petrole;
    donneur->res.pib -= pib_aide;

    receveur->res.petrole += petrole;
    receveur->res.pib += pib_aide;

    receveur->stabilite += 5;
    printf("Aide accomplie !\n");
}

void stats_mondiales(Pays pays[], int nb_pays, float *pib_total, int *pop_totale, int *pays_en_guerre) {
    int cmt_en_guerre = 0;
    int somme_pop = 0;
    float somme_pib = 0;

    for (int i = 0; i < nb_pays; i++) {
        cmt_en_guerre += pays[i].en_guerre;
        somme_pop += pays[i].res.population;
        somme_pib += pays[i].res.pib;
    }

    *pib_total = somme_pib;
    *pop_totale = somme_pop;
    *pays_en_guerre = cmt_en_guerre;
}