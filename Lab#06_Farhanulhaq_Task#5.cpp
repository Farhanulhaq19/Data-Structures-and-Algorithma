#include <iostream>
#include <string>
using namespace std;
struct Song
{
    string title;
    Song* next;
    Song* prev;
};
bool isEmpty(Song* head)
{
    return head == NULL;
}
void addSongToEnd(Song** head, const string& title)
{
    Song* newSong = new Song{title, NULL, NULL};
    if (*head == NULL) {
        *head = newSong;
        return;
    }
    Song* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; 
    }

    temp->next = newSong;
    newSong->prev = temp;
}
void traverseForward(Song* head) {
    if (isEmpty(head)) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Song* temp = head;
    cout << "Playlist (Forward): " << endl;
    while (temp != NULL) {
        cout << temp->title << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse the playlist backwards
void traverseBackward(Song* tail) {
    if (isEmpty(tail)) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    cout << "Playlist (Backward): " << endl;
    while (tail != NULL) {
        cout << tail->title << " ";
        tail = tail->prev;
    }
    cout << endl;
}
void deleteSong(Song** head, const string& title)
{
    if (*head==NULL) {
        cout<<"Playlist is empty, cannot delete song."<<endl;
        return;
    }
    Song* temp=*head;
    if (temp->title==title)
    {
        *head=temp->next;
        if (*head !=NULL)
        {
            (*head)->prev =NULL;
        }
        delete temp;
        cout<<"Deleted song: "<<title<<endl;
        return;
    }
    while(temp !=NULL && temp->title !=title)
    {
        temp = temp->next;
    }
    if (temp ==NULL)
    {
        cout<<"Song"<<title<<" not found in the playlist."<<endl;
        return;
    }
    if (temp->next !=NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev !=NULL)
    {
        temp->prev->next=temp->next;
    }
    delete temp;
    cout << "Deleted song: " << title << endl;
}

int main() {
    Song* playlist=NULL;

    addSongToEnd(&playlist,"Song 1");
    addSongToEnd(&playlist,"Song 2");
    addSongToEnd(&playlist,"Song 3");
    addSongToEnd(&playlist,"Song 4");
    addSongToEnd(&playlist,"Song 5");
    traverseForward(playlist);

    Song* tail = playlist;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    traverseBackward(tail);

    deleteSong(&playlist,"Song 5");

    traverseForward(playlist);

    deleteSong(&playlist,"Song 784");

    return 0;
}