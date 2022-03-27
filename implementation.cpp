// Created by Zach Dupureur on 3/26/2022.
#include "header.h"

void huffTree::insertLetter(char i, std::string route) {
    numNode* temp = root;
    numNode* parent = root;
    auto* newNode = new charNode(i);
    if (temp == nullptr) { // Tree is empty, create empty root
        root = new numNode;
    }
    else { // Tree not empty
        for (char j : route) {
            if (j == 1) {
                temp = temp->right;
                if (temp == nullptr) {
                    parent->right = new numNode(1);
                }
            }
            else if (j == 0) {
                temp = temp->left;
                if (temp == nullptr) {
                    parent->left = new numNode(0);
                }
            }
        }


    }

    temp = nullptr;
    delete temp;
}

bool huffTree::searchTree(std::string currentString, char& currentLetter) {
    Node* temp = root;
    while (temp != nullptr) {
        if (currentString == temp->data) {
            currentLetter = temp->letter;
            return true;
        }
        else if (currentString > temp->data) {
            temp = temp->right;
        }
        else if (currentString < temp->data) {
            temp = temp->left;
        }
    }
    return false;
}