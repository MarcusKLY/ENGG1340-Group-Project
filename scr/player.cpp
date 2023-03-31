#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;

struct PlayerInfo {
    string user_id;
    string user_name;
    string difficulty;
    int hp;
    vector<string> items;
    string location;

};

class PlayerManager {
public:
    // Adds a player to the manager
    void add_player(const PlayerInfo& player_info) {
        players[player_info.user_id] = player_info;
    }

    // Updates a player in the manager
    void update_player(const PlayerInfo& player_info) {
        players[player_info.user_id] = player_info;
    }

    // Returns a player from the manager based on user ID
    PlayerInfo get_player(const string& user_id) const {
        auto it = players.find(user_id);
        if (it == players.end()) {
            throw runtime_error("Player with user ID " + user_id + " does not exist");
        }
        return it->second;
    }

    vector<PlayerInfo> get_all_players() const {
        vector<PlayerInfo> all_players;
        for (const auto& player : players) {
            all_players.push_back(player.second);
        }
        return all_players;
    }   

    // Loads player information from a file into the manager
    void load_players(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file " + filename);
        }
        string line;
        PlayerInfo player_info;
        while (getline(file, line)) {
            if (line == "end_player") {
                add_player(player_info);
                player_info = PlayerInfo();
            } else if (line.substr(0, 5) == "item:") {
                player_info.items.push_back(line.substr(5));
            } else if (line.substr(0, 9) == "location:") {
                player_info.location = line.substr(9);
            } else {
                istringstream iss(line);
                getline(iss, player_info.user_id, ',');
                getline(iss, player_info.user_name, ',');
                getline(iss, player_info.difficulty, ',');
                iss >> player_info.hp;
            }
        }
        file.close();
    }
    // Saves player information from the manager to a file
    void save_players(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file " + filename);
        }
        for (auto it = players.begin(); it != players.end(); ++it) {
            const string& user_id = it->first;
            const PlayerInfo& player_info = it->second;

            file << user_id << "," << player_info.user_name << "," << player_info.difficulty << "," << player_info.hp << "\n";
            for (const auto& item : player_info.items) {
                file << "item:" << item << "\n"; // write each item on a separate line
            }
            file << "location:" << player_info.location << "\n";
            file << "end_player\n";
        }
        file.close();
    }

private:
    unordered_map<string, PlayerInfo> players;
};

// int main() {
//     PlayerManager player_manager;

//     player_manager.load_players("players.txt");


//     PlayerInfo new_player;
//     new_player.user_id = "player3";
//     new_player.user_name = "John";
//     new_player.difficulty = "easy";
//     new_player.hp = 100;
//     new_player.items.push_back("sword");
//     new_player.location = "castle";
//     player_manager.add_player(new_player);

//     PlayerInfo new_player1;
//     new_player1.user_id = "player2";
//     new_player1.user_name = "marcus";
//     new_player1.difficulty = "difficult";
//     new_player1.hp = 80;
//     new_player1.items.push_back("item1");
//     new_player1.items.push_back("item2");
//     new_player1.location = "earch";
//     player_manager.add_player(new_player1);

//     // PlayerInfo existing_player = player_manager.get_player("player3");
//     // existing_player.hp = 50;
//     // player_manager.update_player(existing_player);

//     player_manager.save_players("players.txt");

//     return 0;
// }


void print_all_players(const PlayerManager& player_manager) {
    try {
        for (const auto& player : player_manager.get_all_players()) {
            cout << "User ID: " << player.user_id << "\n";
            cout << "User Name: " << player.user_name << "\n";
            cout << "Difficulty: " << player.difficulty << "\n";
            cout << "HP: " << player.hp << "\n";
            cout << "Items: [";
            for (const auto& item : player.items) {
                cout << item << ", ";
            }
            cout << "]\n";
            cout << "Location: " << player.location << "\n\n";
        }
    } catch (const runtime_error& ex) {
        cerr << "Error: " << ex.what() << "\n";
    }
}

int main() {
    PlayerManager player_manager;
    player_manager.load_players("players.txt");
    PlayerInfo player_info = player_manager.get_player("player2");
    for (int i=0; i<player_info.items.size(); i++) {
        cout << player_info.items[i] << "\n";
    }
    // try {
    //     PlayerManager player_manager;
    //     player_manager.load_players("players.txt");
    //     print_all_players(player_manager);
    // } catch (const runtime_error& ex) {
    //     cerr << "Error: " << ex.what() << "\n";
    //     return 1;
    // }
    // return 0;
}