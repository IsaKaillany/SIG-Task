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
  char data[6];
};

Avisos* cadastroAvisos();