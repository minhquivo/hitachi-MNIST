#include <bits/stdc++.h>
#include "ItemType.h"
#include "UnsortedListByArray.h"

using namespace std;

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.
// Post: Each component in list has been written.
//
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

int main()
{
    cout << "Please type a sequence of strings with a word repeated at least threetimes, please use white space as the delimiter:" << endl;
    string s;
    getline(cin, s);
    cout << "You typed: " << s << endl << endl;
    cout << "Call the old insert item function:" << endl;

    UnsortedListByArray list1, list2, list3, list4, longlist;

    int index = s.find(' ');
    while (index!=-1)
    {
        ItemType it;
        string item = s.substr(0,index);
        s = s.substr(index+1);
        index = s.find(' ');
        it.Initialize(item);
        list1.InsertItem(it);
        if (index==-1)
        {
          it.Initialize(s);
          list1.InsertItem(it);
        }

    }

    cout << "The list created:" << endl;
    PrintList(list1);
    cout << endl << endl;
    cout << "Call the old DeleteItem function:" << endl;
    cout << "After delete the repeated word" << endl;

    ItemType item1;
    item1.Initialize("This");

    ItemType item2;
    item2.Initialize("is");

    ItemType item3;
    item3.Initialize("a");

    ItemType item4;
    item4.Initialize("is");

    ItemType item5;
    item5.Initialize("is");

    ItemType item6;
    item6.Initialize("Hat");

    ItemType item7;
    item7.Initialize("OK");

    list1.DeleteItem(item2);
    PrintList(list1);

    cout << endl << endl;
    cout << "Call the new DeleteAllItems function:" << endl << "After delete all repeated words" << endl;
    list1.DeleteAllItems(item2);
    PrintList(list1);

    cout << endl << endl;
    cout << "Call the new insert item function to insert all words into a new list again:" << endl << "The listed created:" << endl;
    list2.NewInsertItem(item1);
    list2.NewInsertItem(item2);
    list2.NewInsertItem(item3);
    list2.NewInsertItem(item4);
    list2.NewInsertItem(item5);
    PrintList(list2);

    longlist.InsertItem(item1);
    longlist.InsertItem(item3);
    longlist.InsertItem(item6);
    longlist.InsertItem(item7);

    cout << endl << endl << "The long list is" << endl;
    PrintList(longlist);

    cout << endl << endl << "Split with J" << endl << "After split with item :J" << endl;
    ItemType split;
    split.Initialize("J");
    longlist.SplitList(split, list3, list4);
    cout << "list one is :" << endl;
    PrintList(list3);
    cout << endl << endl << "list two is :" << endl;
    PrintList(list4);

    cout << endl << endl << "After split, original list is :" << endl;
    PrintList(longlist);

    return 0;
}
