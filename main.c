#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct doublenode{
    int x;
    struct doublenode* next;
    struct doublenode * prev;
}doublenode;

typedef struct node{
    int x;
    struct node *next;
}node;

void insert( node ** head, int data){
    node * ptr = malloc(sizeof(node));
    ptr->x = data;
    ptr->next = *head;
    *head = ptr;
}

void insertend(node ** head, int value){
    node* last = *head;
    node * ptr = malloc(sizeof(node));
    ptr->x = value;
    ptr->next = NULL ;
    if(*head == NULL) *head = ptr;
    else
        while(last->next != NULL ){
            last = last->next;
        }
    last->next = ptr;
    last = ptr;
    
    
}e
void printlist( node*head ){
    while(head!= NULL){
        printf("%d \n", head->x);
        head = head->next;
    }}

void insertafter (node*head, int value){
    if(head == NULL)return;
    else{
        node * ptr = malloc(sizeof(node));
        ptr->x = value;
        ptr->next = head->next;
        head->next = ptr;}
}


void middle(node** head){
    node *curr = *head;
    node * curr2 = *head;
    
while ( curr2 != NULL){
        curr = curr->next;
        curr2 = curr->next->next;
    }
    printf(" la valeur du node du milieu : %d \n", curr->x );

}
int occ( node* head, int value ){
    node *curr = head;
    int cpt = 0;
    while (curr != NULL){
        if(curr->x == value){cpt ++;}
        curr = curr->next;
    } return cpt;
}

int ifcircular(node* head ){
    node* curr = head->next;
    if(head == NULL){  return 1 ;}
    else
        while(curr != NULL && curr != head ){
            curr = curr->next;
        }
     if(curr == NULL){return 0;}
    else return 1;
}

int nbnoeud(node* head ){
    int cpt = 1;
        node * curr = head->next;
        while (curr != head ){
            curr = curr->next;
            cpt++;
        }return cpt;
    }

struct node* singletocircular(struct node* head)
{
  struct node* start = head;
  while (head->next != NULL)
        head = head->next;

    head->next = start;
    return start;
}
int iterativesearch(node * head, int data ){
    if (head != NULL){
        node  * curr = head;
        while(curr!= NULL){
            if(curr->x == data){return 1;}
            curr = curr->next;
        }
        
    }return 0;
    
}
int recursivesearch(node * head , int data){
    if(head == NULL){return 0;}
    else if(head->x == data ){
        return 1;
    }
    else return recursivesearch(head->next, data);
}
int iterativelength(node* head){
    if(head== NULL){return 0;}
    else {int cpt =0;
        while(head != NULL){
            head = head->next;
            cpt++;
            
        }return cpt;
    }

}

int recursivelength(node *head ){
    if(head == NULL){return 0;}
    else return 1 + recursivelength(head->next);
}
void reverseList(node **head ){
    node * prev = NULL;
    node* curr = *head;
    node*next = NULL ;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }*head = prev;
}

void delete(node**head, int value ){
    node*temp = *head;
    node *prev = NULL;
    if ( temp != NULL && temp->x == value ){
        *head = (*head)->next;
        free(temp);}
        else {
            while(temp != NULL && temp->x != value){
                prev = temp;
                temp = temp->next;
            }
            if(temp==NULL)return;
            else{
                prev->next = temp->next;
                free(temp);
            }
    }
}

void deleteposition(node**head, int pos){
    node *temp = *head;
    node *prev = NULL;
    int cpt = 0;
    if ( temp != NULL && pos == 1 ){
        *head = (*head)->next;
        free(temp);
    } else{
        while(temp!= NULL &&  cpt!= pos){
            prev = temp;
            temp = temp->next;
            cpt++;
        }if(temp==NULL)return;
        else{
            
                prev->next = temp->next;
                free(temp);
            
        }
        
    }
   
}

int getnode( node * head, int pos){
    int cpt = 1;
    node*curr = head;
    if(head!= NULL){
        while(curr!= NULL){
            if(cpt==pos)return curr->x;
            else {cpt++;
                curr = curr->next;
            }
        }
    } assert(0);
    
}

void reversedoubledouble ( doublenode** head ){
    doublenode * temp = NULL;
    doublenode * curr = *head;
    while (curr!= NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
      }if (temp != NULL)
          *head = temp->prev;
    }

void removeduplicates (node ** head ){
    node * curr = *head;
    node *prev = NULL;
    if (curr ==NULL)return;
    while (curr->next != NULL){
        if (curr->next->x == curr->x){
            curr->next = curr->next->next;
            prev = curr->next;
            free(prev);
        }else curr = curr->next;
     }
}

int exist(node*head , int value){
    if (head==NULL)return 0;
    else { node* ptr = head;
        while(ptr!= NULL){
            if(ptr->x == value )return 1;
            ptr = ptr->next;
        }
        
        
    }
    
    return 0;
}

node* intersection(node* L1, node* L2){
    node * L3 = NULL;
    if(L1==NULL||L2==NULL)return NULL;
    else{
        node*temp = L1;
        while(temp!= NULL){
            if (exist(L2, temp->x)==1){insert(&L3, temp->x);}
            temp= temp->next;
            
        }
    }
    return L3;
    
}
node * circulartosingle(node *head){
    node*start = head;
    while(head->next !=start ){
        head  = head->next;
    }head->next = NULL;
    return start;
}
node* rotateright(node * head, int k  ){
    node * head1 = singletocircular(head);
    node*head2;
    for(int i = 0;i<=k;i++){
        head1 = head1->next;
    }
    head2 = circulartosingle(head1);
    return head2;
}
node* mergenodes(node* head){
    node* curl =head;
    node* curr = head->next;
    int sum = 0;
    while(curr != NULL){
        if(curr->x != 0){sum += curr->x;curr = curr->next;}
        else if (curr->x == 0){
            curl->next->x = sum;
            curl = curl->next;
            curl->next = curr;
            sum = 0;
            curr = curr->next;}
        }
        
    curl->next = NULL;
    
    
    return head->next;
}
void deletenthnodefromend(node**head, int n ){
    node* Lf = *head;
    
    int cpt = 0;
    while(Lf!= NULL){
        Lf= Lf->next;
        cpt++;
    }int k = cpt - n;
    if(k>= 0)
    deleteposition(head, k);
}


int main(){
    
    node *t = NULL;
    insert(&t, 0);
    insert(&t, 1);
    insert(&t, 1);
    insert(&t, 2);
    insert(&t, 0);
    insert(&t, 3);
    insert(&t, 5);
    insert(&t, 0);
    deletenthnodefromend(&t, 5);
    printlist(t);
    
    
    
        
    
    
    
    
    
    
    
}
    
