#pragma once

#include <iostream> //Basic library needed
#include <string.h> //String Library
#include <stack> //Stack Library
#include <deque> //Double ended queue

#include <sstream> //To operate on strings
#include <fstream> //Represents the file stream generally

using namespace std;

struct projectDetail
{
    int Id; // project iD number
    std::string Title; // project title
    int PageSize; // project page sizew
    int Priority; // for priority sorting
};

class projectDetailList
{
    private:
    
    struct projectListNode
    {
        projectDetail move;
        struct projectListNode* Next;
    };

    projectListNode * projectHead;
    
    public: 
        deque <projectDetail> proj;         //new deque for Scheduling Functions
        projectDetailList();

        void addProject(projectDetail projectDetail);
        void openProjectFile();
        void saveProjectFile();
        void CreateSched();
        void ViewUpdatedSched();

};