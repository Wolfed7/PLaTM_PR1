#pragma once
#include <vector>
#include <iostream>

using namespace std;

class StaticTable
{
private:

   vector<string> Table;

public:

   // � �������� ��������� ��������� ���� � ���������� ��������.
   StaticTable(string FilePath);

   // ���������� ����� ���������� � ������� ��������,
   // � ������ ������� ���������� -1. 
   int BinarySearch(string Word);

   // ���������� ������ �������.
   size_t size();
};

