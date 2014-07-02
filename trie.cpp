#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	char value; // the character value (a~z)
	bool end; // indicates whether this node completes a word
	Node* children[26]; 
	Node(char vlaue);
	~Node();
};

Node::Node(char value){
	this->value = value;
	for(int i = 0; i < 26; ++i) {
		children[i] = NULL;
	}
}

Node::~Node() {
	// free resources
}
	
	
class Trie{ 
public:
	Trie();
	~Trie();
	void addWord(string word);
	bool searchForWord(string word);
	void deleteWord(string word);
	Node* getRoot();
private:
	Node* root;
};

Trie::Trie() {
	root = new Node(' '); // '' or ' '
	root->end = true;
}

Trie::~Trie() {
	// free resources
}

Node* Trie::getRoot() {
	return root;
}

void Trie::addWord(string word) {
	Node* currentNode = root;
	
	for(int i = 0; i < word.size(); ++i) {
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
		
		// assert(index >= 0)
		if(currentNode->children[index] != NULL) {
			currentNode = currentNode->children[index];
		} else {
			Node* newNode = new Node(currentChar);
			currentNode->children[index] = newNode;
			currentNode = newNode;
		}
		
		if(i == word.size() - 1) {
			currentNode->end = true;
		}
	}
}

bool Trie::searchForWord(string word) {
	Node* currentNode = root;
	for(int i = 0; i < word.size(); ++i) {
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
		// assert(index >= 0);
		
		if(currentNode->children[index] != NULL) {
			currentNode = currentNode->children[index];
		} else {
			return false;
		}
		
		if(i == word.size() - 1 && currentNode->end) {
			return false;
		}
	}
	
	return true;
}

void Trie::deleteWord(string word) {
	Node* currentNode = root;
	
	for(int i = 0; i < word.size(); ++i) {
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
		
		if(currentNode->children[index] != NULL){
			currentNode = currentNode->children[index];
		} else {
			return;
		}
		
		if(i == word.size() - 1 && currentNode->end) {
			currentNode->end = false;
		}
	}
}

// traverse the trie in-order fashion to print the words in lexicographical order
void alphabetize(Node* node, string prefix = "") {
	if(node->end) 
		cout << prefix << endl;
	
	for(int i = 0; i < 26; ++i) {
		if(node->children[i] != NULL) {
			string currentString = prefix + node->children[i]->value;
			alphabetize(node->children[i], currentString);
		}
	}
}

int main() {
	
	Trie* t = new Trie();
	t->addWord("hello");
	t->addWord("world");
	t->addWord("max");
	t->addWord("min");
	t->addWord("maximum");
	
	alphabetize(t->getRoot());
	return 0;
}