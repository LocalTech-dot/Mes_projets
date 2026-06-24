void appliquer_motif(int canva[100][100], int motif[5][5], int pos_i, int pos_j) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((pos_i + i)>=0 && (pos_j + j)>=0 && (pos_i + i)<100 && (pos_j + j)<100 ) {
                canva[pos_i + i][pos_j + j] = motif[i][j];
            }
        }
    }
}