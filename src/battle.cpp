//battle.cpp

#include "../header/battle.h"
#include "../header/choose_event.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;

bool dod(int t_blink)
    {
        int r=rand()%4;
        cout << "direction to dodge will be shown in an instant,input correct direction to dodge successfully" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << endl;
        string o="";
        o=((r==0) ? "        [ <= ]" : (r==1) ? "        [ >= ]" : (r==2) ? "        [ ⬆︎ ]" : "        [ ⬇︎ ]");
        cout << o << endl;
        this_thread::sleep_for(chrono::milliseconds(t_blink));
        system("clear");
        vector<string> opt;
        opt.push_back("Left");
        opt.push_back("Right");
        opt.push_back("Up");
        opt.push_back("Down");
        int indir=choose_event(opt,"Which direction will you dodge?");
        opt.clear();
        system("clear");
        return (indir==r);
    }
// callBattle() is a function that takes in the player's name, hp, attack, enemy's name, hp, attack, items, and time allowed.
// callBattle() returns 0 if the player wins, 1 if the player loses, and 2 if both lose.    if return -1, some magic happened and tmr will snow (•◡•)/.
int callBattle(string& p_name, int& p_hp, int p_atk[2], string& e_name, int& e_hp, int e_atk[2], bool (&items)[6], float time_allowed)
{
    srand(time(NULL)); //seed random number generator
    /***declare variables used in each round***/
    int p_action=0;
    int e_action=0;
    int e_ultimate_cd=0;
    bool first=true;
    const string dict_item[6] = {"energy drink","half-eaten sXXway sandwich","golden leaf","Xphone phone case","key","one-time-use flashlight"};
    const string dict_item_detail[6] = {"energy drink(+5atk in next 3round)","half-eaten sXXway sandwich(+10HP)","golden leaf(+5HP per next 3round)","Xphone phone case(neutralize all of next damage dealt by enemy)","key(throw at enemy to deal 10damage)","one-time-use flashlight(stop next enemy action)"};
    const string dict_action[5] = {"Punch", "Kick", "Block", "Dodge", "Ars Blasto"};
    int p_effect[3] = {-1,-1,-1};
    bool e_frozen=false;
    bool late=false;
    int r=0;
    std::chrono::steady_clock::time_point start_time;
    float time_left;
    cout.precision(1);

    /***battle intro***/
    cout << "Here comes a new challenger!" << endl;
    e_action = rand() % 5;
    e_ultimate_cd = rand() % 3 + 4;

    /***battle loop***/
    while (true)
    {
        /***new round start***/
        cout<<endl;
        first = true;

        /***player choose action/use item loop***/
        while (true)
        {
            bool chosen = false;
            bool item_available = false;
            cout << p_name << ": " << p_hp << " HP | " << e_name << ": " << e_hp << endl;
            cout << "items available: " << endl;
            for (int i=0; i<6; i++)
            {
                if (items[i])
                {
                    cout << "| "<< i << ":" <<dict_item_detail[i] << " ";
                    item_available = true;
                }
            }
            if(!item_available)
            {
                cout << "| X";
            }
            cout << " |" << endl << endl;
            if(first)
            {
                //reset variable used for each round
                this_thread::sleep_for(chrono::milliseconds(3000));
                start_time = std::chrono::steady_clock::now();
                time_left = time_allowed;
                e_frozen = false;
                late = false;
                first=false;
            }
            cout << "select action [ i:use item | p:punch | k:kick | b:block | d:dodge ]" << endl;

            /***input action loop***/
            while (true)
            {
                //input action and count time
                int pin;
                time_left = time_allowed - std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count()/1000.0;
                cout << "You have " << fixed << time_left << " left in this round" << endl;
                vector<string> opt;
                opt.push_back("use items");
                opt.push_back("punch");
                opt.push_back("kick");
                opt.push_back("block");
                opt.push_back("dodge");
                pin=choose_event(opt,"What action do you choose?");
                opt.clear();
                //check time left
                if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count()/1000.0 >= time_allowed)
                {
                    cout << "Your input is too late" << endl;
                    late = true;
                    break;
                }
                //if player choose to use item
                    if(pin==0)
                    {
                        /***input item choice loop***/
                        while(true)
                        {
                            //if no item
                            if(count(begin(items), end(items), true)==0)
                            {
                                cout << "You have no item" << endl;
                            }
                            //if has item
                            else
                            {
                                //input item choice and count time
                                time_left = time_allowed - std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count()/1000.0;
                                cout << "You have " << fixed << time_left << " left in this round" << endl;
                                vector<string> opt;
                                vector<int> convert;
                                opt.push_back("cancel");
                                convert.push_back(-1);
                                for (int i = 0; i < (int)sizeof(items)/(int)sizeof(items[0]); i++)
                                {
                                    if(items[i])
                                    {
                                        opt.push_back(dict_item_detail[i]);
                                        convert.push_back(i);
                                    }
                                }
                                pin=choose_event(opt,"Select your choice: ");
                                opt.clear();
                                //check time left
                                if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count()/1000.0 >= time_allowed)
                                {
                                    late = true;
                                    break;
                                }
                                //if cancel use
                                if(pin==0)
                                {
                                    break;
                                }
                                //if use
                                if(convert[pin]==0)//|atk up|
                                {
                                    
                                    p_atk[0] += 5;
                                    p_atk[1] += 5;
                                    p_effect[0] = 3;
                                    cout << "[slurp slurp ... gulu]" << endl << "You used " << dict_item_detail[0] << endl;
                                    items[0] = false;
                                    break;
                                }
                                if(convert[pin]==1)//|heal|
                                {
                                    p_hp+=10;
                                    cout << "[Om Nom Nom ... Om Nom Nom]" << endl << "You used " << dict_item_detail[1] << endl;
                                    items[1] = false;
                                    break;
                                }
                                if(convert[pin]==2)//|regen|
                                {
                                    p_effect[2] = 3;
                                    cout << "[Sulu Sulu...]" << endl << "You used " << dict_item_detail[2] << endl;
                                    items[2] = false;
                                    break;
                                }
                                if(convert[pin]==3)//|block|
                                {
                                    p_effect[3] = 1000;
                                    cout << "You used " << dict_item_detail[3] << endl;
                                    items[3] = false;
                                    break;
                                }
                                if(convert[pin]==4)//|hurt enemy|
                                {
                                    e_hp-=10;
                                    cout << "[Weeeeeeeee]" << endl << "You used " << dict_item_detail[2] << endl << e_name << "-10HP" << endl;
                                    r=rand()%4;
                                    cout << e_name << ": " << (r == 0 ? "Ouch!" : r == 1 ? "No!" : r == 2 ? "Stop!" : "Ah!") << endl;
                                    items[4] = false;
                                    break;
                                }
                                if(convert[pin]==5)//|freeze enemy|
                                {
                                    e_frozen = true;
                                    cout << "You used " << dict_item_detail[2] << endl;
                                    cout << "Strong light is flashed towards " << e_name << endl;
                                    items[5] = false;
                                    break;
                                }
                            }
                            //back to choose action
                            break;
                        }
                    }
                    //if player choose other action
                    else
                    {
                        chosen = true;
                        p_action=pin-1;
                        //stop input action loop
                        break;
                    }
            }
            //check if enemy is dead
            if(e_hp<=0)
            {
                return (0);
            }
            //check if player input action to start fight
            if(chosen || late)
            {
                break;
            }
        }
        cout<<endl;
        
        /***fight start***/
        //|action advantage:(punch->dodge, kick->block, dodge->kick, block->punch, block/dodge->ultimate)|
        //|dodge atk with random chance, block receive lower damage|
        system("clear");
        int ori_p_hp = p_hp;
        int ori_e_hp = e_hp;
        //if late input and enemy is flashed
        if(late && e_frozen)
        {
            cout << "Your input is too late" << endl;
            cout << e_name << " is blinded" << endl;
            cout << p_name << " cannot decide what to do" << endl;
            p_effect[3] = 1;
            this_thread::sleep_for(chrono::milliseconds(3000));
        }
        //if not late input and enemy is flashed
        if(!late && e_frozen)
        {
            cout << e_name << " is blinded" << endl;
            cout << p_name << " used " << dict_action[p_action]<< endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            if(p_action==0)
            {
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==1)
            {
                e_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
            }
        }
        //if late input and enemy is not flashed
        if(late && !e_frozen)
        {
            cout << "Your input is too late" << endl;
            if(e_action==0||e_action==1||e_action==4)
            {
                cout << e_name << (rand() % 3 == 0 ? ": Hahah! Too slow!" : rand() % 3 == 1 ? ": You are so slow!" : ": Just stay there and shiver!") << endl;
            }
            cout << p_name << " cannot decide what to do" << endl;
            cout << e_name << " used " << dict_action[e_action]<< endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            if(e_action==0)
            {
                p_hp -= e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1));
            }
            if(e_action==1)
            {
                p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))/1.5;
            }
        }
        //if not late input and enemy is not flashed
        if(!late && !e_frozen)
        {
            cout << p_name << " used " << dict_action[p_action]<< " , " << e_name << " used " << dict_action[e_action] << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            if(p_action==0 && e_action==0)
            {
                p_hp -= e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1));
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==0 && e_action==1)
            {
                p_hp -= (p_atk[0]+rand() % (p_atk[1]-p_atk[0]+1))/1.5;
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==0 && e_action==2)
            {
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1))/4;
            }
            if(p_action==0 && e_action==3)
            {
                cout << e_name << " failed to dodge" << endl;
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==0 && e_action==4)
            {
                p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))*1.5;
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==1 && e_action==0)
            {
                p_hp -= e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1));
                e_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
            }
            if(p_action==1 && e_action==1)
            {
                p_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
                e_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
            }
            if(p_action==1 && e_action==2)
            {
                e_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==1 && e_action==3)
            {
                if(rand()%10>=0.7)
                {
                    cout << e_name << " failed to dodge" << endl;
                    e_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
                }
                else
                {
                    cout << e_name << " dodged successfully" << endl;
                }
            }
            if(p_action==1 && e_action==4)
            {
                p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))*1.5;
                e_hp -= (p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1)))/1.5;
            }
            if(p_action==2 && e_action==0)
            {
                p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))/4;
            }
            if(p_action==2 && e_action==1)
            {
                p_hp -= p_atk[0]+(rand() % (p_atk[1]-p_atk[0]+1));
            }
            if(p_action==2 && e_action==4)
            {
                p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)));
            }
            if(p_action==3 && e_action==0)
            {
                if(dod(300))
                {
                    cout << p_name << " dodged successfully" << endl;
                }
                else
                {
                    cout << p_name << " failed to dodge" << endl;
                    p_hp -= e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1));
                }
            }
            if(p_action==3 && e_action==1)
            {
                if(dod(600))
                {
                    cout << p_name << " dodged successfully" << endl;
                }
                else
                {
                    cout << p_name << " failed to dodge" << endl;
                    p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))/1.5;
                }                
            }
            if(p_action==3 && e_action==4)
            {
                if(dod(200))
                {
                    cout << p_name << " dodged successfully" << endl;
                }
                else
                {
                    cout << p_name << " failed to dodge" << endl;
                    p_hp -= (e_atk[0]+(rand() % (e_atk[1]-e_atk[0]+1)))*1.5;
                }
            }
            
            if(p_hp!=ori_p_hp && p_effect[2]>=0)
            {
                cout << "Xphone case protected " << p_name << " and shattered" << endl;
                p_hp=ori_p_hp;
                p_effect[2]=-1;
            }
        }
        /***conclude round***/
        //show fight result
        cout<<endl;
        if(ori_p_hp!=p_hp)
        {
            cout << p_name << ": " << p_hp-ori_p_hp << endl;
        }
        if(ori_e_hp!=e_hp)
        {
            cout << e_name << ": " << e_hp-ori_e_hp << endl;
            //enemy response if hurt
            r=rand()%5;
            cout << (r==0 ? "Ouch!" : r==1 ? "No!" : r==2 ? "Stop!" : r==3 ? "Ah!" : "How dare you!" ) << endl;
        }
        //check win/loss
        if(p_hp<=0 && e_hp<=0)
        {
            return 2;
        }
        if(p_hp<=0){return 1;}
        if(e_hp<=0){return 0;}
        //random enemy action
        r=rand()%4;
        e_action=r;
        e_ultimate_cd-=1;
        //enemy ultimate skill
        if(e_ultimate_cd==0)
        {
            e_action=4;
            e_ultimate_cd = rand()%3+4;
            cout << e_name << ": Omae wa mou shindeiru!(You are dead!)" << endl;
        }
        //random show speech
        else if(rand()%10>=3)
        {
            cout << e_name << ": ";
            r=rand()%2;
            switch(e_action)
            {
                case 0:
                    cout << (r==0 ? "I will punch you!" : "Come at me again and eat my punch!") << endl;
                    break;
                case 1:
                    cout << (r==0 ? "I will kick you!" : "Try again and eat my kick!") << endl;
                    break;
                case 2:
                    cout << (r==0 ? "Don't hurt me!" : "Stop hurting me!") << endl;
                    break;
                case 3:
                    cout << (r==0 ? "You can't hurt me!" : "You will not hit me!") << endl;
                    break;
                default:
                    break;
            }
        }
        //player effect
        if(p_effect[0]>0)
        {
            p_hp+=5;
            cout << p_name << " restored 5HP" << endl;
        }
        if(p_effect[1]==0)
        {
            p_atk[0]-=5;
            p_atk[1]-=5;
        }
        p_effect[0]-=1;p_effect[1]-=1;p_effect[2]-=1;
    }

    return -1;
}

//call this function to start a new battle where (p_name) is the player's name, (e_name) is the enemy's name, (items) is a vector of items that the player has, (difficulty) is the difficulty of the battle [0 for easy, 1 for noraml, 2 for difficult], and (level) is the level of the enemy[1-5 higher level is more stronger]
int call_new_battle(string& p_name, string& e_name, vector<string> items, int difficulty, int level)
{
    int p_hp;
    int p_atk[2];
    int e_hp;
    int e_atk[2];
    bool item[6] = {false, false, false, false, false, false};
    float time_allowed;
    if(difficulty==0)
    {
        p_hp = 100;
        p_atk[0] = 8;
        p_atk[1] = 13;
        e_hp = 30;
        e_atk[0] = 3;
        e_atk[1] = 6;
        time_allowed = 30.0;
    }
    else if(difficulty==1)
    {
        p_hp = 50;
        p_atk[0] = 5;
        p_atk[1] = 8;
        e_hp = 50;
        e_atk[0] = 5;
        e_atk[1] = 8;
        time_allowed = 20.0;
    }
    else
    {
        p_hp = 50;
        p_atk[0] = 3;
        p_atk[1] = 8;
        e_hp = 50;
        e_atk[0] = 5;
        e_atk[1] = 8;
        time_allowed = 10.0;
    }

    e_hp*=(0.7+0.1*level);
    e_atk[0]*=(0.7+0.1*level);
    e_atk[1]*=(0.7+0.1*level);


    for(int i=0; i<items.size(); i++)
    {
        if(items[i]=="energy drink")
        {
            item[0]=true;
        }
        if(items[i]=="half-eaten sXXway sandwich")
        {
            item[1]=true;
        }
        if(items[i]=="golden leaf")
        {
            item[2]=true;
        }
        if(items[i]=="Xphone phone case")
        {
            item[3]=true;
        }
        if(items[i]=="key")
        {
            item[4]=true;
        }
        if(items[i]=="one-time-use flashlight")
        {
            item[5]=true;
        }
    }

    return callBattle(p_name, p_hp, p_atk, e_name, e_hp, e_atk, item, time_allowed);
}

//this call a sample battle with normal difficulty and a level3 enemy;
int call_sample_battle()
{
    string p_name = "Mr Hamburger";
    string e_name = "Flying Spaghetti Monster";
    vector<string> items;
    items.push_back("energy drink");
    items.push_back("Xphone phone case");
    items.push_back("golden leaf");
    call_new_battle(p_name, e_name, items, 1, 3);
    return 0;
}