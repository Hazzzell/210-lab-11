//COMSC-210-5293 | Lab 11 | Keng C Chan
//IDE used: Visual Studio Code (VS Code) 
#include <iostream>
using namespace std;

const int NR_PLAYLISTS = 2, NR_SONGS = 3;

struct Song {
    string title;
    int duration; //in seconds
};

struct Playlist {
    string name;
    int id; 
    Song *songs; //dynamic array of songs

    ~Playlist() {
        if (songs) 
            delete [] songs;
        songs = nullptr;
    }
};

// inputPlaylist() collects info for a playlist
// arguments: Playlist* (Pointer to playlist object)
// returns: NA
void inputPlaylist(Playlist * sptr);
// displayPlaylist() display the data of a playlist and its songs
// arguments: Playlist* (Pointer to playlist object)
// returns: NA
void displayPlaylist(Playlist * sptr);

int main() {
    Playlist *library = new Playlist[NR_PLAYLISTS];
    
    for (int i = 0; i < NR_PLAYLISTS; i++)
        inputPlaylist(&library[i]);
    
    for (int i = 0; i < NR_PLAYLISTS; i++)
        displayPlaylist(&library[i]);
    
    return 0;
}

void inputPlaylist(Playlist * sptr) {
    static int nrPl = 1;
    cout << "Input data for Playlist #" << nrPl << ":\n";
    cout << "Name: ";
    getline(cin, sptr->name);
    cout << "ID: ";
    cin >> sptr->id;
    sptr -> songs = new Song[NR_SONGS];
    for (int i = 0; i < NR_SONGS; i++) {
        cout << "Song #" << i + 1 << "title: ";
        cin.ignore();
        getline(cin, sptr->songs[i].title);
        cout << "Song #" << i+ 1 << "duration (seconds): ";
        cin >> sptr->songs[i].duration;
    }
    cin.ignore();
    cout << endl << endl;
    nrPl++;
}

void displayPlaylist(Playlist * sptr) {
    cout << "Playlist summary:\n";
    cout << "Name: " << sptr->name << endl;
    cout << "ID: " << sptr->id << endl;
    for (int i = 0; i < NR_SONGS; i++)
        cout << "Song #" << i + 1 << ": " 
             << sptr->songs[i].title << " (" 
             << sptr->songs[i].duration << "s)" << endl;
    cout << endl << endl;
}
