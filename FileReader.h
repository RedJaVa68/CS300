//
// Created by jacob on 9/18/21.
//

#ifndef PROJECTONE_FILEREADER_H
#define PROJECTONE_FILEREADER_H


#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept>

class FileReader {

public:

    //Used to get the lines of a file
    std::vector<std::string> getLines(std::string file);
    //Used to get a string that has been splitted by delimiter
    std::vector<std::string> split(std::string contents, std::string delimiter);

private:

    //Used to get the entire file
    std::string readFile(std::string file);

};


#endif //PROJECTONE_FILEREADER_H
