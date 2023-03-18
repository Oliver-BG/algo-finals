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
        projectListNewNode->move.Id = 0;
        isempty = 1;
    }
    else
    {
        while (movNodePtr->Next)
        {
            movNodePtr = movNodePtr->Next;
        }
        lastCode = movNodePtr->move.Id;
        movNodePtr->Next = projectListNewNode;
    }

    cout << "Project Id : " << lastCode + 1 << endl;
    cin.ignore(1);

    cout << "Enter the title of the Project: ";
    getline(cin, projectTitle);

    cout << "Enter the Project Page Size: ";
    cin >> projectPageSize;

    projectListNewNode->move.Id = projectId;
    projectListNewNode->move.Title = projectTitle;
    projectListNewNode->move.PageSize = projectPageSize;

    if (!isempty)
    {

        movNodePtr = movNodePtr->Next;

        movNodePtr->move.Id = lastCode + 1;
    }

    cout << "\nYou have successfully added the Project!\n";
}

void projectDetailList::openProjectFile()
{
    ifstream openProjectFile;
    openProjectFile.open("Projects.txt");

    projectListNode *projectListNewNode;

    projectListNode *openFilePtr = projectHead;

    string tempString;

    int projectId;
    string projectTitle;
    int projectPageSize;
    int projectPriority;

    while (getline(openProjectFile, tempString))
    {
        cout << tempString;

        projectListNewNode = new projectListNode;

        projectListNewNode->move.Id = projectId;
        projectListNewNode->move.Title = projectTitle;
        projectListNewNode->move.PageSize = projectPageSize;
        projectListNewNode->move.Priority = projectPriority;

        projectListNewNode->Next = NULL;

        if (!projectHead)
        {
            projectHead = projectListNewNode;
            openFilePtr = projectHead;
        }
        else
        {
            openFilePtr->Next = projectListNewNode;
            openFilePtr = openFilePtr->Next;
        }
    }

    openProjectFile.close();
}

void projectDetailList::saveProjectFile()
{
    ofstream projectFileText;
    projectFileText.open("Projects.txt");
    projectListNode *projectFile;
    projectFile = projectHead;

    while(projectFile != NULL)
    {
        projectFileText << "Project ID: ";
        projectFileText << projectFile->move.Id;
        projectFileText << endl;

        projectFileText << "Project Title: ";
        projectFileText << projectFile->move.Title;
        projectFileText << endl;

        projectFileText << "Project Page Size: ";
        projectFileText << projectFile->move.PageSize;
        projectFileText << endl;

        projectFileText << "Project Priority: ";
        projectFileText << projectFile->move.Priority;
        projectFileText << endl;

        projectFile = projectFile->Next;
    }
}