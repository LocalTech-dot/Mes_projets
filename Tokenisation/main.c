#include <string.h>

void tokenize(char *prompt, char *vocab[], int N, char *tokens[], int T) {
    int t = 0;
    while (*prompt != '\0' && t<T ) {
        if (*prompt == ' ') {
            prompt++;
            continue;
        }
        for (int i=0; i<N; i++) {
            if (strncmp(prompt, vocab[i], strlen(vocab[i])) == 0) {
                tokens[t] = vocab[i];
                prompt += strlen(vocab[i]);
                t++;
                break;
            }
        }
    }
}
