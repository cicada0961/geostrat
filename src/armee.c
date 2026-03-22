#include "armee.h"

void calculer_puissance(Armee *a) {
    a->puissance = (a->soldats *2) + (a->chars *5) + (a->avions * 10) + (a->missiles * 20);
}

char* get_statut_militaire(int puissance) {
    if (puissance > 50000) return "Superpuissance";
    if (puissance >= 20000 && puissance <= 50000) return "Grande puissance";
    if (puissance >= 5000 && puissance <= 20000) return "Puissance regionale";
    return "Pays en developpement";
}