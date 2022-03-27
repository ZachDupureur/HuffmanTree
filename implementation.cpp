// Created by Zach Dupureur on 3/26/2022.
#include "header.h"

void huffTree::insertLetter(char i, std::string route) {
    numNode* temp = root;
    numNode* parent = root;
    auto* newNode = new charNode(i);
    if (temp == nullptr) { // Tree is empty, create empty root
        root = new numNode;
        insertLetter(newNode->letter, route);
    }
    else { // Tree not empty, continue creation of tree
        for (char j : route) {
            if (j == '1') {
                parent = temp;
                temp = temp->right;
                if (temp == nullptr) {
                    parent->right = new numNode(1);
                    temp = parent->right;
                }
            }
            else if (j == '0') {
                parent = temp;
                temp = temp->left;
                if (temp == nullptr) {
                    parent->left = new numNode(0);
                    temp = parent->left;
                }
            }
        }
        temp->letter = newNode;
    }

    temp = nullptr;
    delete temp;
}

void huffTree::decrypt(std::ifstream & input) { // Takes input stream and outputs message.
    numNode* temp = root;
    char a;
    while (!input.eof() && input.good()) {
        input >> a;
        if (a == '1') {
            temp = temp->right;
            if (temp->letter != nullptr) {
                std::cout << temp->letter->letter << std::endl;
                temp = root;
            }
        }
        else if (a == '0') {
            temp = temp->left;
            if (temp->letter != nullptr) {
                std::cout << temp->letter->letter << std::endl;
                temp = root;
            }
        }
    }
}