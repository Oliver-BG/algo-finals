#include "Data.h"
using namespace std;

projectDetailList::projectDetailList()
{
    projectHead = NULL;
}

void projectDetailList::addProject(projectDetail move)
{
    int lastCode;

    int projectId;            // project iD number
    std::string projectTitle; // project title
    int projectPageSize;      // project page sizew
    int priority;             // for priority sorting

    int isempty = 0;

    projectListNode *movNodePtr = projectHead;
    projectListNode *projectListNewNode;
    projectListNode *temp;

    projectListNewNode = new projectListNode;
    projectListNewNode->Next = NULL;

    if (!projectHead)
    {
        projectHead = projectListNewNode;
        lastCode = -1;
        projectListNewNode->move.projectId = 0;
        isempty = 1;
    }
    else
    {
        while (movNodePtr->Next)
        {
            movNodePtr = movNodePtr->Next;
        }
        lastCode = movNodePtr->move.projectId;
        movNodePtr->Next = projectListNewNode;
    }

    cout << "Project Id : " << lastCode + 1 << endl;
    cin.ignore(1);

    cout << "Enter the title of the Project: ";
    getline(cin, projectTitle);

    cout << "Enter the Project Page Size: ";
    cin >> projectPageSize;

    projectListNewNode->move.projectId = projectId;
    projectListNewNode->move.projectTitle = projectTitle;
    projectListNewNode->move.projectPageSize = projectPageSize;


    if (!isempty)
    {

        movNodePtr = movNodePtr->Next;

        movNodePtr->move.projectId = lastCode + 1;
    }

    cout << "\nYou have successfully added the Project!\n";
}