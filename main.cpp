// Created by Zach Dupureur on 03/26/2022

#include "header.h"

bool searchTree(std::string basicString, char letter);

int main() {
    huffTree huffTree{};
    std::ifstream huffmanCode, huffmanMessage;
    std::string file_code, file_translated, file_cypher, currentNum;
    char currentLetter;

    try {

        while(true) {
            std::cout << "Welcome to the Huffman Tree Program.\nPlease enter the file path for your Huffman key.\n";
            std::cin >> file_code;
            if (std::cin.fail()) {
                std::cerr << "Please enter a valid value.\n";
                clearCin();
            }
            else {
                break;
            }
        }
        clearCin();
        while (true) {
            std::cout << "\nPlease enter the file path for your cypher.\n";
            std::cin >> file_cypher;
            if (std::cin.fail()) {
                std::cerr << "Please enter a valid value.\n";
                clearCin();
            }
            else {
                break;
            }

        }

        while (!std::cin) {
            std::cin >> file_cypher;
        }
        clearCin();

        huffmanCode.open(file_code);
        huffmanMessage.open(file_cypher);
        if (huffmanCode.is_open()) {
        std::cout << "File " << file_code << " is open...\n";
        }
        else {
            std::cerr << "Could not open file " << file_code << " Please try again...\n";
            return -1;
        }

        if (huffmanMessage.is_open()) {
            std::cout << "File " << file_cypher << " is open...\n";
        }
        else {
            std::cerr << "Could not open " << file_cypher << ". Please try again...\n";
            return -1;
        }

        while (!huffmanCode.eof() && huffmanCode.good()) {
            huffmanCode >> currentLetter >> currentNum;
            huffTree.insertLetter(currentLetter, currentNum);
        }

        huffTree.decrypt(huffmanMessage);

    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    huffmanCode.close();
    huffmanMessage.close();


    std::cout << "Done!" << std::endl;

    return 0;
}


/* TESTING BELOW
 *
 * Welcome to the Huffman Tree Program.
Please enter the file path for your Huffman key.
C:\Users\Zach\Desktop\HuffmanCode.txt

Please enter the file path for your cypher.
C:\Users\Zach\Desktop\HuffmanMessage.txt
File C:\Users\Zach\Desktop\HuffmanCode.txt is open...
File C:\Users\Zach\Desktop\HuffmanMessage.txt is open...
Y
O
U
A
R
E
T
H
E
G
R
E
A
T
E
S
T
Done!

Process finished with exit code 0

 */

