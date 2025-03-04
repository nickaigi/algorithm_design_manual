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

void insert(node_t **head, int value){
  /*
   * since We have no need to maintain the list in any particular order,
   * we always insert at head to guarantee insert of O(1) 
  */
  node_t *temp = create_new_node(value);
  temp->next = *head;
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

/*
 * Searching can be done iteratively or recursively
 * If value is in the list, it is either the ﬁrst element or located in the smaller
 * rest of the list. Eventually, we reduce the problem to searching in an empty list,
 * which clearly cannot contain value.
*/
node_t *search_list(node_t *curr, int value){
  if (curr == NULL)
    return(NULL);
  if (curr->value == value)
    return(curr);
  else
    return(search_list(curr->next, value));
}

/*
 * Deletion from a linked list is somewhat more complicated. First, we must ﬁnd a
 * pointer to the predecessor of the item to be deleted. We do this recursively:
*/
node_t *predecessor_node(node_t *curr, int value){
  if ((curr == NULL) || (curr->next == NULL)) {
    printf("Error: predecessor sought on null list\n");
  }
  if ((curr->next)->value == value)
    return (curr);
  else
    return(predecessor_node(curr->next, value));
}

/*
 * The predecessor is needed because it points to the doomed node, so its next
 * pointer must be changed. The actual deletion operation is simple, once ruling out
 * the case that the to-be-deleted element does not exist. Special care must be taken
 * to reset the pointer to the head of the list (l) when the ﬁrst element is deleted:
*/

void delete_node(node_t **head, int value){
  node_t *temp;
  node_t *pred;
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
    insert(&head, i * 10);
  }
  print_list(head);
  printf("\n");
  return 0;
}
