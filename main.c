#include <stdbool.h>
#include <stdio.h>

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
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {
      printf("|");
      if (tab[l][c] == 1) {
        printf("X");
      } else if (tab[l][c] == 2) {
        printf("O");
      } else {
        printf("-");
      }
    }
    printf("|");
    printf("\n");
  }
}

void tourJ1() {
  printf("Vous êtes le joueur X \n");
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  if (choixLigne == 0 || choixLigne == 1 || choixLigne == 2) {
    int choixColonne;
    printf("Entrer colone:");
    scanf("%d", &choixColonne);
    if (choixColonne == 0 || choixColonne == 1 || choixColonne == 2) {
      if (tab[choixLigne][choixColonne] == 9) {
        tab[choixLigne][choixColonne] = 1;
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
  printf("Vous êtes le joueur O \n");
  int choixLigne;
  printf("Entrer ligne: ");
  scanf("%d", &choixLigne);
  if (choixLigne == 0 || choixLigne == 1 || choixLigne == 2) {
    int choixColonne;
    printf("Entrer colone:");
    scanf("%d", &choixColonne);
    if (choixColonne == 0 || choixColonne == 1 || choixColonne == 2) {
      if (tab[choixLigne][choixColonne] == 9) {
        tab[choixLigne][choixColonne] = 2;
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

bool victoireLigneJ1() {
  
  if ((tab[0][0] + tab[0][1] + tab[0][2]) == 3) {
    return true;
  } else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 3) {
    return true;
  } else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 3) {
    return true;
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

bool victoireDiagJ1() {
  if ((tab[0][0] + tab[1][1] + tab[2][2]) == 3) {
    return true;
  } else if ((tab[2][0] + tab[1][1] + tab[0][2]) == 3) {
    return true;
  }
  return false;
}

bool victoireLigneJ2() {
  if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  }
  else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  }
  else if ((tab[0][0] + tab[0][1] + tab[0][2]) == 6) {
    return true;
  }
  
  return false;
}

bool victoireColonneJ2() {
  if ((tab[0][0] + tab[1][0] + tab[2][0]) == 6) {
    return true;
  }
  else if ((tab[0][1] + tab[1][1] + tab[2][1]) == 6) {
    return true;
  }
  else if ((tab[0][2] + tab[1][2] + tab[2][2]) == 6) {
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

int sum(int num1, int num2,int num3) {
   int num4;
   num4 = num1 + num2 + num3;
   return (num4);
}

int main(void) {
  creationTableau();
  while (!isMatchNul()) {

    affichageTableau();
    tourJ1();
    nbJeu++;

    if (isMatchNul()) {
      printf("\n Match Nul \n");
      break;
    } else if (victoireLigneJ1() || victoireColonneJ1() || victoireDiagJ1()) {
      printf("\n JOUEUR 1 à gagné \n");
      break;
    }

    affichageTableau();
    tourJ2();

    if (victoireLigneJ2() || victoireColonneJ2() || victoireDiagJ2()) {
      printf("\n JOUEUR 2 à gagné \n");
      break;
    }
    
    nbJeu++;
  }
  affichageTableau();
  return 0;
}
