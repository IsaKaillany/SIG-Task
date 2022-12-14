void moduloUsuarios(void);
char telaUsuarios(void);
int buscarUsuario(void);
int atualizarUsuario(void);
char oqueAtualizarUsuario(void);
int deletarUsuario(void);

//Funções auxiliares
int departamentoUsuario(void);
int escolhaCargo(void);


typedef struct usuarios Usuarios;

struct usuarios 
{
  char nome[100];
  char email[50];
  char senha[9];
  char telefone[12];
  char id[8];
  int cargo;
  int departamento;
  char status;
};

void cadastroUsuario(void);
int gravaUsuario(Usuarios*);
void exibeUsuario(Usuarios*);
int listaUsuario(void); 