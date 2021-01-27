#include <iostream>
#include <string>
using namespace std;


struct node{
	char op;
	int number;
	node* left;
	node* right;	
	node(int val, char ch){
		number = val;
		op = ch;
		left = NULL;
		right = NULL;
	}
};

int eval(node* tree){
	if(tree->op == '-') return eval(tree->left) - eval(tree->right);
	if(tree->op == '+') return eval(tree->left) + eval(tree->right);
	if(tree->op == '/') return eval(tree->left) / eval(tree->right);
	if(tree->op == '*') return eval(tree->left) * eval(tree->right);
	if(tree->op == NULL) return tree->number;
}

void showNode(node* tree){
	if(tree == NULL){
		return;
	}
	if(tree->number != NULL) cout<<tree->number<<" ";
	if(tree->op != NULL) cout<<tree->op<<" ";
	showNode(tree->left);
	showNode(tree->right);
}


int main(){
	
	node* drzewo = new node(NULL,'*');
	drzewo->left = new node(NULL,'+');
	drzewo->left->left = new node(7,NULL);
	drzewo->left->right = new node(8,NULL);
	drzewo->right = new node(NULL,'-');
	drzewo->right->left = new node(3,NULL);
	drzewo->right->right = new node(2,NULL);
	
	showNode(drzewo);
	cout<<endl<<eval(drzewo);//wynik: 15

	
	return 0;
}
