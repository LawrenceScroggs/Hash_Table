// Lawrence Scroggs CS163 Program 3 02/15/19
// This program will keep track of the information media you want to
// watch and store it into an array.  The array index will
// be decided using a hash function to obtain a key and store.
// The array will be made dynamically and should be able to
// implement add,search,remove, input and output.



#include "media_classes.h"




int main(){

  media to_add,add_new;
  mediaTrack list;

  list.in_file(to_add);

/*  to_add.name = new char[100];
  cout << "Enter name: ";
  jin.get(to_add.name,100); cin.ignore(100,'\n');


  list.insert(&to_add);*/

  list.display();

  list.showKeys();

  list.addNew();

  list.display();








  return 0;

}
