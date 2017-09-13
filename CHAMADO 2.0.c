#include <stdio.h>         //
#include <stdlib.h>       //
#include <string.h>      // BIBLIOTECAS PARA FUNCIONAMENTO DO PROGRAMA
#include <conio.h>      //
#include <windows.h>   //
#include <time.h>     //

typedef struct // CRIA��O DAS VARIAVEIS GLOBAL
{   // VARIAVEIS QUE SERAM UTILIZAAS EM TODA ESTRUTURA A PARTIR DO COMANDO VARIAVEIS X
	char nome[20], setor[30], ramal[20], patrimonio[10], problema[500]; // VARIAVEIS DO TIPO CHAR (CARACTERE) DO PROGRAMA
}variaveis; // VARIAVEL QUE TEM VARIAS VARIAVEIS QUE SERA PUXADA (APELIDADA) POR X

//************************************************************************************************************************************************************************

int chamado(variaveis x) // FUN��O DE RECEBIMENTO DE INFORMA��ES
{
	time_t t; // LOCAL ONDE SER� GUARDADO A DATA E A HORA DO SISTEMA
  	time(&t); // ARMAZENAMENTO DA DATA E HORA EM T PARA SER USADO NO PROGRAMA
	int contador; // CONTADOR PARA CONTAGEM DE LOOP (REPETI��O)
	const size_t tamanho = strlen(x.patrimonio) + 10; // DEFINI��O DE 10 CARACTERES QUE O PATRIMONIO PODER� SER COPIADO
	HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, tamanho); // EXECU��O DA DEFINI��O DO TAMANHO DA C�PIA DE PATRIMONIO NA MEMORIA DO SISTEMA WINDOWS
	FILE *fp; // DEFINI��O PARA CRIA��O DE ARQUIVO
	fp = fopen("DATA.txt","a"); // CRIA��O DE ARQUIVO (__DATE__) COM A DATA DO COMPUTADOR
	if(!fp) // SE HOUVER ALGUM ERRO NA CRAI��O DE ARQUIVO
	{
	   printf( "\a\n\t\t******* ERRO AO CRIAR ENTRADA *******\n\n"); // O USU�RIO � INFOMADO
	   return 0; // PROGRAMA � FECHADO
	}
	printf("\t\t\t\tCONTROLE DE CHAMADO\n\n"); // MOSTRA NA TELA CONTROLE DE CHAMADO
	fprintf(fp,"\t\t\t\t     INICIO: %s",ctime(&t)); // ESCREVE NO ARQUIVO CRIADO AUTOMATICAMENTE A DATA E AS HORAS QUE TEM NO COMPUTADOR
	fprintf(fp,"\t\t\t\t     FIM:               \n");
	printf("NOME: "); // MOSTRA NA TELA NOME
	gets(x.nome); // RECEBE A INFORMA��O DIGITADA
	fprintf(fp,"NOME: %s\n",strupr(x.nome)); // ESCREVE NO ARQUIVO CRIADO A INFORMA��O RECEBIDA PARA NOME
	printf("SETOR: "); // MOSTRA NA TELA SETOR
	gets(x.setor); // RECEBE A INFORMA��O DIGITADA
	fprintf(fp,"SETOR: %s\n",strupr(x.setor)); // ESCREVE NO ARQUIVO CRIADO A INFORMA��O RECEBIDA PARA SETOR
	printf("RAMAL: "); // MOSTRA NA TELA RAMAL
	gets(x.ramal); // RECEBE A INFORMA��O DIGITADA
	fprintf(fp,"RAMAL: %s\n",strupr(x.ramal)); // ESCREVE NO ARQUIVO CRIADO A INFORMA��O RECEBIDA PARA RAMAL
	printf("SUPORTE REMOTO: "); // MOSTRA NA TELA PATRIM�NIO
	gets(x.patrimonio); // RECEBE A INFORMA��O DIGITADA
	memcpy(GlobalLock(hMem), x.patrimonio, tamanho); // C�PIA PARA A MEM�RIA DO COMPUATDOR O PATRIM�NIO ESCRITO PELO TECHADO
	GlobalUnlock(hMem); // C�PIA DIGITADA GUARDADA NA MEM�RIA DO COMPUTADOR
	OpenClipboard(0); // AP�S C�PIA SER FEITA, FECHA C�PIA
	EmptyClipboard(); // SE COPIA VAZIA NADA � FEITO
	SetClipboardData(CF_TEXT, hMem); // FINALIZA��O DA C�PIA GUARDADA NA MEM�RIA DO COMPUTADOR
	fprintf(fp,"SUPORTE REMOTO: %s\n",strupr(x.patrimonio)); // ESCREVE NO ARQUIVO CRIADO A INFORMA��O RECEBIDA PARA PATRIM�NIO
	printf("\n"); // PULA UMA LINHA PARA ORGANIZA��O
	printf("PROBLEMA: "); // MOSTRA NA TELA PROBLEMA
	gets(x.problema); // RECEBE A INFORMA��O DIGITADA
	fprintf(fp,"PROBLEMA: %s\n\n",strupr(x.problema)); // ESCREVE NO ARQUIVO CRIADO A INFORMA��O RECEBIDA
	fprintf(fp,"\t\t\t\t    CHAMADO RESOLVIDO [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMA��O OU N�O NO CHAMADO
	fprintf(fp,"\t\t\t\t        N�O RESOLVIDO [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMA��O OU N�O NO CHAMADO
	fprintf(fp,"\t\t\t\t     TRANSFERIDO PARA: \n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMA��O OU N�O NO CHAMADO
	fprintf(fp,"\t\t\t\t           OS FECHADA [  ]\n"); // ESCREVE UM ITEN PARA SER INSERIDO UMA INFORMA��O OU N�O NO CHAMADO
	fprintf(fp,"\n"); // PULA UMA LINHA NO ARQUIVO CRIADO
	for(contador=0;contador<70;contador++) // CONTADOR DO LOOP (REPETI��O) PARA SER ESCRITA 70 VEZES
	{
		fprintf(fp,"#"); // ESCREVE O SIMBOLO # (JOGO DA VELHA) 70 VEZES NO ARQUIVO CRIADO
	}
	fprintf(fp,"\n"); // PULA UMA LINHA NO ARQUIVO CRIADO
	CloseClipboard(); // FECHA A C�PIA DO PATRIM�NIO COM SEGURAN�A
	fclose(fp); // FECHA O ARQUIVO COM SEGURAN�A
}

//************************************************************************************************************************************************************************

int main() // INICIALIZADOR DO PROGRAMA
{
	variaveis x; // ATRIBUI��O DAS VARIAVEIS GLOBAL
	system("title CHAMADO");
	system("color 3f"); // PERSONALIZA��O DE COR DO CMD (PROMPT DE COMANDO)

		chamado(x); // EXECU��O DA FUN��O DE RECEBIMENTO DE INFORMA��ES
		system("cls"); // FUN��O PARA LIMPAR A TELA
				
} // FIM DO PROGRAMA
