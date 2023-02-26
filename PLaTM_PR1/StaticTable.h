#pragma once
#include <vector>
#include <iostream>

using namespace std;

class StaticTable
{
private:

   vector<string> Table;

public:

   // В качестве аргумента принимает файл с постоянной таблицей.
   StaticTable(string FilePath);

   // Возвращает номер найденного в таблице элемента,
   // в случае неудачи возвращает -1. 
   int BinarySearch(string Word);

   // Возвращает размер таблицы.
   size_t size();
};

