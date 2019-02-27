// This file will hold my classes and function
// protoytpes.  

#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

const int SZ = 23; // changed from 139// changed from 13// changed from 43// changed from 23

class media{

  public:
  media();
  ~media();
  char * name;
  char * channel; // website or channel 
  char * descrip; // description of show
  char * info; // information learned 

  int rating;
  int hashKey;

  media * next;

  private:

};
class mediaTrack{

  public:
    mediaTrack();
    ~mediaTrack();

    int insert(media & to_add);
    int remove();
    int showKeys();
    int addNew();

    // file in and out functions
    int in_file(media & to_add); // reads in data from file
    int out_file(); // moves data to file
   
    //wrapper function
    int display();

  private:
    int addTo_Priv(media & to_add); // adds a node to the list
    int remove_Priv(media & to_find,char * temp,int count); // removes a  node from list
    int hashKey(media * to_add); // produces index for placement in array
    int searchKey(media * to_add); // produces hash key 

    //searching for and displaying keys
    int displayKey(int userKey);
    int displayAll(int count);
    int displayKeys();
    int findNameIndex(char * temp); // finds index for user entered name


    media ** hash_table; // makes array of dynamically allocated head pointers
    int hash_array; // used for array size 
    int count = 0;
    int num_of_media = 0;


};
