// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.

#include <iostream>
#include "Song.h"
#include <fstream>
//The stringstream class in C++ allows a string object to be treated as a stream.
#include <sstream>
#include <algorithm>
using namespace std;


        //function to sort songs by names ascendig 
        bool sortByNameAsc(Song &other1, Song &other2){
            return (other1.getName() < other2.getName());
        }

        //function to sort songs by names descending  
        bool sortByNameDesc(Song &other1, Song &other2) {
            return (other1.getName() > other2.getName());
        }
        //function to sort songs by Artist ascendig 
        bool sortByArtistAsc(Song &other1, Song &other2) 
        {
            return (other1.getArtist() < other2.getArtist());
        }
        //function to sort songs by Artist descendig 
        bool sortByArtistDesc(Song &other1, Song &other2) 
        {
            return (other1.getArtist() > other2.getArtist());
        }
        //function to sort songs by year ascendig 
        bool sortByYearAsc(Song &other1, Song &other2) 
        {
            return (other1.getYear() < other2.getYear());
        }
        //function to sort songs by year descendig 
        bool sortByYearDesc(Song &other1, Song &other2) 
        {
            return (other1.getYear() > other2.getYear());
        }


class Database{
    private:
        int cap;        // length of underlying array
        Song* songs;      // pointer to the underlying array
        int sz;         // # of elements in this int_vec from user's perspective

    public:
        // default constructor
        Database() 
        {
            // Create a text string, which is used to output the text file
            string myText;
            int counter = 0;
            cap = 100;      // initial capacity
            songs = new Song[cap];
            sz = 0;

            // Read from the text file
            ifstream MyReadFile("database.txt");

            cout<<"Loading data.."<<endl;

            // Use a while loop together with the getline() function to read the file line by line
            while (getline (MyReadFile, myText)) {
                // Output the text from the file
              
                    stringstream ss(myText);
                    string s_name;
                    getline(ss, s_name, ',');
                    string a_name;
                    getline(ss, a_name, ',');
                    string year;
                    getline(ss, year, ',');
                    // used to convert data from a string type to an integer type
                    Song song(s_name,a_name,stoi(year));
                    songs[sz]= song;
                    sz++;       
            }
            // Close the file
            MyReadFile.close();
             cout<<"Database.txt loaded successfully!"<<endl;
        }

        //Destructors 
        ~Database(){
            delete []songs;
        }

        int size() const{
            return sz;
        }

        int capacity() const{
            return cap;
        }   
      
      void addSong(Song &song){
          bool flag = true;

          if(sz == cap){
                cout<<"List is already full!"<<endl;
                return;
          }

          for(int i=0; i<sz; i++){
              if( (songs[i].getName() == song.getName()) && (songs[i].getArtist() == song.getArtist()) && (songs[i].getYear() == song.getYear()) ){
                  flag = false;
                  std::cout<<"Record already exists!!"<<endl;
                  break;
              }
          }
           if(flag){
              songs[sz]= song;
              sz++;
            }
        }

      void deleteSong(Song &song){
          bool flag = false;
          int yesNo =  0;
          int index;

          if(sz == 0){
                cout<<"List is empty!"<<endl;
                return;
          }

          for(int i=0; i<sz; i++){
              if( (songs[i].getName() == song.getName()) && (songs[i].getArtist() == song.getArtist()) && (songs[i].getYear() == song.getYear()) ){
                  index = i;
                  flag = true;
                  break;
              }
          }
          if(flag){
              cout<<"want to delete?(0:cancel, 1: confirm): ";
              cin>>yesNo;

              if(yesNo ==1){
                    for(int i = index; i < (sz - 1) ; i++){
                        songs[i] = songs[i + 1];  
                    }
                    sz = sz - 1;
                    cout<<"Record deleted!"<<endl;
                }
              else{
                   cout<<"Cancelled !"<<endl;
                }
          }
          else{
                cout<<"No Record found!"<<endl;
          }
      }
        void showRecords(){
            if(sz == 0){
                cout<<"List is empty!"<<endl;
                return;
            }
            cout<<"\n-----------------------------------"<<endl;
            cout<<"List of records               "<<endl;
            cout<<"------------------------------------"<<endl;

            for(int i=0; i<sz; i++){
                  cout<<songs[i].getName()<<",";
                  cout<<songs[i].getArtist()<<",";
                  cout<<songs[i].getYear()<<endl;
            }
        }

        //search by (N)ame of song
        void findByName(string in_name){
            bool flag = true;
            if(sz == 0){
                cout<<"List is empty!"<<endl;
                return;
            }
            cout<<"\n-----------------------------------"<<endl;
            cout<<"List of records search by song name"<<endl;
            cout<<"------------------------------------"<<endl;

            for(int i=0; i<sz; i++){
                if( songs[i].getName() == in_name  ){
                  flag = false;
                  cout<<songs[i].getName()<<",";
                  cout<<songs[i].getArtist()<<",";
                  cout<<songs[i].getYear()<<endl;
                  break;
                }
            }
            if(flag){
                bool noMore = true;
                for(int i=0; i<sz; i++){
                    if( songs[i].getName().find(in_name) != string::npos ){
                        noMore = false;
                        cout<<songs[i].getName()<<",";
                        cout<<songs[i].getArtist()<<",";
                        cout<<songs[i].getYear()<<endl;
                    }
                }
                if(noMore)
                    cout<<"No Record found!"<<endl;
            }
        }

        //search by (A)rtist who performed the song
        void findByArtist(string in_artist){
            bool flag = true;
            if(sz == 0){
                cout<<"List is empty!"<<endl;
                return;
            }

            cout<<"\n-----------------------------------"<<endl;
            cout<<"List of records search by song Artist"<<endl;
            cout<<"------------------------------------"<<endl;

            for(int i=0; i<sz; i++){
                if( songs[i].getArtist() == in_artist ){
                  flag = false;
                  cout<<songs[i].getName()<<",";
                  cout<<songs[i].getArtist()<<",";
                  cout<<songs[i].getYear()<<endl;
                  break;
                }
            }

            if(flag){
                bool noMore = true;
               for(int i=0; i<sz; i++){
                    if( songs[i].getArtist().find(in_artist) != string::npos ){
                        noMore = false;
                        cout<<songs[i].getName()<<",";
                        cout<<songs[i].getArtist()<<",";
                        cout<<songs[i].getYear()<<endl;
                     }
                }
                if(noMore)
                    cout<<"No Record found!"<<endl;
            }
        }

          //search by (Y)ear of song
        void findByYear(int year){
            bool flag = true;

            if(sz == 0){
                    cout<<"List is empty!"<<endl;
                    return;
            }
            cout<<"\n-----------------------------------"<<endl;
            cout<<"List of records search by song published year"<<endl;
            cout<<"------------------------------------"<<endl;
                for(int i=0; i<sz; i++){
                    if( songs[i].getYear() == year ){
                        flag = false;
                        cout<<songs[i].getName()<<",";
                        cout<<songs[i].getArtist()<<",";
                        cout<<songs[i].getYear()<<endl;
                    }
                }
                if(flag){
                    bool tr = true;
                    for(int i=0; i<sz; i++){
                        if( songs[i].getYear() > 2005 || songs[i].getYear() > 2015   ){
                            tr = false;
                            cout<<songs[i].getName()<<",";
                            cout<<songs[i].getArtist()<<",";
                            cout<<songs[i].getYear()<<endl;
                        }
                    }
                    if(tr)
                        cout<<"No Record found!"<<endl;
                }
        }

        void sortRecord(int srt){
            int n = sz;
            if(srt == 1)
                sort(songs, songs+n, sortByNameAsc);
            else if(srt == 2)
                sort(songs, songs+n, sortByNameDesc);
            else if(srt == 3)
                sort(songs, songs+n, sortByArtistAsc);
            else if(srt == 4)
                sort(songs, songs+n, sortByArtistDesc);
            else if(srt == 5)
                sort(songs, songs+n, sortByYearAsc);
            else if(srt == 6)
                sort(songs, songs+n, sortByYearDesc);
            
	    }

        void saveToFile(){
            ofstream myfile;
            myfile.open ("database.txt");
              if(sz == 0){
                    cout<<"List is empty!"<<endl;
                    myfile.close();
                    return;
                }
            for(int i=0; i<sz; i++){
                  myfile<<songs[i].getName()<<",";
                  myfile<<songs[i].getArtist()<<",";
                  myfile<<songs[i].getYear()<<endl;
            }
            myfile.close();
            cout<<(sz)<<" records saved to database.txt file!"<<endl;
        }
};