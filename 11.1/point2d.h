//
// Created by lucie on 18/05/2026.
//

#ifndef INC_11_1_POINT2D_H
#define INC_11_1_POINT2D_H

typedef struct {
    float x;
    float y;
} Point2D;

void pint_point2d(Point2d p);
Point2D ask_point2d();
Point2D translate(Point2D p, float x, float y);

#endif //INC_11_1_POINT2D_H
