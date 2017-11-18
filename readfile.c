#include <stdio.h>
#include <string.h>

#define HEIGHT 40
#define WIDTH 70
#define BUFSIZE 1000

int main()
{
  char buf[BUFSIZE];
  int cell[HEIGHT][WIDTH];
  FILE *fp;
  const char *filename = "cells.txt";
  // fta7 3adi
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("error: can't open %s\n", filename);
    return 1;
  }
  fseek(fp,-71*40,SEEK_END); 

	// 9ra 1000 7arf b 1000 7rf ola 7tl l sttar jay
  
  int i =0,j; // compteur bch n3raf f achmen star daba
  // 9ra 1000 7arf b 1000 7rf ola 7tl l sttar jay
  while (fgets(buf, BUFSIZE, fp) != NULL)
  { 
    //loop bach dawaz les colonnes
    //printf("%s",buf);
    for (j = 0; j < WIDTH; j++) {
      if(buf[j]=='#')
      {
        cell[i][j] = 1;
      }else{
        cell[i][j]=0;
      }
      
    }

    i++;
  }
  printf("%d",cell[1][1]);

  fclose(fp);

  return 0;
}
