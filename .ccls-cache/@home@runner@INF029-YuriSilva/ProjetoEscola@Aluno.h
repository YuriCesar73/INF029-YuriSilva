typedef struct Alunos {
	char nome[101];
	long int matricula;
	char cpf[20];
	char sexo[20];
	char data[12];
} Alunos;

// int cadastramento(Alunos cadastro[]);
int cadastroAlunos(Alunos cadastroAl[]);
Alunos listaAlunos(Alunos cadastro[]);
int excluiAlunos(Alunos cadastro[]);
int atualizaAlunos(Alunos cadastro[]);
void ordenaSexoAlun(Alunos cadastro[]);
void ordenaNomeAlunos(Alunos cadastro[]);
void ordenaDataAlunos (Alunos cadastro[]);

static int ALcad = 0;

int validaCpf(char cpf[]);
int validaSexo(char sexo[]);
int validarNascimento(char dataNasc[]);
// int matriculaAluno ();

typedef struct Disciplinas {
	char nome[101];
	char codigo[8]; //utilizaremos o padrão do IFBA: 3 letras maiúsculas e 3 números. Exemplo: INF029
	char semestre[8];
	char professor[101];
	Alunos alunosMatriculados;
} Disciplinas;

Disciplinas cadastroDisciplina(Disciplinas cadastro[]);