#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include<Windows.h>
#include<string>
#include"Hospital.h"
#include"Patient.h"
#include"TNode.h"
using namespace std;
void line() {
    cout << "\n-----------------------------------------------------------------------------------------------------";
}

int main()
{
    system("Color 02");
    patientRecord P;
    Hospital st;
    TNode* root;
    root = NULL;
    const int length = 10;
    int i;
    int choice;
    patientRecord h;

    while (1)
    {
        cout << "\n\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n\t\t\t\t\t\t\t";
        line();
        cout << endl;

        cout << "1. Insert Patient" << endl;
        cout << "2. Delete Patient" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Display a specific patient" << endl;
        cout << "5. Display All patient details stored in the Database" << endl;
        cout << "6. Edit the patients data" << endl;
        cout << "7. Split the tree" << endl;
        cout << "7. Exit Program" << endl;
        line();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";
        int input;


        if (choice == 1)
        {
            system("clear");
            line();
            cout << "\n\t\t\t\tPatient Details Input Page";
            line();
            cout << "\nEnter Patient ID to be inserted( Eg 4): ";
            cin >> input;
            cout << "\nEnter Patient name( Eg John ):";
            cin>>h.pname;
            cout << "\nEnter Patient Date of Admission( Eg 12/12/12 ):";
            cin>> h.pDate;
            cout << "\nEnter Patient Diagnosis( Eg Fever ):";
            cin >> h.pDiagnosis;
            cout << "\nEnter Patient Status( Eg Admitted ):";
            cin >> h.pStatus;
            root = st.Insert(input, h, root);
            cout << "\nAfter Insert: " << input << endl;
            st.InOrder(root);
            // getchar();

        }
        if (choice == 2)
        {
            system("clear");
            line();
            cout << "\n\t\t\t\tPatient Details removal Page";
            line();
            cout << "\nEnter Patient to be deleted-:";
            cin >> input;
            root = st.Delete(input, root);
            cout << "\nAfter Delete: " << input << endl;
            st.InOrder(root);
            //getchar();
        }


        if (choice == 3)
        {
            system("clear");
            line();
            cout << "\n\t\t\t\tPatient Detail search Page";
            line();
            cout << "\nEnter Patient No to be searched: ";
            cin >> input;
            root = st.Search(input, root);
            if (root->key == input)
            {
                cout << "\nElement to be searched is found";
                cout << "\nAfter Search " << input << endl;
                st.InOrder(root);
            }
            else {
                cout << "Element Not found";
            }
            //getchar();
        }

        if (choice == 4)
        {
           
            system("clear");
            line();
            cout << "\n\t\t\t\tPatient Detail Display Page";
            line();
            cout << "\nEnter Patient No to be displayed: ";
            cin >> input;
            root = st.Search(input, root);
            if (root->key == input)
            {
                cout << "\nElement to be searched is found";
                st.Output(root);

            }
            else {
                cout << "Element Not found";
            }
            //getchar();
        }
        
        if (choice == 5)
        {
            system("clear");
            cout << setw(49) << "PATIENT DETAILS\n";
            line();
            cout << "\n";
            cout << setw(15) << "Patient No" << setw(15) << "Name" << setw(15) << "Date" << setw(15) << "Diagnosis" << setw(15) << "Status" << "\n";
            line();
            cout << "\n";
            st.PreOrder(root);
            //getchar();
        }

        if (choice == 6)
        {
            system("clear");
            line();
            cout << "\nEnter Patient ID to be inserted( Eg 4): ";
            cin >> input;
            st.Edit(input, root);
          
        }
        if (choice == 7)
        {
            
            
            Hospital st2 = st.split();
            st.InOrder(root);
           st2.InOrder(st2.root);

        }
        cout << "\n";
        if (choice == 8)
        {
            cout << "Program Terminated" << endl;
            return 0;
        }
    }
    return 0;
}
