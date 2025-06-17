#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
};

class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = nullptr;
    }

    void addSong(string title, string artist) {
        Song* newSong = new Song{title, artist, nullptr};
        if (!head) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newSong;
        }
        cout << "🎶 Added: \"" << title << "\" by " << artist << "\n";
    }

    void deleteSong(string title) {
        Song* temp = head;
        Song* prev = nullptr;

        while (temp && temp->title != title) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "⚠️ Song not found in the playlist.\n";
            return;
        }

        if (!prev) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "🗑️ Deleted: \"" << title << "\"\n";
    }

    void showPlaylist() {
        if (!head) {
            cout << "📭 Playlist is empty.\n";
            return;
        }

        cout << "\n🎵 Current Playlist:\n";
        Song* temp = head;
        int count = 1;
        while (temp) {
            cout << count++ << ". \"" << temp->title << "\" by " << temp->artist << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~Playlist() {
        Song* current = head;
        while (current) {
            Song* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    Playlist myPlaylist;
    int choice;
    string title, artist;

    do {
        cout << "\n🎧 Simple Music Playlist Manager 🎧\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Show Playlist\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // To ignore newline left by cin

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                myPlaylist.addSong(title, artist);
                break;
            case 2:
                cout << "Enter song title to delete: ";
                getline(cin, title);
                myPlaylist.deleteSong(title);
                break;
            case 3:
                myPlaylist.showPlaylist();
                break;
            case 4:
                cout << "👋 Exiting Playlist Manager.\n";
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
