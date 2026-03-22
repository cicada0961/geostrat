#include "armee.h"

/* Calcule la puissance militaire en pondérant chaque type d'unité :
   soldats x2, chars x5, avions x10, missiles x20 */
void calculer_puissance(Armee *a) {
    a->puissance = (a->soldats *2) + (a->chars *5) + (a->avions * 10) + (a->missiles * 20);
}

/* Retourne le statut militaire d'un pays selon son score de puissance */
char* get_statut_militaire(int puissance) {
    if (puissance > 50000) return "Superpuissance";
    if (puissance >= 20000 && puissance <= 50000) return "Grande puissance";
    if (puissance >= 5000 && puissance <= 20000) return "Puissance regionale";
    return "Pays en developpement";
}