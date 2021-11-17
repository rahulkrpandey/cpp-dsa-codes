#include <iostream>
using namespace std;

struct Node {
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;
  return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;
  return hl - hr;
}

struct Node *LLRotation(struct Node *p) {
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;
  pl->rchild = p;
  p->lchild = plr;

  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);
  if (root == p) root = pl;
  return pl;
}

struct Node *inSucc(struct Node *p) {
  while (p && p->lchild != NULL) p = p->lchild;
  return p;
}

struct Node *LRRotation(struct Node *p) {
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;
  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;
  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);
  if (root == p) root = plr;
  return plr;
}

struct Node *RRRotation(struct Node *p) {
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;
  pr->lchild = p;
  p->rchild = prl;

  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);
  if (root == p) root = pr;
  return pr;
}

struct Node *RLRotation(struct Node *p) {
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;
  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;
  prl->rchild = pr;
  prl->lchild = p;
  pr->height = NodeHeight(pr);
  p->height = NodeHeight(p);
  prl->height = NodeHeight(prl);
  if (root == p) root = prl;
  return prl;
}

struct Node *RInsert(struct Node *p, int key) {
  struct Node *t = NULL;
  if (p == NULL) {
    t = new Node;
    t->data = key;
    t->height = 1;
    t->lchild = t->rchild = NULL;
    return t;
  }
  if (key < p->data)
    p->lchild = RInsert(p->lchild, key);

  else if (key > p->data)
    p->rchild = RInsert(p->rchild, key);
  p->height = NodeHeight(p);

  if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    return LLRotation(p);

  else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    return LRRotation(p);

  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    return RRRotation(p);

  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    return RLRotation(p);
  return p;
}

struct Node *deleteNode(Node *root, int key) {
  // if (root == NULL)
  if (key < root->data)
    root->lchild = deleteNode(root->lchild, key);

  else if (key > root->data)
    root->rchild = deleteNode(root->rchild, key);

  else {
    if ((root->lchild == NULL) || (root->rchild == NULL)) {
      Node *temp = root->lchild ? root->lchild : root->rchild;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      delete (temp);
    } else {
      // node with two children: Get the inorder
      // successor (smallest in the rchild subtree)
      Node *temp = inSucc(root->rchild);
      // Copy the inorder successor's
      // data to this node
      root->data = temp->data;
      // Delete the inorder successor
      root->rchild = deleteNode(root->rchild, temp->data);
    }
  }

  // If the tree had only one node
  // then return
  if (root == NULL) return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = NodeHeight(root->lchild), (root->rchild);

  // STEP 3: GET THE BALANCE FACTOR
  if (BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == 1)
    return LLRotation(root);

  else if (BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == -1)
    return LRRotation(root);

  else if (BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == -1)
    return RRRotation(root);

  else if (BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == 1)
    return RLRotation(root);
  return root;
}

void preOrder(Node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
  }
}

int main() {
  Node *root = NULL;
  root = RInsert(root, 9);
  root = RInsert(root, 5);
  root = RInsert(root, 10);
  root = RInsert(root, 0);
  root = RInsert(root, 6);
  root = RInsert(root, 11);
  root = RInsert(root, -1);
  root = RInsert(root, 1);
  root = RInsert(root, 2);
  cout << "Preorder traversal of the AVL tree is \n";
  preOrder(root);
  root = deleteNode(root, 10);
  root = deleteNode(root, 11);
  cout << "\nPreorder traversal after deletion of 10 \n";
  preOrder(root);
  return 0;
}
