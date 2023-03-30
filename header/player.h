//player.h

#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#include <string>
#include <vector>

// Define global variables for the PlayerInfo struct
extern std::string user_id;
extern std::string user_name;
extern std::string difficulty;
extern int hp;
extern std::vector<std::string> items;
extern std::string location;

// Writes player information to a file
void write_to_file(const std::string& filename);

// Reads player information from a file
void read_from_file(const std::string& filename);

#endif
