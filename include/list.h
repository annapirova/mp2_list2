#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

//template <typename DataType>
struct Node
{
  DataType data;
  Node* next;
  
  // здесь могут быть конструкторы, методы, деструктор Node
  Node(DataType d = 0, Node* n = nullptr);
  Node(const Node& node2);
  bool operator==(const Node& node2) const;
};

class listIterator
{
private:
	Node* p;
public:
	listIterator(Node* tmp = nullptr) : p(tmp) {}
	DataType& operator*() { return p->data; } // нужна проверка на p != nullptr
	
	listIterator& operator++() // изменился this
	{ 
		p = p->next; 
		return *this;
	}

	listIterator operator++(int) // создали новый следующему ук-лю
	{
		return listIterator(p->next);
	}

	bool operator==(const listIterator& it2) const
	{
		return (this->p == it2.p);
	}
};

class List
{
  Node* head;

public:
  List();

  bool isEmpty() { return (head == nullptr); }

  void InsertToHead(const DataType& d); // вставить элемент d первым

  DataType ViewHead() 
  { 
	  if (!isEmpty())
		  return head->data;
	  else
		  throw std::logic_error("list is empty");
  }
  
  void InsertToTail(const DataType& d); // вставить элемент d последним

  DataType ViewTail();
										
  void Delete(const DataType& d); // удалить звено со значением data = d											
  listIterator begin() { return listIterator(head); }

  listIterator tail();

  listIterator end(); 

  ~List();
										//  List(const List& list2);
//  List& operator=(const List& list2);
  //~List();

  //
  //DataType ViewHead() { return head->data;  }
  //
  //void Clean(); // удалить все звенья  
  //			
  //myiterator begin() { return myiterator(head); };
		//		
  //void InsertAfter(const myiterator& it, const DataType& d); // вставить элемент d после звена node
  //myiterator Search(const DataType& d); // найти указатель на звено со значением data = d
  //void Delete(const myiterator& it); // удалить звено со значением data = d	
		//								
  //void Delete(const myiterator& start, const myiterator& finish);

  //void DeleteAll(const DataType& d);

  //void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке

  //List Merge(const myiterator& start, const List& list2); // создать список3, добавив список2 в текущий список после итератора 

  //void MergeWith(const myiterator& start, const List& list2); // в *this добавить список2 после итератора

  //friend ostream& operator<<(ostream& os, const List& l);	
  //
  //void MadeUnique(); // исключить повторяющиеся звенья

  //// пересортировка списка: создать новый список, в кот сначала четные, потом нечетные звенья
  //void Reordering();

  //// определить, есть ли цикл в списке
  //bool Cycle();

  //std::string ToString(); // "зн 1; зн2; " 

  ////int GetSize(); // узнать число звеньев в списке
  ////Node* GetHead(); // получить указатель на первое звено списка

  //
  //// 
  ////List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  ////
  ////bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif