#include <stdio.h>         //
#include <stdlib.h>       //
#include <string.h>      // BIBLIOTECAS PARA FUNCIONAMENTO DO PROGRAMA
#include <conio.h>      //
#include <windows.h>   //
#include <time.h>     //

typedef struct // CRIAÇÃO DAS VARIAVEIS GLOBAL
{   // VARIAVEIS QUE SERAM UTILIZAAS EM TODA ESTRUTURA A PARTIR DO COMANDO VARIAVEIS X
	char nome[20], setor[30], ramal[20], patrimonio[10], problema[500]; // VARIAVEIS DO TIPO CHAR (CARACTERE) DO PROGRAMA
}variaveis; // VARIAVEL QUE TEM VARIAS VARIAVEIS QUE SERA PUXADA (APELIDADA) POR X

//************************************************************************************************************************************************************************

int chamado(variaveis x) // FUNÇÃO DE RECEBIMENTO DE INFORMAÇÕES
{
	time_t t; // LOCAL ONDE SERÁ GUARDADO A DATA E A HORA DO SISTEMA
  	time(&t); // ARMAZENAMENTO DA DATA E HORA EM T PARA SER USADO NO PROGRAMA
	int contador; // CONTADOR PARA CONTAGEM DE LOOP (REPETIÇÃO)
	const size_t tamanho = strlen(x.patrimonio) + 10; // DEFINIÇÃO DE 10 CARACTERES QUE O PATRIMONIO PODERÁ SER COPIADO
	HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, tamanho); // EXECUÇÃO DA DEFINIÇÃO DO TAMANHO DA CÓPIA DE PATRIMONIO NA MEMORIA DO SISTEMA WINDOWS
	FILE *fp; // DEFINIÇÃO PARA CRIAÇÃO DE ARQUIVO
	fp = fopen("DATA.txt","a"); // CRIAÇÃO DE ARQUIVO (__DATE__) COM A DATA DO COMPUTADOR
	if(!fp) // SE HOUVER ALGUM ERRO NA CRAIÇÃO DE ARQUIVO
	{
	   printf( "\a\n\t\t******* ERRO AO CRIAR ENTRADA *******\n\n"); // O USUÁRIO É INFOMADO
	   return 0; // PROGRAMA É FECHADO
	}
	printf("\t\t\t\tCONTROLE DE CHAMADO\n\n"); // MOSTRA NA TELA CONTROLE DE CHAMADO
	fprintf(fp,"\t\t\t\t     INICIO: %s",ctime(&t)); // ESCREVE NO ARQUIVO CRIADO AUTOMATICAMENTE A DATA E AS HORAS QUE TEM NO COMPUTADOR
	fprintf(fp,"\t\t\t\t     FIM:               \n");
	printf("NOME: "); // MOSTRA NA TELA NOME
	gets(x.nome); // RECEBE A INFORMAÇÃO DIGITADA
	fprintf(fp,"NOME: %s\n",strupr(x.nome)); // ESCREVE NO ARQUIVO CRIADO A INFORMAÇÃO RECEBIDA PARA NOME
	printf("SETOR: "); // MOSTRA NA TELA SETOR
	gets(x.setor); // RECEBE A INFORMAÇÃO DIGITADA
	fprintf(fp,"SETOR: %s\n",strupr(x.setor)); // ESCREVE NO ARQUIVO CRIADO A INFORMAÇÃO RECEBIDA PARA SETOR
	printf("RAMAL: "); // MOSTRA NA TELA RAMAL
	gets(x.ramal); // RECEBE A INFORMAÇÃO DIGITADA
	fprintf(fp,"RAMAL: %s\n",strupr(x.ramal)); // ESCREVE NO ARQUIVO CRIADO A INFORMAÇÃO RECEBIDA PARA RAMAL
	printf("SUPORTE REMOTO: "); // MOSTRA NA TELA PATRIMÔNIO
	gets(x.patrimonio); // RECEBE A INFORMAÇÃO DIGITADA
	memcpy(GlobalLock(hMem), x.patrimonio, tamanho); // CÓPIA PARA A MEMÓRIA DO COMPUATDOR O PATRIMÔNIO ESCRITO PELO TECHADO
	GlobalUnlock(hMem); // CÓPIA DIGITADA GUARDADA NA MEMÓRIA DO COMPUTADOR
	OpenClipboard(0); // APÓS CÓPIA SER FEITA, FECHA CÓPIA
	EmptyClipboard(); // SE COPIA VAZIA NADA É FEITO
	SetClipboardData(CF_TEXT, hMem); // FINALIZAÇÃO DA CÓPIA GUARDADA NA MEMÓRIA DO COMPUTADOR
	fprintf(fp,"SUPORTE REMOTO: %s\n",strupr(x.patrimonio)); // ESCREVE NO ARQUIVO CRIADO A INFORMAÇÃO RECEBIDA PARA PATRIMÔNIO
	printf("\n"); // PULA UMA LINHA PARA ORGANIZAÇÃO
	printf("PROBLEMA: "); // MOSTRA NA TELA PROBLEMA
	gets(x.problema); // RECEBE A INFORMAÇÃO DIGITADA
	fprintf(fp,"PROBLEMA: %s\n\n",strupr(x.problema)); // ESCREVE NO ARQUIVO CRIADO A INFORMAÇÃO RECEBIDA
	fprintf(fp,"\t\t\t\t    CHAMADO RESOLVIDO [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMAÇÃO OU NÃO NO CHAMADO
	fprintf(fp,"\t\t\t\t        NÃO RESOLVIDO [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMAÇÃO OU NÃO NO CHAMADO
	fprintf(fp,"\t\t\t\t     TRANSFERIDO PARA: \n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMAÇÃO OU NÃO NO CHAMADO
	fprintf(fp,"\t\t\t\t           OS FECHADA [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMAÇÃO OU NÃO NO CHAMADO
	fprintf(fp,"\n"); // PULA UMA LINHA NO ARQUIVO CRIADO
	for(contador=0;contador<70;contador++) // CONTADOR DO LOOP (REPETIÇÃO) PARA SER ESCRITA 70 VEZES
	{
		fprintf(fp,"#"); // ESCREVE O SIMBOLO # (JOGO DA VELHA) 70 VEZES NO ARQUIVO CRIADO
	}
	fprintf(fp,"\n"); // PULA UMA LINHA NO ARQUIVO CRIADO
	CloseClipboard(); // FECHA A CÓPIA DO PATRIMÔNIO COM SEGURANÇA
	fclose(fp); // FECHA O ARQUIVO COM SEGURANÇA
}

//************************************************************************************************************************************************************************

int main() // INICIALIZADOR DO PROGRAMA
{
	variaveis x; // ATRIBUIÇÃO DAS VARIAVEIS GLOBAL
	system("title CHAMADO");
	system("color 3f"); // PERSONALIZAÇÃO DE COR DO CMD (PROMPT DE COMANDO)

		chamado(x); // EXECUÇÃO DA FUNÇÃO DE RECEBIMENTO DE INFORMAÇÕES
		system("cls"); // FUNÇÃO PARA LIMPAR A TELA
				
} // FIM DO PROGRAMA
