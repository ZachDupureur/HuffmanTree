// Created by Zach Dupureur on 03/26/2022

#include "header.h"

bool searchTree(std::string basicString, char letter);

int main() {
    huffTree huffTree{};
    std::ifstream huffmanCode, huffmanMessage;
    std::ofstream huffmanTranslated;
    std::string file_code, file_translated, file_cypher, currentNum;
    char currentLetter;


    file_code = "HuffmanCode.txt";
    file_cypher = "HuffmanMessage.txt";
    try {
        huffmanCode.open(file_code);
        huffmanMessage.open(file_cypher);
        if (huffmanCode.is_open()) {
        std::cout << "File " << file_code << " is open...\n";
        }
        else {
            std::cout << "Could not open file. Please try again...\n";
            return -1;
        }

        if (huffmanMessage.is_open()) {
            std::cout << "File " << file_cypher << " is open...\n";
        }
        else {
            std::cout << "Could not open " << file_cypher << ". Please try again...\n";
            return -1;
        }

        while (!huffmanCode.eof()) {
            huffmanCode >> currentLetter >> currentNum;
            huffTree.insertLetter(currentLetter, currentNum);
        }


        std::string currentString;
        char a;
        while (!huffmanMessage.eof() && huffmanMessage.good()) { // Translating message using a loop
            bool found = false;
            while (!found && !huffmanMessage.eof()) {
                huffmanMessage >> a;
                currentString.append(1, a);
                found = huffTree.searchTree(currentString, a);
            }
            if (!huffmanMessage.eof()) {
                std::cout << a << " : " << currentString << std::endl;
                currentString = "";
            }
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    huffmanCode.close();
    huffmanMessage.close();
    huffmanTranslated.close();

    std::cout << "Done!" << std::endl;

    return 0;
}


