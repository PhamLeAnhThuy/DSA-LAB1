#include <iostream>
#include <vector>
using namespace std;

//Homework 1
struct SongNode {
    string title;
    SongNode *next;
    SongNode *previous;
    SongNode(string name) {
        title = name;
        next = nullptr;
        previous = nullptr;
    }
};

struct MusicPlaylist {
    SongNode *head;
    SongNode *tail;
    SongNode *current;

    MusicPlaylist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string name) {
        SongNode *newTrack = new SongNode(name);
        if (head == nullptr) {
            head = tail = newTrack;
            tail->next = head;
            head->next = tail;
        } else {
            tail->next = newTrack;
            newTrack->previous = tail;
            newTrack->next = head;
            head->previous = newTrack;
            tail = newTrack;
        }
        current = head;
    }

    void removeSong(string name) {
        if (head == nullptr) return;
        SongNode *temp = head;
        do {
            if (temp->title == name) {
                if (temp == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                        current = nullptr;
                    } else {
                        head = head->next;
                        head->previous = tail;
                        tail->next = head;
                        delete temp;
                        current = head;
                    }
                } else if (temp == tail) {
                    tail = tail->previous;
                    tail->next = head;
                    head->previous = tail;
                    delete temp;
                    current = head;
                } else {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != nullptr);
    }

    void nextTrack() {
        if (head != nullptr)
            head = head->next;
    }

    void previousTrack() {
        if (head != nullptr)
            head = head->previous;
    }

    void displayPlaylist() {
        if (head == nullptr) return;
        SongNode *temp = head;
        do {
            cout << temp->title << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

void MusicApp() {
    MusicPlaylist playlist;
    int actions;
    cout << "How many actions would you like to perform? ";
    cin >> actions;
    string task;
    cout << "Input your actions: " << endl;
    for (int i = 0; i < actions; i++) {
        cin >> task;
        if (task == "ADD") {
            string trackName;
            cin >> trackName;
            playlist.addSong(trackName);
        } else if (task == "NEXT") {
            playlist.nextTrack();
        } else if (task == "PREV") {
            playlist.previousTrack();
        } else if (task == "DISPLAY") {
            playlist.displayPlaylist();
        } else if (task == "REMOVE") {
            string songToRemove;
            cin >> songToRemove;
            playlist.removeSong(songToRemove);
        }
    }
}

// Homework 2
struct TabPage {
    string url;
    TabPage *previous;
    TabPage *next;
    TabPage(string address) {
        url = address;
        previous = nullptr;
        next = nullptr;
    }
};

struct BrowserNavigator {
    TabPage *start;
    TabPage *end;
    TabPage *activeTab;
    
    BrowserNavigator(string address) {
        TabPage *initialTab = new TabPage(address);
        start = end = activeTab = initialTab;
    }

    void openPage(string address) {
        TabPage *newTab = new TabPage(address);
        if (activeTab != end) {
            activeTab->next = nullptr;
            end = activeTab;
        }
        end->next = newTab;
        newTab->previous = end;
        end = newTab;
        activeTab = newTab;
    }

    void back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (activeTab->previous == nullptr) break;
            activeTab = activeTab->previous;
        }
    }

    void forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (activeTab->next == nullptr) break;
            activeTab = activeTab->next;
        }
    }

    void showCurrentTab() {
        cout << activeTab->url << " ";
    }
};

void BrowserApp() {
    vector<string> actions;
    vector<string> urls;
    string input;
    cout << "Input your actions (type 'done' to finish):\n";
    while (true) {
        cin >> input;
        if (input == "done") break;
        actions.push_back(input);
    }

    cout << "Input URLs and steps (type 'done' to finish):\n";
    while (true) {
        cin >> input;
        if (input == "done") break;
        urls.push_back(input);
    }

    BrowserNavigator browser(urls[0]);
    cout << "null ";
    for (int i = 1; i < actions.size(); i++) {
        if (actions[i] == "visit") {
            browser.openPage(urls[i]);
            cout << "null ";
        } else if (actions[i] == "back") {
            browser.back(stoi(urls[i]));
            browser.showCurrentTab();
        } else if (actions[i] == "forward") {
            browser.forward(stoi(urls[i]));
            browser.showCurrentTab();
        }
    }
}

// Homework 3
struct TokenRecord {
    string id;
    int expiryTime;
    TokenRecord *next;
    TokenRecord(string tokenID, int expiration) {
        id = tokenID;
        expiryTime = expiration;
        next = nullptr;
    }
};

struct AuthManager {
    int ttl;
    TokenRecord *head;
    
    AuthManager(int timeToLive) {
        ttl = timeToLive;
        head = nullptr;
    }

    void createToken(string id, int currentTime) {
        int expiration = currentTime + ttl;
        TokenRecord *newToken = new TokenRecord(id, expiration);
        newToken->next = head;
        head = newToken;
    }

    void refreshToken(string id, int currentTime) {
        TokenRecord* temp = head;
        while (temp != nullptr) {
            if (temp->id == id && temp->expiryTime > currentTime) {
                temp->expiryTime = currentTime + ttl;
                return;
            }
            temp = temp->next;
        }
    }

    int countValidTokens(int currentTime) {
        int validCount = 0;
        TokenRecord *temp = head;
        while (temp != nullptr) {
            if (temp->expiryTime > currentTime) {
                validCount++;
            }
            temp = temp->next;
        }
        return validCount;
    }
};

void AuthApp() {
    vector<string> actions;
    string input;
    cout << "Input your commands (type 'done' to finish):\n";

    while (true) {
        cin >> input;
        if (input == "done") break;
        actions.push_back(input);
    }

    AuthManager* manager = nullptr;
    for (int i = 0; i < actions.size(); i++) {
        if (actions[i] == "AuthManager") {
            int ttl;
            cin >> ttl;
            manager = new AuthManager(ttl);
            cout << "null ";
        } else if (actions[i] == "generate" || actions[i] == "renew") {
            string id;
            int currentTime;
            cin >> id >> currentTime;
            if (actions[i] == "generate") {
                manager->createToken(id, currentTime);
                cout << "null ";
            } else {
                manager->refreshToken(id, currentTime);
                cout << "null ";
            }
        } else if (actions[i] == "countValidTokens") {
            int currentTime;
            cin >> currentTime;
            int validTokens = manager->countValidTokens(currentTime);
            cout << validTokens << " ";
        }
    }
}

void showMenu() {
    cout << "Select an option: \n";
    cout << "1. Music Playlist\n";
    cout << "2. Web Browser\n";
    cout << "3. Authentication Manager\n";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        MusicApp();
        break;
    case 2:
        BrowserApp();
        break;
    case 3:
        AuthApp();
        break;
    }
}

int main() {
    showMenu();
    return 0;
}
