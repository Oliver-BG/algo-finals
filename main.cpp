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
        
        cout << "[1] Add projects: " << endl;
        cout << "[2] View Projects " << endl;
        cout << "[3] Schedule Projects" << endl;    //New Functions
        cout << "[4] Get a Project" << endl;
        cout << "[5] Exit" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Enter a new project";
            projectObject.addProject(project);
            projectObject.openProjectFile();      //nicomment ko muna these functions cuz inconsistent ung input sa data
            projectObject.saveProjectFile();
            break;
        case 2:
            break;
        case 3:                                     //new case for scheduling function
            int choice;
                do{
                    cout << "||Scheduling Projects|| \n\n";
                    cout << "[1] Create Schedule" << endl;
                    cout << "[2] View Schedule" << endl;
                    cout << "[3] Exit" << endl;
                    cin >> choice;
                    switch(choice){
                        case 1:
                            projectObject.CreateSched();
                            break;
                        case 2:
                            projectObject.ViewUpdatedSched();
                            break;
                        default:
                            break;
                    }
                }while(choice != 3);
            break;
        case 4:
            projectObject.GetProject();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}