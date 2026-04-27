#include <stdio.h>
#include <raylib.h>
#include "sokoban.h"

void initialiser_matrices(staticelement carte_fond[MAXLIGNES][MAXCOLONNES],movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) { //fonction qui créer mes deux matrices, fond et mouvante
    for (int y=0;y<MAXLIGNES; y= y + 1) {
        for (int x=0;x<MAXCOLONNES;x++) {
        carte_fond[y][x] = SOL;
        carte_mouvante[y][x] = VIDE;
        }
    }
}

void afficher_jeux(staticelement carte_fond[MAXLIGNES][MAXCOLONNES],movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) { // fonction qui affiche le jeux dans le terminal, n'est plus utilisé dès la v1 du jeux.
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

void player_movement(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES], position *p, int dx, int dy) { //fonction qui gère la physique du personnage : la collision avec les caisses et les murs

    int cibleX = p->x + dx;
    int cibleY = p->y + dy;

    if (carte_fond[cibleY][cibleX] == MUR) {
        return;
    }

    else if (carte_mouvante[cibleY][cibleX] == CAISSE) { //grosse condition pour gérer le déplacement de la caisse lorsque le joueur la "pousse"
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

int verifier_victoire(staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES]) { //fonction de vérification de victoire qui renvoie 1 si toutes les cibles sont occupées par des caisses
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

void charge_level(const char *nameLevel, staticelement carte_fond[MAXLIGNES][MAXCOLONNES], movingelement carte_mouvante[MAXLIGNES][MAXCOLONNES],position *p) { //fonction qui s'occupe d'ouvrir de parcourir et de traiter les informations contenue dans le dossier "levels"
    FILE *level;
    int lu;

    level = fopen(nameLevel, "r"); // définition du mode de lecture du fichier sur "read"

    if (level == NULL) { //test permettant le renvoie d'un message en cas d'échec d'ouverture du fichier
        printf("Erreur : Niveau introuvable");
        return;
    }



    for (int y=0;y<MAXLIGNES; y= y+ 1){
        for (int x=0;x<MAXCOLONNES;x= x + 1) {

            lu = fgetc(level);

            if (lu == EOF) { //condition pour arreter la lecture si le fichier "lu" est en End Of File
                fclose(level);
                return;
            }

            if (lu == '\n') break;

            switch (lu) { //définition de la variable case en fonction des donées lue dans le fichier levelx.txt
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
                  GameAssets assets) { //fonction gérant toute la partie raylib du jeux, partie graphique du jeux
    while (!WindowShouldClose()) {

        int dx = 0;
        int dy = 0;
        //ici on gère les différentes touche pressé par l'utilisateur lors de l'execution du jeux.
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

        int victoire = verifier_victoire(carte_fond, carte_mouvante);


        BeginDrawing();

        ClearBackground(BLACK);



        for (int y=0;y<MAXLIGNES; y = y + 1) { //toujours la même double boucle qui parcoure mes cases et qui affiche ici mes assets qui sont dans le dossier Ressources
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

        if (victoire == 1)   {
            int screenx = 0;
            int screeny = 0;
            int fullheight = GetScreenHeight();
            int fullwidth = GetScreenWidth();
            int midheight = GetScreenHeight()/2;
            int midwidth = GetScreenWidth()/2;

            DrawRectangle(screenx, screeny,fullwidth , fullheight, Fade(BLACK, 0.5f));{
            const char *victoire = "Victoire";
            int taille = 80;
            int taillemsg = MeasureText(victoire, taille);
            DrawText(victoire, midwidth-taillemsg/2, midheight - taille/2, taille, GOLD);
            }
        }

        EndDrawing();
    }
}
