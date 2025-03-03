#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

typedef struct node node_t;

node_t *create_new_node(int value){
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void insert_at_head(node_t **head, int value){
  node_t *temp = create_new_node(value);
  *head = temp;
}

node_t *insert_at_tail(node_t *head, int value){
  node_t *new_node = create_new_node(value);

  if (head == NULL){
    return new_node;
  }
  
  node_t *curr = head;
  while (curr->next != NULL){
    curr = curr->next;
  }
  curr->next = new_node;
  return head;
}

void print_list(node_t *head){
  node_t *curr = head;
  while (curr != NULL){
    printf("%d -> ", curr->value);
    curr = curr->next;
  }
}


int main(int argc,  char **argv){
  node_t *head = NULL;
  for (int i = 1; i < 5; i++){
    head = insert_at_tail(head, i * 10);
  }
  print_list(head);
  printf("\n");
  return 0;
}
