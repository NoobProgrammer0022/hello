/**
 * @file analytics.h
 * @author Matthew Lewis (mdlewis@students.nic.edu)
 * @brief Program will read info from a file sort the file and display a menu depending on the option chosen
 * by the user the program will display sorted data on that choice. all sorts are using an insertion sort
 * the 11 option is using a binary search. 
 * @version 1.15
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ANALYTICS_H
#define ANALYTICS_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>



    struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    std::string educationMajor;   // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major    

    GradEmploymentData()
    {
        demographicsTotal = 0;
        educationMajor = " ";
        meanSalary= 0;
        medianSalary= 0;
        demographicsAsian= 0;
        demographicsMinority= 0;
        demographicsWhite= 0;
        demographicsFemales= 0;
        demographicsMales= 0;
        educationBachelor= 0;
        educationDoctorate= 0;
        educationMasters= 0;
    }
};

int getChoice();
void displayMenu();
void readFromFile(std::vector<GradEmploymentData> &file1);
void insertionSort(std::vector<GradEmploymentData> &file1, int menuOption);
void displayVector(std::vector<GradEmploymentData> file1, int menuOption);
std::string getMajor(std::vector<GradEmploymentData> file1);
int binarySearch(std::vector<GradEmploymentData> file1, std::string value);
std::string turnCapital(std::string word);
void displayDegree(std::vector<GradEmploymentData> file1, int element);
std::string remBadInfo(std::string str);






#endif
