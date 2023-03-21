#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    // testing push for file-handling branch
    // tangina nababaliw na ako
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
        int choice;
        switch (input)
        {
        case 1:
            cout << "Enter a new project";
            try{
            projectObject.addProject();}catch(std::exception e){cout<<"There's something wrong with your input"<<endl;}
            break;
        case 2:
            do{
                    cout << "||View Projects|| \n\n";
                    cout << "[1] View One Project" << endl;
                    cout << "[2] View Completed Projects" << endl;
                    cout << "[3] All Projects" << endl;
                    cout << "[4] Exit"<<endl;
                    cin >> choice;
                    switch(choice){
                        case 1:
                            projectObject.viewOneProject();
                            break;
                        case 2:
                            projectObject.CompletedProjects();
                            break;
                        case 3:
                            projectObject.viewAllProjects();
                            break;
                        default:
                            break;
                    }
                }while(choice != 4);
            break;
        case 3:                                     //new case for scheduling function
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
            projectObject.saveProjectFile();
            return 0;
        }
    }
    return 0;
}