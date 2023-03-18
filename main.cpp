#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    //testing push for file-handling branch
    //tangina nababaliw na ako 
    projectDetail project;
    projectDetailList projectObject;

    bool checker;
    int input;
    cout << "[1] Add projects: " << endl;
    cout << "[2] View Projects " << endl;
    cout << "[3] Schedule Projects" << endl;
    cout << "[4] Get a project" << endl;
    cin >> checker;

    while(true) 
    {
        switch(checker)
        {
            case 1:
                cout << "Enter a new project";
                projectObject.addProject(project);
                projectObject.openProjectFile();
                break;
        }
    }
    return 0;
}