#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;
const int SIZE = 100;
//.............................................................Variables for admin.............................

string Admin_ID = "PF";
string Admin_Password = "2021";

//............................................................Data Structures For Patient..........................

string Patient_Name[SIZE];
string Patient_Disease[SIZE];
string Patient_Doc_ID[SIZE];
string Patient_ID[SIZE];
string Patient_Password[SIZE];
int Patient_Counter = 0;

//............................................................. Data Structures For Doctor.........................

string Doctor_Name[SIZE];
string Doctor_Speciality[SIZE];
int Doctor_Salary[SIZE];
string Doctor_ID[SIZE];
string Doctor_Password[SIZE];
string Doctor_Status[SIZE];
int Doctor_Counter = 0;

//............................................................. Data Structures For Services..........................

string Service_Name[SIZE];
int Service_Fee[SIZE];
int Service_Counter = 0;

//..................................................................PROTOTYPES........................................

void header();
int User_Selection_Menu();
int Admin_login();
int Admin_Main_Menu();
void Display_Doctor_info(int index);
bool Validation_of_Password(string pass);
void Change_Password(int, int);
void Display_Patient_info(int index);
void Doc_Status(int index);
void Display_Services(int index);
void Recommend_Doctor(string Disease);
void Add_Patient();
void Add_Services();
void Sorting_Doctors();
void Add_Doctor();
int Doctor_Login();
int Doctor_Main_Menu();
int Patient_Login();
int Patient_Main_Menu();
string Extraction_of_Specific_Field(string Source, int field);
void Populating_Patient_Structures();
void Populating_Doctor_File();
void Populating_Doctor_Structures();
void Populating_Patient_File();
void Extraction_of_Admin_password();
void Store_Admin_password();
void Populating_Service_File();
void Populating_Service_Structures();
bool ValidationOnNumberInput(string);

//........................................................................ Header Function.................................................

void header()
{
    system("cls");

    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "**                              Hospital Management System                                    ** " << endl;
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl
         << endl
         << endl;

} //...End of Header

// ..............................................................Menu That Select User of The Application.................................................

int User_Selection_Menu()
{

    system("cls");
    header();
    cout << " --------------------------------------------------------------------------------------------------" << endl;
    cout << "|     option  |                   				 Discription	        	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    1        |  Admin                             						 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    2        |  Patient                             					         |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    3        |  Doctor                                   		        		 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    4        |  Exit                            						 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------| " << endl;
    cout << " Your Option... ";
    int option;
    cin >> option;
    return option;

} //...End of User Selection Menu

//........................................................................  Admin Login screen.................................................

int Admin_login()
{

    header();
    string ID, Password;
    cout << "Enter Admin ID and Password" << endl
         << endl;
    cin.ignore();
    cout << "Admin ID : ";
    getline(cin, ID);

    cout << "Password : ";
    getline(cin, Password);

    if (ID == Admin_ID && Password == Admin_Password)
    {
        return 1;
    }
    else
    {
        header();
        cout << "Wrong ID or Password" << endl;
        cout << "Press any key to continue…";
        getch();
        return 0;
    }
} // end of admin login

//........................................................................  Admin Main Menu.................................................

int Admin_Main_Menu()
{

    int option;

    header();
    cout << "Admin > " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|    option   |                   				 Discription            	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    1        | Add Patient                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    2        | Add Doctor                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    3        | Add Services                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    4        | See Details of all Doctors      						 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    5        | See Details of all Patients                                                   	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    6        | See Doctors list according to increasing order of salary              		 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    7        | Details of Particular Doctor                                   	         	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    8        | Details of Particular Patients                  				 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    9        | See Doctor Status                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    10       | See All Services	                                                         |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    11       | Change Password                                    			         |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    12       | Exit                              						 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << " Your Option...";

    cin >> option;
    return option;
} // end of admin main menu

// ........................................................................ Details of Doctor.................................................

void Display_Doctor_info(int index)
{
    cout.setf(ios::left);
    cout.width(30);
    cout << Doctor_Name[index];
    cout.width(30);
    cout << Doctor_Speciality[index];
    cout.width(30);
    cout << Doctor_Salary[index];
    cout.width(30);
    cout << Doctor_ID[index] << endl;
} //...End of Display_Doctor_info

//.................................................................Validation on number type input...............................................
bool ValidationOnNumberInput(string source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        if (!(source[i] >= 48 && source[i] <= 57))
            return 0;
        i++;
    }
    return 1;
}

//...................................................................... Validation_of_Password.................................................

bool Validation_of_Password(string pass)
{
    int i = 0;

    while (pass[i] != '\0')
    {
        // It will CHeck that password must contain a number
        if (pass[i] >= 48 && pass[i] <= 57)
        {
            return 1;
            break;
        }
        i++;
    }
    return 0;
} // Validation_of_Password

// .......................................................................  Change Password.................................................

void Change_Password(int user, int index = 0)
{

    header();
    string pass;

    if (user == 1) // for admin
    {
        cout << "Admin > Change Password" << endl;

        cout << "Passwrod Must Contain a Number..." << endl;
        cout << "Enter New Password... ";
        cin.ignore();
        getline(cin, pass);

        if (Validation_of_Password(pass))
        {
            Admin_Password = pass;
            cout << endl
                 << "The Password Has been Succesfully Changed..." << endl
                 << endl;
        }
        else
            cout << "Password is not Valid..." << endl;
    }
    if (user == 2) // for Patient
    {
        cout << "Patient > Change Password" << endl;

        cout << "Passwrod Must Contain a Number..." << endl;
        cout << "Enter New Password... ";
        cin.ignore();
        getline(cin, pass);

        if (Validation_of_Password(pass))
        {
            Patient_Password[index] = pass;
            cout << endl
                 << "The Password Has been Succesfully Changed..." << endl
                 << endl;
        }
        else
            cout << "Password is not Valid..." << endl;
    }
    if (user == 3) // for Doctor
    {
        cout << "Doctor > Change Password" << endl;
        cout << "Passwrod Must Contain a Number..." << endl;
        cout << "Enter New Password... ";
        cin.ignore();
        getline(cin, pass);

        if (Validation_of_Password(pass))
        {
            Doctor_Password[index] = pass;
            cout << endl
                 << "The Password Has been Succesfully Changed..." << endl
                 << endl;
        }
        else
            cout << "Password is not Valid..." << endl;
    }

    cout << "Press any key to continue..." << endl;
    getch();

} // end of Change_Password

// ........................................................................ Details of Patient.................................................

void Display_Patient_info(int index)
{
    cout.setf(ios::left);
    cout.width(30);
    cout << Patient_Name[index];
    cout.width(30);
    cout << Patient_Disease[index];
    cout.width(30);
    cout << Patient_Doc_ID[index];
    cout.width(30);
    cout << Patient_ID[index] << endl;
} // End of PAtient info

// ........................................................................ See Doctor Status.................................................

void Doc_Status(int index)
{
    cout.setf(ios::left);
    cout.width(30);
    cout << Doctor_Name[index];
    cout.width(30);
    cout << Doctor_Status[index];
    cout.width(30);
    cout << Doctor_ID[index] << endl;
} // End of doc status

// ........................................................................ Display Services.................................................

void Display_Services(int index)
{
    cout.setf(ios ::left);
    cout.width(30);
    cout << Service_Name[index];
    cout.width(30);
    cout << Service_Fee[index] << endl;
} // end of dislay services

// ........................................................................ Recommend DOctor.................................................

void Recommend_Doctor(string Disease)
{
    bool flag = 1; // if it is true then no doctor is availbe for recomendation
    for (int i = 0; i < Doctor_Counter; i++)
    {
        if (Doctor_Speciality[i] == Disease)
        {
            cout << "Doctor " << Doctor_Name[i] << " with ID : " << Doctor_ID[i] << " is recommended for this patient"
                 << endl;
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << "No recommendations availabe..." << endl;
    }
} // End of Recommend Doctor

// ........................................................................   Add Patient.................................................

void Add_Patient()
{
    header();
    cout << "Admin > Add Patient" << endl;

    cout << "Enter Patient Name : ";
    cin.ignore();
    getline(cin, Patient_Name[Patient_Counter]);
    cout << endl
         << "Enter Patient Disease : ";
    getline(cin, Patient_Disease[Patient_Counter]);

    Recommend_Doctor(Patient_Disease[Patient_Counter]);

    cout << endl
         << "Enter Patient's Doctor ID : ";

    getline(cin, Patient_Doc_ID[Patient_Counter]);

    cout << endl
         << "Assign ID to Patient : ";
    getline(cin, Patient_ID[Patient_Counter]);
    cout << endl
         << "Assign Password : ";
    string pass;
    getline(cin, pass);

    //.............validaiton on password............

    if (Validation_of_Password(pass))
    {
        Patient_Password[Patient_Counter] = pass;

        //.........CHECKING FOR UNIQUENESS IN ID............

        if (Patient_Counter > 0)
        {
            bool flag = 1;
            for (int i = Patient_Counter - 1; i >= 0; i--)
            {

                if (Patient_Counter == 0)
                    continue;
                if (Patient_ID[Patient_Counter] == Patient_ID[i])
                {

                    Patient_Counter--;
                    system(" cls ");
                    header();
                    cout << "Admin > Add Patients" << endl;
                    cout << "You Cannot Add Patients  with same ID. " << endl;
                    cout << endl
                         << "Press any key to continue… ";
                    flag = 0;
                    getch();
                }
            }
            if (flag)
            {
                cout << "The patient has been Added" << endl;
                cout << endl
                     << "Press any key to continue… ";
                getch();
            }
        }

        Patient_Counter++;
    }

    else
    {

        cout << endl
             << "Password is not Valid..." << endl;
        cout << "PAssword must contain a number..." << endl;
        cout << endl
             << "Press any key to continue… ";
        getch();
    }

} //...End of Add patient

//........................................................................... Add Services.................................................

void Add_Services()
{
    header();
    cout << "Admin > Add services" << endl;

    cout << "Enter Service Name : ";
    cin.ignore();
    getline(cin, Service_Name[Service_Counter]);

    cout << "Enter Service Fee : ";
    string fee;
    cin >> fee;
    if (ValidationOnNumberInput(fee))
    {
        Service_Fee[Service_Counter] = stoi(fee);
        cout << "The Service Has been Added" << endl;
        Service_Counter++;
    }
    else
    {
        cout << endl
             << "Fee Must contain only a Number....";
    }
    cout << endl
         << "Press any key to continue… ";
    getch();

} // End of Add Services

// .........................................................................Sorting of Doctors.................................................

void Sorting_Doctors()
{
    /* temporary arrays for storing values of DOctor_salary and their respective indices */

    // I use this logic it prevent my original array from rearranging
    int temp[Doctor_Counter];
    int index[Doctor_Counter];

    //....................................................................................

    // filling of index
    for (int i = 0; i < Doctor_Counter; i++)
    {
        index[i] = i;
    }

    // filling of temp
    for (int i = 0; i < Doctor_Counter; i++)
    {
        temp[i] = Doctor_Salary[i];
    }

    // sorting indices in index array
    for (int i = 0; i < Doctor_Counter; i++)
    {
        for (int j = 0; j < Doctor_Counter - 1; j++)
        {
            int tempValue = temp[j];
            int tempIndex = index[j];
            if (temp[j] < temp[j + 1])
            {
                temp[j] = temp[j + 1];
                temp[j + 1] = tempValue;
                index[j] = index[j + 1];
                index[j + 1] = tempIndex;
            }
        }
    }
    // Printing Sorted List of doctors
    cout.setf(ios::left);
    cout.width(30);
    cout << "Name";
    cout.width(30);
    cout << "Speciality";
    cout.width(30);
    cout << "Salary";
    cout.width(30);
    cout << "ID" << endl
         << endl;
    for (int i = 0; i < Doctor_Counter; i++)
    {
        Display_Doctor_info(index[i]);
    }
} // End of Sorting Doctors

// ...........................................................................Add Doctor.................................................

void Add_Doctor()
{

    header();
    cout << "Admin > Add Doctor" << endl;

    cout << "Enter Doctor Name : ";
    cin.ignore();
    getline(cin, Doctor_Name[Doctor_Counter]);

    cout << endl
         << "Enter Doctor's Speciality : ";
    getline(cin, Doctor_Speciality[Doctor_Counter]);

    cout << endl
         << "Enter Doctor's Salary  : ";
    string salary;
    cin >> salary;

    //..............validaiton on salary...............

    if (ValidationOnNumberInput(salary))
    {
        Doctor_Salary[Doctor_Counter] = stoi(salary);

        cout << endl
             << "Enter Doctor's Status  : ";
        cin.ignore();
        getline(cin, Doctor_Status[Doctor_Counter]);
        cout << endl
             << "Assign ID to Doctor : ";
        getline(cin, Doctor_ID[Doctor_Counter]);
        string pass;
        cout << endl
             << "Assign Password : ";
        getline(cin, pass);

        //.............validaiton on password............

        if (Validation_of_Password(pass))
        {
            Doctor_Password[Doctor_Counter] = pass;

            //.........CHECKING FOR UNIQUENESS IN ID............

            if (Doctor_Counter > 0)
            {
                bool flag = 1;
                for (int i = Doctor_Counter - 1; i >= 0; i--)
                {

                    if (Doctor_Counter == 0)
                        continue;
                    if (Doctor_ID[Doctor_Counter] == Doctor_ID[i])
                    {

                        Doctor_Counter--;
                        system(" cls ");
                        header();
                        cout << "Admin > Add Doctors" << endl;
                        cout << endl
                             << "You Cannot Add Doctors  with same ID. " << endl;
                        cout << "Press any key to continue… ";
                        flag = 0;
                        getch();
                    }
                }
                if (flag)
                {
                    cout << "The Doctor has been Added" << endl;
                    cout << endl
                         << "Press any key to continue… ";
                    getch();
                }
            }

            Doctor_Counter++;
        }
        else
        {
            cout << endl
                 << "Password is not Valid..." << endl;
            cout << "PAssword must contain a number..." << endl;
            cout << endl
                 << "Press any key to continue… ";
            getch();
        }
    }
    else
    {
        cout << endl
             << "Salary Must contain Numbers only...";
        cout << endl
             << "Press any key to continue… ";
        getch();
    }

} //...End of Add_Doctor

//........................................................................... Doctor_Login.................................................

int Doctor_Login()
{
    header();
    string ID, Password;
    cout << "Enter Doctor ID and Password" << endl
         << endl;

    cout << "Doctor ID : ";
    cin.ignore();
    getline(cin, ID);

    cout << "Password : ";
    getline(cin, Password);

    //...........Checking whether doctor exist or not...........

    for (int i = 0; i < Doctor_Counter; i++)
    {
        if (ID == Doctor_ID[i] && Password == Doctor_Password[i])
            return i;
    }
    return -1;

} // End of Doctor login

// ...........................................................................Doctor Main_menu.................................................

int Doctor_Main_Menu()
{
    header();

    cout << "Doctor > " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|    option   |                   				 Discription            	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    1        | My Details                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    2        | Patient Details                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    3        | All Services                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    4        | Change Status     						                 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    5        | Change Password                                                               	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    6        | Exit                                                                      	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << " Your Option...";

    int option;
    cin >> option;

    return option;
} // ENd of Doctor MAin menu

// ...........................................................................Patient Login.................................................

int Patient_Login()
{
    header();
    string ID, Password;
    cout << "Enter Patient ID and Password" << endl
         << endl;

    cout << "Patient ID : ";
    cin.ignore();
    getline(cin, ID);

    cout << "Password : ";
    getline(cin, Password);

    //...........Checking whether doctor exist or not...........

    for (int i = 0; i < Patient_Counter; i++)
    {
        if (ID == Patient_ID[i] && Password == Patient_Password[i])
            return i;
    }
    return -1;

} // End of PAtient login

//........................................................................... Paient Main Menu.................................................

int Patient_Main_Menu()
{
    header();

    cout << "Patient > " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|    option   |                   				 Discription            	 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    1        | My Details                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    2        | Doctor Status                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    3        | All Services                              					 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    4        | Change Password   				                                 |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << "|    5        | Exit     						                         |" << endl;
    cout << "|------------------------------------------------------------------------------------------------|" << endl;
    cout << " Your Option...";

    int option;
    cin >> option;

    return option;
} // ENd of Patient main menu

// ..................................................................Extraction of specific Field from File.................................................

string Extraction_of_Specific_Field(string Source, int field)
{
    int count_comma = 0;
    int i = 0;

    //............CHeking for Comma According to field

    while (count_comma < field - 1)
    {
        if (Source[i] == ',')
            count_comma++;
        i++;
    }

    //.............Extracting the field

    string temp = "";
    while (1)
    {
        temp = temp + Source[i];
        i++;
        if (Source[i] == ',' || Source[i] == '\0')
            break;
    }

    return temp;
} // End of Extraction of SPecific Field

//...................................................................Populatiing Patient's Data Structures from File.................................................

void Populating_Patient_Structures()
{

    fstream patientFile("Patients.txt", ios ::in);
    string temp = " ";

    //............................cheking whether file is empty or not...........
    char chk;
    patientFile >> chk;

    if (!patientFile.eof()) //.........................control goes inside If file is not empty
    {

        patientFile.seekg(0, ios::beg); //..........To go back to starting of file

        while (!patientFile.eof())
        {

            getline(patientFile, temp);

            //...The below condition is used to prevent reading a blank line because file contains a blank line at end

            if (patientFile.eof())
            {
                break;
            }

            //.........................................................................................................

            Patient_Name[Patient_Counter] = Extraction_of_Specific_Field(temp, 1);
            Patient_Disease[Patient_Counter] = Extraction_of_Specific_Field(temp, 2);
            Patient_Doc_ID[Patient_Counter] = Extraction_of_Specific_Field(temp, 3);
            Patient_ID[Patient_Counter] = Extraction_of_Specific_Field(temp, 4);
            Patient_Password[Patient_Counter] = Extraction_of_Specific_Field(temp, 5);
            Patient_Counter++;
        }
    }
    patientFile.close();
} // End of Populating PAtient Structures

// ...................................................................Populatiing Doctor's Data Structures from File.................................................

void Populating_Doctor_Structures()
{

    fstream DoctorFile("Doctors.txt", ios ::in);
    string temp = " ";

    //............................cheking whether file is empty or not...........
    char chk;
    DoctorFile >> chk;

    if (!DoctorFile.eof()) //.........................control goes inside If file is not empty
    {
        DoctorFile.seekg(0, ios::beg); //..........To go back to starting of file

        while (!DoctorFile.eof())
        {

            getline(DoctorFile, temp);

            //...The below condition is used to prevent reading a blank line because file contains a blank line at end

            if (DoctorFile.eof())
            {
                break;
            }

            //.........................................................................................................

            Doctor_Name[Doctor_Counter] = Extraction_of_Specific_Field(temp, 1);
            Doctor_Speciality[Doctor_Counter] = Extraction_of_Specific_Field(temp, 2);
            Doctor_Salary[Doctor_Counter] = stoi(Extraction_of_Specific_Field(temp, 3));
            Doctor_Status[Doctor_Counter] = Extraction_of_Specific_Field(temp, 4);
            Doctor_ID[Doctor_Counter] = Extraction_of_Specific_Field(temp, 5);
            Doctor_Password[Doctor_Counter] = Extraction_of_Specific_Field(temp, 6);
            Doctor_Counter++;
        }
    }
    DoctorFile.close();
} // ENd of populating Doctor Structures

// ........................................................................populating File with Doctors info.................................................

void Populating_Doctor_File()
{

    fstream DoctorFile("Doctors.txt", ios ::out);
    for (int i = 0; i < Doctor_Counter; i++)
    {
        DoctorFile << Doctor_Name[i] << "," << Doctor_Speciality[i] << "," << Doctor_Salary[i] << "," << Doctor_Status[i] << "," << Doctor_ID[i] << "," << Doctor_Password[i];
        DoctorFile << endl;
    }

    DoctorFile.close();
} // ENd of populating doctor file

// .......................................................................populating File with PAtients info.................................................

void Populating_Patient_File()
{

    fstream patientFile("Patients.txt", ios ::out);
    for (int i = 0; i < Patient_Counter; i++)
    {
        patientFile << Patient_Name[i] << "," << Patient_Disease[i] << "," << Patient_Doc_ID[i] << "," << Patient_ID[i] << "," << Patient_Password[i];
        patientFile << endl;
    }

    patientFile.close();
} // end of populating patient file

// .......................................................................Extraction of Admin password from file.................................................

void Extraction_of_Admin_password()
{
    fstream adminFile("Admin.txt", ios ::in);
    //............................cheking whether file is empty or not...........

    char chk;
    adminFile >> chk;

    if (!adminFile.eof()) //.........................control goes inside If file is not empty
    {
        adminFile.seekg(0, ios::beg); //..........To go back to starting of file
        getline(adminFile, Admin_Password);
    }
    adminFile.close();
} // end of extraction of admin password

//........................................................................Storing admin password in file.................................................

void Store_Admin_password()
{
    fstream adminFile("Admin.txt", ios ::out);
    adminFile << Admin_Password;
    adminFile.close();
} // ENd of store Admin PAssword

//......................................................................    Populating File with Services.................................................

void Populating_Service_File()
{
    fstream serviceFile("Services.txt", ios ::out);
    for (int i = 0; i < Service_Counter; i++)
    {
        serviceFile << Service_Name[i] << "," << Service_Fee[i];
        serviceFile << endl;
    }

    serviceFile.close();
} // end of populating Service File

//......................................................................Populating Service Structures from file.................................................

void Populating_Service_Structures()
{
    fstream serviceFile("Services.txt", ios ::in);
    string temp = " ";

    //............................cheking whether file is empty or not...........
    char chk;
    serviceFile >> chk;

    if (!serviceFile.eof()) //.........................control goes inside If file is not empty
    {
        serviceFile.seekg(0, ios::beg); //..........To go back to starting of file

        while (!serviceFile.eof())
        {

            getline(serviceFile, temp);

            //...The below condition is used to prevent reading a blank line because file contains a blank line at end

            if (serviceFile.eof())
            {
                break;
            }

            //.........................................................................................................

            Service_Name[Service_Counter] = Extraction_of_Specific_Field(temp, 1);
            Service_Fee[Service_Counter] = stoi(Extraction_of_Specific_Field(temp, 2));
            Service_Counter++;
        }
    }
    serviceFile.close();
} // end Populating_Service_Structures()

//........................................................................... Start of main.................................................

int main()
{

    //...................Filling oF all Data Structures From FIle....................

    Populating_Service_Structures();
    Extraction_of_Admin_password();
    Populating_Doctor_Structures();
    Populating_Patient_Structures();

    //................................................................................

    int option; // It will store USer type

    while (1)
    {
        header();
        option = User_Selection_Menu();

        //.....................If user enter wrong input in selecting user.............

        if (option > 4 || option < 1)
            continue;

        //.............................................................................

        // Selection According Value of option Variable

        if (option == 1) // For Admin
        {
            int admin_option = 1; // For storing admin selected option
            header();

            if (Admin_login())
            {
                while (admin_option != 12)
                {
                    header();
                    admin_option = Admin_Main_Menu();

                    if (admin_option == 1)
                    {
                        Add_Patient();
                    } //.....ENd of Option 1

                    else if (admin_option == 2)
                    {
                        Add_Doctor();
                    } //.....ENd of Option 2

                    else if (admin_option == 3)
                    {
                        Add_Services();
                    } //.....ENd of Option 3

                    else if (admin_option == 4)
                    {

                        header();

                        if (Doctor_Counter == 0) // If no Doctor is Added
                        {
                            cout << "Admin > See Details of All Doctors" << endl;
                            cout << "No Record Found..." << endl;
                        }
                        else
                        {
                            cout << "Admin > See Details of All Doctors" << endl;
                            cout.setf(ios::left);
                            cout.width(30);
                            cout << "Name";
                            cout.width(30);
                            cout << "Speciality";
                            cout.width(30);
                            cout << "Salary";
                            cout.width(30);
                            cout << "ID" << endl
                                 << endl;
                            for (int i = 0; i < Doctor_Counter; i++)
                            {
                                Display_Doctor_info(i);
                            }
                        }
                        cout << "Press Any Key to Continue..." << endl;
                        getch();
                    } //.....ENd of Option 4

                    else if (admin_option == 5)
                    {
                        header();

                        if (Patient_Counter == 0) // If no patient is added
                        {
                            cout << "Admin > See Details of All Patients" << endl;
                            cout << "No Record Found..." << endl;
                        }
                        else
                        {
                            cout << "Admin > See Details of All Patients" << endl;
                            cout.setf(ios::left);
                            cout.width(30);
                            cout << "Name";
                            cout.width(30);
                            cout << "Disease";
                            cout.width(30);
                            cout << "Doc ID";
                            cout.width(30);
                            cout << "ID" << endl
                                 << endl;
                            for (int i = 0; i < Patient_Counter; i++)
                                Display_Patient_info(i);
                        }
                        cout << "Press Any Key to Continue..." << endl;
                        getch();

                    } //.....ENd of Option 5

                    else if (admin_option == 6)
                    {
                        header();

                        if (Doctor_Counter == 0) // if no Doctor is added
                        {
                            cout << "Admin > Details of Doctors according to increasing order of salary.." << endl;
                            cout << "Record Not Found..." << endl;
                        }
                        else
                        {
                            cout << "Admin > Details of Doctors according to increasing order of salary.." << endl;
                            Sorting_Doctors();
                        }
                        cout << endl
                             << "Press Any Key To Continue..." << endl;
                        getch();

                    } //.....ENd of Option 6

                    else if (admin_option == 7)
                    {
                        header();
                        bool flag = 0; // If it is false then ID will be wrong

                        cout << "Admin > Details of Particular Doctor" << endl;
                        string ID;
                        cout << "Enter Doctor's ID : ";
                        cin.ignore();
                        getline(cin, ID);
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Speciality";
                        cout.width(30);
                        cout << "Salary";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        for (int i = 0; i < Doctor_Counter; i++)
                        {
                            if (ID == Doctor_ID[i]) // If user enter right ID
                            {
                                Display_Doctor_info(i);
                                flag = 1;
                            }
                        }

                        if (flag == 0)
                        {
                            header();
                            cout << "Admin > Details of Particular Doctor" << endl;
                            cout << "Record Not Found..." << endl;
                        }
                        cout << "Press Any Key To continue...";
                        getch();

                    } //.....ENd of Option 7

                    else if (admin_option == 8)
                    {

                        header();
                        bool flag = 0; // If it is false then ID will be wrong

                        cout << "Admin > Details of Particular Patient" << endl;
                        string ID;

                        cout << "Enter Patient's ID : ";
                        cin.ignore();
                        getline(cin, ID);
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Disease";
                        cout.width(30);
                        cout << "Doc ID";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        for (int i = 0; i < Patient_Counter; i++)
                        {
                            if (ID == Patient_ID[i]) // If user enter right ID
                            {
                                Display_Patient_info(i);
                                flag = 1;
                            }
                        }

                        if (flag == 0)
                        {
                            header();
                            cout << "Admin > Details of Particular Patient" << endl;
                            cout << "Record Not Found..." << endl;
                        }
                        cout << "Press Any Key To continue...";
                        getch();

                    } //.....ENd of Option 8

                    else if (admin_option == 9)
                    {
                        header();
                        bool flag = 0; // If it is false then ID will be wrong
                        cout << "Admin > Doctor Status" << endl;
                        string ID;

                        cout << "Enter Doctor's ID : ";
                        cin.ignore();
                        getline(cin, ID);
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Status";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        for (int i = 0; i < Doctor_Counter; i++)
                        {
                            if (ID == Doctor_ID[i]) // If user enter right ID
                            {
                                Doc_Status(i);
                                flag = 1;
                            }
                        }
                        if (flag == 0)
                        {
                            header();
                            cout << "Admin > Doctor Status" << endl;
                            cout << "No Record Found..." << endl;
                        }
                        cout << "Press Any Key To continue...";
                        getch();

                    } //.....ENd of Option 9

                    else if (admin_option == 10)
                    {
                        header();
                        cout << "Admin > See All Services :" << endl;

                        if (Service_Counter == 0) // If no Service is added yets
                        {
                            cout << "No Record Found..." << endl;
                        }
                        else
                        {
                            cout.setf(ios::left);
                            cout.width(30);
                            cout << "Name";
                            cout.width(30);
                            cout << "Fee" << endl
                                 << endl;
                            for (int i = 0; i < Service_Counter; i++)
                                Display_Services(i);
                        }
                        cout << "Press any Key To Continue..." << endl;
                        getch();

                    } //.....ENd of Option 10

                    else if (admin_option == 11)
                    {
                        Change_Password(1);
                    } //.....ENd of Option 11

                } //..End of Admin While Loop

            } //..End of IF ( admin_login () )
            else
                continue;

        } //......end of Admin If

        else if (option == 2) // FOr PAtient
        {
            int Patient_Option = 1; // For storing PAtient selected option
            header();

            int Patient_number = Patient_Login(); // it return -1 if password is incorrect

            if (Patient_number != -1)
            {
                while (Patient_Option != 5)
                {
                    header();
                    Patient_Option = Patient_Main_Menu();

                    if (Patient_Option == 1)
                    {
                        header();
                        cout << "Patient > My Details" << endl;
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Disease";
                        cout.width(30);
                        cout << "Doc ID";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        Display_Patient_info(Patient_number);

                        cout << "Press Any Key To continue...";
                        getch();
                    } //...End of option 1

                    else if (Patient_Option == 2)
                    {
                        header();
                        cout << "Patient > Doctor Status" << endl;
                        string ID;

                        cout << "Enter Doctor's ID : ";
                        cin.ignore();
                        getline(cin, ID);
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Status";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        bool flag = 0; // if its value is false then entered ID will be wrong

                        for (int i = 0; i < Doctor_Counter; i++)
                        {
                            if (ID == Doctor_ID[i])
                            {
                                Doc_Status(i);
                                flag = 1;
                            }
                        }

                        if (flag == 0)
                        {
                            header();
                            cout << "Patient > Doctor Status" << endl;
                            cout << "No Record Found..." << endl;
                        }

                        cout << "Press Any Key To continue...";
                        getch();

                    } //...End of option 2

                    else if (Patient_Option == 3)
                    {
                        header();
                        cout << "Patient > See All Services :" << endl;

                        if (Service_Counter == 0) // If no Service is added yet
                        {
                            cout << "No Record Found..." << endl;
                        }

                        else
                        {
                            cout.setf(ios::left);
                            cout.width(30);
                            cout << "Name";
                            cout.width(30);
                            cout << "Fee" << endl;
                            for (int i = 0; i < Service_Counter; i++)
                                Display_Services(i);
                        }

                        cout << "Press any Key To Continue..." << endl;
                        getch();

                    } //...End of option 3

                    else if (Patient_Option == 4)
                    {
                        Change_Password(2, Patient_number);
                    } //...End of option 4

                    else if (option == 5)
                    {
                        break;
                    } //...End of option 5

                } //...End of PAtient While

            } // End of Patient_number != -1

            else // If ID or PAssword is incorrect
            {
                header();
                cout << "Wrong ID or Password" << endl;
                cout << "Press any key to continue…";
                getch();
            }

        } //.......... End of PAtient IF

        else if (option == 3) // FOr Doctor
        {
            int Doctor_option = 1; // SFor storing PAtient selected option
            header();

            int Doctor_Number = Doctor_Login();

            if (Doctor_Number != -1) // it return -1 if password is incorrect
            {
                while (Doctor_option != 6)
                {
                    header();
                    Doctor_option = Doctor_Main_Menu();

                    if (Doctor_option == 1)
                    {
                        header();
                        cout << "Doctor > My Details" << endl;
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Speciality";
                        cout.width(30);
                        cout << "Salary";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        Display_Doctor_info(Doctor_Number);

                        cout << "Press Any Key To continue...";
                        getch();
                    } //...ENd of option 1

                    else if (Doctor_option == 2)
                    {
                        header();
                        cout << "Doctor > Patient Details" << endl;
                        string ID;

                        cout << "Enter Patient's ID : ";
                        cin.ignore();
                        getline(cin, ID);
                        cout.setf(ios::left);
                        cout.width(30);
                        cout << "Name";
                        cout.width(30);
                        cout << "Disease";
                        cout.width(30);
                        cout << "Doc ID";
                        cout.width(30);
                        cout << "ID" << endl
                             << endl;

                        bool flag = 0; // if its value is false then entered ID will be wrong

                        for (int i = 0; i < Patient_Counter; i++)
                        {
                            if (ID == Patient_ID[i])
                            {
                                Display_Patient_info(i);
                                flag = 1;
                            }
                        }

                        if (flag == 0)
                        {
                            header();
                            cout << "Doctor > Patient Details" << endl;
                            cout << "No Record Found..." << endl;
                        }
                        cout << "Press Any Key To continue...";
                        getch();
                    } //...ENd of option 2

                    else if (Doctor_option == 3)
                    {
                        header();
                        cout << "Doctor > See All Services :" << endl;

                        if (Service_Counter == 0) // If no Service is added yet
                        {
                            cout << "No Record Found..." << endl;
                        }
                        else
                        {
                            cout.setf(ios::left);
                            cout.width(30);
                            cout << "Name";
                            cout.width(30);
                            cout << "Fee" << endl;
                            for (int i = 0; i < Service_Counter; i++)
                                Display_Services(i);
                        }

                        cout << "Press any Key To Continue..." << endl;
                        getch();

                    } //...ENd of option 3

                    else if (Doctor_option == 4)
                    {
                        header();
                        cout << "Doctor > Change Status" << endl;
                        cout << "Your Current Status :\t " << Doctor_Status[Doctor_Number] << endl;
                        cout << "Your New Status : ";
                        cin.ignore();
                        getline(cin, Doctor_Status[Doctor_Number]);
                        cout << endl
                             << "The Status has been Changed" << endl;
                        cout << "Press any Key To Continue..." << endl;
                        getch();
                    } //...ENd of option 4

                    else if (Doctor_option == 5)
                    {
                        Change_Password(3, Doctor_Number);
                    } //...ENd of option 5

                } //..End of Doctor While Loop

            } //.. End of Doctor_Number != -1

            else // If ID or PAssword is incorrect
            {

                header();
                cout << "Wrong ID or Password" << endl;
                cout << "Press any key to continue…";
                getch();
            }

        } //..End of DOctor IF

        else if (option == 4) // FOr exit
        {
            break;
        } //..End of Exit

    } //............................End of LEading While

    //............Populating FIles With Data Structures.....................

    Populating_Patient_File();
    Populating_Doctor_File();
    Populating_Service_File();
    Store_Admin_password();

    //......................................................................

    //.........Exit MEssage............

    header();
    cout << "\t\t\t\t\t Thanks For Using Our Application" << endl;
    cout << "Press Any Key To Continue...";

    //.................................

    getch();

} //..End of main