![](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)

# ENGG1340-Group-Project
A repository for the HKU COMP2113/ENGG1340 course game group project.
Group 1


## Group Members
- Kam Long Yin, Marcus (3036050738)
- Chan Yat Kwan, Simon (3036066517)
- Wong Chun Hei (3036067066)
- Lam Chuck Yu, Chuck (3036057786)
- Diao Mo Chiu, Stream (3036067327)


## Documentation
* [Storyline](#Storyline)
* [Gameplay](#Gameplay)
* [Combat](#Combat)
* [Coding Features](#Coding-Features)
* [Game State Design](#Game-State-Design)
* [Installation & Run](#Installation--Run)


## Game Description

    ┋======================================┋
    ┋      ___ ___  ____  __.____ ___      ┋
    ┋     /   |   \|    |/ _|    |   \     ┋
    ┋    /    ~    \      < |    |   /     ┋
    ┋    \    Y    /    |  \|    |  /      ┋
    ┋     \___|_  /|____|__ \______/       ┋
    ┋           \/         \/              ┋
    ┋__________.__                    .___ ┋
    ┋\______   \  |   ____   ____   __| _/ ┋
    ┋ |    |  _/  |  /  _ \ /  _ \ / __ |  ┋
    ┋ |    |   \  |_(  <_> |  <_> ) /_/ |  ┋
    ┋ |______  /____/\____/ \____/\____ |  ┋
    ┋        \/                        \/  ┋
    ┋      _____                           ┋
    ┋     /     \   ____   ____   ____     ┋
    ┋    /  \ /  \ /  _ \ /  _ \ /    \    ┋
    ┋   /    Y    (  <_> |  <_> )   |  \   ┋
    ┋   \____|__  /\____/ \____/|___|  /   ┋
    ┋           \/                   \/    ┋
    ┋======================================┋

You are an ordinary HKU student. As an HKU student, it is normal to have a lot of homework to complete. One day, you were stuck in the KKL building and fell asleep while working on a deadline for the next day.

You need to go home immediately or you will be scolded by your family. However, you notice that it's weird, there's no light source, and you can't find anyone to help.

As you look for your way out of HKU, you encounter many obstacles to overcome, and then you slowly discover that the whole thing behind it is much more serious than you thought.

Do your best to get through all the challenges, learn the story behind this event, and get out of the place!


## Gameplay
The game is a text-based game.


## Combat


## Coding Features

### 1. Generation of random game sets or events
- In battle, attack damage(p_atk,e_atk) is random integer within a range, enemy have random action(e_action) and random dialogue with player in each round.
-
### 2. Data structures for storing game status

- Inside the `PlayerInfo`, player specific information will be stored, including:
  - `user_name`, in form of string
  - `difficulty`, in form of string
  - `hp`(Health Point), in form of integer
  - `buff`, in form of integer
  - `items`, in form of string vector
  - `checkpoint`, in form of string
  
 - Inside `ColorOption`, word colors are being stored

- In battle, int is used to store player and enemy hp, and array of int is used to store remain numbers of rounds of special effect players have.

### 3. Dynamic memory management

- In battle, a dynamic int array with changing size is used to store id of items player have in each round

### 4. File input/output

- Game data are stored in the `saves.sav` file for player to save and load game saves. Those files could also be delete in the game menu.
- The wordle's predefined words are stored in `answer.txt`, and loaded during the game.
  
### 5. Program codes in multiple files

- DIfferent function are in multiple files (some examples below)
  - `PlayerInfo` and `ColorOption` struct,  will be declared and defined in its own header and source files, which could be used in all other sourse file.
  - Different word output styles in `output_style.h` could be used repeatedly.
  - From main game can call function `call_new_battle` in `battle.h` to start a new battle 



## Game State Design


## Installation & Run

1. In Linux/ Mac Terminal, change the directory to the one that want the game to be downloaded.
2. Run `git clone https://github.com/MarcusKLY/ENGG1340-Group-Project` to clone this reporepository to the directory.
3. Run `make game` to compile and start the game.
