#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strng

int registrar() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char escolha[10];
	//fim criação de variáveis/string
	
 do{
	system("cls");
	
	printf("Cadastrar CPF: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string

	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	file = fopen(arquivo,"a");
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha arquivo
	
	
	file = fopen(arquivo, "a"); //abrir arquivo 
	fprintf(file,"\nNome: "); 
	fclose(file); //fechar arquivo
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n\nDeseja inserir mais um usúario? (sim/não): ");
	scanf("%s",escolha);
     if (strcmp(escolha, "sim") == 0 || strcmp(escolha, "Sim") == 0 || strcmp(escolha, "SIM") == 0){
	     
	 } else {
		 return 0;
	 }
   } while (1);
}

int consultar()
{
   setlocale(LC_ALL, "Portuguese");//definindo linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Consultar CPF: ");
   scanf("%s",cpf);
   getchar();
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	   printf("\nArquivo não localizado!");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
   {
   	   printf(" ");
   	   printf("%s",conteudo);
   	   
   }
       printf("\n\n");
    
	system("pause");
    
   fclose(file);
   
}
int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
    char cpf[40];
    char confirmacao[10];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema! \n\n");
		system("pause");
		return;
		
	} else{
	   fclose(file);
	   
	   char conteudo[200];
	   file = fopen(cpf,"r");
	   
	   printf("\nDados do usuário a ser deletado:\n");
	   while (fgets(conteudo, 200, file) != NULL) {
	   	printf(" %s", conteudo);
	   }
	   
	   
	   
	   printf("\n\nDeseja deletar esse usuário? (sim/não): ");
	   scanf(" %s",confirmacao);
	   fclose(file);
	   
	   if(strcmp(confirmacao,"sim") == 0 || strcmp(confirmacao,"Sim") == 0 || strcmp(confirmacao,"SIM") == 0) {
	      remove(cpf);	  
	      printf("\nUsuário removido com sucesso!\n\n");
	      fclose(file); 
	   } else{
	   	  printf("\nAção cancelada. O usuário não foi deletado.\n\n");
	   }
	   
	system("pause"); 
	   
	}
}

int main()
{
	int opcao=0;//definindo variáveis
	int repetir=1;
	
	for(repetir=1;repetir==1;)
    {
	  system("cls");
	  
	  setlocale(LC_ALL, "Portuguese");//definindo linguagem
		
	  printf("### Cartório da Ebac ###\n\n");//nome projeto 		
	  printf("Escolha a opção desejada do menu:\n\n");//inicio menu	
	  printf("\t1-Registrar nomes\n");//opções_menu
	  printf("\t2-Consultar nomes\n");
	  printf("\t3-Deletar nomes\n\n");
	  printf("\t4-Sair do sistema\n\n");
	  printf("opção:");//fim menu

	  scanf("%d",&opcao);//armazenando a escolha do usuário
	
	  system("cls"); //responsável por limpar a tela
	
	  switch(opcao) //inicio de seleção
	  {
		case 1:
		registrar(); //chamada de funções
		break;
	   	
		case 2:
	    consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("\nObrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;	
		//fim da seleção
	  }
    }
	return 0;	
}
