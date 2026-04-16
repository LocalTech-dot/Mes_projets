#include <stdio.h>
#include <raylib.h>
#include "sokoban.h"

void initialiser_matrices(staticelement carte_fond[MAXLIGNES][MAXCOLONNES],movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) {
    for (int y=0;y<MAXLIGNES; y= y + 1) {
        for (int x=0;x<MAXCOLONNES;x++) {
        carte_fond[y][x] = SOL;
        carte_mouvante[y][x] = VIDE;
        }
    }
}

void afficher_jeux(staticelement carte_fond[MAXLIGNES][MAXCOLONNES],movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) {
    for (int y=0;y<MAXLIGNES; y = y + 1) {
        for (int x=0;x<MAXCOLONNES;x++) {


            if (carte_mouvante[y][x]==PLAYER) {
                printf("@");
            }
            else if (carte_mouvante[y][x]==CAISSE) {
                printf("$");
            }
            else {
                if (carte_fond[y][x] == SOL) {
                    printf(" ");
                }
                else if (carte_fond[y][x] == MUR) {
                    printf("#");
                }
                else if (carte_fond[y][x] == CIBLE) {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

void player_movement(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES], position *p, int dx, int dy) {

    int cibleX = p->x + dx;
    int cibleY = p->y + dy;

    if (carte_fond[cibleY][cibleX] == MUR) {
        return;
    }

    else if (carte_mouvante[cibleY][cibleX] == CAISSE) {
        int devantX = cibleX + dx;
        int devantY = cibleY + dy;
        if (carte_mouvante[devantY][devantX] == VIDE && carte_fond[devantY][devantX] != MUR) {
            carte_mouvante[devantY][devantX] = CAISSE;
            carte_mouvante[cibleY][cibleX] = PLAYER;
            carte_mouvante[p->y][p->x] = VIDE;

            p->x = cibleX;
            p->y = cibleY;
            return;
        }
    }

    else {
        carte_mouvante[p->y][p->x] = VIDE;
        p->x = cibleX;
        p->y = cibleY;
        carte_mouvante[cibleY][cibleX] = PLAYER;
    }

}

int verifier_victoire(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) {
    for (int y=0;y<MAXLIGNES; y = y + 1) {
        for (int x=0;x<MAXCOLONNES;x++) {
            if (carte_fond[y][x] == CIBLE) {
                if (carte_mouvante[y][x] != CAISSE) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void charge_level(const char *nameLevel, staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES],position *p) {
    FILE *level;
    char lu;

    level = fopen(nameLevel, "r");

    if (level == NULL) {
        printf("Erreur : Niveau introuvable");
        return;
    }



    for (int y=0;y<MAXLIGNES; y= y+ 1){
        for (int x=0;x<MAXCOLONNES;x= x + 1) {

            lu = fgetc(level);

            if (lu == EOF) {
                fclose(level);
                return;
            }

            if (lu == '\n') break;

            switch (lu) {
                case '#':
                    carte_fond[y][x] = MUR;
                    carte_mouvante[y][x] = VIDE;
                    break;

                case ' ':
                    carte_fond[y][x] = SOL;
                    carte_mouvante[y][x] = VIDE;
                    break;

                case '$':
                    carte_fond[y][x] = SOL;
                    carte_mouvante[y][x] = CAISSE;
                    break;

                case '.':
                    carte_fond[y][x] = CIBLE;
                    carte_mouvante[y][x] = VIDE;
                    break;

                case '@':
                    carte_fond[y][x] = SOL;
                    carte_mouvante[y][x] = PLAYER;
                    p->x = x;
                    p->y = y;
                    break;

                default:
                    printf("Erreur de lecture du niveau");
                    break;
            }

        }
    }
    fclose(level);
}

void game_loop(staticelement carte_fond[MAXLIGNES][MAXCOLONNES],
                  movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES],
                  position *p,
                  GameAssets assets) {
    while (!WindowShouldClose()) {

        int dx = 0;
        int dy = 0;

        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            dx = 1;
        }

        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            dy = 1;
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_LEFT)) {
            dx = -1;
        }

        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_Z) || IsKeyPressed(KEY_UP)) {
            dy = -1;
        }

        if (dx != 0 || dy != 0) {
            player_movement(carte_fond, carte_mouvante, p, dx, dy);
        }

        BeginDrawing();

        ClearBackground(BLACK);



        for (int y=0;y<MAXLIGNES; y = y + 1) {
            int posY = y*32;
            for (int x=0;x<MAXCOLONNES;x++) {
                int posX = x*32;

                DrawTexture(assets.sol, posX, posY, WHITE);


                if (carte_fond[y][x] == MUR) {
                    DrawTexture(assets.mur, posX, posY, WHITE);
                }
                if (carte_fond[y][x] == CIBLE) {
                    DrawTexture(assets.cible, posX, posY, WHITE);
                }
                if (carte_mouvante[y][x] == PLAYER) {
                    DrawTexture(assets.joueur, posX, posY, WHITE);
                }
                if (carte_mouvante[y][x] == CAISSE) {
                    DrawTexture(assets.caisse, posX, posY, WHITE);
                }

            }
        }


        EndDrawing();
    }
}
