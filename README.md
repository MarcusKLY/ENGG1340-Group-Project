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

In a world where every HKU student is constantly juggling a multitude of assignments, you find yourself as an ordinary student embroiled in this never-ending struggle. One fateful night, you're trapped in the enigmatic KKL building, feverishly working to meet a deadline for the next day. Overwhelmed, you drift off to sleep, with dreams of completing your work and returning home to your family.

Jolted awake, you realize that the once-familiar surroundings have transformed into a dimly-lit labyrinth. Desperate to leave, you search for help, only to find that you are completely alone.

Embarking on a thrilling quest to escape HKU, you face a series of increasingly formidable obstacles. As you delve deeper into the unknown, you start to unravel a sinister conspiracy lurking beneath the surface, with implications far more profound than you could have ever imagined.

Unleash your inner strength, conquer the challenges that lie ahead, and uncover the shocking truth behind this mysterious event. The fate of your world rests in your hands, as you embark on a heart-pounding race against time to break free from the clutches of this enigmatic realm!


## Gameplay
In this text-based game, players use their keyboard and mouse to control their character, making different decisions that influence the outcome and progression of the story.


## Combat
A turn-based battle game, player can choose actions of punch, kick, block, dodge and use items. Different actions has its advantage and disadvantage against different opponent action. Consider what action opponent will take and choose the suitable action to win the battle. Moreover, various games will be implemented such as tic-tac-toe and wordle, where the players could battle with the program.

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


## Installation & Running the game

1. Open the Linux/Mac Terminal and navigate to the directory where you want to download the game.
2. Clone the repository using the command `git clone https://github.com/MarcusKLY/ENGG1340-Group-Project`.
3. Change your directory to the downloaded repository using the command `cd ENGG1340-Group-Project`.
4. Compile and start the game by running the command `make game`.
