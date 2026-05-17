#include <stdio.h>
#include <raylib.h>

#include "sokoban.h"//les fonctions définies dans le moteur sont prototypé dans sokoban.h, l'appel de ce fichier permet l'appel du "moteur" du jeux

int main(void) {

    EtatJeux actuel = CHARGEMENT;
    int framecounter = 0;
    float fade = 0.01;
    int chargelevel = 0;

    while (!WindowShouldClose()) {
        switch (actuel) {
            case CHARGEMENT:
                framecounter++;
                fade = ((float)framecounter/30);
                chargelevel = framecounter*fade;
                if (framecounter == 180) {
                    actuel = MENU;
                }
        }
    }

    staticelement carte_fond[MAXLIGNES][MAXCOLONNES];
    movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES];
    position player;
    LevelDim dimensions;
    int taillecasewindow = TAILLE_CASE/2;
    initialiser_matrices(carte_fond, carte_mouvante);
    charge_level("levels/level2.txt", carte_fond, carte_mouvante, &player,&dimensions);

    InitWindow(dimensions.nbColonnes*taillecasewindow, dimensions.nbLignes*taillecasewindow, "Sokoban");
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