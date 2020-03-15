#include "Item.h"

void testItem()
{
    Item item1;
    item1.print();

    Item item2 = item1;

    item2.print();

    Item item3("Parjola", { 1053, 13, 4 });
    item3.print();

    (item1 = item3) = item2;
    item1.print();
}
int main()
{
    Date date;
    
    testItem();
}
