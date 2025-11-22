#include <stdio.h>
#include <stdlib.h>

typedef struct noeud_s {
    int valeur;
    struct noeud_s* gauche;
    struct noeud_s* droite;
} noeud_s;

typedef noeud_s* arbre_t;
typedef noeud_s* noeud_t;

arbre_t creer_arbre(int valeur, arbre_t gauche, arbre_t droite) {
    noeud_t nouveau_noeud = malloc(sizeof(noeud_s));
    if (nouveau_noeud == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->gauche = gauche;
    nouveau_noeud->droite = droite;
    return nouveau_noeud;
}

int detruit_arbre(arbre_t arbre) {
    if (arbre == NULL) {
        return 0;
    }
    detruit_arbre(arbre->gauche);
    detruit_arbre(arbre->droite);
    free(arbre);
}

int nombre_noeuds(arbre_t arbre) {
    if (arbre == NULL) {
        return 0;
    }
    return 1 + nombre_noeuds(arbre->gauche) + nombre_noeuds(arbre->droite);

}