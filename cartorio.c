#include <stdio.h> //Permite a comunica��o mais simples com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Inclui diferentes caracteres de acordo com a l�ngua
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //rspons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo w = write
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coleta informa��o do usu�rio
	scanf("%s",nome); //busca o valor da string
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,nome); //salvar o valor da vari�vel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //informa��o que o usu�rio vai fornecer
	scanf("%s", sobrenome); //coleta essa informa��o
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,","); //"espa�amento de cada informa��o"
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //informa��o do usu�rio
	scanf("%s",cargo); //coleta a informa��o
	
	file = fopen(arquivo, "a"); //abre um arquivo para anexa��o
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause"); 
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //le o arquivo (no caso o cpf)
	
	if(file == NULL)
	{	
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //!= significa diferente (ent�o se as informa��es s�o diferentes de nulo, ele realiza a fun��o)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //remove o arquivo do banco de dados
	
	FILE *file;
	file = fopen(cpf,"r");   // "r" l� o valor do arquivo (do cpf no caso) e o "fopen" procura o aqrquivo na pasta
    
	if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema \n");
    	system("pause");
	}
	
}




int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
		
		printf("\t Cart�rio da EBAC\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); //\t seve para dar um certo espa�o e o \n serve para pular linhas em textos
		printf("\t1) Registrar usu�rios\n");
		printf("\t2) Consultar usu�rios\n");
		printf("\t3) Deletar usu�rios\n\n");
		printf("Op��es: ");//Final do menu
		
		scanf("%d", &opcao);//Armazenando as informa��es/escolha do usu�rio
			
		system("cls");//Sumir com tudo/limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chama a fun��o de registro
			break;
			
			case 2:
			consulta(); //chama a fun��o de consulta
			break;
			
			case 3:
			deletar(); //chama a fun��o de deletar
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel \n");
			system("pause");
			break;
		}
	
		
		
		}
}
