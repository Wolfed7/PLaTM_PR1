#include "Tables.h"

Tables::Tables
(
   string keywords,
   string operators,
   string separators,
   string brackets,
   string specials
)
{
   try
   {
      Keywords   = new StaticTable(keywords  );
      Operators  = new StaticTable(operators );
      Separators = new StaticTable(separators);
      Brackets   = new StaticTable(brackets  );
      Specials   = new StaticTable(specials  );

      Constants = new DynamicTable();
      Variables = new DynamicTable();
   }
   catch (exception ex)
   {
      cout << ex.what();
      exit(EXIT_FAILURE);
   }
}

pair<int, int> Tables::SearchOnStatic(string Word)
{
   int inTableNum = 0;

   inTableNum = Keywords->BinarySearch(Word);
   if (inTableNum != -1)
      return { StaticKeywords,  inTableNum };

   inTableNum = Operators->BinarySearch(Word);
   if (inTableNum != -1)
      return { StaticOperators,  inTableNum };

   inTableNum = Separators->BinarySearch(Word);
   if (inTableNum != -1)
      return { StaticSeparators,  inTableNum };

   inTableNum = Brackets->BinarySearch(Word);
   if (inTableNum != -1)
      return { StaticBrackets,  inTableNum };

   inTableNum = Specials->BinarySearch(Word);
   if (inTableNum != -1)
      return { StaticSpecials,  inTableNum };

   return { -1, -1 };
}

pair<int, int> Tables::SearchOnDynamic(string Word)
{
   int inTableNum = 0;
   inTableNum = Variables->LinearSearch(Word);
   if (inTableNum != -1)
      return { DynamicVariables,  inTableNum };

   inTableNum = Constants->LinearSearch(Word);
   if (inTableNum != -1)
      return { DynamicConstants,  inTableNum };

   return { -1, -1 };
}

Variable *Tables::SearchOnDynamic(pair<int, int> Address)
{
   return Address.first == DynamicVariables ? &Variables->Table[Address.second] : &Constants->Table[Address.second];
}

pair<int, int> Tables::IncludeInDynamic(string Word, int Type, int SizeBytes, int FieldOfView)
{
   pair<int, int> IsExists = SearchOnDynamic(Word);
   if (IsExists != pair<int, int> {-1, -1})
      return IsExists;

   Variable newVar = { Word, Type, SizeBytes, FieldOfView };
   if (Variables->LinearSearch(Word) == -1)
   {
      Variables->Table.push_back(newVar);
      return { DynamicVariables, Variables->Table.size() - 1 };
   }
}

pair<int, int> Tables::IncludeInDynamic(string Value, int Type)
{
   pair<int, int> IsExists = SearchOnDynamic(Value);
   if (IsExists != pair<int, int> {-1, -1})
      return IsExists;

   Variable newVar = { Value, Type };
   if (Constants->LinearSearch(Value) == -1)
   {
      Constants->Table.push_back(newVar);
      return { DynamicConstants, Constants->Table.size() - 1 };
   }
}

pair<int, int> Tables::ChangeNameOrValue(pair<int, int> Address, string Word)
{
   Address.first == DynamicVariables ? Variables->Table[Address.second].Name = Word : Constants->Table[Address.second].Name = Word;
   return Address;
}

pair<int, int> Tables::ChangeType(pair<int, int> Address, int Type)
{
   Address.first == DynamicVariables ? Variables->Table[Address.second].Type = Type : Constants->Table[Address.second].Type = Type;
   return Address;
}

pair<int, int> Tables::ChangeSizeBytes(pair<int, int> Address, int SizeBytes)
{
   Address.first == DynamicVariables ? Variables->Table[Address.second].SizeBytes = SizeBytes : throw new exception("В таблицах констант нет атрибута SizeBytes");
   return Address;
}

pair<int, int> Tables::ChangeFOV(pair<int, int> Address, int FOV)
{
   Address.first == DynamicVariables ? Variables->Table[Address.second].FieldOfView = FOV : throw new exception("В таблицах констант нет атрибута FOV");
   return Address;
}
