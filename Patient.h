#pragma once
#include<iostream> 
#include<string>
using namespace std;
class patientRecord 
{
public:
    string pname;
    int pID;
    string pDate;
    string pDiagnosis;
    string pStatus;

   

    int getPatientid()
    {
        return pID;
    }

  /*  patientRecord(const patientRecord& p1)
    {
        pname = p1.pname;
        pID = p1.pID;
        pDate = p1.pDate;
        pDiagnosis = p1.pDiagnosis;
        pStatus = p1.pStatus;
    }*/
};