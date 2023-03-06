#pragma once
#include <iostream>

using namespace std;

enum VariableType
{
   None,
   Void,
   Char,
   Int,
   Float,
};

enum VariableFieldOfView
{
   Global,
   Local
};

struct Variable
{
   string Name;
   int Type;
   int SizeBytes;
   int FieldOfView;
   //bool IsInitialised;
};