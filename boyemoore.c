#include <stdio.h>
#include <string.h>

#define MAX 256

/* ============================================================
 * Function: badCharHeuristic
 * Purpose : Creates bad character table
 * ============================================================
 */
void badCharHeuristic(char *str, int size, int badchar[MAX]) {

    int i;

    for (i = 0; i < MAX; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

/* ============================================================
 * Function: search
 * Purpose : Boyer-Moore String Matching
 * ============================================================
 */
void search(char *txt, char *pat) {

    int m = strlen(pat);
    int n = strlen(txt);

    /* Edge case checks */
    if (m == 0) {
        printf("Pattern is empty\n");
        return;
    }

    if (n == 0) {
        printf("Text is empty\n");
        return;
    }

    int badchar[MAX];

    badCharHeuristic(pat, m, badchar);

    int s = 0;

    while (s <= (n - m)) {

        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {

            printf("Pattern found at index %d\n", s);

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else {

            s += (j - badchar[txt[s + j]] > 1) ?
                 j - badchar[txt[s + j]] : 1;
        }
    }
}

/* ============================================================
 * Main Function
 * ============================================================
 */
int main() {

    char txt[100], pat[100];

    printf("Enter text: ");
    fgets(txt, sizeof(txt), stdin);

    printf("Enter pattern: ");
    fgets(pat, sizeof(pat), stdin);

    /* Remove newline character */
    txt[strcspn(txt, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';

    search(txt, pat);

    return 0;
}
