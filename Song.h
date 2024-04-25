
#include <string>
using namespace std;

class Song{
    private:
        string name;
        string artist;
        int year_of_publication;

    public:
    // default constructor
    Song(){ }    
    // copy constructor
	Song(const Song &other) {
        name = other.name;
        artist = other.artist;
        year_of_publication = other.year_of_publication;
    }
        Song(string in_name, string in_artist, int in_year){
            name = in_name;
            artist = in_artist;
            year_of_publication = in_year;
        }

        string getName(){
            return name;
        }

        string getArtist(){
            return artist;
        }

        int getYear(){
            return year_of_publication;
        }
};