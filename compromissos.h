void navegacaoCrudCompromissos(void);
char crudCompromissos(void);
int buscarCompromissos(void);
int atualizarCompromissos(void);
char oqueAtualizarCompromissos(void);
int deletarCompromissos(void); 
int escolhaDepartamento(void);



typedef struct compromissos Compromissos;

struct compromissos {
  char titulo[200];
  char descricao[3000];
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
int gravaCompromisso(Compromissos*);
void exibeCompromisso(Compromissos*);
int listaCompromissos(void);