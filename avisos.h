void navegacaoCrudAvisos(void);
char crudAvisos(void);
void buscarAvisos(void);
void atualizarAvisos(void);
char oqueAtualizarAvisos(void);
void deletarAvisos(void);



typedef struct avisos Avisos;

struct avisos {
  char titulo[100];
  char descricao[1000];
  int dia;
  int mes;
  int departamento;
  int codigo;
  char status;
};

void cadastroAvisos(void);
void gravaAviso(Avisos*);
void exibeAviso(Avisos*);