#include <iostream>

struct Node {
  double x;
  Node* right;
  Node *left;
  Node() { right = NULL; left = NULL; }
};

class Tree {
public:
  Node* root;
  Tree() { root = NULL; }
  void create(double c);
  int insert(double c,Node *& n );
  void del(double c);
  void show(Node *n);
  void task(int *c,Node* n);
  int getroot();
  
};

void Tree::create(double c) {
  root = new Node();
  root->x = c;
  std::cout << "Added root:" << c << std::endl;
}
int Tree::getroot() {
  if (root != NULL)
    return root->x;
  else
    std::cout << "Tree is empty";
    return 0;
}
void Tree::show(Node * n) {
  {
    if (n != NULL) {
      
      show(n->left);
      std::cout << n->x << "," << std::endl;
      show(n->right);

    }
    
  }
}
int Tree::insert(double c,Node *& n) {
  if (n == NULL) {
    n = new Node;
      n->x = c;
    
  }
  else
  {   
    
    if (c > n->x) {
      insert(c, n->right);
    }
    else
    {
      insert(c, n->left);
    }
  }
  return c;
}

void Tree::del(double c) {
  if (root == NULL) {
    return;
  }
  Node* temp = root;
  Node* parent = NULL;
  while (temp != NULL && temp->x != c) {
    parent = temp;
    if (c > temp->x) {
      temp = temp->right;
    }
    else
    {
      temp = temp->left;
    }
  }
  if (temp != NULL) {
    if (temp->left == NULL || temp->right == NULL) {
      if (temp == parent->right) {
        if (temp->right != NULL) {
          parent->right = temp->right;
        }
        else if (temp->left != NULL) {
          parent->right = temp->left;
        }
      }
      else if (temp == parent->left) {
        if (temp->right != NULL) {
          parent->left = temp->right;
        }
        else if (temp->left != NULL) {
          parent->left = temp->left;
        }
      }
    }
    else if(temp->left != NULL && temp->right != NULL)
    {
      Node* minparent = temp;
      Node* min = temp->right;
      while (min->left != NULL) {
        minparent = min;
        min = min->left;
      }
      
      temp->x = min->x;
      Node* rm = min;
      if (minparent->left==min ) {
        minparent->left = NULL;
        
      }
      else
      {
        minparent->right = min->right;
      }
      delete rm;
    }
  }
}

void Tree::task(int *c,Node* n) {
  
  if (n != NULL) {
    if ((n->left != nullptr && n->right != nullptr) && (n->left->x != 0 && n->right->x != 0)) {
      (*c)++;
    }
    task(c,n->left);
    task(c,n->right);
    

  }
  

}

int main() {
  
  Tree* n = new Tree();

  int k;
  while (true) {
    std::cout << "1-show,2-add,3-show root,4-task,5-delete element" << std::endl;
    std::cin >> k;
    switch (k) {
    case 1:
      n->show(n->root);
      break;
    case 2: {
      std::cout << "Enter element";
      double m;
      
      std::cin >> m;
      if (n->root == NULL) {
        n->create(m);
      }
      else {
        n->insert(m, n->root);
      }
      break;
    }
    case 3:
      std::cout << "Root:" << n->getroot() << std::endl;
      break;
    case 4: {
      int count = 0;
      n->task(&count, n->root);
      std::cout << "Count:" << count << std::endl;
      break;
    }
    case 5: {
          double m;
      std::cout << "Enter element" << std::endl;
      std::cin >> m;
      n->del(m);
      break;
    }
    default:
      return 0;
    }
  }
}