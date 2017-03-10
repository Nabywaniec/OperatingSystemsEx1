
//#include <stdlib.h>
#include <string.h>
/*
typedef struct info {                       // informacje o u¿ytkowniku
  const char *firstName;
  const char *lastName;
  const char *birthDate;
  const char *email;
  long phone;
  const char *address;
}info;

typedef struct ListNode {           // element listy dwukierunkowej
    struct ListNode *next;
    struct ListNode *prev;
    struct info value;
} ListNode;

typedef struct List {                //lista dwukierunkowa
    ListNode *first;
    ListNode *last;
} List;

typedef struct TreeNode {           // element listy dwukierunkowej
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode * parent;
    struct info value;
} TreeNode;

typedef struct Tree {                //lista dwukierunkowa
    TreeNode*root;
} Tree;


*/
/////////////////////////////////////////////////////////////////////////////


Tree *Tree_create()
{
    return calloc(1, sizeof(Tree));
}
////////////////////////////////////////////////////////////////////////////////////////////////

void Tree_add_element2(Tree*tree, info informacja){

  TreeNode * root = tree->root;
  TreeNode* node = calloc(1, sizeof(TreeNode));
  node->value=informacja;



  if(root==NULL){
    tree->root = node;
    tree->root->left=NULL;
    tree->root->right=NULL;
    tree->root->value=informacja;
    tree->root->parent=NULL;
    return;
  }

  TreeNode * tmp = NULL;
  while(root!=NULL){
        tmp=root;


     if(strcmp(node->value.lastName, root->value.lastName) > 0){
        root=root->right;

     }
     else {root=root->left;

     }
  }
  node->parent=tmp;

  if(strcmp(node->value.lastName, tmp->value.lastName) > 0){

    tmp->right=node;
    tmp->right->value=informacja;
    tmp->right->left=NULL;
    tmp->right->right=NULL;
  }
  else{
    tmp->left=node;
    tmp->left->value=informacja;
    tmp->left->left=NULL;
    tmp->left->right=NULL;
  }



}


////////////////////////////////////////////////////////////////////////////////////////////////
void Tree_add_element(Tree * tree, info  informacja){
  TreeNode * root = tree->root;
  TreeNode* node = calloc(1, sizeof(TreeNode));
  node->value=informacja;



  if(root==NULL){
    tree->root = node;
    tree->root->left=NULL;
    tree->root->right=NULL;
    tree->root->value=informacja;
    tree->root->parent=NULL;
    return;
  }

  TreeNode * tmp = NULL;
  while(root!=NULL){
        tmp=root;


     if(strcmp(node->value.firstName, root->value.firstName) > 0){
        root=root->right;

     }
     else {root=root->left;

     }
  }
  node->parent=tmp;

  if(strcmp(node->value.firstName, tmp->value.firstName) > 0){

    tmp->right=node;
    tmp->right->value=informacja;
    tmp->right->left=NULL;
    tmp->right->right=NULL;
  }
  else{
    tmp->left=node;
    tmp->left->value=informacja;
    tmp->left->left=NULL;
    tmp->left->right=NULL;
  }

}
///////////////////////////////////////////////////////////////////////
void Tree_show2(TreeNode * node){

  if(node==NULL) return;

  Tree_show2(node->left);
  printf(node->value.firstName);

  Tree_show2(node->right);

}
//////////////////////////////////////////////////////////////////////

void Tree_show(Tree * tree){

 Tree_show2(tree->root);
}
///////////////////////////////////////////////////////////////////////
void Tree_add(Tree* tree, const char *firstName,const char *lastName,const char *birthDate,const long Phone,const char *address){

struct info dane;
dane.firstName=firstName;
dane.lastName=lastName;
dane.birthDate=birthDate;
dane.phone=Phone;
dane.address=address;
Tree_add_element(tree, dane);


}
/////////////////////////////////////////////////////////////////////////////////////////
TreeNode* Tree_search(Tree * tree, const char*firstName){

  TreeNode * node =tree->root;
  if(node==NULL) return;
  while(node!=NULL){

    if(node->value.firstName==firstName) return node;
        if(strcmp(node->value.firstName, firstName) > 0){
            node=node->left;
        }
        else{
            node=node->right;
        }
  }

return NULL;

}
/////////////////////////////////////////////////////////////////////

TreeNode * Tree_smallest(Tree * tree){

 TreeNode * node = tree->root;
 if(node==NULL) return NULL;;

  while(node->left!=NULL){
    node=node->left;

  }
  return node;


}
//////////////////////////////////////////////////////////////////////
TreeNode * Tree_biggest(Tree * tree){

 TreeNode * node = tree->root;
 if(node==NULL) return NULL;;

  while(node->right!=NULL){
    node=node->right;

  }
  return node;


}
///////////////////////////////////////////////////////////////////////

TreeNode* Max( TreeNode *x )
{
while( x->right != NULL )
{
x = x->right;
}

return x;
}

TreeNode* Min( TreeNode *x )
{
while( x->left != NULL )
{
x = x->left;
}

return x;
}

//////////////////////////////////////////////////////////////////////


TreeNode* Successor( TreeNode *x )
{
if( x->right != NULL ) return Min( x->right );
else
{
TreeNode *y = x->parent;

while( y != NULL && x == y->right )
{
x = y;
y = y->parent;
}

return y;
}
}

TreeNode* Predessor( TreeNode *x )
{
if( x->left != NULL ) return Max( x->left );

TreeNode *y = x->parent;

while( y != NULL && x == y->left )
{
x = y;
y = y->parent;
}

return y;
}


////////////////////////////////////////////////////////////////////////

TreeNode*Delete( Tree* tree, TreeNode *DeleteNode )
{
TreeNode *y = NULL;
TreeNode *x = NULL;

if( (DeleteNode->left == NULL) || (DeleteNode->right == NULL) )
{
y = DeleteNode;
}
else
{
y = Successor(DeleteNode);
}

if( y->left != NULL )
{
x = y->left;
}
else
{
x = y->right;
}

if( x != NULL )
{
x->parent = y->parent;
}

if( y->parent == NULL )
{
tree->root = x;
}
else
{
if(y == y->parent->left)
{
y->parent->left = x;
}
else
{
y->parent->right = x;
}
}

if( y != DeleteNode )
{
DeleteNode->value = y->value;
}
return DeleteNode;

}
////////////////////////////////////////////////////////////////////////
Tree * Tree_sort (Tree * tree){

Tree * sorted =Tree_create();
sorted->root=NULL;
while(tree->root!=NULL){
    TreeNode * node = Tree_smallest(tree);
    info data = node->value;
    TreeNode * del = Delete(tree,node);
    Tree_add_element2(sorted,data);

}
return sorted;


}
///////////////////////////////////////////////////////////////////////
void Delete_tree_all(TreeNode * node){

 if(node==NULL) return;
 Delete_tree_all(node->left);
 Delete_tree_all(node->right);
 free(node);
 node =NULL;

}


////////////////////////////////////////////////////////////////////////
void Delete_tree(Tree*tree){

 if( tree->root!=NULL) Delete_tree_all(tree->root);
 tree->root=NULL;
}




///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//static ListNode * sortList(ListNode * node);

List *List_create()
{
    return calloc(1, sizeof(List));
}
////////////////////////////////////////////////////////////////////////////////
void List_remove(List * list, ListNode * node){

 if(list->first == NULL || list->last == NULL){
		printf("List is empty");
		return;
	}

	if(node == NULL){
		printf("Node can't be null");
		return;
	}


    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }
}

//////////////////////////////////////////////////////////////////////////////


void List_add_element(List *list, info  informacja){
 ListNode * node = calloc(1, sizeof(ListNode));
 node->value = informacja;

   if(list->first == NULL){                  //pusta lista
      list->first=node;
      list->last=node;
   }
   else{                                     // do³¹czamy na koniec
      list->last->next=node;
      node->prev=list->last;
      list->last = node;
   }
}
//////////////////////////////////////////////////////////////////////////////////////////
void List_add(List* list, const char *firstName,const char *lastName,const char *birthDate,const long Phone,const char *address){
struct info dane;

dane.firstName=firstName;
dane.lastName=lastName;
dane.birthDate=birthDate;
dane.phone=Phone;
dane.address=address;
List_add_element(list, dane);

}
///////////////////////////////////////////////////////////////////////////////////////////
void setPrevs(List * list){

 if (list->first==NULL) return;
 ListNode * node = list->first;
 while(node->next!=NULL){
    node->next->prev=node;
    node=node->next;
 }

}


////////////////////////////////////////////////////////////////////////////////////////////
struct info List_pop(List * list){                 //wybieramy dane 1 osoby

struct info dane;
if(list->first == NULL) return dane;
else{
    dane = list->first->value;
    List_remove(list, list->first);
    return dane;
}

}
/////////////////////////////////////////////////////////////////////////////////////////////

ListNode * List_find(List * list, char * name) {
  ListNode * node = list->first;
  while(node->next!=NULL && node!=NULL  && strcmp(name,node->value.firstName ) !=0) {
    node = node -> next;
  }
  return node;
}

//////////////////////////////////////////////////////////////////////////
void List_delete_element (List*list, const char*name){

ListNode*node= List_find(list, name);
List_remove(list, node);

}


//////////////////////////////////////////////////////////////////////////////
void List_delete(List *list){                        //usuwanie listy z pamiêci,

  ListNode * node = list->first;
  while(node!=NULL){
        ListNode* next = node -> next;
        List_remove(list,node);
        node = next;
  }
  list->first=NULL;
  list->last=NULL;
  list=NULL;


}


/////////////////////////////////////////////////////////////////////////////
 List* list_sort (List *list) {

    if(list == NULL || list->first == NULL || list->last == NULL) {
        printf("Lista jest pusta\n");
        return NULL;
    }

    List* sortedList = List_create();

    ListNode* maxValue;
    ListNode* cur;

    // until list is empty
    while(list->first != NULL) {


        cur = list->first;
        maxValue = list->first;
        while(cur != NULL) {
            if(strcmp(cur->value.firstName, maxValue->value.firstName) < 0) {
                maxValue = cur;
            }
            cur = cur->next;
        }

        List_add(sortedList, maxValue->value.firstName, maxValue->value.lastName, maxValue->value.birthDate, maxValue->value.phone,  maxValue->value.address);
        List_remove(list, maxValue);
    }
    setPrevs(sortedList);
    return sortedList;
 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void List_show(List * list){

 ListNode * node  = list->first;
 while(node!=NULL){
    printf( node->value.firstName );
    printf(" ");
    node=node->next;
 }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void List_show_end(List * list){
ListNode*node= list->last;

while(node!=NULL){
    printf( node->value.firstName );
    printf(" ");
    node=node->prev;
}


}

