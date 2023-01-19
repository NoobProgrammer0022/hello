#include "analytics.h"


int main()
{
    int choice;
    std::vector<GradEmploymentData> data;

    readFromFile(data);
    std::vector<GradEmploymentData> tempVector = data;  // using temp vector in case of error.
    std::string degreeChoice;
    int degreeElement = -1;  // when running the search for the degree this will get the element of the degree the user choose.

    do
    {
        std::cout << std::endl;  // spacing for the menu and the choice/ table
        displayMenu();
        std::cout << std::endl;  
        choice = getChoice();    // get choice from user. This function will filter out numbers outside of 1-12
        std::cout << std::endl;      
        insertionSort(tempVector, choice);   // sorts the vector depending on the option user chose.
        // display table function accepting temp vector and choice
        if(choice == 11)
        {
            // gets input from user on what degree they want info on.
            degreeChoice = getMajor(tempVector);  
            
            // searches for the degree the user entered. Case does not matter only spelling
            // when function searches it will temporarily upgrade the degree being searched for and 
            // the name of the function in the vector to all caps. (part of the extra step in the assignment)
            degreeElement = binarySearch(tempVector, degreeChoice);

            if(degreeElement != -1)
            std::cout << std::endl;
            displayDegree(tempVector, degreeElement);
            std::cout << "\n \n Press enter to continue. ";
            std::cin.get();
        }
        else
        {
        displayVector(tempVector, choice);
        if(choice != 12)
        {
            std::cout << "\n \n Press enter to continue. ";
            std::cin.get();
        }
        }

    }while(choice != 12);

    return 0;

}
