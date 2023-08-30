#include <iostream>
#include <fstream>
#include <string>
#include "proto/address_book.pb.h"

using namespace std;

void ListPeople(xy::AddressBook * address_book) {
  for (int i = 0; i < address_book->person_size(); ++i) {
    const xy::Person &person = address_book->person(i);
    cout << person.name() << " " << person.age() << endl;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " Address bool file " << endl;
    return -1;
  }
  xy::AddressBook address_book;
  {
    fstream input(argv[1], ios::in | ios::binary);
    if (!address_book.ParseFromIstream(&input)) {
      return -1;
    }
    input.close();
  }
  ListPeople(&address_book);
  ListPeople(&address_book);
}
