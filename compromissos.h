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
  int dia;
  int mes;
  char id[8];
  int hora;
  int min;
  int departamento;
  char codigo[10];
  char status;
};

void cadastroCompromissos(void);
void gravaCompromisso(Compromissos*);
void exibeCompromisso(Compromissos*);