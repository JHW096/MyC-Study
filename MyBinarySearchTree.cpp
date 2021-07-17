#include<iostream>
#include<string>
using namespace std;

template<class T>
struct node {
	T data;
	struct node<T>* left = nullptr;
	struct node<T>* right = nullptr;
};

template<class T>
class Tree {
private:
	struct node<T>* root;
	int count = 0;

	node<T>* new_node(T item) {
		node<T>* Node = new node<T>();
		if (Node == nullptr) {
			cout << "Error : New Node.." << endl;
			exit(1);
		}
		Node->left = nullptr;
		Node->right = nullptr;
		Node->data = item;
		count++;
		return Node;
	}

	node<T>* min_value(node<T>* Node) {
		node<T>* current = Node;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	node<T>* search(node<T>* s_node, T item) {
		if (s_node == nullptr) {
			return nullptr;
		}
		if (s_node->data == item) {
			return s_node;
		}
		else if (s_node->data > item) {
			return search(s_node->left, item);
		}
		else {
			return search(s_node->right, item);
		}
	}

	node<T>* add(node<T>* node, T item) {
		if (node == nullptr) {
			return new_node(item);
		}

		if (node->data == item) {
			cout << "Error : Data exist.." << endl;
			exit(1);
		}

		else if (node->data > item) {
			node->left = add(node->left, item);
		}
		else if (node->data < item) {
			node->right = add(node->right, item);
		}
		return node;
		count++;
	}

	node<T>* remove(node<T>* Node, T item) {
		if (Node == nullptr) {
			return Node;
		}

		if (Node->data > item) {
			Node->left = remove(Node->left, item);
		}
		else if (Node->data < item) {
			Node->right = remove(Node->right, item);
		}
		else {
			if (Node->left == nullptr) {
				node<T>* temp = Node->right;
				delete(Node);
				count--;
				return temp;
			}
			else if (Node->right == nullptr) {
				node<T>* temp = Node->right;
				delete(Node);
				count--;
				return temp;
			}
			node<T>* temp = min_value(Node->right);
			Node->data = temp->data;
			Node->right = remove(Node->right, temp->data);
		}
		return Node;

	}

	void inorder(node<T>* node) {
		if (node) {
			inorder(node->left);
			cout << node->data << "->"; 
			inorder(node->right);
		}
	}

	void preorder(node<T>* node) {
		if (node) {
			cout << node->data << "->";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(node<T>* node) {
		if (node) {
			postorder(node->left);
			postorder(node->right);
			cout << node->data << "->";
		}
	}

public:

	Tree() {
		this->root = nullptr;
	}
	~Tree() {
		cout << "remove Tree Class.." << endl;
	}

	void add(T item) {
		this->root = add(this->root, item);
	}

	void remove(T item) {
		this->root = remove(this->root, item);
	}

	bool exist(T item) {
		if (search(this->root, item) == nullptr) {
			return false;
		}
		return true;
	}

	int size() {
		return this->count;
	}

	void inorder() {
		inorder(this->root);
		cout << "Nullptr.." << endl;
	}

	void preorder() {
		preorder(this->root);
		cout << "Nullptr.." << endl;
	}

	void postorder() {
		postorder(this->root);
		cout << "Nullptr.." << endl;
	}

};

int main(void) {

	Tree<int>* tree = new Tree<int>();
	tree->add(30);
	tree->add(20);
	tree->add(10);
	tree->add(40);
	tree->add(50);
	tree->add(60);
	bool A = tree->exist(50);
	cout << A << endl;
	tree->remove(50);
	A = tree->exist(50);
	cout << A << endl;
	tree->inorder();
	cout << endl;
	tree->preorder();
	cout << endl;
	tree->postorder();
	cout << tree->size() << endl;
	
	delete(tree);
}