#include <iostream>
#include <fstream>
#include <string>

#include "proto/address_book.pb.h"

using namespace std;

void PromoptForAddress(xy::Person *person) {
  cout << "Enter Person Name & age: " << endl;
  string name;
  int age;
  cin >> name >> age;
  person->set_name(name);
  person->set_age(age);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " Address bool file << " << endl;
    return -1;
  }

  xy::AddressBook address_book;
  {
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << " : File not found, creating a new file " << endl;
    } else if (!address_book.ParseFromIstream(&input)) {
        return -1;
    }
  }

  PromoptForAddress(address_book.add_person());
  {
    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    if (!address_book.SerializeToOstream(&output)) {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
  }
  return 0;
}
