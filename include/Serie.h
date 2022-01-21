#ifndef SERIE_H
#define SERIE_H
typedef struct Serie {
  int id;
  char nome[30];
  float rankImdb;
  int idStreaming;
} Serie;

Serie criar_serie(int id, char nome[30], float rankImdb, int idStreaming);

Serie criar_serie_gui();

long get_size_serie();

void print_serie(Serie *self);
#endif
