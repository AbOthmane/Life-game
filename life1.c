#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 40
#define WIDTH 70

int cell[HEIGHT][WIDTH];

void init_cells()
{
  int i, j;
  
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      cell[i][j] = 0;
    }
  }

  cell[20][30] = 1;
  cell[22][30] = 1;
  cell[22][31] = 1;
  cell[23][31] = 1;
  cell[20][32] = 1;
}
//fonction bach affichi tableau ola tktab tableau f fichier
void print_cells(FILE *fp)
{
  int i, j;
  //ktab sonzai hiritsu f fichier
  int n = count_cells();
  double ratio = (double)n/(double)2800;
  fprintf(fp, "---------- %.8f\n", ratio);

  for (i = 0; i < HEIGHT; i++) {//loop dyal lignes
    for (j = 0; j < WIDTH; j++) {//loop dyal colonnes
      const char c = (cell[i][j] == 1) ? '#' : ' '; // il kanat 7aya affichi symbole diaz
      fputc(c, fp);
    }
    fputc('\n', fp);//na9az star men ba3d kola ligne
  }
  fflush(fp);//ma3raftch had fonction dyalach b7al kayn b7al makaynach

  sleep(1);
}
//fonction bach t7ssab 3adad cellules mojawira
int count_adjacent_cells(int i, int j)
{
  int n = 0;
  int k, l;
  for (k = i - 1; k <= i + 1; k++) {//loop ligne men elmt li fo9 tal lli ta7t
    // khass nta2kdo men k wach kayn ola la 7it momkin nkono f lakhar dyal tableau men fo9 ola men ta7t
    if (k < 0 || k >= HEIGHT) continue;// continue bla mat9ra dakchi li men ba3d 3awd iteration dyal loop li 9bal
    for (l = j - 1; l <= j + 1; l++) {// loop colonne men elmt li 9bal tal men ba3d

      if (k == i && l == j) continue;//ila wssalat loop l elmt li lwasst mat7asboch

      if (l < 0 || l >= WIDTH) continue;// b7al lfo9 khassna ntaakdo men wach 7na flawel ola  felakher dyal ligne
      n += cell[k][l];// hna tzid elmt li f ligne k colonne l ya3ni ila kan 7ay +1 kan mayat +0
    }
  }
  return n;
}

void update_cells()
{
  int i, j;
  int cell_next[HEIGHT][WIDTH];

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      cell_next[i][j] = 0;
      const int n = count_adjacent_cells(i, j);// entre 0 et 8
      // 3la 7ssab 9awa3id dyl life game khass yt7adad state dyal kola cellule
      if(n<2 || n>3)
      {
        cell_next[i][j] = 0;
      }
      else if(n==2)
      {
        cell_next[i][j] = cell[i][j];
      }
      else if(n==3)
      {
        cell_next[i][j] = 1;
      }
      /*  ???  */

    }

  }

  //nghayro tableau bach yweli f generation jdida
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      cell[i][j] = cell_next[i][j];
    }
  }
}
int count_cells()//7ssab ch7al men cellule kayna f cells
{
  int i, j,n=0;
  
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if(cell[i][j] == 1)
      {
        n++;
      }
    }
  }
  return n;

}

int main()
{
  int gen;
  FILE *fp;
  // ouvrir fichier bach naffichiw resultat
  if ((fp = fopen("cells.txt", "a")) == NULL) {
    fprintf(stderr, "error: cannot open a file.\n");
    return 1;
  }

  init_cells();//intialiser cellules
  print_cells(fp);// afficher cellules

  for (gen = 1;; gen++) {
    printf("generation = %d\n", gen);
    update_cells();
    print_cells(fp);
  }
  fclose(fp);

  return 0;
}
