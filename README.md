# GÉOSTRAT — Simulateur de Crise Géopolitique 🌍

Simulateur géopolitique tour par tour en C, développé dans le cadre de ma L1 Maths-Informatique à Sorbonne Université (Mars 2026).

Le programme modélise trois blocs géopolitiques rivaux qui s'affrontent pour le contrôle de ressources stratégiques (énergie, technologie, matières premières). À chaque tour (= une année), le monde évolue : croissance économique, consommation de pétrole, événements aléatoires (crises, conflits, catastrophes), et la simulation s'arrête si tous les pays entrent en guerre simultanément.

## Fonctionnalités

- Modélisation de pays avec ressources, armée et données politiques via `struct`
- Simulation sur 10 tours avec évolution économique et démographique
- Événements aléatoires : crise économique, boom technologique, conflit armé, accord de paix, catastrophe naturelle
- Détection d'effondrement mondial (tous les pays en guerre)
- Transfert d'aide entre pays alliés
- Classement final par PIB (tri à bulles)
- Statistiques mondiales en fin de simulation

## Compilation

```bash
gcc -Wall main.c src/pays.c src/armee.c src/ressources.c -o geostrat
./geostrat
```

## Structure du projet

```
.
├── main.c                # Point d'entrée, boucle de simulation
├── src/
│   ├── pays.h / pays.c           # Structure Pays, initialisation, affichage, événements, simulation
│   ├── armee.h / armee.c         # Structure Armee, calcul de puissance
│   └── ressources.h / ressources.c   # Structure Ressources
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Exemple de sortie

```
La super puissance mondiale est : Kaldera

Debut du Tour 1
Arcturia subit un boom technologique.

=== FIN DU TOUR 1 ===
PAYS            PIB($MDS)    STAB   PEUPLE(M)  STATUT
--------------- ------------ ------ ---------- ----------
Arcturia        4680.51      80     323        En paix
Kaldera         863.30       47     95         En guerre
Veralion        2446.76      93     212        En paix
```

## Concepts C utilisés

- `typedef struct` imbriquées
- Pointeurs et passage par référence
- Tableaux de structures
- `switch`, `if/else`, boucles `for` et `while`
- `rand()` / `srand()` pour l'aléatoire
- `strcpy` pour les chaînes

## Auteur

Karim — L1 Maths-Informatique, Sorbonne Université