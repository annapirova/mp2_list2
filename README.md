# mp2_list2


0. ~List();

1. void InsertAfter(const listIterator& it, const DataType& d); // вставить элемент d после звена node

2. listIterator Search(const DataType& d); // найти указатель на звено со значением data = d

3. void DeleteAll(const DataType& d);
```
//  5 3 5 3 1 3 
// DeleteAll(3);
// 5 5 1
```

4. void Delete(const listIterator& start, const listIterator& finish);
```
// 3 4 5 7 9 10
// между 5 и 9
// 3 4 10
```
5. friend ostream& operator<<(ostream& os, const List& l);


6. void MadeUnique(); // исключить повторяющиеся звенья
```
// 1 3 1 5 3 6 --> 1 3 5 6 
```
7. List Merge(const listIterator& start, const List& list2); // создать список3, добавив список2 в текущий список после итератора
```
// *this = 1 5 7 2 
// list2 = 4 5 7
// start(*this) = 7
// l3 = 1 5 7 4 5 7 2 
```

8. void MergeWith(const listIterator& start, List& list2); // в *this добавить список2 после итератора
```
// *this = 1 5 7 2 
// list2 = 4 5 7
// start(*this) = 7
// *this = 1 5 7 4 5 7 2 
// list2 = { }
```

Макаров - 0, 5, 1, 6

Суслова - 0, 5, 2, 7

Еремин - 0, 5, 3, 8

Егорова - 0, 5, 4, 6

Молев - 0, 5, 8, 4

Чемоданов - 0, 5, 6, 3

Веселова - 0, 5, 7, 2
