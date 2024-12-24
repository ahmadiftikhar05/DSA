
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
// Node class represents each node in the Huffman Tree.
class Node {
public:
	char data;
	int freq;
	Node* left;
	Node* right;
	// Constructor to initialize a node with character and frequency.
	Node(char data, int freq) {
		this->data = data;
		this->freq = freq;
		left = right = nullptr;
	}
};
// Compare class for priority queue to order nodes by frequency.
class Compare {
public:
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};
// Function to build a frequency table from the input string.
unordered_map<char, int> buildFrequencyTable(const string& str) {
	unordered_map<char, int> freqTable;
	for (char ch : str) {
		freqTable[ch]++;
	}
	return freqTable;
}
// Function to build the Huffman Tree from the frequency table.
Node* buildHuffmanTree(unordered_map<char, int>& freqTable) {
	priority_queue<Node*, vector<Node*>, Compare> pq;
	// Create a leaf node for each character and add it to the priority queue.
	for (auto pair : freqTable) {
		pq.push(new Node(pair.first, pair.second));
	}
	// Build the tree by merging nodes until only one remains in the queue.
	while (pq.size() > 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();
		// Create a new internal node with combined frequency.
		Node* newNode = new Node('\0', left->freq + right->freq);
		newNode->left = left;
		newNode->right = right;
		pq.push(newNode);
	}
	return pq.top(); // Return the root of the Huffman Tree.
}
// Recursive function to generate Huffman codes for each character.
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
	if (!root) return; // Base case: empty node.
	// If leaf node is reached, store the code for the character.
	if (!root->left && !root->right) {
		huffmanCodes[root->data] = code;
	}
	// Traverse left and right subtrees with updated codes.
	generateHuffmanCodes(root->left, code + "0", huffmanCodes);
	generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}
// Function to encode the input string using Huffman codes.
string encodeString(const string& str, unordered_map<char, string>& huffmanCodes) {
	string encodedString = "";
	for (char ch : str) {
		encodedString += huffmanCodes[ch];
	}
	return encodedString;
}
// Function to decode the encoded string using the Huffman Tree.
string decodeString(const string& encodedString, Node* root) {
	string decodedString = "";
	Node* current = root;
	for (char bit : encodedString) {
		current = (bit == '0') ? current->left : current->right;
		if (!current->left && !current->right) {
			decodedString += current->data;
			current = root;
		}
	}
		return decodedString;
	}
    int main() {
		string input;
		cout << " HUFFMAN CODING PROGRAM " << endl;
		cout << "\nPlease enter the input string to encode:";
		getline(cin, input);
		// Build frequency table.
		unordered_map<char, int> freqTable = buildFrequencyTable(input);
		cout << "\n FREQUENCY TABLE " << endl;
		for (auto pair : freqTable) {
			cout << pair.first << ": " << pair.second << endl;
		}
		// Build Huffman Tree.
		Node* root = buildHuffmanTree(freqTable);
		// Generate Huffman codes.
		unordered_map<char, string> huffmanCodes;
		generateHuffmanCodes(root, "", huffmanCodes);
		cout << "\n HUFFMAN CODING " << endl;
		for (auto pair : huffmanCodes) {
			cout << pair.first << ": " << pair.second << endl;
		}
		// Encode the input string.
		string encodedString = encodeString(input, huffmanCodes);
		cout << "\nOriginal String: " << input << endl;
		cout << "\nEncoded String: " << encodedString << endl;
		// Decode the encoded string.
		string decodedString = decodeString(encodedString, root);
		cout << "Decoded String: " << decodedString << endl;
		// Analyze compression.
		int originalSize = input.length() * 8;
		int compressedSize = encodedString.length();
		cout << "\nCompression Analysis:\n";
		cout << "Original Size: " << originalSize << " bits\n";
		cout << "Compressed Size: " << compressedSize << " bits\n";
		// Verify if the decoding is correct.
		if (decodedString == input) {
			cout << "\nThe decoded string matches the original string.\n";
		}
		else {
			cout << "\nError: Decoded string does not match the original string.\n";
		}
		return 0;
	}