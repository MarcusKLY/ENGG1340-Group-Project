// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

struct PlayerInfo
{
    std::string user_id;
    std::string user_name;
    std::string difficulty;
    int hp;
    std::vector<std::string> items;
    std::string checkpoint;
};

class PlayerManager
{
public:
    void add_player(const PlayerInfo &player_info);
    void update_player(const PlayerInfo &player_info);
    PlayerInfo get_player(const std::string &user_id) const;
    std::vector<PlayerInfo> get_all_players() const;
    void delete_player(const std::string &user_id);
    void load_players(const std::string &filename);
    void save_players(const std::string &filename) const;

private:
    std::unordered_map<std::string, PlayerInfo> players;
};

// int mainn();

#endif
