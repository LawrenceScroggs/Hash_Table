// This file will hold my classes and function
// protoytpes.  

#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

const int SZ = 23;

class media{

  public:
  char * name;
  char * channel; // website or channel 
  char * descrip;
  char * info;

  int rating;
  int hashKey;

  media * next;

  private:

};
class mediaTrack{

  public:
    mediaTrack();
    ~mediaTrack();
    //wrapper functions 
    int insert(media & to_add);
    int remove();
    int display();
    
    int in_file(media & to_add); // reads in data from file
    int out_file(); // moves data to file
    

  private:
    int addTo_Priv(media & to_add); // adds a node to the list
    int remove_Priv(media * to_find); // removes a  node from list
    int hashKey(media * to_add); // produces index for placement in array
    int searchKey(media * to_add); // produces hash key 

    //searching for and displaying keys
    int searchKey();
    int displayAll(int count);
    int displayKeys();


    media ** hash_table; // makes array of dynamically allocated head pointers
    int hash_array; // used for array size 
    int count = 0;


};
