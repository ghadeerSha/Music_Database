#include <iostream>
#include "Menu.h"
#include "Database.h"
#include <string>


int main(){
        char choice;
        char song_name[100];
        char artist_name[100];
        string artist;
        string name;
        string dum;
        int year;
        Menu m1;
        Database d1;
        Song* in_song;
       
           
        do {
                 m1.menuOptions();
                 cin>>choice;

                 //if(choice )

                 if(choice == 'A'){

                     cout<<"Enter a Song name: ";
                     getline(cin, dum);
                     getline(cin, name);
                
                            cout<<"Enter a Artist name: ";
                            getline(cin, artist);

                            do{
                                 cout<<"Enter a published year: ";
                                 cin>>year;
                                 while(1)
                                {
                                    if(cin.fail())
                                    {
                                        cout<<"You have entered invalid number"<<endl;
                                        cout<<"Enter a published year: ";
                                        cin>>year;
                                    }
                                    if(!cin.fail())
                                        break;
                                }
                            }while(year <0 || year > 2201);
                            
                            Song song(name,artist,year);
                            d1.addSong(song);

                 }else if (choice == 'F'){
                        char subChoice;
                        do{

                          m1.findSubMenu();
                          cin>>subChoice;

                         switch (subChoice)
                            {
                            case 'N':
                              cout<<"Enter a Song name: ";
                               getline(cin, dum);
                               getline(cin, name);
                                d1.findByName(name);
                                break;

                            case 'A':
                               cout<<"Enter a Artist name: ";
                               getline(cin, dum);
                               getline(cin, artist);
                               
                                d1.findByArtist(artist);
                                break;

                            case 'Y':
                                cout<<"Enter a published year: ";
                                 cin>>year;
                                 d1.findByYear(year);
                                break;

                            case 'R':
                                break;
                            
                            default:
                                cout<<"Invalid choice!"<<endl;
                                break;
                            }
                    }while(subChoice != 'R');

                 }
                 else if (choice == 'D'){
                      cout<<"Enter a Song name: ";
                       getline(cin, dum);
                       getline(cin, name);
                      
                    
                            cout<<"Enter a Artist name: ";
                            getline(cin, artist);

                            do{
                                 cout<<"Enter a published year: ";
                                 cin>>year;
                                 while(1)
                                {
                                    if(cin.fail())
                                    {
                                        cout<<"You have entered invalid number"<<endl;
                                        cout<<"Enter a published year: ";
                                        cin>>year;
                                    }
                                    if(!cin.fail())
                                        break;
                                }
                            }while(year <0 || year > 2201);
                            
                         Song song1(name,artist,year);
                        d1.deleteSong(song1);
                 }
                 else if (choice == 'L'){
                     int sortNum;
                     m1.sortSubMenu();
                     cin>>sortNum;
                     switch (sortNum)
                     {
                        case 1:
                            d1.sortRecord(1);
                            d1.showRecords();
                            break;
                        case 2:
                            d1.sortRecord(2);
                            d1.showRecords();
                            break;
                        case 3:
                            d1.sortRecord(3);
                            d1.showRecords();
                            break;
                        case 4:
                            d1.sortRecord(4);
                            d1.showRecords();
                            break;
                        case 5:
                            d1.sortRecord(5);
                            d1.showRecords();
                            break;
                        case 6:
                            d1.sortRecord(6);
                            d1.showRecords();
                            break;
                     default:
                         break;
                     }
                 }
                 else if (choice == 'Q'){
                     d1.saveToFile();
                     cout<<"Program Terminated!"<<endl;
                     break;

                 }else{
                      cout<<"Invalid choice!"<<endl;
                 }
            }while(choice != 'Q');
           
            return choice;
    return 0;
}