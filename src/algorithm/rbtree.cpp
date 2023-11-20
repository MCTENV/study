#include <iostream>

enum class Color { RED, BLACK };

struct Node {
  int key;
  Color color;
  Node* parent;
  Node* left;
  Node* right;

  Node(int k)
      : key(k),
        color(Color::RED),
        parent(nullptr),
        left(nullptr),
        right(nullptr) {}
};

class RedBlackTree {
 private:
  Node* root;

  // 红黑树的插入操作
  void insertFixup(Node* newNode) {
    while (newNode->parent && newNode->parent->color == Color::RED) {
      if (newNode->parent == newNode->parent->parent->left) {
        Node* uncle = newNode->parent->parent->right;
        if (uncle && uncle->color == Color::RED) {
          newNode->parent->color = Color::BLACK;
          uncle->color = Color::BLACK;
          newNode->parent->parent->color = Color::RED;
          newNode = newNode->parent->parent;
        } else {
          if (newNode == newNode->parent->right) {
            newNode = newNode->parent;
            leftRotate(newNode);
          }
          newNode->parent->color = Color::BLACK;
          newNode->parent->parent->color = Color::RED;
          rightRotate(newNode->parent->parent);
        }
      } else {
        Node* uncle = newNode->parent->parent->left;
        if (uncle && uncle->color == Color::RED) {
          newNode->parent->color = Color::BLACK;
          uncle->color = Color::BLACK;
          newNode->parent->parent->color = Color::RED;
          newNode = newNode->parent->parent;
        } else {
          if (newNode == newNode->parent->left) {
            newNode = newNode->parent;
            rightRotate(newNode);
          }
          newNode->parent->color = Color::BLACK;
          newNode->parent->parent->color = Color::RED;
          leftRotate(newNode->parent->parent);
        }
      }
    }
    root->color = Color::BLACK;
  }

  // 左旋转操作
  void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (!x->parent) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  // 右旋转操作
  void rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (!x->parent) {
      root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

 public:
  RedBlackTree() : root(nullptr) {}

  // 插入操作
  void insert(int key) {
    Node* newNode = new Node(key);
    Node* parent = nullptr;
    Node* current = root;

    while (current) {
      parent = current;
      if (key < current->key) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    newNode->parent = parent;
    if (!parent) {
      root = newNode;
    } else if (key < parent->key) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }

    insertFixup(newNode);
  }

  // 搜索操作
  Node* search(int key) {
    Node* current = root;

    while (current && current->key != key) {
      if (key < current->key) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    return current;
  }

  // 打印红黑树（中序遍历）
  void printInorder(Node* node) {
    if (node) {
      printInorder(node->left);
      std::cout << node->key << " ";
      printInorder(node->right);
    }
  }

  // 打印红黑树
  void printTree() {
    printInorder(root);
    std::cout << std::endl;
  }
};

int main(int argc, char** argv) {
  RedBlackTree tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);

  tree.printTree();

  Node* searchNode = tree.search(30);
  if (searchNode) {
    std::cout << "Found node with key 30" << std::endl;
  } else {
    std::cout << "Node with key 30 not found" << std::endl;
  }

  return 0;
}