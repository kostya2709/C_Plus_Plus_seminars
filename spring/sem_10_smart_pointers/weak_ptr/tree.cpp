#include <iostream>
#include <memory>

template <typename T>
struct Node {

	using NodePtr = std::shared_ptr<Node>;

	T value;
	NodePtr left;
	NodePtr right;

	Node(T value) : value(value) {}
	Node(T value, NodePtr left, NodePtr right) : value(value), left(left), right(right) {}
};

template <typename T>
struct Tree {
	std::shared_ptr<Node<T>> root;
};

int main() {

	auto right_son = std::make_shared<Node<int>>(3);
	auto left_son = std::make_shared<Node<int>>(2);
	auto root = std::make_shared<Node<int>>(1, left_son, right_son);
	Tree<int> tree{root};

	std::cout << "Root: " << root->value << '\n';
	std::cout << "Left son: " << root->left->value << '\n';
	std::cout << "Right son: " << root->right->value << '\n';

}

