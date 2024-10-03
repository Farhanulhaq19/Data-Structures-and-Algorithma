#include <iostream>
#include <string>
using namespace std;
class Song
{
public:
    string title;
    Song* next;
    Song* prev;
    Song(string title):title(title),next(nullptr),prev(nullptr) {}
};
class Playlist
{
public:
    Song* head;
    Song* tail;
    Playlist():head(nullptr),tail(nullptr) {}
    void addSong(string title)
    {
        Song* newSong=new Song(title);
        if (head==nullptr)
        {
            head=tail=newSong;
        }
        else
        {
            tail->next=newSong;
            newSong->prev=tail;
            tail =newSong;
        }
        cout<<"Added song: "<<title<<endl;
    }
    void traverseForwards()
    {
        Song* temp=head;
        while (temp !=nullptr)
        {
            cout<<temp->title<<" -> ";
            temp = temp->next;
        }
        cout << "End" << endl;
    }
    void traverseBackwards()
    {
        Song* temp=tail;
        while (temp != nullptr)
        {
            cout<<temp->title << " -> ";
            temp=temp->prev;
        }
        cout << "Start" << endl;
    }
    void deleteSong(string title)
    {
        Song* temp=head;
        while (temp !=nullptr && temp->title !=title)
        {
            temp=temp->next;
        }
        if (temp==nullptr)
        {
            cout<<"Song not found: "<<title<<endl;
            return;
        }
        if (temp->prev !=nullptr)
        {
            temp->prev->next=temp->next;
        }
        else{
            head=temp->next;
        }
        if (temp->next !=nullptr)
        {
            temp->next->prev=temp->prev;
        }
        else
        {
            tail=temp->prev;
        }
        delete temp;
        cout<<"Deleted song: "<<title<<endl;
    }
};
int main()
{
    Playlist playlist;
    // Adding songs in the playlist
    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    // Traversing the playlist toward and then backward
    cout << "Playlist (Forwards): ";
    playlist.traverseForwards();
    cout << "Playlist (Backwards): ";
    playlist.traverseBackwards();
    // Deleting song from the playlist that you have added
    playlist.deleteSong("Song 2");
    // Traversing the playlist towards after deletion
    cout << "Playlist (Forwards) after deletion: ";
    playlist.traverseForwards();
    return 0;
}