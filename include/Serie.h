#ifndef SERIE_H
#define SERIE_H
typedef struct Serie {
  int id;
  float rankImdb;
  int idStreaming;
  int generos[3];
  char nome[30];
} Serie;

Serie criar_serie(int id, char nome[30], float rankImdb, int idStr, int gen[3]);

Serie criar_serie_gui();

long get_size_serie();

void print_serie(Serie *self);
#endif
