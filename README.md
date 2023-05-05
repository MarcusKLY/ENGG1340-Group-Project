![](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)

# ENGG1340-Group-Project
A repository for the HKU COMP2113/ENGG1340 course (2022-23 semester 2) game group project.

Group 1

"You learned a lot by playing RPGs, although not all of it was useful, or real for that matter." - Sorin Suciu


## Group Members
- Kam Long Yin, Marcus (3036050738)
- Chan Yat Kwan, Simon (3036066517)
- Wong Chun Hei (3036067066)
- Lam Chak Yu, Chuck (3036057786)
- Diao Mo Chiu, Stream (3036067327)


## Documentation
* [Background](#Background)
* [Gameplay](#Gameplay)
* [Coding Features](#Coding-Features)
* [Installation & Run](#Installation--Run)


## Background

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

As an HKU student, you're no stranger to the pressure of managing multiple assignments. One night, while working on a deadline in the KKL building, you doze off only to wake up in a dimly lit maze. Feeling alone and desperate to escape, you embarked on a thrilling quest and faced a series of obstacles.

As you delve deeper into the myth, you uncover a sinister conspiracy that threatens the very fabric of your world. To unravel the mystery and escape, you must summon your inner strength and overcome increasingly daunting challenges.

The fate of your world hangs in the balance as you race against time to break free from the clutches of this enigmatic realm. Are you ready to unleash your full potential and uncover the shocking truth behind this mysterious event? Adventure awaits!


## Gameplay
In this text-based role-playing game, player uses their keyboard and mouse to control their character, making different decisions to influence the outcome and trajectory of the story. Clear instructions will be given at every stage throughout the entire gameplay.

### Mini Games
- 2 mini games are included. Players may have to pass one or both of the games to unveil latter chapters, depending on the trajectory.
- In the Password checkpoint, the first mini game "wordle", a classic word guessing game would be implemented to prompt the player for password input. Player would be given the password length and number of allowed trials, both vary with the difficulty chosen at the beginning of the game.
- The other mini game is the classic Tic-Tac-Toe but with our twist. Like Wordle, versions of distinct levels of difficulty were made. Under "Hard" mode, the game becomes very challenging due to the state-of-the-art AI algorithms embedded. Try to defeat it!

### Combat
In each turn-based battle, player can choose different actions: punch, kick, block, dodge or use items. Each action offers different merits and risks against different opponent actions. Considering what action the opponent will take and choosing wisely what action to take within a tight time limit could be challenging.

## Coding Features

### Generation of Random Game Sets and Events

- Numerous C++ standard libraries are used to ensure a high level of randomness, considering that computer fails to generate genuine random numbers on its own.
- In each battle, attack damage(p_atk,e_atk) is a random integer within a specific range; enemy has random action(e_action) and random dialogue with player in each round.
- Password is randomly chosen from answer.txt for each game.

### Data Structures For Storing Game Status

- Inside the `PlayerInfo`, player-specific information will be stored, including:
  - `user_name`, in the form of a string
  - `difficulty`, in the form of a string
  - `hp`(Health Point), in form of integer
  - `buff`, in the form of an integer
  - `items`, in the form of string vector
  - `checkpoint`, in the form of a string
  
 - Inside `ColorOption`, a wide variety of combinations of word colors and fonts are stored

- In each battle, int is used to store player and enemy hp, and an array of int is used to store the remaining numbers of rounds of special effects players have.

### Dynamic Memory Management

- In each battle, a dynamic int array with varying sizes is used to store the ID of the items the player have within each round
- vectors (dynamic arrays) are used to store sequences of elements
- Examples: vector<string> answerlist; vector<string> attempts;

### File input/output

- Game data, like checkpoint completion, are stored in `saves.sav` for multiple players to save and load game saves. Those files could also be deleted from the game menu.
- For the Password checkpoint, a wide variety of possible passwords are stored in `answer.txt`, and an extensive list of valid English words is stored in `dictionary.txt`. They are loaded when a password is randomly chosen and when each player input goes through a validity check. The program reads from files using ifstream.

### Program codes in multiple files

- Functions are stored in multiple separate files. Examples include:
  - `PlayerInfo` and `ColorOption` structs,  will be declared and defined in their own header and source files, which could be used in all other source files.
  - Functions for different output styles, animations, colors and fonts, etc. are included in `output_style.h` and `word_style.h` and could be used repeatedly and globally, without copying the same blocks of code every time to establish a specific format.
  - From the main game, player could call the function `call_new_battle` in `battle.h` to start a new battle.
  
### Elucidation of what each section does through extensive comments

- Example: "// function to generate a random password (randomly choose one from answer.txt)"

### Formatting

- The code is organized into functions to make it readable and modular.
- For our naming style, function and variable names are made self-explanatory and in a consistent style.

## Installation & Run

1. On Mac/Linux computers, open Terminal and navigate to the directory where you want to download the game.
2. Clone the repository using the command `git clone https://github.com/MarcusKLY/ENGG1340-Group-Project`.
3. Change your directory to the downloaded repository using the command `cd ENGG1340-Group-Project`.
4. Compile and start the game by entering the command `make game`.
