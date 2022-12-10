char telaRelatorios(void);
void navegacaoRelatorios(void);

// Relatórios Usuários
void navRelatoriosUsu(void);
char relatoriosUsuarios(void);
int filtrarUsuarios(void);

// Relatórios Compromissos
void navRelatoriosComp(void);
char relatoriosCompromissos(void);
int filtrarCompromissos(void);

// Relatórios Avisos
void navRelatoriosAvisos(void);
char relatoriosAvisos(void);
int filtrarAvisos(void);

//Usuários ordenados
typedef struct noUsuario NoUsuario;

struct noUsuario
{
  char nome[50];
  char email[50];
  char senha[9];
  char telefone[12];
  char id[8];
  int cargo;
  int departamento;
  char status;
  NoUsuario* prox;
};

NoUsuario* listaOrdenadaUsu(void);
void exibeOrdemUsuario(NoUsuario*);