void navegacaoCrudAvisos(void);
char crudAvisos(void);
int buscarAvisos(void);
int atualizarAvisos(void);
char oqueAtualizarAvisos(void);
int deletarAvisos(void);
int departamentoAviso(void);



typedef struct avisos Avisos;

struct avisos {
  char titulo[200];
  char descricao[3000];
  int dia;
  int mes;
  int departamento;
  char codigo[6];
  char status;
};

void cadastroAvisos(void);
int gravaAviso(Avisos*);
void exibeAviso(Avisos*);
int listaAvisos(void);