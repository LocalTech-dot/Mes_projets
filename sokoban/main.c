#include <stdio.h>
#include <raylib.h>

#include "sokoban.h"//les fonctions définies dans le moteur sont prototypé dans sokoban.h, l'appel de ce fichier permet l'appel du "moteur" du jeux

int main(void) {
    staticelement carte_fond[MAXLIGNES][MAXCOLONNES];
    movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES];
    position player;
    initialiser_matrices(carte_fond, carte_mouvante);
    charge_level("levels/level2.txt", carte_fond, carte_mouvante, &player);

    InitWindow(800, 600, "Sokoban");
    SetTargetFPS(60);

    GameAssets assets;

    assets.sol = LoadTexture("Ressources/sol.png");
    assets.joueur = LoadTexture("Ressources/joueur.png");
    assets.caisse = LoadTexture("Ressources/caisse.png");
    assets.mur = LoadTexture("Ressources/mur.png");
    assets.cible = LoadTexture("Ressources/cible.png");

    if (assets.sol.id == 0) {
        printf("Erreur : Texture sol non trouvée  Chemin actuel : %s\n", GetWorkingDirectory());
    }

    game_loop(carte_fond, carte_mouvante,&player, assets);

    UnloadTexture(assets.sol);
    UnloadTexture(assets.joueur);
    UnloadTexture(assets.mur);
    UnloadTexture(assets.caisse);
    UnloadTexture(assets.cible);

    CloseWindow();

    return 0;
}