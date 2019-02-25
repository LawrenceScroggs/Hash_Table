// This file will implement my functions for my class

#include "media_classes.h"

int mediaTrack::in_file(media & to_add){

  ifstream file_in;
  file_in.open("mediaTracker.txt");

  if(file_in){

    if(file_in.peek() == -1) return -1;
    /*to_add->name = new char[100];
    file_in.get(to_add->name,100,'@');
    file_in.ignore(100,'@');
    to_add->channel = new char[100];
    file_in.get(to_add->channel,100,'\n');
    file_in.ignore(100,'\n');

    cout << "name: " << to_add->name << endl;
    cout << "channel: " << to_add->channel << endl;

    insert(to_add);*/

    while(file_in && !file_in.eof()){

      if(file_in.peek() == -1){
        
        file_in.clear();
        file_in.close();
        return -1;
      }

      cout << file_in.peek() << endl;
      to_add.name = new char[100];
      file_in.get(to_add.name,100,'@');
      file_in.ignore(100,'@');
      to_add.channel = new char[100];
      file_in.get(to_add.channel,100,'\n');
      file_in.ignore(100,'\n');

      insert(to_add);
    }

  file_in.clear();
  file_in.close();
  }

}
//wrapper function for recursive display
int mediaTrack::display(){

  displayAll(count);

}
// recursive function for display all 
int mediaTrack::displayAll(int count){

  if(count >= SZ-1)
  {
    cout << "End of List" << endl << endl;
    return 1;
  }
  while(!hash_table[count] && count < SZ-1)
  {
    ++count;
  }

  while(hash_table[count] && count < SZ-1)
  {
    cout << "Name: " << hash_table[count] << endl;
    cout << "Channel/Site: " << hash_table[count] << endl;
    cout << "count: " << count << endl;

    hash_table[count] = hash_table[count]->next;

  }
  ++count;

  return displayAll(count);

}
// adds to table
int mediaTrack::addTo_Priv(media & to_add){

  int returnCode = hashKey(&to_add);

  cout << "return code: " << returnCode << endl;

  media * current = new media;

  if(!hash_table[returnCode])
  {
    cout << "test 2" << endl;
    hash_table[returnCode] = new media;
    hash_table[returnCode]->name = new char[strlen(to_add.name) + 1];
    strcpy(hash_table[returnCode]->name,to_add.name);
    hash_table[returnCode]->channel = new char[strlen(to_add.channel) + 1];
    strcpy(hash_table[returnCode]->channel,to_add.channel);
    hash_table[returnCode]->next = NULL;
    cout << "hash: " << hash_table[returnCode]->name << endl;
  }
  else if(hash_table[returnCode])
  {

    cout << "in here " << endl;
 
    current->name = new char[strlen(to_add.name)+1];
    strcpy(current->name,to_add.name);
    current->channel = new char[strlen(to_add.channel)+1];
    strcpy(current->channel,to_add.channel);
  }
  current->next = hash_table[returnCode];
  hash_table[returnCode] = current;
    cout << "hash: " << hash_table[returnCode]->name << endl;
  /*hash_table[returnCode] = new media;
  hash_table[returnCode]->name = new char[strlen(to_add->name) + 1];
  strcpy(hash_table[returnCode]->name,to_add->name);
  hash_table[returnCode]->channel = new char[strlen(to_add->channel) + 1];
  strcpy(hash_table[returnCode]->channel,to_add->channel);
  hash_table[returnCode]->next = NULL;*/



}
// wrapper function to check for proper insert
int mediaTrack::insert(media & to_add){

  int check = 0;

  check = addTo_Priv(to_add);

  if(check == -1)
    cout << "ERROR" << endl;

  else return 1;
  
}
// initalizes array for build
mediaTrack::mediaTrack(){

  hash_array = SZ; // makes hash table size

  hash_table = new media *[SZ];

  for(int i=0; i<SZ;++i)
  {
    cout << "null test" << endl;
    hash_table[i] = NULL;  //sets initial values to null
  }

}
mediaTrack::~mediaTrack(){



}
// this will return the search key for list
int mediaTrack::searchKey(media * to_add){

  int temp = 0;
  int power = 0;
  int len = strlen(to_add->name);


  for(int i=0;i<len;++i)
    temp += to_add->name[i];

  temp = temp/23;

  power = pow(temp, 3);

  return power;

}
// used to pass hash key to table
int mediaTrack::hashKey(media * to_add){

  int temp = 0;
  int power = 0;
  int len = strlen(to_add->name);

 // cout << to_add->name << " name" << endl;

  for(int i=0;i<len;++i)
    temp += to_add->name[i];

  temp = temp/23; 
  power = pow(temp, 3);
  

 // cout << "Power: " << power << "temp: " << temp << "len: " << len <<  endl;

  return power%hash_array;

}

