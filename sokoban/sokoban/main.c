#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "sokoban.h"

int main(void) {
    staticelement carte_fond[MAXLIGNES][MAXCOLONNES];
    movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES];
    position player;
    initialiser_matrices(carte_fond, carte_mouvante);
    charge_level("levels/level1.txt", carte_fond, carte_mouvante, &player);

    InitWindow(800, 600, "Sokoban");
    SetTargetFPS(60);

    Texture2D sol;
    Texture2D joueur;
    Texture2D caisse;
    Texture2D mur;
    Texture2D cible;

    sol = LoadTexture("Ressources/sol.png");
    joueur = LoadTexture("Ressources/joueur.png");
    caisse = LoadTexture("Ressources/caisse.png");
    mur = LoadTexture("Ressources/mur.png");
    cible = LoadTexture("Ressources/cible.png");

    while (!WindowShouldClose()) {

        int dx = 0;
        int dy = 0;

        if (IsKeyPressed(KEY_D)) {
            dx = 1;
        }

        if (IsKeyPressed(KEY_S)) {
            dy = 1;
        }

        if (IsKeyPressed(KEY_A)) {
            dx = -1;
        }

        if (IsKeyPressed(KEY_Z)) {
            dy = -1;
        }

        if (dx != 0 || dy != 0) {
            player_movement(carte_fond, carte_mouvante, &player, dx, dy);
        }
        
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(player.x * 32, player.y * 32, 32, 32, GRAY);
        DrawCircle(player.x * 32 + 16, player.y * 32 + 16, 12, RED);

        EndDrawing();
    }
    UnloadTexture(sol);
    UnloadTexture(joueur);
    UnloadTexture(mur);
    UnloadTexture(caisse);
    UnloadTexture(cible);

    CloseWindow();

    return 0;
}