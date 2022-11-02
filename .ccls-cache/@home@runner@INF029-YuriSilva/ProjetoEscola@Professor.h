typedef struct Professores {
	char nome[101];
	long int matricula;
	char cpf[20];
	char sexo[20];
	char data[12];
} Professores;

int cadastroProfessores(Professores cadastroPr[]);

static int PRcad = 0;

Professores listaProfessores(Professores cadastro[]);
int excluiProfessores(Professores cadastro[]);
int atualizaProfessores(Professores cadastro[]);
void ordenaSexoProf(Professores cadastro[]);
void ordenaNomeProf (Professores cadastro[]);
void ordenaDataProf(Professores cadastro[]);


int validaCpf(char cpf[]);
int validaSexo(char sexo[]);
int validarNascimento(char dataNasc[]);
int matriculaProfessor ( );

