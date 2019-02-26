// This file will implement my functions for my class

#include "media_classes.h"


//reads file out to .txt
int mediaTrack::out_file(){

  ofstream file_out;
  file_out.open("mediaTracker.txt");


  count = 0;
 
  while(count != SZ-1)
  {
    media * current = hash_table[count];
    if(hash_table[count] && count < SZ-1)
    {

      while(current){
      file_out << current->name << '@' << current->channel << '@'
               << current->descrip << '@' << current->info << '@' << current->rating << '\n';

      current = current->next;
      }
      ++count;
    }
    while(!hash_table[count] && count < SZ-1)
    {
      ++count;
    }
  }

  file_out.clear();
  file_out.close();

  return 0;
  


}
//remove wrapper
int mediaTrack::remove(){

  media to_add;
  char * temp = new char[100];
  count = 0;

  cout << "Please enter the name of Show/Media Outlet you are looking to remove: ";
  cin.get(temp,100);
  cin.ignore(100,'\n');

  for(int i=0;i != strlen(temp);++i)
    temp[i] = toupper(temp[i]);
  int check = 0;

  check = remove_Priv(to_add,temp,count);

  if(check == -1) 
  {
    cout << "ERROR" << endl;
    delete [] temp;
    return -1;
  }
  else if(check == 2){
    cout << "NO MATCH FOUND" << endl << endl;
    delete [] temp;
    return -1;
  }
  else{
    cout << "SUCCESFULLY REMOVED" << endl << endl;
    delete [] temp;
    return 1;
  }

}
int mediaTrack::remove_Priv(media & to_add,char * temp,int count){

  media * current = hash_table[count];

  if(count >= SZ-1) return 2;

  else if(hash_table[count] && count < SZ-1)
  {
    media * prev = current;
    int tailCheck = 0;

    while(current)
    {
      char * temp2 = new char[100];
      strcpy(temp2,current->name);
      for(int i=0;i != strlen(temp2);++i) // puts currents name into uppercase string for easier comparison
        temp2[i] = toupper(temp2[i]);

      if(strcmp(temp,temp2) == 0)
      {
        if(tailCheck == 0) // checks for only one node
        {
          hash_table[count] = current->next;
          delete current;
          delete [] temp;
          delete [] temp2;
          return 1;
        }
        else
        {
          if(!current->next) // checks if at end of LLL
          {
            prev->next = NULL;
            delete current;
            delete [] temp;
            delete [] temp2;
            return 1;
          }
          else{  // removes in middle of LLL
            prev->next = current->next;
            delete current;
            delete [] temp;
            delete [] temp2;
            return 1;
          }
        }

      }
      if(strcmp(temp,temp2) != 0);
      {
        ++tailCheck;
      }
      prev = current;
      current = current->next;
      delete [] temp2;
    }
    ++count;
  }
  while(!hash_table[count] && count < SZ-1)
    ++count; 

  if(count >= SZ-1)
  {
    delete [] temp;
    return 2;
  }

  return remove_Priv(to_add,temp,count);
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

      to_add.name = new char[100];
      file_in.get(to_add.name,100,'@');
      file_in.ignore(100,'@');
      to_add.channel = new char[100];
      file_in.get(to_add.channel,100,'@');
      file_in.ignore(100,'@');
      to_add.descrip = new char[500];
      file_in.get(to_add.descrip,500,'@');
      file_in.ignore(500,'@');
      to_add.info = new char[500];
      file_in.get(to_add.info,500,'@');
      file_in.ignore(500,'@');
      file_in >> to_add.rating;
      file_in.ignore(15,'\n');

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

  int rate = 0;

  add.name = new char[100];
  cout << "Please enter the Name of Show/Media outlet you want to add: ";
  cin.get(add.name,100);
  cin.ignore(100,'\n');
  add.channel = new char[100];
  cout << "Please enter the website or channel: ";
  cin.get(add.channel,100);
  cin.ignore(100,'\n');
  cout << "Please enter a brief description of show/media: ";
  add.descrip = new char[500];
  cin.get(add.descrip,500);
  cin.ignore(500,'\n');
  cout << "Please enter the information you learned about show/media: ";
  add.info = new char[500];
  cin.get(add.info,500);
  cin.ignore(500,'\n');
  cout << "Please enter the rating of show/media 1-10: ";
  cin >> add.rating;
  cin.ignore(100,'\n');

  insert(add);
  cout << endl << endl;

  delete add.name;
  delete add.channel;
  delete add.descrip;
  delete add.info;
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
      
      if(current->hashKey == userKey)
      {
        cout << "Match/es for Key" << endl;
        cout << "Name: " << current->name << endl;
        cout << "Channel/Site: " << current->channel << endl;
        cout << "Key: " << current->hashKey << endl;
        cout << "Description: " << current->descrip << endl;
        cout << "Info: " << current->info << endl;
        cout << "Rating: " << current->rating << endl;
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

  cout << "Number of Shows: " << shows << endl << endl;
}
// recursive function for display all 
int mediaTrack::displayAll(int count){

  media * current = hash_table[count];
  
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
    cout << "Key: " << current->hashKey << endl;
    cout << "Description: " << current->descrip << endl;
    cout << "Info: " << current->info << endl;
    cout << "Rating: " << current->rating << endl;
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

  media * current = hash_table[returnCode];

  if(!current) // add if nothing in index
  {
    current = new media;
    current->name = new char[strlen(to_add.name) + 1];
    strcpy(current->name,to_add.name);
    current->channel = new char[strlen(to_add.channel) + 1];
    strcpy(current->channel,to_add.channel);
    current->hashKey = searchKey(&to_add);
    current->descrip = new char[strlen(to_add.descrip)+1];
    strcpy(current->descrip,to_add.descrip);
    current->info = new char[strlen(to_add.info)+1];
    strcpy(current->info,to_add.info);
    current->rating = to_add.rating;

    cout << "return code: "<< returnCode << endl;
    hash_table[returnCode] = current;

    current->next = NULL;
  }
  else if(current) // if something in index insert in front
  {


    current = new media;
    current->name = new char[strlen(to_add.name)+1];
    strcpy(current->name,to_add.name);
    current->channel = new char[strlen(to_add.channel)+1];
    strcpy(current->channel,to_add.channel);
    current->hashKey = searchKey(&to_add);
    current->descrip = new char[strlen(to_add.descrip)+1];
    strcpy(current->descrip,to_add.descrip);
    current->info = new char[strlen(to_add.info)+1];
    strcpy(current->info,to_add.info);
    current->rating = to_add.rating;

    cout << "return code: " << returnCode << endl;
    current->next = hash_table[returnCode];
    hash_table[returnCode] = current;
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

  delete [] name;
  delete [] channel;
  delete [] descrip;
  delete [] info;

}
