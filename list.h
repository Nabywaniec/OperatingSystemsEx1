#ifndef MYLIB
#define MYLIB

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

Tree *Tree_create(void);

void Tree_add_element2(Tree*, info);

void Tree_add_element(Tree*, info);

void Tree_show2(TreeNode*);

void Tree_show(Tree*);

void Tree_add(Tree*, const char*, const char*, const char*, const long ,const char* );

TreeNode *Tree_search(Tree*, const char*);

TreeNode * Tree_smallest(Tree*);

TreeNode* Tree_biggest(Tree*);

TreeNode * Max(TreeNode*);

TreeNode * Min(TreeNode*);

TreeNode * Successor(TreeNode *);

TreeNode * Predessor(TreeNode*);

TreeNode * Delete (Tree* , TreeNode*);

Tree * Tree_sort(Tree*);

void Delete_tree_all (TreeNode *);

void Delete_tree(Tree*);

List * List_create(void);

void List_remove (List*, ListNode*);

void List_add_element(List*, info);

void List_add(List* , const char*, const char*, const char*, long, const char *);

void setPrevs(List *);

info List_pop(List*);

ListNode * List_find(List*, const char *);

void List_delete_element(List *, const char*);

void List_delete(List*);

List * List_sort(List*);

void List_show(List*);

void List_show_end(List*);

#endif
