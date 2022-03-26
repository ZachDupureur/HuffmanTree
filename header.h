// Created by Zach Dupureur on 3/26/2022.

#ifndef HUFFMANTREE_HEADER_H
#define HUFFMANTREE_HEADER_H


#include <iostream>
#include <iomanip>
#include <fstream>

class Node {
public:
    std::string data{};
    char letter{};
    Node* right;
    Node* left;

    Node(std::string data, char i) {
        this->data = data;
        letter = i;
        right = nullptr;
        left = nullptr;
    }
};


class huffTree {
public:
    Node* root;

    void insertLetter(char i, std::string data);
    bool searchTree(std::string currentString, char& currentLetter);
};

#endif //HUFFMANTREE_HEADER_H
