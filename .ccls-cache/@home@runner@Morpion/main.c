#include <stdbool.h>
#include <stdio.h>

int l = 0;
int c = 0;
int nbTour = 0;
int tab[3][3];

void creationTableau() {
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {
      tab[l][c] = 0;
    }
  }
}

void affichageTableau() {
  l = 0;
  c = 0;
  printf("\n Début TABLEAU  = \n");
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {
      printf("%d", tab[l][c]);
      printf("|");
    }
    printf("\n");
  }
  printf("\n FIN TABLEAU \n");
}

void tourJ1() {
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  int choixColonne;
  printf("Entrer colone:");
  scanf("%d", &choixColonne);
  if (choixLigne < 3 || choixColonne < 3 || tab[choixLigne][choixColonne] == 0) {
    if (choixLigne > 0 || choixColonne > 0) {
      tab[choixLigne][choixColonne] = 1;
    } else {
      printf("veuillez rejouer des nombres < 0 \n");
      tourJ1();
    }
  } else {
    printf("veuillez rejouer des nombres < 3 \n");
    tourJ1();
  }
}

void tourJ2() {
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  int choixColonne;
  printf("Entrer colone:");
  scanf("%d", &choixColonne);
  if (tab[choixLigne][choixColonne] == 0) {
    tab[choixLigne][choixColonne] = 2;
  } else {
    printf("veuillez rejouer \n");
    tourJ2();
  }
}

// CONDITIONS VICTOIRES
bool isMatchNul() {
  if (nbTour == 9) {
    return true;
  } else {
    return false;
  }
}

void victoireLigne() {}

void victoireColonne() {}

int main(void) {
  int tour = 0;
  creationTableau();
  while (tour < 2) {

    affichageTableau();
    tourJ1();
    affichageTableau();
    tourJ2();
    affichageTableau();

    tour++;
  }
  return 0;
}
