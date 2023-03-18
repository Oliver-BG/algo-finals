#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    //testing push for file-handling branch
    projectDetail project;
    projectDetailList projectObject;

    bool checker;
    int input;
    cout << "Enter option: " << endl;
    cin >> checker;

    while(true) 
    {
        switch(checker)
        {
            case 1:
                cout << "Enter a new project";
                projectObject.addProject(project);
                break;
        }
    }
    return 0;
}