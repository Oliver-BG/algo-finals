#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    // testing push for file-handling branch
    // tangina nababaliw na ako
    projectDetail project;
    projectDetailList projectObject;

    int input;

    while (true)
    {
        system("cls");
        cout << "[1] Add projects: " << endl;
        cout << "[2] View Projects " << endl;
        cout << "[3] Schedule Projects" << endl;
        cout << "[4] Get a project" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Enter a new project";
            projectObject.addProject(project);
            projectObject.openProjectFile();
            projectObject.saveProjectFile();
            break;
        case 2:
            break;
        }
    }
    return 0;
}