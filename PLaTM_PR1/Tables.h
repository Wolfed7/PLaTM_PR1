#pragma once
#include "StaticTable.h"
#include "DynamicTable.h"
#include "Variable.h"

enum TableType
{
   StaticKeywords,
   StaticOperators,
   StaticSeparators,
   StaticBrackets,
   StaticSpecials,
   DynamicVariables,
   DynamicConstants,
};

class Tables
{
   StaticTable *Keywords;
   StaticTable *Operators;
   StaticTable *Separators;
   StaticTable *Brackets;
   StaticTable *Specials;
   
   DynamicTable *Variables;
   DynamicTable *Constants;

public:

   Tables(string, string, string, string, string);

   // ���������� ����: ����� ������� �
   // ����� ���������� � ������� ��������,
   // � ������ ������� ���������� ���� -1. 
   pair<int, int> SearchOnStatic(string Word);
   pair<int, int> SearchOnDynamic(string Word);

   // ����� ������� �� ������, ���������� ���������
   // �� ���������, ���������� ��������.
   Variable *SearchOnDynamic(pair<int, int> Address);

   // ���������� � ������� ��������������� � ��������.
   pair<int, int> IncludeInDynamic(string Word, int Type, int SizeBytes, int FieldOfView);
   pair<int, int> IncludeInDynamic(string Value, int Type);

   // ���������/���������� ��������� ������� �� ������.
   pair<int, int> ChangeNameOrValue(pair<int, int> Address, string Word);
   pair<int, int> ChangeType(pair<int, int> Address, int Type);
   pair<int, int> ChangeSizeBytes(pair<int, int> Address, int SyzeBytes);
   pair<int, int> ChangeFOV(pair<int, int> Address, int FOV);
   
};

