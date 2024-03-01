#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
	char nome[50];
	int idade;
	int matricula;
};

typedef struct aluno Aluno;

struct no{
	Aluno valor;
	struct no *prox;
};

typedef struct no No;

typedef struct{
	No *inicio;
}Lista;

void imprimir(Lista *l){
	No *aux;
	aux = l->inicio;
	if(aux == NULL){
		printf("Lista vazia!!");
	}else{
		printf("\nLista de ALUNOS\n");
		
		while(aux != NULL){
			printf("\n----------------\n");
			printf("Nome: %s", aux->valor.nome);
			printf("\nIdade: %d",aux->valor.idade);
			printf("\nMatricula: %d", aux->valor.matricula);
			printf("\n----------------\n");
			aux = aux->prox;
		}
	}
}

void buscar(Lista *l){
	No *aux;
	aux = l->inicio;
	if(aux == NULL){
		printf("Lista vazia!!");
	}else{
		
	}
}

void inserir(Lista*l){
	
	char nome[50];
	int idade;
	int matricula;
	
	printf("Digite o nome do aluno: ");
	scanf(" %[^\n]", nome);
	
	printf("Digite a idade do aluno: ");
	scanf("%d", &idade);
	
	printf("Digite a matricula do aluno: ");
REFAZ:  scanf("%d", &matricula);
	
	No *no;
	
	No *aux;
	aux = l->inicio;

	no = malloc(sizeof(No));

	strcpy(no->valor.nome,nome);
	no->valor.idade = idade;
	no->valor.matricula = matricula;
	no->prox = NULL;

	if(aux == NULL){
		l->inicio = no;
	}else{
		while(aux->prox != NULL){
			if(aux->valor.matricula == no->valor.matricula){
				printf("Matricula já está em uso!\nPor favor insira novamente: ");
				goto REFAZ;
			}
			printf("%d", aux->valor.matricula);
			aux = aux->prox;
		}

		if(aux->valor.matricula == no->valor.matricula){
			printf("Matricula já está em uso!\nPor favor insira novamente: ");
			goto REFAZ;
		}

		aux->prox = no;
	}

	while (getchar() != '\n');

}

void excluir(Lista *l){

}

void main(){
	Lista l;
	l.inicio = NULL;
	int opcao;

	while (opcao != 5){
		printf("\n ######## Lista de Alunos ########\n");
		printf("1) Inserir\n");
		printf("2) Listar\n");
		printf("3) Buscar\n");
		printf("4) Excluir\n");
		printf("5) Sair\n");

		scanf("%i", &opcao);

		switch(opcao){
			case 1:
				inserir(&l);
				break;
			case 2:
				imprimir(&l);
				break;
			case 3:
				buscar(&l);
				break;
			case 4:
				excluir(&l);
				break;
			case 5:
				printf("Programa encerrado!!");
				break;
			default:
				printf("Opção incorreta!!");

		}
	}
}
