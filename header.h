// Created by Zach Dupureur on 3/26/2022.

#ifndef HUFFMANTREE_HEADER_H
#define HUFFMANTREE_HEADER_H


#include <iostream>
#include <iomanip>
#include <fstream>

class charNode {
public:
    char letter{};

    charNode(char i) {
        letter = i;
    }
};

class numNode {
public:
    int num;
    numNode* right;
    numNode* left;
    charNode* letter{};
    numNode() {
        right = nullptr;
        left = nullptr;
        num = 0;
    }
    explicit numNode(int i) {
        right = nullptr;
        left = nullptr;
        num = i;
    }
};


class huffTree {
public:
    numNode* root = new numNode();

    void insertLetter(char i, std::string data);
    bool searchTree(std::string currentString, char& currentLetter);
};

#endif //HUFFMANTREE_HEADER_H
