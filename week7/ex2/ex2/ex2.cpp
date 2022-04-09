#include "Vector.h"

int main()
{
    Vector<int> v(10);
    v.push(23);
    v.push(50);
    v.push(99);
    v.push(572);
    v.push(120);
    v.push(1);
    v.push(102);
    v.push(3);
    v.push(555);
    v.push(50);

    v.print();
    printf("Numarul de elemente din vector: %d\n", v.countt());

    v.pop();
    v.print();

    v.delete_element(3);
    v.print();

    v.set(777, 2);
    v.print();

    printf("Element pe poz 3: %d\n", v.get(3));
    printf("Numarul de elemente din vector: %d\n", v.countt());

    v.sort();
    v.print();

    printf("50 apare prima data pe poz: %d\n", v.firstindexOf(50));

    return 0;
}