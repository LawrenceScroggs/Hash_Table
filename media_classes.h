// This file will hold my classes and function
// protoytpes.  

#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct media{

  char * name;
  char * channel;
  char * descrip;
  char * info;

  int rating;
  int hashKey;

  media * next;

};
class mediaTrack{

  public:
    mediaTrack();
    ~mediaTrack();
    //wrapper functions
    int addTo();
    int remove();
    //searching for and displaying keys
    int searchKey();
    int displayAll();
    int displayKeys();
    

  private:
    int addTo_Priv(media *& head); // adds a node to the list
    int remove_Prive(media *& head); // removes a  node from list
    int hashKey(media * head); // produces hash key for placement in array

    int in_file(media *& head); // reads in data from file
    int out_file(media *& head); // moves data to file




};
