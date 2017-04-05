#include <SPLAY_shopping.h>

node_product_t *zig_left_product(node_product_t* node_up){
	node_product_t* aux = node_up->father;
	aux->right = node_up->left;
	if (node_up->left != NULL)
		node_up->left->father = aux;
	node_up->father = aux->father;
	if (node_up->father != NULL){
		if (node_up->father->code > node_up->code)
			node_up->father->left = node_up;
		else
			node_up->father->right = node_up;
	}
	node_up->left = aux;
	aux->father = node_up;
	return node_up;
}

node_product_t *zig_right_product(node_product_t* node_up){
	node_product_t* aux = node_up->father;
	aux->left = node_up->right;
	if (node_up->right != NULL)
		node_up->right->father = aux;
	node_up->father = aux->father;
	if (node_up->father != NULL){
		if (node_up->father->code > node_up->code)
			node_up->father->left = node_up;
		else
			node_up->father->right = node_up;
	}
	node_up->right = aux;
	aux->father = node_up;
	return node_up;
}

node_product_t* splay_product(node_product_t* new_root){
	while (new_root->father != NULL){//Quando o pai for nullo ja é a raiz
		if (new_root->father->code > new_root->code){ // pai > filho
			/*zig*/
			if (new_root->father->father == NULL){// avo = NULL				
				new_root = zig_right_product(new_root); // gira direita filho
			}
			/*zig-zig*/
			else if (new_root->father->father->code > new_root->father->code){// vo > pai
				new_root->father = zig_right_product(new_root->father);// gira esquerda pai
				//new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_right_product(new_root); // gira esquerda filho
			}
			/*zig-zag*/
			else { // vo < pai
				new_root = zig_right_product(new_root); //gira esquerda filho;
				//new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_left_product(new_root); // gira esquerda filho;
			}
		}
		else { // pai < filho
			/*zig*/
			if (new_root->father->father == NULL){ // vo == NULL
				new_root = zig_left_product(new_root); // gira direita filho
			}
			/*zig-zag*/
			else if (new_root->father->father->code > new_root->father->code){ // vo > pai
				new_root = zig_left_product(new_root); //gira direita filho
				//new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_right_product(new_root); // gira esquerda filho
			}
			/*zig-zig*/
			else{ // vo < pai
				new_root->father = zig_left_product(new_root->father); // gira direita pai
				//new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_left_product(new_root); // gira direita filho
			}
		}	 
	}
	return new_root;
} 


node_category_t *zig_left_category(node_category_t* node_up){
	node_category_t* aux= node_up->father;
	aux->right = node_up->left;
	if (node_up->left != NULL)
		node_up->left->father = aux;
	node_up->father = aux->father;
	if (node_up->father != NULL){
		if (node_up->father->code > node_up->code)
			node_up->father->left = node_up;
		else
			node_up->father->right = node_up;
	}
	node_up->left = aux;
	aux->father = node_up;
	return node_up;
}

node_category_t *zig_right_category(node_category_t* node_up){
	node_category_t* aux= node_up->father;
	aux->left = node_up->right;
	if (node_up->right != NULL)
		node_up->right->father = aux;
	node_up->father = aux->father;
	if (node_up->father != NULL){
		if (node_up->father->code > node_up->code)
			node_up->father->left = node_up;
		else
			node_up->father->right = node_up;
	}
	node_up->right = aux;
	aux->father = node_up;
	return node_up;
}

node_category_t* splay_category(node_category_t* new_root){
	while (new_root->father != NULL){//Quando o pai for nullo ja é a raiz
		if (new_root->father->code > new_root->code){ // pai > filho
			/*zig*/
			if (new_root->father->father == NULL){// avo = NULL				
				new_root = zig_right_category(new_root); // gira direita filho
			}
			/*zig-zig*/
			else if (new_root->father->father->code > new_root->father->code){// vo > pai
				new_root->father = zig_right_category(new_root->father);// gira esquerda pai
				//new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_right_category(new_root); // gira esquerda filho
			}
			/*zig-zag*/
			else { // vo < pai
				new_root = zig_right_category(new_root); //gira esquerda filho;
				//new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_left_category(new_root); // gira esquerda filho;
			}
		}
		else { // pai < filho
			/*zig*/
			if (new_root->father->father == NULL){ // vo == NULL
				new_root = zig_left_category(new_root); // gira direita filho
			}
			/*zig-zag*/
			else if (new_root->father->father->code > new_root->father->code){ // vo > pai
				new_root = zig_left_category(new_root); //gira direita filho
				//new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_right_category(new_root); // gira esquerda filho
			}
			/*zig-zig*/
			else{ // vo < pai
				new_root->father = zig_left_category(new_root->father); // gira direita pai
				//new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_left_category(new_root); // gira direita filho
			}
		}	 
	}
	return new_root;
} 

