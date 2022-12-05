#include <stdio.h>
int l = 0;
int c = 0;
int tab[3][3];

void creationTableau() {
  for (l = 0 ; l < 3 ; l++) {
    for (c = 0 ; c < 3 ; c++) {
      tab[l][c] = 0;
    }
  }
}

void affichageTableau() {
  l = 0;
  c = 0;
  for (l = 0 ; l < 3 ; l++) {
    for (c = 0 ; c < 3 ; c++) {
      printf("%d", tab[l][c]);
      printf("|");
    }
    
    printf("%d \n", tab[l][c]);
  }
}

int main(void) {
  printf("\n Début Main \n");

  creationTableau();
  affichageTableau();

  printf("\n Fin Main \n");

  return 0;
}
