// Created by Zach Dupureur on 3/26/2022.

#ifndef HUFFMANTREE_HEADER_H
#define HUFFMANTREE_HEADER_H


#include <iostream>
#include <iomanip>
#include <fstream>

class charNode {
public:
    char letter{};

    explicit charNode(char i) {
        letter = i;
    }
};

class numNode {
public:
    int num;
    numNode* right;
    numNode* left;
    charNode* letter;
    numNode() {
        right = nullptr;
        left = nullptr;
        letter = nullptr;
        num = 9;
    }
    explicit numNode(int i) {
        right = nullptr;
        left = nullptr;
        letter = nullptr;
        num = i;
    }
};


class huffTree {
public:
    numNode* root = nullptr;

    void insertLetter(char i, std::string route);
    void decrypt(std::ifstream & input);
};

#endif //HUFFMANTREE_HEADER_H
