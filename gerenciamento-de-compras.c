Fazer um programa para gerenciamento de compras em um supermercado, com as seguintes  características: 
a. O programa deve mostrar um menu de opções ao usuário: adicionar item, remover item, obter  valor total da compra, mostrar relatório (lista de itens) e sair. 
b. O programa deve definir o tipo de struct Item, que pretende representar um item sendo  comprado no supermercado. 
Campos do struct: nome do item, valor unitário e quantidade. 
c. O programa deve definir um array (vetor) para permitir criar uma lista de compras no  supermercado. 

struct
{
  char nome[15];
  float valor;
  int quantidade;
} item[100];

int main()
{

  char lista[20], nome[15], nameremove[15];
  int i, escolha = -1, quantremove, valorremove;
  int cont = 0;
  float valortotal = 0, aux = 0;

  while (escolha != 0)
  {
    printf("\nMENU DE OPCOES\n");
    printf("\n1. Inserir item");
    printf("\n2. Remover item");
    printf("\n3. Obter valor total");
    printf("\n4. Lista de itens");
    printf("\n0. Sair\n\n");
    scanf("%i", &escolha);    
    system ("cls");
    switch (escolha) 
    {
    case 1:
    {
      printf("Nome do item: ");
      fflush(stdin);
      scanf("%s", item[cont].nome);
      printf("Valor: ");
      scanf("%f", &item[cont].valor);
      printf("Quantidade: ");
      scanf("%d", &item[cont].quantidade);
      valortotal = item[cont].valor;
      cont++;
      system ("cls");
    }
    break;
    
    case 2:
    {
      if (valortotal == 0)
      {
        printf("LISTA VAZIA!");
      }
      else
      {
        printf("Digite o nome do item que deseja remover: ");
        scanf("%s", nameremove);
        for (i = 0; i < cont; i++)
        {
          if (strcmp(nameremove, item[i].nome) == 0)
          {
            printf("Digite a quantidade a ser removida: ");
            scanf("%d", &quantremove);
            while (quantremove > item[i].quantidade)
            {
              printf("Digite a quantidade a ser removida: ");
              scanf("%d", &quantremove);
            }
            system ("cls");
            valorremove = item[i].quantidade - quantremove;
            item[i].quantidade = valorremove;
            printf("Item Removido!\n");
            break;
          }
        }
        if (strcmp(nameremove, item[i].nome) == 1)
        {
          printf("Não enontrado na lista");
        }
      }
    }

    break;
system ("cls");
    case 3:
    {
      for (i = 0; i < cont; i++)
      {
        valortotal = ((item[i].valor * item[i].quantidade) + aux);
        aux = valortotal;
      }
      printf("\nValor total das compras: %.2f", valortotal);
      aux = 0;
    }
    break;
    system ("cls");
    case 4:
    {
      printf("\tLISTA DE COMPRAS\n\n");
      printf("---------------------------\n");
      printf("|      Item        |Quant.|\n");
      printf("--------------------------- \n");
      for (i = 0; i < cont; i++)
      {
        printf("| %-16s | %4d |\n", item[i].nome, item[i].quantidade);
      }
      printf("--------------------------- \n");
    }
    break;
    system ("cls");
    default:
      break;
    }
  }

  return 0;
}
