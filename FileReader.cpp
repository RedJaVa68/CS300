//
// Created by jacob on 9/18/21.
//

#include "FileReader.h"

/**
 * Splits any given string by delimiter
 * @param contents
 * @param delimiter
 * @return a vector of contents that were splitted
 */
std::vector<std::string> FileReader::split(std::string contents, std::string delimiter) {

    size_t pos = 0;

    std::vector<std::string> lines;

    //Traverses through all contents of string
    while((pos = contents.find(delimiter)) != std::string::npos){

        //Adds the content found between start to the delimiter
        lines.push_back(contents.substr(0, pos));

        //Erases the contents up to the next element
        contents.erase(0, pos + delimiter.length());

    }

    //Adds the last content of split
    lines.push_back(contents.substr(0, pos));

    return lines;

}

/**
 * Gets each line in a file
 * @param file the path to a file
 * @return a vector of strings of each line
 */
std::vector<std::string> FileReader::getLines(std::string file) {

    //Grabs the contents of the file
    std::string contents = readFile(file);

    //Returns a vector splitted by a new line
    return split(contents, "\n");

}

/**
 * Gets the entire file
 * @param file the path to a file
 * @return the string of the file
 */
std::string FileReader::readFile(std::string file) {

    //Opens a stream
    auto stream = std::ostringstream();

    //Creates a file stream
    std::ifstream iFile(file);

    //Tries to open file
    if(!iFile.is_open()){
        throw std::runtime_error("File Reader: Could not open file!");
    }

    //Puts what is read into the output stream
    stream << iFile.rdbuf();

    //Returns the file as a string
    return stream.str();

}