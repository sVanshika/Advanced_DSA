/*
Ques: WAP to implement a K-way merge sort algorithm. Generate an initial file 
    containing random integers between a range of (-20 to 50000) with the total 
    count of values in it must be 60000. Consider this file content could not 
    be loaded into RAM as RAM size is too small to accommodate only 5000 
    elements at once. Determine the suitable K value and sort the sequence using
    K-way merge sort. 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <fstream>
using namespace std;

// Objective: creating the main file 
void createMainFile(string mainFile, int totalSize, int rangeMin, int rangeMax){
    srand(time(0));

    // creating file and opening in write mode
    ofstream myFile(mainFile);
    for(int i=0; i<totalSize; i++){
        myFile << -rangeMin + rand()%rangeMax << endl;
    }
    myFile.close();
}

// Objective: creating n files containing chunks from main file
void createFileChunks(string mainFileName, int totalSize, int ramSize){
    int numFiles = totalSize / ramSize;
    string line, fileName;
    
    // opening main file in read mode
    ifstream mainFile(mainFileName);

    for(int i=0; i<numFiles; i++){
        fileName = "file" + to_string(i+1) + ".txt";
        // creating temp files and opening in write mode
        ofstream tempFile(fileName);

        for(int i=0; i<ramSize; i++){
            getline(mainFile, line);
            tempFile << line << endl;
        }

        tempFile.close();
    }

    mainFile.close();
}

int main(){

    int totalSize=60000, ramSize=5000, rangeMin=-20, rangeMax=50000;
    string mainFile = "file.txt";

    // createMainFile(mainFile, totalSize, rangeMin, rangeMax);
    // createFileChunks(mainFile, totalSize, ramSize);

    return 0;
}