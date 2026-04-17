#ifndef SOKOBAN_H
#define SOKOBAN_H
#include <raylib.h>

#define TAILLE_CASE 64
#define MAXLIGNES 12
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

typedef struct {
    Texture2D sol;
    Texture2D mur;
    Texture2D caisse;
    Texture2D joueur;
    Texture2D cible;
} GameAssets;

void initialiser_matrices(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]);
void afficher_jeux(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]);
void player_movement(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES], position *p, int dx, int dy);
int verifier_victoire(staticelement fond[MAXLIGNES][MAXCOLONNES], movingelement mobile[MAXLIGNES][MAXCOLONNES]);
void charge_level(const char *nameLevel, staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES],position *p);
void game_loop(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES], position *p, GameAssets assets);


#endif