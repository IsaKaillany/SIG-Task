void navegacaoCrudCompromissos(void);
char crudCompromissos(void);
void buscarCompromissos(void);
void atualizarCompromissos(void);
char oqueAtualizarCompromissos(void);
void deletarCompromissos(void);
int escolhaDepartamento(void);



typedef struct compromissos Compromissos;

struct compromissos {
  char titulo[100];
  char descricao[1000];
  char data[6];
  char id[7];
  int hora;
  int min;
};

Compromissos* cadastroCompromissos();