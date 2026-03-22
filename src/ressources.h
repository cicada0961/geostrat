#ifndef GEOSTRAT_RESSOURCES_H
#define GEOSTRAT_RESSOURCES_H

/* Représente les ressources économiques et naturelles d'un pays */
typedef struct {
    int petrole;       /* Réserves de pétrole en barils/jour */
    int tecnologie;    /* Niveau technologique sur 100 */
    int nourriture;    /* Stock de nourriture en mégatonnes */
    float pib;         /* Produit intérieur brut en milliards de dollars */
    int population;    /* Population en millions d'habitants */
}Ressources;


#endif //GEOSTRAT_RESSOURCES_H