#pragma once

#include <iostream> //Basic library needed
#include <string.h> //String Library
#include <stack> //Stack Library
#include <deque> //Double ended queue
#include <iterator>
#include <list>

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
    deque <projectDetail> proj;         //new deque for Scheduling Functions
    list<projectDetail> completed;
    list<projectDetail> read;
    public: 
        
        projectDetailList();

        void addProject();
        void openProjectFile();
        void openCompletedProj();
        void saveProjectFile();
        void CreateSched();
        void ViewUpdatedSched();
        void GetProject();
        void CompletedProjects();
        bool projectidexist(int id, list<projectDetail> a);
        void checkprojectiddupe();
        void viewAllProjects();
        void viewOneProject();
};