void moduloUsuarios(void);
char telaUsuarios(void);
void buscarUsuario(void);
void atualizarUsuario(void);
char oqueAtualizarUsuario(void);
void deletarUsuario(void);
void navegacaoUsuariosCadastrados(void);
char departamentoUsuario(void);
int escolhaCargo(void);



typedef struct usuarios Usuarios;

struct usuarios 
{
  char nome[50];
  char email[50];
  char senha[9];
  char telefone[12];
  char id[7];
};

Usuarios* cadastroUsuario();
void usuariosCadastrados(const Usuarios*);