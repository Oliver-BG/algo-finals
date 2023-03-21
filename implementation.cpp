#include "Data.h"
using namespace std;
projectDetailList::projectDetailList()
{
    openProjectFile();
    openCompletedProj();
    checkprojectiddupe();
}
void projectDetailList::addProject()
{

    projectDetail tempd = projectDetail();
    tempd.Id = 1;
    while(projectidexist(tempd.Id, read) || projectidexist(tempd.Id, completed))
    {
        tempd.Id = tempd.Id + 1;
    }
    cout << "Project Id : " << tempd.Id << endl;
    cin.ignore(1);

    cout << "Enter the title of the Project: ";
    getline(cin, tempd.Title);

    cout << "Enter the Project Page Size: ";
    cin >> tempd.PageSize;

    cout << "Enter the Project's Priority: ";
    cin >> tempd.Priority;

    read.push_back(tempd);

    cout << "\nYou have successfully added the Project!\n";
}

void projectDetailList::openProjectFile()
{
    ifstream openProjectFile;

    openProjectFile.open("Projects.txt");

    projectDetail temp = projectDetail();
    while (!openProjectFile.eof())
    {
        openProjectFile >> temp.Id;
        openProjectFile.ignore();
        getline(openProjectFile, temp.Title, '\n');
        openProjectFile >> temp.PageSize;
        openProjectFile >> temp.Priority;
        if(temp.Id != 0)
        read.push_back(temp);
        temp = {};
    }

    openProjectFile.close();
}

void projectDetailList::saveProjectFile()
{
    ofstream projectFileText;
    projectFileText.open("Projects.txt", std::ios::trunc);

    for(auto i = read.begin(); i != read.end(); ++i)
    {
        projectFileText << i->Id;
        projectFileText << endl;

        projectFileText << i->Title;
        projectFileText << endl;

        projectFileText << i->PageSize;
        projectFileText << endl;

        projectFileText << i->Priority;
        projectFileText << endl;
    }
    projectFileText.close();
}

void projectDetailList::CreateSched() // functions below are new functions for scheduling functions
{
    // clears data from queue when called again considering queue is not empty
    if (!proj.empty())
        while (!proj.empty())
            proj.pop_front();

    projectDetail temp = projectDetail();
    list<projectDetail> templist;
    // sorts linked list first with lower priority means higher priority and if same, sort by page size in ascending order
    templist = read;
    list<projectDetail>::iterator prt;

    for (auto prt = templist.begin(); prt != templist.end(); ++prt)
    {
        for (auto prt2 = templist.begin(); prt2 != templist.end(); ++prt2)
        {
            if (prt->Priority > prt2->Priority)
            {
                temp.Id = prt->Id;
                temp.PageSize = prt->PageSize;
                temp.Priority = prt->Priority;
                temp.Title = prt->Title;

                prt->Id = prt2->Id;
                prt->PageSize = prt2->PageSize;
                prt->Priority = prt2->Priority;
                prt->Title = prt2->Title;

                prt2->Id = temp.Id;
                prt2->PageSize = temp.PageSize;
                prt2->Priority = temp.Priority;
                prt2->Title = temp.Title;
            }
            else if ((prt->Priority == prt2->Priority) && (prt->PageSize > prt2->PageSize))
            {
                temp.Id = prt->Id;
                temp.PageSize = prt->PageSize;
                temp.Priority = prt->Priority;
                temp.Title = prt->Title;

                prt->Id = prt2->Id;
                prt->PageSize = prt2->PageSize;
                prt->Priority = prt2->Priority;
                prt->Title = prt2->Title;

                prt2->Id = temp.Id;
                prt2->PageSize = temp.PageSize;
                prt2->Priority = temp.Priority;
                prt2->Title = temp.Title;
            }
        }
    }
    for (auto prt = templist.begin(); prt != templist.end(); ++prt)
    {
        temp.Id = prt->Id;
        temp.PageSize = prt->PageSize;
        temp.Priority = prt->Priority;
        temp.Title = prt->Title;
        proj.push_front(temp);
    }

    if (!proj.empty())
        cout << "Created A New Schedule" << endl;
    else
        cout << "Schedule wasn't successfully created" << endl;
}

void projectDetailList::ViewUpdatedSched()
{
    projectDetail temp1 = projectDetail();
    deque<projectDetail> temp2 = proj;
    if (temp2.empty())
    {
        cout << "There's no created schedule yet." << endl;
        return;
    }
    cout<<"ID\t\tTitle\t\tPageSize\tPriority"<<endl;
    while (!temp2.empty())
    {
        temp1 = temp2.front();
        cout << temp1.Id << "\t\t" << temp1.Title << "\t\t" << temp1.Priority << "\t" << temp1.PageSize << endl;
        temp2.pop_front();
    }
}

void projectDetailList::GetProject()
{
    ofstream completeproj("completeproj.txt", std::ios::app);
    if (proj.empty())
    {
        cout << "Currently you have not created a schedule yet" << endl;
        return;
    }
    projectDetail temp;
    while (!proj.empty())
    {
        temp = proj.front();
        cout << "[Project Id\tProject Title\tProjectPriority\tProjectPageSize]" << endl;
        cout << "[" << temp.Id << "\t\t" << temp.Title << "\t\t" << temp.Priority << "\t\t" << temp.PageSize << "\t]" << endl;

        list<projectDetail>::iterator i;
        for(auto i = read.begin(); i != read.end(); ++i)
        {
            if(i->Id == temp.Id){
                read.erase(i);
                break;
            }    
        }
        completeproj << temp.Id;
        completeproj << endl;
        completeproj << temp.Title;
        completeproj << endl;
        completeproj << temp.PageSize;
        completeproj << endl;
        completeproj << temp.Priority;
        completeproj << endl;

        proj.pop_front();
        cout << "[Current Project is completed]" << endl;
    }

    cout << "\n\t\t[[[All projects have been copy-typed]]]" << endl;
}

void projectDetailList::CompletedProjects()
{
    list<projectDetail>::iterator i;
    if(completed.empty()){
        cout<<"You have no currently completed Projects"<<endl;
        return;
    }
    cout<<"ID\t\tTitle\t\tPageSize\tPriority\n"<<endl;
    for(auto i = completed.begin(); i != completed.end(); ++i){
        cout<<i->Id<<"\t\t"<<i->Title<<"\t\t"<<i->PageSize<<"\t\t"<<i->Priority<<endl;
    }
}

bool projectDetailList::projectidexist(int id, list<projectDetail> a)
{
    list<projectDetail>::iterator i;
    for(auto i = a.begin(); i != a.end(); ++i){
        if(id == i->Id)
            return true;
    }
    return false;
}

void projectDetailList::openCompletedProj()
{
    ifstream compproj("completeproj.txt");
    
    projectDetail temp;
    if(compproj.is_open())
    while(!compproj.eof()){
        compproj >> temp.Id;
        compproj.ignore();
        getline(compproj, temp.Title, '\n');
        compproj >> temp.PageSize;
        compproj >> temp.Priority;
        if(temp.Id != 0)
        completed.push_back(temp);
        temp = {};
    }
    else
        cout<<"There's no existing Complete Projects"<<endl;
}
void projectDetailList::checkprojectiddupe()
{
    for (auto i =read.begin(); i != read.end(); ++i)
        for(auto j = completed.begin(); j != completed.end(); ++j)
        {
            if(i->Id == j->Id)
            {
                cout<<"There is a duplicated ID, proceeding to erase duplicate completed project..."<<endl;
                completed.erase(j);
            }
        }
}

void projectDetailList::viewOneProject()
{
    int tempProjectId;
    bool exist;
    cout << "Enter Project ID: ";
    cin >> tempProjectId;

    for(auto i = read.begin(); i != read.end(); ++i){
        if(i->Id == tempProjectId)
        {
            cout << endl << "Project ID: \t\t" << i->Id << endl;
            cout << "Project Title: \t\t" << i->Title << endl;
            cout << "Project Page Size: \t\t" << i->PageSize << endl;
            cout << "Project Priority: \t\t" << i->Priority << endl;
            exist = true;
            return;
        }
    
    }
    if(!exist)
        {
            cout << "Project doesn't exist";
        }
}

void projectDetailList::viewAllProjects()
{   
    if(read.empty()){
        cout<<"No Available Projects yet"<<endl;
        return;
    }
    cout << "Displaying all projects" << endl;
    cout<<"ID\t\tTitle\t\tPageSize\tPriority"<<endl;
    for(auto i = read.begin(); i != read.end(); ++i)    
    {
        cout << "" << i->Id << "\t\t";
        cout << "" << i->Title << "\t\t";
        cout << "" << i->PageSize << "\t\t";
        cout << "" << i->Priority << "\t" << endl;
    }
}