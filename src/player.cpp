// player.cpp

#include "../header/player.h"
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

// function to add a new player
void PlayerManager::add_player(const PlayerInfo &player_info)
{
    players[player_info.user_id] = player_info;
}

// function to update the player's information
void PlayerManager::update_player(const PlayerInfo &player_info)
{
    players[player_info.user_id] = player_info;
}

// function to load the player's information
PlayerInfo PlayerManager::get_player(const std::string &user_id) const
{
    auto it = players.find(user_id);
    if (it == players.end())
    {
        throw std::runtime_error("Player with user ID " + user_id + " does not exist");
    }
    return it->second;
}

// function to get all the players' information
std::vector<PlayerInfo> PlayerManager::get_all_players() const
{
    std::vector<PlayerInfo> all_players;
    for (const auto &player : players)
    {
        all_players.push_back(player.second);
    }
    return all_players;
}

// function to delete the player's information
void PlayerManager::delete_player(const std::string &user_id)
{
    auto it = players.find(user_id);
    if (it == players.end())
    {
        throw std::runtime_error("Player with user ID " + user_id + " does not exist");
    }
    players.erase(it);
    PlayerManager::save_players("saves.sav");
}

// function to load the player's information from the file
void PlayerManager::load_players(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file " + filename);
    }
    std::string line;
    PlayerInfo player_info;
    while (std::getline(file, line))
    {
        if (line == "end_player")
        {
            add_player(player_info);
            player_info = PlayerInfo();
        }
        else if (line.substr(0, 5) == "item:")
        {
            player_info.items.push_back(line.substr(5));
        }
        else if (line.substr(0, 11) == "checkpoint:")
        {
            player_info.checkpoint = line.substr(11);
        }
        else
        {
            std::istringstream iss(line);
            std::getline(iss, player_info.user_id, ',');
            std::getline(iss, player_info.user_name, ',');
            std::getline(iss, player_info.difficulty, ',');
            iss >> player_info.hp;
            iss >> player_info.buff;
        }
    }
    file.close();
}

// function to save the player's information to the file
void PlayerManager::save_players(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file " + filename);
    }
    for (auto it = players.begin(); it != players.end(); ++it)
    {
        const std::string &user_id = it->first;
        const PlayerInfo &player_info = it->second;

        file << user_id << "," << player_info.user_name << "," << player_info.difficulty << "," << player_info.hp << "," << player_info.buff << "\n";
        for (const auto &item : player_info.items)
        {
            file << "item:" << item << "\n"; // write each item on a separate line
        }
        file << "checkpoint:" << player_info.checkpoint << "\n";
        file << "end_player\n";
    }
    file.close();
}

// int main(){
//     PlayerManager player_manager;
//     player_manager.load_players("saves.sav");
//     player_manager.delete_player("marcus");
//     cout << "Player deleted" << endl;
// }

// int main()
// {
//     PlayerManager player_manager;

//     player_manager.load_players("saves.sav");

//     PlayerInfo new_player;
//     new_player.user_id = "player3";
//     new_player.user_name = "Johnnnnn";
//     new_player.difficulty = "easy";
//     new_player.hp = 100;
//     new_player.items.push_back("sword");
//     new_player.checkpoint = "castle";
//     player_manager.add_player(new_player);

//     PlayerInfo new_player1;
//     new_player1.user_id = "player2";
//     new_player1.user_name = "marcus";
//     new_player1.difficulty = "difficult";
//     new_player1.hp = 80;
//     new_player1.items.push_back("item1");
//     new_player1.items.push_back("item2");
//     new_player1.checkpoint = "earch";
//     player_manager.add_player(new_player1);

//     // PlayerInfo existing_player = player_manager.get_player("player3");
//     // existing_player.hp = 50;
//     // player_manager.update_player(existing_player);

//     player_manager.save_players("saves.sav");

//     return 0;
// }

// void print_all_players(const PlayerManager &player_manager)
// {
//     try
//     {
//         for (const auto &player : player_manager.get_all_players())
//         {
//             cout << "User ID: " << player.user_id << "\n";
//             cout << "User Name: " << player.user_name << "\n";
//             cout << "Difficulty: " << player.difficulty << "\n";
//             cout << "HP: " << player.hp << "\n";
//             cout << "Buff: " << player.buff << "\n";
//             cout << "Items: [";
//             for (const auto &item : player.items)
//             {
//                 cout << item << ", ";
//             }
//             cout << "]\n";
//             cout << "Check point: " << player.checkpoint << "\n\n";
//         }
//     }
//     catch (const runtime_error &ex)
//     {
//         cerr << "Error: " << ex.what() << "\n";
//     }
// }

// int main()
// {
//     PlayerManager player_manager;
//     player_manager.load_players("saves.sav");
//     PlayerInfo player_info;
//     // player_info = player_manager.get_player("player2");
//     for (int i = 0; i < player_info.items.size(); i++)
//     {
//         cout << player_info.items[i] << "\n";
//     }

//     try
//     {
//         PlayerManager player_manager;
//         player_manager.load_players("saves.sav");
//         print_all_players(player_manager);
//     }
//     catch (const runtime_error &ex)
//     {
//         cerr << "Error: " << ex.what() << "\n";
//         return 1;
//     }
//     return 0;
// }

// int get_playerinfo_name(){
//     PlayerManager player_manager;
//     player_manager.load_players("players.txt");

//     return 0;
// }