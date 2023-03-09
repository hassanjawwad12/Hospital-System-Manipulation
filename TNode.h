#pragma once
#include<iostream> 
#include"Patient.h"
using namespace std;

class TNode
{
public:
    int key;
    patientRecord val;
    TNode* lchild;
    TNode* rchild;
};
