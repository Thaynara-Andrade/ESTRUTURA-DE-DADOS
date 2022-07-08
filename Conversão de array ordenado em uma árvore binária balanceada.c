#include<stdio.h>
#include<stdlib.h>

/* Nó da árvore binaria */
struct TNode
{
  int data;
  struct TNode* left;
  struct TNode* right;
};

struct TNode* newNode(int data);

/* Uma função que constrói uma árvore de pesquisa binária balanceada a partir de uma matriz classificada*/
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
  /* Base */
  if (start > end)
  return NULL;

  /* Pega o elemento do meio e torna raiz*/
  int mid = (start + end)/2;
  struct TNode *root = newNode(arr[mid]);

  /* Construir recursivamente a subárvore esquerda e torná-la
  filho esquerdo da raiz */
  root->left = sortedArrayToBST(arr, start, mid-1);

  /* Construir recursivamente a subárvore correta e torná-la
  filho direito da raiz*/
  root->right = sortedArrayToBST(arr, mid+1, end);

  return root;
}

/* Função auxiliar que aloca um novo nó com o
dados fornecidos e ponteiros esquerdo e direito NULL.*/
struct TNode* newNode(int data)
{
  struct TNode* node = (struct TNode*)
            malloc(sizeof(struct TNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

/* Uma função de utilitário para imprimir travessia de pré-encomenda de BST*/
void preOrder(struct TNode* node)
{
  if (node == NULL)
    return;
  printf("%d ", node->data);
  preOrder(node->left);
  preOrder(node->right);
}

/* Serve para testar as funções acima*/
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  /* Converter a lista para BST*/
  struct TNode *root = sortedArrayToBST(arr, 0, n-1);
  printf("n PreOrder Traversal of constructed BST ");
  preOrder(root);

  return 0;
}
