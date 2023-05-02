// Time_Tunnel.cpp

#include "../header/Time_Tunnel.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// input: player name
// function for the story chapter "Time_Tunnel"
int Time_Tunnel(string player_name)
{
    system("clear");
    char_typewriter("When you arrive in time tunnel, you see a man sitting across from you, right at the opposite side of the tunnel", italic_green);
    char_typewriter("You wounder who is this man again", italic_green);
    char_typewriter("You🙎: Ohhh, are you the man that the girl mentioned?", bold_magenta);
    char_typewriter("You🙎: The future me that is from ten years later", bold_magenta);
    char_typewriter("Future You: Hi....And yes, the younger me", bold_magenta);
    char_typewriter("You🙎: Are we going to fight again like what I did with the others", bold_magenta);
    char_typewriter("Future You: Nonono", bold_magenta);
    char_typewriter("You🙎: A girl told me to ask you what happened...So can you tell me...?", bold_magenta);
    char_typewriter("Future You: So actually, ten years later, there was a murder at HKU", bold_magenta);
    char_typewriter("Future You: A professor strangled a girl with a rope, causing her to suffocate", bold_magenta);
    char_typewriter("You🙎: Why is it about me and you?", bold_magenta);
    char_typewriter("Future You: I was there when the professor killed the girl, yet I did nothing...", bold_magenta);
    char_typewriter("Future You: It was so scary watching all this at the time, my brain was completely empty", bold_magenta);
    char_typewriter("Future You: I thought my life could still be fine after all this", bold_magenta);
    char_typewriter("Future You: But NO! I was completely wrong!!", bold_magenta);
    char_typewriter("Future You: That girl's enmity had dragged me into the alien space and summoned all the ghosts of HKU, you just faced two", bold_magenta);
    char_typewriter("You🙎: Then what about me? Why am I here?", bold_magenta);
    char_typewriter("Future You: I called you in because I had to tell you this!", bold_magenta);
    char_typewriter("Future You: Remember to save that girl ten years after. Otherwise you will become me!", bold_magenta);
    char_typewriter("You🙎: But I would have been dead if i cant put down those ghost!", bold_magenta);
    char_typewriter("Future You: Yes, but if you are not here now, you will be here in the future", bold_magenta);
    char_typewriter("You🙎: You are right tho...So how could we get out of here?", bold_magenta);
    char_typewriter("Future You: It's almost time for you to be sent back to your original world", bold_magenta);
    char_typewriter("He looks at his watch", italic_green);
    char_typewriter("You🙎: How about you? Although I'm not really you, you're still me...", bold_magenta);
    char_typewriter("Future You: Because of what I've done, I should be here forever...\n", bold_magenta);

    vector<string> items;
    items.push_back("Comfort him");
    items.push_back("Agree with him");
    int response = choose_event(items, "Your response?");
    items.clear(); // Clear the vector
    if (response == 0)
    {
        // option "Comfort him" chosen
        char_typewriter("\nYou🙎: It is normal to act like that under such situation...", bold_magenta);
        char_typewriter("You🙎: Lets leave together and go back to our normal lives", bold_magenta);
        char_typewriter("There is a portal appears behind You 🌀", italic_green);
        char_typewriter("You🙎: Let's leave this shitty place", bold_magenta);
        char_typewriter("Future You: .....", bold_magenta);
        char_typewriter("Future You: Well then", bold_magenta);
        char_typewriter("Then, you hold his hands and walk towards the portal together", italic_green);
        blink(5, "⌛", 300, italic_green);
        char_typewriter("Suddenly, you are back at the KKL building", italic_green);
        char_typewriter("But the difference is that everything is back to normal", italic_green);
        char_typewriter("You🙎: I guess he may have also been teleported back to his original world", bold_magenta);
        char_typewriter("You look at the computer in front of you, and the word document is still empty", italic_green);
        char_typewriter("You🙎: Damn it! After all, I still have to complete my assignments...\n", bold_magenta);
    }
    else if (response == 1)
    {
        // option "Agree with him" chosen
        char_typewriter("\nYou🙎: Yes! You deserve it! I think you should definitely stay here", bold_magenta);
        char_typewriter("You🙎: I think you should definitely stay here forever because of what you did", bold_magenta);
        char_typewriter("There is a portal appears behind You 🌀", italic_green);
        char_typewriter("You🙎: Finally!! I leave this shitty place", bold_magenta);
        char_typewriter("Future You: .....", bold_magenta);
        char_typewriter("He stares at you without a word", italic_green);
        char_typewriter("Then you walk towards the portal and step inside it", italic_green);
        blink(5, "⌛", 300, italic_green);
        char_typewriter("Suddenly, you are back at the KKL building", italic_green);
        char_typewriter("But the difference is that everything is back to normal", italic_green);
        char_typewriter("You🙎: Hmmm...don't know what will happen to him in the future", bold_magenta);
        char_typewriter("You look at the computer in front of you, and the word document is still empty", italic_green);
        char_typewriter("You🙎: Damn it! After all, I still have to complete my assignments...\n", bold_magenta);
    }
    char_typewriter("THANKS FOR PLAYING\n", bold_blue);
    char_typewriter("PROJECT BY:", bold_blue);
    char_typewriter("Kam Long Yin", bold_blue);
    char_typewriter("Chan Yat Kwan", bold_blue);
    char_typewriter("Wong Chun Hei", bold_blue);
    char_typewriter("Lam Chuck Yu", bold_blue);
    char_typewriter("Diao Mo Chiu\n", bold_blue);
    char_typewriter("Play again if you want to know more about the different options for the story!", bold_blue);
    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}