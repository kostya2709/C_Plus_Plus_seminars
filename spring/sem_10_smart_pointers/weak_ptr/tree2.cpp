#include <iostream>
#include <memory>

template <typename T>
struct Node {

	using NodePtr = std::shared_ptr<Node>;

	T value;
	NodePtr left;
	NodePtr right;
	NodePtr parent;

	Node(T value, NodePtr parent = NodePtr()) : value(value), parent(parent) {}
	Node(T value, NodePtr left, NodePtr right) : value(value), left(left), right(right) {}
};

template <typename T>
struct Tree {
	std::shared_ptr<Node<T>> root;
};

int main() {

	std::cout << "Start\n";
	auto root = std::make_shared<Node<int>>(1);
	auto right_son = std::make_shared<Node<int>>(3, root);
	auto left_son = std::make_shared<Node<int>>(2, root);
	root->left = left_son;
	root->right = right_son;
	Tree<int> tree{root};

	std::cout << "Root: " << root->value << '\n';
	std::cout << "Left son: " << root->left->value << '\n';
	std::cout << "Right son: " << root->right->value << '\n';

	std::cout << "End\n";
}

