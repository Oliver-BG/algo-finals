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

    cout << "Enter the Project's Priority: ";
    cin >> priority;

    projectListNewNode->move.Id = projectId;
    projectListNewNode->move.Title = projectTitle;
    projectListNewNode->move.PageSize = projectPageSize;
    projectListNewNode->move.Priority = priority;

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
    projectFileText.close();
}

void projectDetailList::CreateSched()               //functions below are new functions for scheduling functions
{
    projectDetail temp = projectDetail();
    projectListNode *projectnword, *projectnword2;
    //sorts linked list first with lower priority means higher priority and if same, sort by page size in ascending order
    for(projectnword = projectHead; projectnword->Next != NULL;projectnword=projectnword->Next){
        for(projectnword2=projectnword->Next; projectnword2->Next != NULL; projectnword2=projectnword2->Next){
            if(projectnword->move.Priority > projectnword2->move.Priority){
                temp = projectnword->move;
                projectnword->move = projectnword2->move;
                projectnword2->move = temp;
            }
            else if((projectnword->move.Priority == projectnword2->move.Priority)&&
            (projectnword->move.PageSize > projectnword2->move.PageSize)){
                temp = projectnword->move;
                projectnword->move = projectnword2->move;
                projectnword2->move = temp;
            }
        }
    }
    projectnword = projectHead;
        while(projectnword != NULL){
            temp = projectnword->move;
            proj.push_front(temp);
            projectnword = projectnword->Next;
        }

    if(!proj.empty())
        cout<<"Created A Schedule"<<endl;
    else
        cout<<"Schedule wasn't successfully created"<<endl;
}

void projectDetailList::ViewUpdatedSched(){
    projectDetail temp1 = projectDetail();
    deque <projectDetail> temp2;
    temp2 = proj;
    if(temp2.empty()){
        cout<<"There's no created schedule yet."<<endl;
        return;
    }
    while(!temp2.empty()){
        temp1 = temp2.front();
        cout<<temp1.Id<<"\t"<<temp1.Title<<"\t"<<temp1.Priority<<"\t"<<temp1.PageSize<<endl;
    }
}

