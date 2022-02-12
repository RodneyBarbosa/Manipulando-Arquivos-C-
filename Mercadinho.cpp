#include <stdio.h>
#include <string.h>

struct compras_diarias
{
  char identificador[6];
  char nomeproduto[101];
  float precoproduto;
  int quantidade;
  int dia;
  int mes;
  int ano;
  int hora;
  int min; 
};
struct compras_diarias caixa;

int main(void) {
FILE *produtos = fopen("Produtos.txt", "r");
FILE *copia = fopen("Produtos_Excluidos.txt", "r");
FILE *estoque = fopen("Estoque.txt", "r");
FILE *dia = fopen("Compras_Do_Dia.txt", "r");
  
  printf("    MERCADINHO\n-------------------\nBom Dia!O que deseja fazer hoje?\n(1)-Adicionar Produtos.\n(2)-Remover produtos.\n(3)-Alterar dados de um produto\n(4)-Carrinho de compras\n(5)-Finalizar tarefas do dia.\n");

	char produto[1000];
	char bo[4];
  char busca[20];
	char extra[1000];

  int a, cont, i, po, qtd;
  float b;
//enquanto o código for diferente de 4, continuará requisitando códigos

  while(a!=5){
	scanf("%d", &a);

  //se for igual a 5, o programa acaba
  

  if(a>5 || a<0){
    printf("Não existe tarefa para tal comando...\nDigite um código válido.\n");
  // caso o comando não exista imprimirá o seguinte:
  }
  //primeiro comando
	if(a==1){
    int cont2, qtd2;
    char prod[100];
    float b2;

    printf("~Digite o código, nome, preço e a quantidade do produto, respectivamente:\n");
    //mensagem para usuário digitar nº e nome

	scanf("%d %s %f %d", &cont, produto, &b, &qtd);
  //verifica se produto já existe
  while(fscanf(produtos, "%d %s R$%f %d", &cont2, prod, &b2, &qtd2)!=EOF){
  if(cont==cont2 || cont2==cont){
    printf("Este produto já existe!\nAdicione outro não existente\n");
    return 0;
  }
  }
  while(fscanf(copia, "%d %s R$%f %d", &cont2, prod, &b2, &qtd2)!=EOF){
  if(cont==cont2 || cont2==cont){
    printf("Este produto já existe!\nAdicione outro não existente\n");
    return 0;
  }
  }
  
    produtos = fopen("Produtos.txt", "a");
    fprintf(produtos, "%d\t%s\tR$ %.2f\t%d\n", cont, produto, b, qtd);
    //imprime no arquivo "Produtos.txt" o produto
  
  printf("~Deseja realizar outra ação?\nSim              Não\n");
  //Requerimento para que realize outra ação

  scanf("%s", bo);
  if (strcmp(bo, "Sim")==0 || strcmp(bo, "sim")==0 || strcmp(bo, "SIM")==0){
    produtos = fopen("Produtos.txt", "r");
    printf("Qual outra tarefa deseja realizar?\n(Digite o número da respectiva tarefa):\n(1)-Adicionar Produtos.\n(2)-Remover produtos.\n(3)-Alterar dados de um produto\n(4)-Carrinho de compras\n(5)-Finalizar tarefas do dia.\n");
    //Digitar respectivo nº de respectiva função
	}
	else{
	  printf("Obrigado! Tenha um ótimo dia!\n");
    return 0;
  }
  }

  //próximo comando
  else if(a==2){
    copia = fopen("Produtos_Excluidos.txt", "a");
    estoque = fopen("Estoque.txt", "a");
    printf("Qual produto deseja remover do estoque?(Digite o código do respectivo produto)\n");
    char produto2[100];
    int codigo, ID;
    float preco;

    int j;
    scanf("%d", &j);

    while(fscanf(produtos, "%d %s R$%f %d", &codigo , busca, &preco, &ID)!=EOF){
      if(codigo!=j){
      fprintf(estoque, "%d %s R$%.2f %d\n", codigo, busca, preco, ID);
      }
      else{
        fprintf(copia, "%d %s R$%.2f %d\n", codigo, busca, preco, ID);
      }
    }
         remove("Produtos.txt");
         rename("Estoque.txt", "Produtos.txt");
         printf("~Deseja realizar outra ação?\n(Sim)              (Não)\n");
  //Requerimento para que realize outra ação
  scanf("%s", bo);
  if (strcmp(bo, "Sim")==0 || strcmp(bo, "sim")==0 || strcmp(bo, "SIM")==0){
    produtos = fopen("Produtos.txt", "r");
    printf("Qual outra tarefa deseja realizar?\n(Digite o número da respectiva tarefa:\n(1)-Adicionar Produtos.\n(2)-Remover produtos.\n(3)-Alterar dados de um produto\n(4)-Carrinho de compras\n(5)-Finalizar tarefas do dia.\n");
    //Digitar respectivo nº de respectiva função
	}
	else{
	  printf("Obrigado! Tenha um ótimo dia!\n");
    return 0;
  }
  }

  //próximo comando
  else if(a==3){
    copia = fopen("Produtos_Excluidos.txt", "a");
    estoque = fopen("Estoque.txt", "a");
    printf("Qual produto deseja alterar?\n(Digite o código do respectivo produto)\n");
    char produto2[100];
    int codigo, ID;
    float preco;

    int j;
    scanf("%d", &j);

    while(fscanf(produtos, "%d %s R$%f %d", &codigo , busca, &preco, &ID)!=EOF){
      if(codigo!=j){
      fprintf(estoque, "%d %s R$%.2f %d\n", codigo, busca, preco, ID);
      }
      else{
        fprintf(copia, "%d %s R$%.2f %d\n", codigo, busca, preco, ID);
      }
    }
         remove("Produtos.txt");
         rename("Estoque.txt", "Produtos.txt");
    printf("Digite suas alterações:\n");

    int A, ID2;
    char compras[100];
    float gasto;

    scanf("%d %s %f %d", &A, compras, &gasto, &ID2);
    fprintf(estoque, "%d %s R$%.2f %d", A, compras, gasto, ID2);
         printf("~Deseja realizar outra ação?\n(Sim)              (Não)\n");
  //Requerimento para que realize outra ação
  scanf("%s", bo);
  if (strcmp(bo, "Sim")==0 || strcmp(bo, "sim")==0 || strcmp(bo, "SIM")==0){
    produtos = fopen("Produtos.txt", "r");
    printf("Qual outra tarefa deseja realizar? (Digite o número da respectiva tarefa):\n(1)-Adicionar Produtos.\n(2)-Remover produtos.\n(3)-Alterar dados de um produto\n(4)-Carrinho de compras\n(5)-Finalizar tarefas do dia.\n");
    //Digitar respectivo nº de respectiva função
	}
	else{
	  printf("Obrigado! Tenha um ótimo dia!\n");
    return 0;
  }
  }
else if(a==4){
 FILE * Compras_do_caixa = fopen("Registro das compras diarias.txt", "a");
//esse laço pega os produtos passados no caixa
  
  int fechamento = 0;
  float precofinal;
  while(fechamento != 1){
  printf ("Caixa aberto, passe o proximo produto...\n");
  printf ("Para fechar o caixa, digite a senha: SeuZe\n");
  
//controla o momento do fecamento da compra, qnd a senha é digitada
  scanf("%s", caixa.identificador);
  if(strcmp (caixa.identificador, "SeuZe") == 0){
  	fechamento = 1;
  	//coleta data e hora
  	printf("Antes de fechar o caixa, por favor, digite a data (dd/mm/aa) e hora(hr:min) atuais:\n");
  	scanf("%d %d %d %d %d", &caixa.dia, &caixa.mes, &caixa.ano, &caixa.hora, &caixa.min);
  	
  	//printa a data e hora que foi feito o fechamento da compra
  	Compras_do_caixa = fopen("Registro das compras diarias.txt", "a");
  	fprintf(Compras_do_caixa, "\n%d/%d/%d\t %d:%d\n", caixa.dia,caixa.mes, caixa.ano, caixa.hora, caixa.min);
  	fclose(Compras_do_caixa);
  	printf("Caixa fechado!\n");
  	break;
  }
  
  else{
  scanf ("%s %f %d", 
  caixa.nomeproduto,
  &caixa.precoproduto,
  &caixa.quantidade);
  precofinal = caixa.precoproduto * caixa.quantidade; // Calcula o preco final da quantidade de cada item passado no caixa
  }

  
  //aqui o prog printa tudo oq é passado no caixa, para o arq 'Compras_do_caixa'
  fprintf(Compras_do_caixa, "%s\t %s\t R$%.2f\t %d\t R$%.2f\n", 
  caixa.identificador,
  caixa.nomeproduto,
  caixa.precoproduto,
  caixa.quantidade,
  precofinal);
  }
  
fclose(Compras_do_caixa);
//o registro ja esta feito no arq 'Compras_do_caixa'
  }
  }
	fclose(produtos);
  fclose(estoque);
  fclose(copia);
  fclose(dia);

	return 0;

}
