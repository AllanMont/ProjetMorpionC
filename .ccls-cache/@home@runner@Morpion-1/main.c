#include <stdbool.h>
#include <stdio.h>
#define KRED "\x1B[31m"
#define KBLU "\x1B[34m"
#define KGRN "\x1B[32m"
#define KNRM "\x1B[0m"
#define KMAG "\x1B[35m"

int l = 0;
int c = 0;
int nbJeu = 0;
int tab[3][3];

void creationTableau() {
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {
      tab[l][c] = 9;
    }
  }
}

void affichageTableau() {
  l = 0;
  c = 0;

  printf("%s  1 2 3 \n", KNRM);
  for (l = 0; l < 3; l++) {
    printf("%d", l + 1);
    for (c = 0; c < 3; c++) {
      printf("%s|", KNRM);
      if (tab[l][c] == 1) {
        printf("%sX", KRED);
      } else if (tab[l][c] == 2) {
        printf("%sO", KBLU);
      } else {
        printf("%s-", KMAG);
        printf("%s", KNRM);
      }
    }
    printf("%s|", KNRM);
    printf("\n");
  }
}

void affichageTableauVictoire(int laVictoire, int joueurVainqueur) {
  l = 0;
  c = 0;
  
  printf("%s  1 2 3 \n", KNRM);
  if (laVictoire == 1) {
    if (joueurVainqueur == 1) {
      printf("%s1|%sX%s|%sX%s|%sX%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
    } else {
      printf("%s1|%sO%s|%sO%s|%sO%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
    }
    for (l = 1; l < 3; l++) {
      printf("%d", l + 1);
      for (c = 0; c < 3; c++) {
        printf("%s|", KNRM);
        if (tab[l][c] == 1) {
          printf("%sX", KRED);
        } else if (tab[l][c] == 2) {
          printf("%sO", KBLU);
        } else {
          printf("%s-", KMAG);
          printf("%s", KNRM);
        }
      }
      printf("%s|", KNRM);
      printf("\n");
    }
  } 
    
  else if (laVictoire == 2) {
    for (l = 0; l < 3; l++) {
      if(l==2){
        if(joueurVainqueur==1){
          printf("%s2|%sX%s|%sX%s|%sX%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
        }
        else{
          printf("%s2|%sO%s|%sO%s|%sO%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
        }
      }
      printf("%d", l + 1);
      for (c = 0; c < 3; c++) {
        printf("%s|", KNRM);
        if (tab[l][c] == 1) {
          printf("%sX", KRED);
        } else if (tab[l][c] == 2) {
          printf("%sO", KBLU);
        } else {
          printf("%s-", KMAG);
          printf("%s", KNRM);
        }
      }
      printf("%s|", KNRM);
      printf("\n");
      l++;
    }
  }
  else if (laVictoire == 3) {
    for (l = 0; l < 2; l++) {
      printf("%d", l + 1);
      for (c = 0; c < 3; c++) {
        printf("%s|", KNRM);
        if (tab[l][c] == 1) {
          printf("%sX", KRED);
        } else if (tab[l][c] == 2) {
          printf("%sO", KBLU);
        } else {
          printf("%s-", KMAG);
          printf("%s", KNRM);
        }
      }
      printf("%s|", KNRM);
      printf("\n");
      if(l==1){
        if(joueurVainqueur==1){
          printf("%s2|%sX%s|%sX%s|%sX%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
        }
        else{
          printf("%s2|%sO%s|%sO%s|%sO%s|\n", KNRM, KGRN, KNRM, KGRN, KNRM, KGRN,
             KNRM);
        }
      }
    }
  }
  
}
void tourJ1() {
  printf("%sVous êtes le joueur X \n", KRED);
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  if (choixLigne == 1 || choixLigne == 2 || choixLigne == 3) {
    int choixColonne;
    printf("Entrer colone:");
    scanf("%d", &choixColonne);
    if (choixColonne == 1 || choixColonne == 2 || choixColonne == 3) {
      if (tab[choixLigne - 1][choixColonne - 1] == 9) {
        tab[choixLigne - 1][choixColonne - 1] = 1;
      } else {
        printf("Case déjà prise \n");
        tourJ1();
      }
    } else {
      printf("Veuillez jouer des nombres logiques \n");
      tourJ1();
    }
  } else {
    printf("Veuillez jouer des nombres logiques \n");
    tourJ1();
  }
}

void tourJ2() {
  printf("%sVous êtes le joueur O \n", KBLU);
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  if (choixLigne == 1 || choixLigne == 2 || choixLigne == 3) {
    int choixColonne;
    printf("Entrer colone:");
    scanf("%d", &choixColonne);
    if (choixColonne == 1 || choixColonne == 2 || choixColonne == 3) {
      if (tab[choixLigne - 1][choixColonne - 1] == 9) {
        tab[choixLigne - 1][choixColonne - 1] = 2;
      } else {
        printf("Case déjà prise \n");
        tourJ2();
      }
    } else {
      printf("Veuillez jouer des nombres logiques \n");
      tourJ2();
    }
  } else {
    printf("Veuillez jouer des nombres logiques \n");
    tourJ2();
  }
}

// CONDITIONS VICTOIRES
bool isMatchNul() {
  if (nbJeu == 9) {
    return true;
  } else {
    return false;
  }
}

int victoireLigneJ1() {
  if ((tab[0][0] + tab[0][1] + tab[0][2]) == 3) {
    return 1;
  } else if ((tab[1][0] + tab[1][1] + tab[1][2]) == 3) {
    return 2;
  } else if ((tab[2][0] + tab[2][1] + tab[2][2]) == 3) {
    return 3;
  }
  return false;
}

bool victoireColonneJ1() {
  if ((tab[0][0] + tab[1][0] + tab[2][0]) == 3) {
    return true;
  } else if ((tab[0][1] + tab[1][1] + tab[2][1]) == 3) {
    return true;
  } else if ((tab[0][2] + tab[1][2] + tab[2][2]) == 3) {
    return true;
  }

  return false;
}

int victoireDiagJ1() {
  if ((tab[0][0] + tab[1][1] + tab[2][2]) == 3) {
    return 1;
  } else if ((tab[2][0] + tab[1][1] + tab[0][2]) == 3) {
    return 2;
  }
  return 0;
}

bool victoireLigneJ2() {
  if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  } else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  } else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  }

  return false;
}

bool victoireColonneJ2() {
  if ((tab[0][0] + tab[1][0] + tab[2][0]) == 6) {
    return true;
  } else if ((tab[0][1] + tab[1][1] + tab[2][1]) == 6) {
    return true;
  } else if ((tab[0][2] + tab[1][2] + tab[2][2]) == 6) {
    return true;
  }

  return false;
}

bool victoireDiagJ2() {
  if ((tab[0][0] + tab[1][1] + tab[2][2]) == 6) {
    return true;
  } else if ((tab[2][0] + tab[1][1] + tab[0][2]) == 6) {
    return true;
  }
  return false;
}

int main(void) {
  creationTableau();
  while (!isMatchNul()) {

    affichageTableau();
    tourJ1();
    nbJeu++;

    if (isMatchNul()) {
      printf("\n Match Nul \n");
      affichageTableau();
      break;
    } else if (victoireLigneJ1() > 0 || victoireColonneJ1() > 0 || victoireDiagJ1() > 0) {
      printf("\n JOUEUR 1 à gagné \n");
      if (victoireLigneJ1() > 0) {
        if (victoireLigneJ1() == 1) {
          affichageTableauVictoire(1, 1);
        } else if (victoireLigneJ1() == 2) {
          affichageTableauVictoire(2, 1);
        } else if (victoireLigneJ1() == 3) {
          affichageTableauVictoire(3, 1);
        }

      } else if (victoireColonneJ1() > 0) {

      } else if (victoireDiagJ1() > 0) {
        if (victoireDiagJ1() == 1) {
          affichageTableauVictoire(7, 1);
        } else {
          affichageTableauVictoire(8, 1);
        }
      }
      break;
    } else if (victoireDiagJ1() > 0) {
    }

    affichageTableau();
    tourJ2();

    if (victoireLigneJ2() || victoireColonneJ2() || victoireDiagJ2()) {
      printf("\n JOUEUR 2 à gagné \n");
      if (victoireLigneJ2() > 0) {
        if (victoireLigneJ2() == 1) {
          affichageTableauVictoire(1, 2);
        }
      } else if (victoireColonneJ2()) {

      } else {
        if (victoireDiagJ2() == 1) {
          affichageTableauVictoire(7, 2);
        } else {
          affichageTableauVictoire(8, 2);
        }
      }
      break;
    }

    nbJeu++;
  }

  return 0;
}
