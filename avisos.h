void navegacaoCrudAvisos(void);
char crudAvisos(void);
int buscarAvisos(void);
int atualizarAvisos(void);
char oqueAtualizarAvisos(void);
int deletarAvisos(void);



typedef struct avisos Avisos;

struct avisos {
  char titulo[100];
  char descricao[1000];
  int dia;
  int mes;
  int departamento;
  char codigo[6];
  char status;
};

void cadastroAvisos(void);
int gravaAviso(Avisos*);
void exibeAviso(Avisos*);