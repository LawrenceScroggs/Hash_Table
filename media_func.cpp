// This file will implement my functions for my class

#include "media_classes.h"

//remove wrapper
int mediaTrack::remove(){

  media to_add;

  int check = 0;

  check = remove_Priv(to_add);

  if(check == -1) 
  {
    cout << "ERROR" << endl;
    return -1;
  }
  else if(check == 2){
    cout << "NO MATCH FOUND" << endl;
    return -1;
  }
  else{
    cout << "SUCCESFULL REMOVED" << endl;
    return 1;
  }

}
int mediaTrack::remove_Priv(media & to_add){

  char * temp = new char[100];
  int findIndex = 0;

  cout << "Please enter the name of Show/Media Outlet you are looking for: ";
  cin.get(temp,100);
  cin.ignore(100,'\n');

  media * current = hash_table[count];

  if(count > SZ-1) return 2;

  else if(hash_table[count] && count < SZ-1)
  {
    while(current)
    {
      if(toupper(temp) == toupper(current->name)
      if(toupper(temp) != toupper(current->name)
      {
        media * prev = current;
        current = current->next;
        }

  
        }
        }
  //findIndex = findNameIndex(temp);


}
//adds additional info as needed.
int mediaTrack::in_file(media & to_add){

  ifstream file_in;
  file_in.open("mediaTracker.txt");

  if(file_in){

    if(file_in.peek() == -1) return -1;

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
  delete to_add.name;
  delete to_add.channel;
}
// adds a new media item
int mediaTrack::addNew(){

  media add;
  add.name = new char[100];
  cout << "Please enter the Name of Show/Media outlet: ";
  cin.get(add.name,100);
  cin.ignore(100,'\n');
  add.channel = new char[100];
  cout << "Please enter the website or channel: ";
  cin.get(add.channel,100);
  cin.ignore(100,'\n');

  insert(add);
  cout << endl << endl;

  delete add.name;
  delete add.channel;
}
// function for key display/display all 
int mediaTrack::showKeys(){

  int userKey = 0;
  int check = 0;

  cout << "Please enter the key you are wanting to display: ";
  cin >> userKey;
  cin.ignore(100,'\n');

  check = displayKey(userKey);

  if(check == -1)
  {
    cout << "KEY NOT FOUND" << endl << endl;
  }

}
int mediaTrack::displayKey(int userKey){

  int index = userKey%SZ;


  media * current = hash_table[index];

  if(!hash_table[index])
    return -1;

  else if(hash_table[index])
  {
    while(current){
      if(current->hashKey != userKey) return -1;
      
      cout << "Match/es for Key" << endl;
      if(current->hashKey == userKey)
      {
        cout << "Name: " << current->name << endl;
        cout << "Channel/Site: " << current->channel << endl;
        cout << "Key: " << current->hashKey << endl << endl;
      }
    current = current->next;
    }
  
  }
}
//wrapper function for recursive display
int mediaTrack::display(){

  int shows = 0;
  count = 0;
  num_of_media = 0;
  
  shows = displayAll(count);

  //cout << "Number of Shows: " << shows << endl << endl;
}
// recursive function for display all 
int mediaTrack::displayAll(int count){

  media * current = hash_table[count];
    cout << "count: " << count << endl;
  if(count >= SZ-1)
  {
    cout << "End of List" << endl << endl;
    return num_of_media;
  }

  else if(hash_table[count] && count < SZ-1)
  {

    while(current){
    cout << "Name: " << current->name << endl;
    cout << "Channel/Site: " << current->channel << endl;
    cout << "Key: " << current->hashKey << endl << endl;
    current = current->next;
    ++num_of_media;
    }
    ++count;
  }
  while(!hash_table[count] && count < SZ-1)
  {
    ++count;
  }

  return displayAll(count);

}
// adds to table
int mediaTrack::addTo_Priv(media & to_add){

  int returnCode = hashKey(&to_add);

  cout << "return code: " << returnCode << endl;

  media * current = hash_table[returnCode];

  if(!current)
  {
    cout << "test 2" << endl;
    current = new media;
    current->name = new char[strlen(to_add.name) + 1];
    strcpy(current->name,to_add.name);
    current->channel = new char[strlen(to_add.channel) + 1];
    strcpy(current->channel,to_add.channel);
    current->hashKey = searchKey(&to_add);
    hash_table[returnCode] = current;

    current->next = NULL;
    cout << "hash: " << current->name << endl;
  }
  else if(current)
  {

    cout << "in here " << endl;

    current = new media;
    current->name = new char[strlen(to_add.name)+1];
    strcpy(current->name,to_add.name);
    current->channel = new char[strlen(to_add.channel)+1];
    strcpy(current->channel,to_add.channel);
    current->hashKey = searchKey(&to_add);

    current->next = hash_table[returnCode];
    hash_table[returnCode] = current;
    cout << "hash2: " << current->next->name << endl;
  }

}
// function to check for proper insert
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
// this will find the index for name entered
int mediaTrack::findNameIndex(char * temp){

  int sum = 0;
  int power = 0;
  int len = strlen(temp);


  for(int i=0;i<len;++i)
    sum += temp[i];

  sum = sum/23;

  power = pow(sum, 3);

  return power%hash_array;

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
media::media(){

  name = NULL;
  channel = NULL;
  descrip = NULL;
  info = NULL;
  
  rating = 0;
  hashKey = 0;
}
media::~media(){

}
