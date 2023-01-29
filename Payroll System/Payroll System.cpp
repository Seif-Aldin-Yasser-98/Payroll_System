#include "stdafx.h" // is a file, that describes both standard system and project specific include files that are used frequently but hardly ever change.
#include <iostream> // header file in C++ standard library for providing basic input and output services.
#include <iomanip>  // is a library that is used to manipulate the output of C++ program. Using C++, header providing parametric manipulators.
#include <string>  // is a library  when you use a variable that has type std::string.
#include <fstream> // is a library used to perform file processing in C++.
#include <conio.h> // It is a header file used in c++ and it includes inbuilt functions like getch() and clrscr().
#include <windows.h> // It is a Library include Functions Like setw().
using namespace std;

struct Employee // Struct Contain All Empolyee's Data.
{
    unsigned int ID;                    // input/output - ID of the Employee-unsigned repsentive only postive numbers and zero.
    string Name;                       //  input/output -Name of  Employee
    double Salary;                     // input/output -salary of  Employee
    double working_hour_per_month;     //input/output - working hour per month of  Employee
    double price_per_hour;             // input/output -price per hour of  Employee
    double Basic_Salary;               // input/output -Basic salary of  Employee
    double Gross_Salary;               //input/output - Gross salary of  Employee
    double Net_Salary;                 // input/output -Net salary of  Employee
    double Tax;                        // -Tax of  Employee
};

double Total_Net;            //input/output - Total salary of  Employee
double Max_Salary;           // input/output -Max salary of  Employee
double Min_salary;           // input/output -Min salary of  Employee
const int Maximum = 10;      // Maximum size of employees
int Emps_Number = 0;         // input/output -The  Employee of number
char Option;                 // input -Option of the main menu


Employee Emp[Maximum], //declartion of object of Employees.
	Swap_data[Maximum]; //declartion of object for sorting Employee's details.   

void Display_Greeting();    // Display greeting Massege
void Display_Goodbye();     // Displaying Goodbye Massege
char Display_Menu();        // Displaying The Main Menu
void Add_List_of_Employee();         // input data
void List_Table();          // Displaying Data as a Table
void Inset_An_Employee();        // Add Employee data
void Modify();			    // Modify Employee's data
void Delete_Employee();     // Delete the employees data
void Compute();             // Display The main menu
void Compute_Total();       // compute total salary
void Compute_Tax();         // compute tax
void Compute_Net();         // compute Net salary
void Compute_Basic();       // compute basic salary
void Compute_Gross();       // compute gross salary
void Compute_Max();         // compute max salary
void Compute_Mini();        // compute mini salary
void Sort_Data();           // sorting data from mxamum to minmum basic salary
void Print_All_Emps_Data(); // print all the data employees
void Write_to_File();       // write the data to file
void Read_From_File();      // Read the data to file

int main()
{
    system ( "color 0" );  // Background is black and the font is white.
    Display_Greeting();  // function for Displaying Payroll Massege. 
    bool Quit = false;   // Declearing Variable for quit from payroll system.
    while (Quit != true) //If not quit it will show you the Main menu of payroll system.
    {
        Display_Menu();  // Displaying The Main Menu  

        

        switch (Option) // Switch condition to choose any process from Main menu of the payroll system. 
        {
        case 'A': // A or a means to choose one of these functions.
        case 'a':
            Add_List_of_Employee();
            Compute_Basic();
            Sort_Data();
            Compute_Gross();
            Compute_Net();
            Write_to_File();// write employee data to file (Saved).
            break; //end of first case.

        case 'L': // L or i means to choose one of these functions.
        case 'l':
            Read_From_File();// Read employee data from file (Load).
            Sort_Data();
            List_Table();
            break;//end of second case.

        case 'I':// I or a i means to choose one of these functions.
        case 'i':
            Read_From_File();
            Inset_An_Employee();
            Compute_Basic();
            Compute_Gross();
            Compute_Net();
            Write_to_File();
            break;//end of third case.

        case 'M':// M or m means to choose one of these functions.
        case 'm':
            Read_From_File();
            Modify();
            Compute_Basic();
            Compute_Gross();
            Compute_Net();
            Write_to_File();
            break;//end of fourth case.

        case 'D': // D or d means to choose one of these functions.
        case 'd':
            Delete_Employee(); 
            Write_to_File();
            break; //end of fifth case.

        case 'C':// C or c means to choose one of these functions.
        case 'c':
            Compute();
            break; //end of sixth case.

        case 'P': // P or p means to choose one of these functions.
        case 'p':
            Read_From_File();
            Sort_Data();
            Print_All_Emps_Data();
            break; //end of seventh case. 

        case 'Q': // Q or q means to choose one of these functions.
        case 'q':
            Quit = true;
            break; //end of eighth case. 

        default: // If choose different characters from Main menu
            system("cls");                            // clear the screen
            cout << "Enter a right choice.\n";
            _getch();                                 
            break; // end of case.
        }
        if(Quit == true)                         
            Display_Goodbye();
    }
    return 0; //close the system.
}

	 

void Display_Greeting() // function for Displaying Payroll Message
{
    cout << "\t                                                              \n\n\n\n";
    cout << "\t   _____                 _ _    _____         _               \n";
    cout << "\t  |  _  |___ _ _ ___ ___| | |  |   __|_ _ ___| |_ ___ _____   \n";
    cout << "\t  |   __| .'| | |  _| . | | |  |__   | | |_ -|  _| -_|     |  \n";
    cout << "\t  |__|  |__,|_  |_| |___|_|_|  |_____|_  |___|_| |___|_|_|_|  \n";
    cout << "\t            |___|                    |___|                    \n";
    Sleep(2);          // function makes the program wait for 2 seconds
}

	

void Display_Goodbye() // Function For Displaying goodbye Message
{
    system("cls");
    cout << "\t                                                       \n\n\n";
    cout << "\t   _____ _____ _____ ____  _____ __ __ _____           \n";
    cout << "\t  |   __|     |     |    \ | __  |  |  |   __|          \n";
    cout << "\t  |  |  |  |  |  |  |  |  | __ -|_   _|   __|   _    _ \n";
    cout << "\t  |_____|_____|_____|____/|_____| |_| |_____|  |_|  |_|\n";
    Sleep(2); 

}



char Display_Menu()  // function For Displaying a List and Choose From The Given Choices.
{
    system("cls");      
    cout << "\t\t***** Welcome to the Payroll system *****\n\n\n";
    cout << "\t\tChoose from this list: \n\n";
    cout << "\t\t(A) Add List of Employee\n";
    cout << "\t\t(L) List Table\n";
    cout << "\t\t(I) Insert An Employee\n";
    cout << "\t\t(M) Modify Employee\n";
    cout << "\t\t(D) Delete Employee\n";
    cout << "\t\t(P) Print All Employees data\n";
    cout << "\t\t(C) Compute\n";
    cout << "\t\t(Q) Quit\n\n";
    cout << "\t\tEnter your choice: ";
    cin >> Option; // enter characthers to choose the process.
    return Option; 
}

 

void Add_List_of_Employee() // Function To Add All Data Of The Employees
{
    system("cls");  // function to clear the screen.       
    cin.ignore(100,'\n');	// leave a terminating character in the stream or // is used to ignore  one or more characters from the input buffer.
    cout << "\t\tMaximum number of employees is 10\n";
    cout << "\t\tHow many employees do you want to insert:";
    while(!(cin >> Emps_Number)) // enter the right number (maximum : 10) of employees
    {
        cout << "\t\tEnter as a number: " << endl;
        cin.clear();// clear wrong flags. 
        cin.ignore(100,'\n'); // leave a terminating character in the stream
    }
    if (Emps_Number > 10) // if enter more than 10 employee.
    {
        cout << "\tThe maximum number of employees is 10 . . you have to delete someone.\n";
    }
    else
    {
        for (int i = 0 ; i < Emps_Number ; i++) //for loop to start adding employee which maximum number is 10.
        {
            cout << "\t\tEnter the ID of the employee " << i+1 << " :";
            while(!(cin >> Emp[i].ID)) 
            {
                cout << "\t\tEnter The ID as a number: ";
                cin.clear(); // clear wrong flags.
                cin.ignore(100,'\n'); 
            }
            cout << "\n\t\tEnter the Name of the employee " << i+1 << " :";
            cin.ignore(1000,'\n'); 
            getline(cin,Emp[i].Name); // Input The Name
            cout << "\n\t\tEnter the working hours per month:";
            while(!(cin >> Emp[i].working_hour_per_month)) 
            {
                cout << "\t\tEnter The Working hours as a number: ";
                cin.clear(); // clear wrong flags.
                cin.ignore(100,'\n'); 
            }
            cout << "\n\t\tEnter the price per hour:";
            while(!(cin >> Emp[i].price_per_hour)) 
            {
                cout << "\n\t\tEnter The price as a number: ";
                cin.clear(); // clear wrong flags.
                cin.ignore(100,'\n');
            }
        }
        cout << "\n\t\tBUILD SUCSSEFULLY . .\n";
    }
    if (Emps_Number > 10) //if reach the maximum number then cout (Press any key to go back).
        Emps_Number = 10;

    cout << "\n\n\t\tPress any key to go back . .";
    _getch(); // Get Char From The User
}

 

void List_Table() // Function To Display The Data as a Table
{
    system("cls"); //clear the screen.
    cin.ignore(100,'\n');
    cout << "        ID     " << "NAME      " << "BASIC SALARY		" << "GROSS SALARY     " << "NETSALARY\n";
    cout << "        -----------------------------------------------------------------------\n\n";
    for (int i = 0 ; i < Emps_Number ; i++) // for loop to recieve data from (Add_List_of_Employee) and (Inset_An_Employee) function and showed as list table.
    {   // setw means set width for ever variable with 8.
        cout << i+1;
        cout << setw (8) << Emp[i].ID;
        cout << setw (11) << Emp[i].Name;
        cout << setw (14) << Emp[i].Basic_Salary;
        cout << setw (21) << Emp[i].Gross_Salary;
        cout << setw (19) << Emp[i].Net_Salary;
        cout << endl;
    }
    cout << "\n\n\t\tPress any key to go back ...";
    _getch(); // Get Char From The User
}

 

void Print_All_Emps_Data() // Function To Print The Data Of All Employees
{
    system("cls");  // clear the system.      
    cin.ignore(100,'\n'); // is used to ignore  one or more characters from the input buffer.
    if (Emps_Number == 0)
    {
        cout << "\t\tYou must to add data to print it !\n";
    }
    else
    {
        for (int i = 0 ; i < Emps_Number ; i++) // for loop to print out all employee's data that was entered in function (add or inset employee).
        {
            cout << "\t\tEmployee's ID: " << Emp[i].ID << endl;
            cout << "\t\tEmployee's Name: " << Emp[i].Name << endl;
            cout << "\t\tWorking hous per month: " << Emp[i].working_hour_per_month << endl;
            cout << "\t\tEmployee's price per hour: " << Emp[i].price_per_hour << endl;
            cout << "\t\tEmployee's Basic Salary: " << Emp[i].Basic_Salary << endl;
            cout << "\t\tEmployee's Gross Salary: " << Emp[i].Gross_Salary << endl;
            cout << "\t\tEmployee's Net Salary: " << Emp[i].Net_Salary << endl;
            cout << "\n\n";
            cout << "\t\t******************************\n\n";
        }
    }

    cout << "\n\n\t\tPress any key to go back ...";
    _getch(); // Get Char From The User
}

 

void Inset_An_Employee() // Function To Insert new Employees Data.
{
    system("cls"); // clear the system.
    cin.ignore(100,'\n');// is used to ignore  one or more characters from the input buffer.
    char check; 
    bool exit = false;
    int i;

    if (Emps_Number >= 10)
    {
        cout << "\t\tThe maximum is 10 . . you have to delete someone.\n";
        _getch();
    }
    else if (Emps_Number < 10)
    {
        do
        {
            i = Emps_Number;
            Emps_Number += 1;
            cout << "\t\tInsert New Record\n\n";
            cout << "\t\tEnter the ID of the employee " << i+1 << " :";
            while(!(cin >> Emp[i].ID))
            {
                cout << "\n\t\tEnter The ID as a number: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout << "\n\t\tEnter the Name of the employee " << i+1 << " :";
            cin.ignore(1000,'\n');
            getline(cin,Emp[i].Name);
            cout << "\n\t\tEnter the working hours per month:";
            while(!(cin >> Emp[i].working_hour_per_month))
            {
                cout << "\n\t\tEnter The Working hours as a number: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout << "\n\t\tEnter the price per hour:";
            while(!(cin >> Emp[i].price_per_hour))
            {
                cout << "\n\t\tEnter The Price per hour as a number: ";
                cin.clear();
                cin.ignore(100,'\n');
            }

            cout << "\n\t\tADDED SUCSSESFULLY . .\n";

            cout << "\t\tDo you want to continue: (Y-N)";
            cin >> check;
            cin.get();
            do
            {
                if (check == 'n' || check == 'N')
                {
                    exit = true;
                    break;
                }

                else if (check != 'n' || check != 'N')
                {
                    if (check == 'y' || check == 'Y')
                    {
                        break;
                    }

                    else
                    {
                        cout << "\n\t\tEnter (Y-N):";
                        cin >> check;
                    }
                }
            }
            while(true);
        }
        while(exit == false);
    }
}

   
	
void Modify() // function to Edit the Employees data
{
    system("cls");
    char check; // declare variable called (check) to make choose to contiune modifu or not
    unsigned int Employee_Number ,choice; // cannot choose negative number only postive.
    bool exit = false;
    if (Emps_Number == 0)
    {
        cout << "\t\t No Data to Modify . .";
    }
    else
    {
        do
        {
            for (int i = 0; i < Emps_Number; i++)
            {
                cout << "\n\t\t" << i+1 << "- " << Emp[i].Name;
            }
            cout << "\n\n\t\tEnter a number of the employee you want to Modify.";
            while(!(cin >> Employee_Number))
            {
                cout << "\n\t\tEnter as a positive number: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            if (Employee_Number > Emps_Number)
            {
                cout << "\n\t\tEnter a correct number";
                _getch();
            }
            else
            {
                system("cls");
                cout << "\n\t\t1- To modify the ID";
                cout << "\n\t\t2- To modify the Name";
                cout << "\n\t\t3- To modify the working hour per month";
                cout << "\n\t\t4- To modify the price per hour";
                cout << "\n\t\t5- To modify all the data";
                cout << "\n\n\t\tEnter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "\t\tEnter the New ID of the employee :";
                    while(!(cin >> Emp[Employee_Number-1].ID))
                    {
                        cout << "\n\t\tEnter The ID as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    break;

                case 2:
                    cout << "\n\t\tEnter the new Name of the employee " << Employee_Number+1 << " :";
                    cin.ignore(1000,'\n');
                    getline(cin,Emp[Employee_Number-1].Name);
                    break;

                case 3:
                    cout << "\n\t\tEnter the working hours per month:";
                    while(!(cin >> Emp[Employee_Number-1].working_hour_per_month))
                    {
                        cout << "\n\t\tEnter The new Working hours as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    break;

                case 4:
                    cout << "\n\t\tEnter the new price per hour:";
                    while(!(cin >> Emp[Employee_Number-1].price_per_hour))
                    {
                        cout << "\n\t\tEnter The new Price per hour as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    break;

                case 5:
                    cout << "\t\tEnter the New ID of the employee :";
                    while(!(cin >> Emp[Employee_Number-1].ID))
                    {
                        cout << "\n\t\tEnter The ID as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cout << "\n\t\tEnter the new Name of the employee " << Employee_Number+1 << " :";
                    cin.ignore(1000,'\n');
                    getline(cin,Emp[Employee_Number-1].Name);
                    cout << "\n\t\tEnter the working hours per month:";
                    while(!(cin >> Emp[Employee_Number-1].working_hour_per_month))
                    {
                        cout << "\n\t\tEnter The new Working hours as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cout << "\n\t\tEnter the new price per hour:";
                    while(!(cin >> Emp[Employee_Number-1].price_per_hour))
                    {
                        cout << "\n\t\tEnter The new Price per hour as a number: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    break;

                default:
                    cout << "\n\t\tEnter a correct choice";
                    break;
                }
                cout << "\n\t\tDo you want to Continue Updating ?";
                cin >> check;
                cin.get();
                do
                {
                    if (check == 'n' || check == 'N')
                    {
                        exit = true;
                        break;
                    }

                    else if (check != 'n' || check != 'N')
                    {
                        if (check == 'y' || check == 'Y')
                            break;

                        else
                        {
                            cout << "\n\t\tEnter (Y-N):";
                            cin >> check;
                        }
                    }
                }
                while(true);
            }
        }
        while(exit == false);
    }
}

   

void Delete_Employee() // Function to delete The employees Data  
{
    unsigned int Deleted_Item; //declare variable which used in postive or zero means number of employees should not be -1 or it will not be data to remove
    char check; // declare variable to check continue deleting process or not
    bool exit = false; 
    system("cls");
    cin.ignore(100,'\n');
    if (Emps_Number == 0) // if you delete the all empolyees or you didnt add any one in this functions (Add_List_of_Employee,Inset_An_Employee)
    {
        cout << "\t\t No Data to Delete . .";
    }
    else
    {
        do
        {
            system("cls");
            cout << "\n\t\tDelete an entry . .";
            for (int i = 0; i < Emps_Number; i++)
            {
                cout << "\n\t\t" << i+1 << "- " << Emp[i].Name;
            }
            cout << "\n\n\t\tEnter a number of the employee you want to delete.";
            while(!(cin >> Deleted_Item))
            {
                cout << "\n\t\tEnter as a positive number: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            if (Deleted_Item > Emps_Number)
            {
                cout << "\n\t\tEnter a correct number";
                _getch();
            }
            else
            {
                for(int i = (Deleted_Item - 1); i < Emps_Number ; i++) // for loop for deleted a selected employee number and it contains all of his data which it declared in previous functions.
                {
                    Emp[i].ID = Emp[i+1].ID;
                    Emp[i].Name = Emp[i+1].Name;
                    Emp[i].working_hour_per_month = Emp[i+1].working_hour_per_month;
                    Emp[i].price_per_hour = Emp[i+1].price_per_hour;
                    Emp[i].Basic_Salary = Emp[i+1].Basic_Salary;
                    Emp[i].Gross_Salary = Emp[i+1].Gross_Salary;
                    Emp[i].Net_Salary = Emp[i+1].Net_Salary;
                }
                cout << "\n\n\t\tDeleted Sucssesfully . .";
                cout << "\n\t\tDo you want to Continue deleting ?";
                cin >> check;
                cin.get();
                do
                {
                    if (check == 'n' || check == 'N') //if condition to check you will continue deleting process or not.
                    {
                        exit = true;
                        break;
                    }

                    else if (check != 'n' || check != 'N')
                    {
                        if (check == 'y' || check == 'Y')
                            break;

                        else
                        {
                            cout << "\n\t\tEnter (Y-N):";
                            cin >> check;
                        }
                    }
                }
                while(true);
                Emps_Number--;
            }
        }
        while(exit == false);
    }
    cout << "\n\t\tPress any key to go back ...";
    _getch();
}

   

void Compute() // Function to Compute (Total - Gross - Net - Maximum - Minimum) Salary
{
    system("cls");
    cin.ignore(100,'\n'); // leave a terminating character in the stream
    bool Turn_Back = false; // declare vairable to return to compute process
    while (Turn_Back != true)
    {
        system("cls");
        char Option;
        cout << "\n\n";
        cout << "\t\t(T) Total Salary\n";
        cout << "\t\t(G) Gross Salary\n";
        cout << "\t\t(N) Net Salary\n";
        cout << "\t\t(X) Maximum Salary\n";
        cout << "\t\t(I) Minimum Salary\n";
        cout << "\t\t(B) Back to the main menu\n\n";

        cout << "\t\tEnter your choice: ";
        cin >> Option;

        switch (Option)
        {
        case 'G':
        case 'g':
            Compute_Gross();
            for (int i = 0; i < Emps_Number; i++)
            {
                cout << "\t\tThe Gross Salary of " << Emp[i].Name << " is: " << Emp[i].Gross_Salary << endl;
            }
            cout << "\n\n\t\tPress any key to go back ...";
            _getch();
            break;

        case 'T':
        case 't':
            Compute_Total();
            break;

        case 'N':
        case'n':
            Compute_Net();
            for (int i = 0; i < Emps_Number; i++)
            {
                cout << "\t\tThe Net Salary of " << Emp[i].Name << " is: " << Emp[i].Net_Salary << "\n";
            }
            cout << "\t\tThe total net salary is: " << Total_Net;
            cout << "\n\n\t\tPress any key to go back ...";
            _getch();
            break;

        case 'X':
        case 'x':
            Compute_Max();
            break;

        case 'I':
        case 'i':
            Compute_Mini();
            break;

        case 'B':
        case 'b':
            Turn_Back = true;
            cout << "\t\tPress any key ...\n";
            break;

        default:
            system("cls");
            cout << "\t\tEnter a right character.\n";
            cout << "\n\n\t\tPress any key to go back ...";
            _getch();
            break;

        }
    }
}

   

void Compute_Basic() // function to compute The Basic salary Of Employees
{
    system("cls");
    for (int i = 0; i < Emps_Number; i++)
    {
        Emp[i].Basic_Salary = Emp[i].working_hour_per_month * Emp[i].price_per_hour;
    }
}



void Compute_Gross()  // Function To Compute THe Gross Salary Of Employees
{
    system("cls");
    for (int i = 0; i < Emps_Number; i++)
    {
        Emp[i].Gross_Salary = Emp[i].Basic_Salary + (Emp[i].Basic_Salary * 0.52);
    }
}



void Compute_Tax()  // Function To Compute The Taxes For Employees 
{
    for (int i = 0; i < Emps_Number; i++)
    {
        if (Emp[i].Basic_Salary < 0.00)
        {
            Emp[i].Tax = -1;
        }
        else if (Emp[i].Basic_Salary < 15000.00)
        {
            Emp[i].Tax = 0.15 * Emp[i].Basic_Salary;
        }
        else if (Emp[i].Basic_Salary < 30000.00)
        {
            Emp[i].Tax = (Emp[i].Basic_Salary - 15000.00) * 0.16 + 2250.00;
        }
        else if (Emp[i].Basic_Salary < 50000.00)
        {
            Emp[i].Tax = (Emp[i].Basic_Salary < 30000.00) * 0.18 + 4650.00;
        }
        else if (Emp[i].Basic_Salary < 80000.00)
        {
            Emp[i].Tax = (Emp[i].Basic_Salary - 50000.00) * 0.20 + 8250.00;
        }
        else if (Emp[i].Basic_Salary <= 150000.00)
        {
            Emp[i].Tax = (Emp[i].Basic_Salary - 80000.00) * 0.25 + 14250.00;
        }
        else
        {
            Emp[i].Tax = -1;
        }
    }
}

    

void Compute_Net() // Function to Compute The Net salary For Employees
{
    system("cls");
    Compute_Gross();
    Compute_Tax();
    for (int i = 0; i < Emps_Number ; i++)
    {
        Emp[i].Net_Salary = Emp[i].Basic_Salary - Emp[i].Tax;
        Total_Net += Emp[i].Net_Salary;
    }
}

    

void Compute_Total() // Function to compute The Total salary For Employees
{
    system("cls");
    double Total_Salary = 0;
    bool check = true;
    for (int i = 0; i < Emps_Number; i++)
    {
        if (Emp[i].Net_Salary != 0.00 && Emp[i].Basic_Salary != 0.00)
        {
            Total_Salary += (Emp[i].Basic_Salary + Emp[i].Tax);
        }
        else
        {
            check = false;
        }
    }
    if (check == true)
    {
        cout << "\t\tThe total is: " << Total_Salary << "\n";
    }
    else
    {
        cout << "\t\tYou must compute the Net and Basic salary.\n";
    }
    cout << "\n\n\t\tPress any key to go back ...";
    _getch();
}

  

void Compute_Max() // function to compute The Maximum salary Of Employees
{
    system("cls");
    double Max_Number = Emp[0].Basic_Salary;
    for (int i = 0; i < Emps_Number; i++)
    {
        if (Emp[i].Basic_Salary > Max_Number)
        {
            Max_Number = Emp[i].Basic_Salary;
        }
    }
    cout << "\t\tThe Maximum number is: " << Max_Number;
    cout << "\n\n\t\tPress any key to go back ...";
    _getch();
}

 

void Compute_Mini() // function to compute The Minimum salary Of Employees 
{
    system("cls");
    double Mini_Number = Emp[0].Basic_Salary;
    for (int i = 0; i < Emps_Number; i++)
    {
        if (Emp[i].Basic_Salary < Mini_Number)
        {
            Mini_Number = Emp[i].Basic_Salary;
        }
    }
    cout << "\t\tThe Minimum number is: " << Mini_Number;
    cout << "\n\n\t\tPress any key to go back ...";
    _getch();
}

 

void Sort_Data() // Function To Sorting Data According to Basic Salary
{
    for (int i = 0; i < Emps_Number; i++)
    {
        for (int j = 0; j < Emps_Number-1; j++)
        {
            if (Emp[j].Basic_Salary < Emp[j+1].Basic_Salary)
            {
                Swap_data[j].ID = Emp[j].ID;
                Emp[j].ID = Emp[j+1].ID;
                Emp[j+1].ID = Swap_data[j].ID;

                Swap_data[j].Name = Emp[j].Name;
                Emp[j].Name = Emp[j+1].Name;
                Emp[j+1].Name = Swap_data[j].Name;

                Swap_data[j].Basic_Salary = Emp[j].Basic_Salary;
                Emp[j].Basic_Salary = Emp[j+1].Basic_Salary;
                Emp[j+1].Basic_Salary = Swap_data[j].Basic_Salary;

                Swap_data[j].Net_Salary = Emp[j].Net_Salary;
                Emp[j].Net_Salary = Emp[j+1].Net_Salary;
                Emp[j+1].Net_Salary = Swap_data[j].Net_Salary;
            }
        }
    }
}

   

void Write_to_File() // function To write data in a file and Saved Empolyee's data.
{
    ofstream Write_Data;
    Write_Data.open("Employees.xls");
    Write_Data << Emps_Number << endl;
    for (int j = 0; j < Emps_Number; j++)
    {
        Write_Data << Emp[j].ID << endl;
        Write_Data << Emp[j].Name << endl;
        Write_Data << Emp[j].working_hour_per_month << endl;
        Write_Data << Emp[j].price_per_hour << endl;
        Write_Data << Emp[j].Basic_Salary << endl;
        Write_Data << Emp[j].Gross_Salary << endl;
        Write_Data << Emp[j].Net_Salary << endl;
    }
    Write_Data.close();
}

  

void Read_From_File() // Function to Read Data From File and Load Employee's data.
{
    ifstream Read_Data;
    Read_Data.open("Employees.xls");
    Read_Data >> Emps_Number;
    for (int j = 0; j < Emps_Number; j++)
    {
        Read_Data >> Emp[j].ID;
        Read_Data.ignore(1000,'\n');
        getline(Read_Data,Emp[j].Name);
        Read_Data >> Emp[j].working_hour_per_month;
        Read_Data >> Emp[j].price_per_hour;
        Read_Data >> Emp[j].Basic_Salary;
        Read_Data >> Emp[j].Gross_Salary;
        Read_Data >> Emp[j].Net_Salary;
    }
    Read_Data.close();
}
