#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;	
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void showNode(node* tree){//preorder
	if(tree == NULL){
		return;
	}
	cout<<tree->data<<" ";
	showNode(tree->left);
	showNode(tree->right);
}
void showNodeIn(node* tree){
	if(tree == NULL){
		return;
	}
	showNodeIn(tree->left);
	cout<<tree->data<<" ";
	showNodeIn(tree->right);
}

void showNodePost(node* tree){
	if(tree == NULL){
		return;
	}
	showNodeIn(tree->left);
	showNodeIn(tree->right);
	cout<<tree->data<<" ";
}

bool search(node* tree, int x){//zadanie 1
	if(tree == NULL){
		return false;
	}
	if(tree->data == x) return true; 
	search(tree->left,x);
	search(tree->right,x);
}

//zadanie 2.a
int counterNode=0;
int node_count(node* tree){
	if(tree == NULL){
		return counterNode;
	}
	if(tree->left != NULL || tree->right != NULL) counterNode++;
	node_count(tree->left);
	node_count(tree->right);
}

//zadanie 2.b
int counterLeaves=0;
int leaves_count(node* tree){
	if(tree == NULL){
		return counterLeaves;
	}
	if(tree->left == NULL && tree->right == NULL) counterLeaves++;
	leaves_count(tree->left);
	leaves_count(tree->right);
}

//zadanie 2.c
int counterRight=0;
int right_children_count(node* tree){
	if(tree == NULL){
		return counterRight;
	}
	if(tree->right != NULL) counterRight++;
	right_children_count(tree->left);
	right_children_count(tree->right);
}

//zadanie 2.
int leftH;
int rightH;
int tree_height(node* tree){
	if(tree == NULL){
		return 0;
	}
	leftH = tree_height(tree->left);
	rightH = tree_height(tree->right);
	return max(leftH,rightH)+1;	
}

//zadanie 3
bool is_balanced(node* tree){
	int l = tree_height(tree->left);
    int p = tree_height(tree->right);
	if(l == p){
		return true;
	}else{
		return false;
	}	
}

//zadanie 4
bool jest = true;
bool is_BST(node* tree){
	if(tree == NULL){
		return jest;
	}
	if(tree->left != NULL){
		if(tree->data > tree->left->data) jest = false;	
	}
	if(tree->right != NULL){
		if(tree->data > tree->right->data) jest = false;	
	}
	is_BST(tree->left);
	is_BST(tree->right);
}

//zadanie 5
void delete_leaves(node* &tree){
	
	if(tree == NULL){
		return;
	}else{
		if(tree->left || tree->right){
			delete_leaves(tree->left);
			delete_leaves(tree->right);
		}else{
			tree = NULL;
			delete tree;
			return;
		}
	}	
}

//zadanie 6

void preorder(node* tree){
	if(tree == NULL){
		return;
	}
	if(tree->left != 0 && tree->data - tree->left->data < 2){
		tree->left->data += 2;
	}
	preorder(tree->left);
	preorder(tree->right);
}
void inorder(node* tree){
	if(tree == NULL){
		return;
	}
	preorder(tree->left);
	if(tree->left != 0 && tree->data - tree->left->data < 2){
		tree->left->data += 2;
	}
	preorder(tree->right);
}
void postorder(node* tree){
	if(tree == NULL){
		return;
	}
	preorder(tree->left);
	preorder(tree->right);
	if(tree->left != 0 && tree->data - tree->left->data < 2){
		tree->left->data += 2;
	}
}

void preorderB(node* &tree){
	if(tree == NULL){
		return;
	}
	if(tree->left == 0){
		tree->right = 0;
	}
	preorder(tree->left);
	preorder(tree->right);
}
void inorderB(node* &tree){
	if(tree == NULL){
		return;
	}
	preorder(tree->left);
	if(tree->left == 0){
		tree->right = 0;
	}
	preorder(tree->right);
}
void postorderB(node* &tree){
	if(tree == NULL){
		return;
	}
	preorder(tree->left);
	preorder(tree->right);
	if(tree->left == 0){
		tree->right = 0;
	}
}

//zadanie 8

node* mirror_tree(node* tree){
	if(tree != NULL){
		node* scho;
		mirror_tree(tree->left);
		mirror_tree(tree->right);
		scho = tree->left;
		tree->left = tree->right;
		tree->right = scho;
		
	}
}

//zadanie 9

void print_tree(node* tree, int depth=0, char prefix='.'){
	if(tree == NULL){
		depth--;
		return;
	}
	if(depth != 0){
		for(int i=0;i<depth;++i){
			cout<<prefix;
		}
	}
	cout<<tree->data<<endl;
	depth++;
	print_tree(tree->left, depth);
	print_tree(tree->right, depth);
}

int main(){
	
	node* drzewo = new node(1);
	drzewo->left = new node(2);
	drzewo->right = new node(3);
	drzewo->left->left = new node(4);
	drzewo->left->right = new node(5);


	showNode(drzewo);
	if(search(drzewo , 3)){//wynik: jest
		cout<<"jest"<<endl;
	}else{
		cout<<"nie jest"<<endl;
	}
	cout<<"wierzcholki "<<node_count(drzewo)<<endl;//wynik: 2
	cout<<"liscie "<<leaves_count(drzewo)<<endl;//wynik: 3
	cout<<"prawi "<<right_children_count(drzewo)<<endl;//wynik: 2
	cout<<"wysokosc "<<tree_height(drzewo)<<endl;//wynik: 2
	if(is_balanced(drzewo) == true){//wynik: nie jest
		cout<<"jest balanced"<<endl;	
	} else{
		cout<<"nie jest balanced"<<endl;
	}
	if(is_BST(drzewo) == true){//wynik: jest
		cout<<"jest BST"<<endl;	
	} else{
		cout<<"nie jest BST"<<endl;
	}
	delete_leaves(drzewo);
	showNode(drzewo);
	
	cout<<endl<<"----------"<<endl;
	
	//zadanie 6
	
	node* drze = new node(10);
	drze->left = new node(5);
	drze->left->left = new node(4);
	drze->left->left->left = new node(0);
	drze->left->right = new node(6);
	drze->left->right->right = new node(7);
	drze->left->right->right->right = new node(9);
	drze->right = new node(20);
	drze->right->left = new node(15);
	drze->right->left->left = new node(13);
	drze->right->right = new node(30);
	
	
	//dla a
	cout<<endl<<"przed ";
	showNode(drze);
	preorder(drze);
	cout<<endl<<"pre   ";
	showNode(drze);
	inorder(drze);
	cout<<endl<<"in    ";
	showNodeIn(drze);
	postorder(drze);
	cout<<endl<<"post  ";
	showNodePost(drze);
	
	//dla b
	
	cout<<endl<<"-----------";
	
	node* drze2 = new node(10);
	drze2->left = new node(5);
	drze2->left->left = new node(4);
	drze2->left->left->left = new node(0);
	drze2->left->right = new node(6);
	drze2->left->right->right = new node(7);
	drze2->left->right->right->right = new node(9);
	drze2->right = new node(20);
	drze2->right->left = new node(15);
	drze2->right->left->left = new node(13);
	drze2->right->right = new node(30);
	
	cout<<endl<<"przed ";
	showNode(drze2);
	preorderB(drze2);
	cout<<endl<<"pre   ";
	showNode(drze2);
	inorderB(drze2);	
	cout<<endl<<"in    ";
	showNodeIn(drze2);
	postorderB(drze2);
	cout<<endl<<"post  ";
	showNodePost(drze2);
	cout<<endl;
	
	//zadanie 7
	//aby preorder i inorder wyœwietli³y to samo to drzewo musi mieæ tylko prawych synów
	node* drze4 = new node(1);
	drze4->right = new node(4);
	drze4->right->right = new node(5);
	showNode(drze4);//wynik preorder: 1 4 5
	cout<<endl;
	showNodeIn(drze4);//wynik inorder 1 4 5
	
	//zadanie 8
	
	node* drze3 = new node(1);
	drze3->left = new node(2);
	drze3->right = new node(3);
	drze3->left->left = new node(4);
	cout<<endl<<"przed ";//1 2 4 3
	showNode(drze3);
	mirror_tree(drze3);
	cout<<endl<<"po ";//1 3 2 4
	showNode(drze3);
	
	cout<<endl;
	print_tree(drze2);
	/*Wynik:10
	.5
	..10
	...0
	..6
	...7
	....9
	.20
	..15
	...13
	..30
	*/
	
	
	
	
	return 0;
}
