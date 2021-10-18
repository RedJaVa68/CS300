#include <iostream>
#include <vector>
#include "Course.h"
#include "FileReader.h"
#include <time.h>

using namespace std;
/**
 * Node structure for binary search tree
 */
struct Node{

    //contains the course
    Course course;
    //left leaf
    Node* left = nullptr;
    //right leaf
    Node* right = nullptr;
    //this node is root
    bool isRoot = false;

    /**
     * Constructor for any node
     * @param course
     */
    Node(Course course){

        this->course = course;

    }
    /**
     * Constructor for root node
     * @param isRoot
     */
    Node(bool isRoot){

        this->isRoot = isRoot;

    }

};
/**
 * The binary search tree object
 */
class BST{

private:
    //The root of the bst
    Node* root = nullptr;

    /**
     * Inserts a course object recursively
     * @param current
     * @param course
     */
    void Insert(Node* current, Course course){

        //This means the current node is the root
        if(current == nullptr) {
            root->left = new Node(course);
            return;
        }
        else{
            //The course we are adding is bigger than the current node
            if(course.getSection().compare(current->course.getSection()) < 0){

                //If it's at the leaf add the course to it
                if(current->left == nullptr)
                    current->left = new Node(course);
                //If not keep searching for leaf
                else
                    Insert(current->left,course);

            }else{
                //If it's at the leaf add the course to it
                if(current->right == nullptr)
                    current->right = new Node(course);
                //If not keep searching for leaf
                else
                    Insert(current->right, course);

            }

        }

    }
    /**
     * Prints all nodes in order traversal recursively
     * @param current
     */
    void InOrder(Node* current){

        //Do nothing if there is nothing on node
        if(current == nullptr)
            return;
        else{

            //Traverse left
            InOrder(current->left);
            //Print current node
            current->course.printCourse();
            //Traverse right
            InOrder(current->right);

        }

    }
    /**
     * Prints a course from a given section
     * @param current
     * @param section
     */
    void PrintCourse(Node* current, string section){

        //If current is nothing than do nothing
        if(current == nullptr)
            return;
        else{
            //If the current node is what we are looking for
            if(current->course.getSection().compare(section) == 0){
                //Print node
                current->course.printCourse();

            }else{
                //Search left
                PrintCourse(current->left, section);
                //Search right
                PrintCourse(current->right, section);

            }

        }

    }

public:
    /**
     * Default constructor of BST
     */
    BST(){}

    /**
    * Constructor of BST passing in root
    * @param root
    */
    BST(Node* root){

        this->root = root;

    }

    /**
     * Inserts course to BST
     * Calls a recursive function
     * @param course
     */
    void Insert(Course course){

        Insert(root->left, course);

    }
    /**
     * Prints in order traversal
     * Calls a recursive function
     */
    void InOrder(){

        InOrder(root->left);

    }
    /**
     * Prints a specific course
     * Calls a recursive function
     * @param section
     */
    void PrintCourse(string section){

        PrintCourse(root->left, section);

    }



};


/**
 * Gets the courses given a file path
 * @param file file path
 * @return a vector of courses
 */
BST getBST(string file){

    //Create a new vector of courses
    BST bst(new Node(true));

    FileReader fileReader;

    //Get the lines obtained from the file
    vector<string> lines = fileReader.getLines(file);

    //Traverse through the lines
    for(string line : lines){

        //Get the details of each line to be added to a course
        vector<string> details = fileReader.split(line,",");

        //Checks if the amount of details are sufficient to create a course
        if(details.size() >= 2) {
            //Creates a course with section and name
            Course course(details.at(0), details.at(1));

            //The extra details are prerequisites
            for(int i = 2; i < details.size(); i ++){

                //Add the prerequisite
                course.addPreq(details.at(i));

            }

            //Insert the course to the bst
            bst.Insert(course);

        }

    }

    return bst;

}
/**
 * Displays menu
 * @return the response from user
 */
int DisplayMenu(){

    cout << endl;
    cout << "\t1: Load Data Structure" << endl;
    cout << "\t2: Print Course List" << endl;
    cout << "\t3: Print Course" << endl;
    cout << "\t4: Exit" << endl;
    cout << endl;
    cout << "What would you like to do?" << endl;
    int ans;
    cin >> ans;

    //Checks if input was an integer
    if(cin.good())
        return ans;
    else {
        cin.clear();
        cin.ignore();
        return -1;
    }

}

/**
 * main method
 */
int main(int argc, char* argv[]) {

    BST bst;
    string path = "courselist.txt";
    string section = "CSCI400";

    clock_t ticks;

    //Grabbing commands
    switch(argc){
        //User inputted custom file
        case 2:
            path = argv[1];
            break;
        //User inputted custom file and section
        case 3:
            path = argv[1];
            section = argv[2];
            break;
        //User didn't input anything
        default:
            break;

    }

    cout << "Using path: " << path << " and section: " << section << "." << endl << endl;
    cout << "Welcome to the course planner." << endl;

    //Keep continuing set to true
    bool cont = true;
    //While keep continuing
    while(cont){

        //Get response from user
        int ans = DisplayMenu();
        //Switch user response
        switch (ans) {

            //Loads bst
            case 1:
                ticks = clock();
                //loads bst
                bst = getBST(path);
                //Calculate and display elapsed time
                ticks = clock() - ticks;
                cout << "Took: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                break;
            //Prints in alphanumerical
            case 2:
                ticks = clock();
                //prints bst
                bst.InOrder();
                //calculate and display elapsed time
                ticks = clock() - ticks;
                cout << "Took: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                break;
            //Print specific course
            case 3:
                ticks = clock();
                //prints course
                bst.PrintCourse(section);
                //calculate and display elapsed time
                ticks = clock() - ticks;
                cout << "Took: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                break;
            //Exits program
            case 4:
                cont = false;
                break;
            //Invalid input
            default:
                cout << "Please enter a valid number from 1 to 4" << endl;
                break;

        }


    }



    return 0;
}
