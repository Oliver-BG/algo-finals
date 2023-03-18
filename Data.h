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
    int projectId; // project iD number
    std::string projectTitle; // project title
    int projectPageSize; // project page sizew
    int priority; // for priority sorting
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
        projectDetailList();

        void addProject(projectDetail projectDetail);

};