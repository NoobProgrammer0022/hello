#include"analytics.h"


void displayMenu()
{
    std::cout << " 2015 National Survey of Recent College Graduates." << std::endl;
    std::cout << "1. Top 10 Majors with the Highest Mean Sallery." << std::endl;
    std::cout << "2. Top 10 Majors with the Lowest Mean Sallery." << std::endl;
    std::cout << "3. Top 10 Majors with the Highest Median Sallery." << std::endl;
    std::cout << "4. Top 10 Majors with the Lowest Median Sallery." << std::endl;
    std::cout << "5. Top 10 Majors with the Highest Number of Asians." << std::endl;
    std::cout << "6. Top 10 Majors with the LowestNumber of Asians." << std::endl;
    std::cout << "7. Top 10 Majors with the Highest Number of Minorities" << std::endl;
    std::cout << "8. Top 10 Majors with the Lowest Number of Minorities" << std::endl;
    std::cout << "9. Top 10 Majors with the Highest Masters Degrees Awarded" << std::endl;
    std::cout << "10.Top 10 Majors with the Lowest Masters Degrees Awarded" << std::endl;
    std::cout << "11. Display Information for a Specific Major " << std::endl;
    std::cout << "12. Quit the program. " << std::endl;
}

int getChoice()
{
    int choice;

    std::cout << " Please input your selection. ";
    std::cin >> choice;
    std::cin.ignore();

    while(choice < 1 || choice > 12)        // prevents bad input on the menu
    {
        std::cout << " You entered an invalid entry please enter a number between 1 and 12. ";
        std::cin >> choice;
    }
    return choice;
}

void readFromFile(std::vector<GradEmploymentData> &file1)
{
    std::ifstream inputFile {"graduates2015.csv"};

    if(inputFile.fail())
    {
        std::cout << "Error opening file closing program... ";
        exit(1);
    }

    char delim;
    double temp1;               // using double to prevent truncation on the median and mean sallary
    std::string temp2, temp3, temp4;
    int count = 0;
    std::vector<std::string> catagories(12);
    char test;

    for (int i = 0; i < 12; i++)  // this part reads the upper line for all the catagories
    {
    if(i<11)
    getline(inputFile, catagories[i], ',' );
    else
    getline(inputFile, catagories[i]);
    }

    while(inputFile.peek() != EOF)
    {
        file1.push_back(GradEmploymentData());

        inputFile >> temp1 >> delim;
        file1[count].demographicsTotal = temp1;

        getline(inputFile, temp2, ',');
        

        test = inputFile.peek();   // reads next charachter. If its a space or letter we get another
        if(isalpha(test) || isspace(test))  // temp string then add them together when assigning 
        {                                   // to the vector.
            getline(inputFile, temp3, ',');
            temp4 = temp2 + " " + temp3;
            temp4 = remBadInfo(temp4);
            file1[count].educationMajor = temp4;
        }

        temp2 = remBadInfo(temp2);
        file1[count].educationMajor = temp2;


        inputFile >> temp1 >> delim;
        file1[count].meanSalary = temp1;

        inputFile >> temp1 >> delim;
        file1[count].medianSalary = temp1;

        inputFile >> temp1 >> delim;
        file1[count].demographicsAsian = temp1;

        inputFile >> temp1 >> delim;
        file1[count].demographicsMinority = temp1;

        inputFile >> temp1 >> delim;
        file1[count].demographicsWhite = temp1;

        inputFile >> temp1 >> delim;
        file1[count].demographicsFemales = temp1;

        inputFile >> temp1 >> delim;
        file1[count].demographicsMales = temp1;

        inputFile >> temp1 >> delim;
        file1[count].educationBachelor = temp1;

        inputFile >> temp1 >> delim;
        file1[count].educationDoctorate = temp1;

        inputFile >> temp1;
        file1[count].educationMasters = temp1;       

        count++;
    }
    inputFile.close();
}

void insertionSort(std::vector<GradEmploymentData> &file1, int menuOption)
{
    int size = file1.size();
    std::vector<GradEmploymentData> key;
    key.push_back(GradEmploymentData());
    menuOption -= 1;    // since vector element starts at zero I have to subtract one from user choice.

    switch(menuOption)                  // each case will tell the program what we are sorting by
    {
        case 0:               // menu selection one
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].meanSalary < key[0].meanSalary)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 1:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].meanSalary > key[0].meanSalary)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 2:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].medianSalary < key[0].medianSalary)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 3:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].medianSalary > key[0].medianSalary)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 4:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].demographicsAsian < key[0].demographicsAsian)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 5:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].demographicsAsian > key[0].demographicsAsian)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 6:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].demographicsMinority < key[0].demographicsMinority)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 7:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].demographicsMinority > key[0].demographicsMinority)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 8:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].educationMasters < key[0].educationMasters)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 9:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].educationMasters > key[0].educationMasters)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;
        case 10:
        {
            for(int startScan = 1; startScan < size; startScan++)
            {
                key[0] = file1[startScan];
                int index = startScan - 1;

                while(index >= 0 && file1[index].educationMajor > key[0].educationMajor)
                {
                    file1[index + 1] = file1[index];
                    -- index;
                }
                file1[index + 1] = key[0];
            }
        }
        break;                                 // default not needed since getchoice() will filter out bad input
    }

    
}


void displayVector(std::vector<GradEmploymentData> file1, int menuOption)
{
    menuOption -= 1;        // decrease by one since vector starts at element zero
    switch(menuOption)
    {
        case 0:
        {

            std::cout << std::setw(40) << std::left << "Education Major" << "Mean Sallary " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << "$ " << std::setw(12) << std::right << std::fixed << std::setprecision(2) <<  file1[i].meanSalary << std::endl;
        }
        break;
        case 1:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Mean Sallary " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << "$ " << std::setw(12) << std::right << std::fixed << std::setprecision(2) << file1[i].meanSalary << std::endl;
        }
        break;
        case 2:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Median Sallary " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << "$ " << std::setw(12) << std::right << std::fixed << std::setprecision(2) << file1[i].medianSalary << std::endl;
        }
        break;
        case 3:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Median Sallary " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << "$ " << std::setw(12) << std::right << std::fixed << std::setprecision(2) << file1[i].medianSalary << std::endl;
        }
        break;
        case 4:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Asians " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor  << std::setw(12) << std::right << file1[i].demographicsAsian << std::endl;
        }
        break;
        case 5:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Asians " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << std::setw(12) << std::right << file1[i].demographicsAsian << std::endl;
        }
        break;
        case 6:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Minorities " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << std::setw(12) << std::right << file1[i].demographicsMinority << std::endl;
        }
        break;
        case 7:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Minorities " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << std::setw(12) << std::right << file1[i].demographicsMinority << std::endl;

        }
        break;
        case 8:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Masters Degrees Awarded " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << std::setw(12) << std::right << file1[i].educationMasters << std::endl;
        }
        break;
        case 9:
        {
            std::cout << std::setw(40) << std::left << "Education Major" << "Number of Masters Degrees Awarded " << std::endl;
            std::cout << "-----------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < 10; i++)
            std::cout << std::setw(40) << std::left << file1[i].educationMajor << std::setw(12) << std::right << file1[i].educationMasters << std::endl;
        }
    }            
}


std::string getMajor(std::vector<GradEmploymentData> file1)
{
    std::string userChoice;
    int size = file1.size();

    std::cout << " Degrees to choose from: ";
    for (int i = 0; i < size; i++)
    std::cout << file1[i].educationMajor << std::endl;
    
    std::cout << " Above is a list of all majors.";
    std::cout << " Please type in the major you want to get more info on, then press enter. ";
    getline(std::cin, userChoice);

    while(binarySearch(file1, userChoice) == -1)
    {
    std::cout << userChoice << " is not found please choose from the list above." << std::endl;
    getline(std::cin, userChoice);
    }

    return userChoice;
    
}

    // searches the list of degrees and matches it against what the user typed in
    // will return -1 if not found.
int binarySearch(std::vector<GradEmploymentData> file1, std::string value)
{
    int first = 0,
    last = (file1.size() - 1),
    middle,
    position = -1;
    bool found= false;
    std::string menuTemp, userTemp;  // will hold the string in all caps for easier searching.
    

    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        userTemp = turnCapital(value);
        menuTemp = turnCapital(file1[middle].educationMajor);
        if ( menuTemp == userTemp)
            {
                found = true;
                position = middle;
            }
        else if(menuTemp > userTemp)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

// this will return all words passed to it in all caps
// this will be used to compare menu items no matter if the user used caps or not.
std::string turnCapital(std::string word)
{
   int size = word.length();

   for (int i = 0; i < size; i++)
   word[i] = toupper(word[i]);

   return word;
}

void displayDegree(std::vector<GradEmploymentData> file1, int element) 
{
    std::cout << std::setw(8) << std::left << " Degree: " << file1[element].educationMajor << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of People: " << std::setw(12) << std::right << file1[element].demographicsTotal<< std::endl;
    std::cout << std::setw(60) << std::left << " Mean Salary: " << "$ " << std::setw(10) << std::right << file1[element].meanSalary<< std::endl;
    std::cout << std::setw(60) << std::left << " Median Salary: " << "$ " << std::setw(10) << std::right << file1[element].medianSalary<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Asians in this Field: " << std::setw(12) << std::right << file1[element].demographicsAsian<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Minorities in this Field: " << std::setw(12) << std::right << file1[element].demographicsMinority<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Whites in this Field: " << std::setw(12) << std::right << file1[element].demographicsWhite<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Females in this Field: " << std::setw(12) << std::right << file1[element].demographicsFemales<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Males in this Field: " << std::setw(12) << std::right << file1[element].demographicsMales<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Bachelor Degrees Awarded: " << std::setw(12) << std::right << file1[element].educationBachelor<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Doctorate Degrees Awarded: " << std::setw(12) << std::right << file1[element].educationDoctorate<< std::endl;
    std::cout << std::setw(60) << std::left << " Total Number of Masters Degrees Awarded: " << std::setw(12) << std::right << file1[element].educationMasters<< std::endl;      
}


std::string remBadInfo(std::string str)
{
    int size = str.length();

    for(int i = 0; i < size; i++)
    {
        if(str[i] == '"')
        str.erase(str.begin() + i);

        if(str[i] == 'O' || str[i] == 'o')
        {
            if(str[i + 1] == 'T' || str[i + 1] == 't')
            {
                if(str[i+2] == 'H' || str[i + 2] == 'h')
                {
                    if(str[i+3] == 'E' || str[i + 3] == 'e')
                    {
                        if(str[i+4] == 'R' || str[i + 4] == 'r')
                        {
                            str.erase(str.begin() + i);
                            str.erase(str.begin() + i);
                            str.erase(str.begin() + i);
                            str.erase(str.begin() + i);
                            str.erase(str.begin() + i);
                            str.erase(str.begin() + i);
                        }
                    }
                }
            }
        }

    }
    return str;
}


    

