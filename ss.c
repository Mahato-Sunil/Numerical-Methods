#include <stdio.h>
#include <stdlib.h>

struct Cricketer {
    char name[50];
    int runs;
    int wickets;
};

void sortByWickets(struct Cricketer *players, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (players[i].wickets < players[j].wickets) {
                struct Cricketer temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    int n = 20;
    struct Cricketer *players = malloc(n * sizeof(struct Cricketer));

    printf("Enter player name, runs scored, and wickets taken for %d cricketers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", players[i].name, &players[i].runs, &players[i].wickets);
    }

    sortByWickets(players, n);

    printf("\nPlayers arranged in order of maximum wickets to minimum wickets taken:\n");
    printf("Name\t\tWickets\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s\t%-15d\n", players[i].name, players[i].wickets);
    }

    free(players);
    return 0;
}
