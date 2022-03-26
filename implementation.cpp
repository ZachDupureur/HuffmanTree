// Created by Zach Dupureur on 3/26/2022.

#include <utility>

#include "header.h"

void huffTree::insertLetter(char i, std::string data) {
    Node* newNode = new Node(std::move(data), i);
    Node* temp = root;
    if (temp == nullptr) { // Tree is empty, make new node root
        root = newNode;
    }
    else { // Tree not empty
        while (temp != nullptr) { // Search for leaf
            if (temp->data == newNode->data) { // Node found, but duplicate
                temp = nullptr;
            }
            else {
                if (newNode->data < temp->data) { // If smaller go to left
                    if (temp->left == nullptr) { // Add node if nullptr
                        temp->left = newNode;
                        temp = nullptr;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else {
                    if (newNode->data > temp->data) { // If larger go to right
                        if (temp->right == nullptr) { // Add node if nullptr
                            temp->right = newNode;
                            temp = nullptr;
                        }
                        else {
                            temp = temp->right;
                        }
                    }
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