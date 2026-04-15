#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdbool.h>
#include <stdint.h>

#define TAILLE_CASE 64
#define MAXLIGNES 10
#define MAXCOLONNES 20

typedef enum {
        MUR,
        SOL,
        CIBLE
    }staticelement;
typedef enum {
        PLAYER,
        CAISSE,
        VIDE,
    }movingelement;

typedef struct {
    int x;
    int y;
}position;

void initialiser_matrices(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]);
void afficher_jeux(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]);
void player_movement(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES], position *p, int dx, int dy);
int verifier_victoire(staticelement fond[MAXLIGNES][MAXCOLONNES], movingelement mobile[MAXLIGNES][MAXCOLONNES]);
void charge_level(const char *nameLevel, staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES],position *p);


#endif