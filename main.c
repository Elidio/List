#include <stdio.h>
#include <stdlib.h>


/*TESTE UNITARIO*/

typedef struct {
  int elem;
  void *next;
} SingleLinkedListOfIntsNode;

void printList(SingleLinkedListOfIntsNode **head){
  
  SingleLinkedListOfIntsNode* p = *head;

  if (!p)
    printf("[]\n");
  else{
    printf("[");
    while(p){
      if(!(p->next)){
        printf("%d", p->elem);
      }
      else
        printf("%d, ", p->elem);
      p = (SingleLinkedListOfIntsNode*)p->next;
    }
    printf("]\n");
  }

}

void listAppend(SingleLinkedListOfIntsNode **head, int elem){
  SingleLinkedListOfIntsNode* p1 = malloc(sizeof(SingleLinkedListOfIntsNode));
  SingleLinkedListOfIntsNode* p2 = *head;
  p1->next = NULL;
  p1->elem = elem;
  if (!(*head)) {
    *head = p1;
  }
  else {
    while (p2){
      SingleLinkedListOfIntsNode* pprev = p2;
      p2 = p2->next;
      if(!p2)
       pprev->next = p1; 
    }
  }
}

/*ATIVIDADE*/

void listPartition(SingleLinkedListOfIntsNode **head, int x) {
  SingleLinkedListOfIntsNode *p  = *head; // ponteiro para o elemento
  SingleLinkedListOfIntsNode *lx = NULL;   // lista que só contém px
  SingleLinkedListOfIntsNode *lstx = NULL;  // lista que só contém elementos menores que x
  SingleLinkedListOfIntsNode *lgtx = NULL;  // lista que só contém elementos maiores que x
  
  SingleLinkedListOfIntsNode *lxlast   = NULL;
  SingleLinkedListOfIntsNode *lstxlast  = NULL;
  SingleLinkedListOfIntsNode *lgtxlast = NULL;

  /*
     Separando a lista em três listas
  */

  while(p){
    SingleLinkedListOfIntsNode *pnext = p->next;

    if(p->elem < x){
      if (lstxlast)
      { 
        lstxlast->next = p;
        lstxlast = lstxlast->next;
        lstxlast->next = NULL;
      }
      else
      {
        lstx = p;
        lstxlast = p;
        lstxlast->next = NULL;
      }
    }

    else if(p->elem == x){
      if (lxlast)
      {  
        lxlast->next = p;
        lxlast = lxlast->next;
        lxlast->next = NULL;
      }
      else
      {
        lx = p;
        lxlast = p;
        lxlast->next = NULL;
      }
    }

    else if(p->elem > x){
      if (lgtxlast)
      {  
        lgtxlast->next = p;
        lgtxlast = lgtxlast->next;
        lgtxlast->next = NULL;
      }
      else
      {
        lgtx = p;
        lgtxlast = p;
        lgtxlast->next = NULL;
      }
    }

    p = pnext;  

  }


/*
 mergeando lstx com lx
*/

  p = lstx;

  if(!p)
    lstx = lx;

  while(p){
    SingleLinkedListOfIntsNode *pprev = p;
    p = p->next;
    if (!p)
      pprev->next = lx;
  }

/*
 mergeando lstx com lgtx
*/

  p = lstx;

  if(!p)
    lstx = lgtx;

  while(p){
    SingleLinkedListOfIntsNode *pprev = p;
    p = p->next;
    if (!p)
      pprev->next = lgtx;
  }

/*
 colocando o head em lstx
*/

  *head = lstx;

}


/*TESTE UNITARIO*/

int main(void) {
  
  SingleLinkedListOfIntsNode *list = NULL;
  int i;

  //printList(&list);

  
  for(i = 0; i < 10; i++)
    if (i%2)
      listAppend(&list, 9-i);
    else
      listAppend(&list, i+1); 

  printList(&list);

  listPartition(&list, 5); 

  printList(&list);


  return 0;
}