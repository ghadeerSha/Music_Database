#include <iostream>
using namespace std;

class Menu{
    public:
        void menuOptions(){
            cout<<"\nWelcome to the Song Database!"<<"\n-----------------------------"<<endl;
            cout<<"(A)dd a song."<<endl;
            cout<<"\n(F)ind a song.."<<endl;
            cout<<"\n(D)elete a song."<<endl;
            cout<<"\n(L)ist songs."<<endl;
            cout<<"\n(Q)uit"<<endl;
            cout<<"\nEnter the letter of your choice: ";
        }

        void findSubMenu(){
            cout<<"\nFind a Song!"<<"\n-------"<<endl;
            cout<<"You can search by:"<<endl;
            cout<<"\n(N)ame of song"<<endl;
            cout<<"\n(A)rtist who performed the song"<<endl;
            cout<<"\n(Y)ear of song"<<endl;
            cout<<"\n(R)eturn to main menu"<<endl;
            cout<<"\nEnter the letter of your choice: ";
        }

         void sortSubMenu(){
            cout<<"\nSort a Song!"<<"\n-------"<<endl;
            cout<<"You can sort by:"<<endl;
            cout<<"\n1.Name of song in Ascending "<<endl;
            cout<<"\n2.Name of song in descending "<<endl;
            cout<<"\n3.Artist who performed the song in Ascending "<<endl;
            cout<<"\n4.Artist who performed the song in Descening "<<endl;
            cout<<"\n5.Year of song in Ascending"<<endl;
            cout<<"\n6.Year of song in Descening"<<endl;
            cout<<"\n7.Return to main menu"<<endl;
            cout<<"\nEnter the number of your choice: ";
        }

};