// These correspond to the frame 0-24 in player.png
// Walking
#define STAND 0
#define STEP1 1
#define STEP2 2
#define BLOWDOWN 3
#define FALL 4
#define SUCK 5
#define SUCKUP 6
#define SUCKDOWN 7
#define BLOW 8

#define bool int
#define true 1
#define false 0


// define the actions and the keyboard keys assosiated with them
int IsLeft (const char *key)
{
    return (key[KEY_LEFT] == 1 || key[KEY_a] == 1);
}

int IsRight (const char *key)
{
    return (key[KEY_RIGHT] == 1 || key[KEY_d] == 1);
}

int IsUp (const char *key)
{
    return (key[KEY_UP] == 1 || key[KEY_w] == 1);
}

int IsDown (const char *key)
{
    return (key[KEY_DOWN] == 1 || key[KEY_s] == 1);
}

int IsBlow (const char *key)
{
    return (key[KEY_SPACE] == 1 || key[KEY_x] == 1);
}

int IsSuck (const char *key)
{
    return (key[KEY_z] == 1);
}

void flipX (int yes)
{
    if (yes)
        ChangeAnimation ("Event Actor", "player-left", NO_CHANGE);
    else
        ChangeAnimation ("Event Actor", "player-right", NO_CHANGE);
}

void setCurrentAnimation (char* animation)
{
    ChangeAnimation ("Event Actor", "player-left", NO_CHANGE);
}

//void Trace (const char* formatString, ...)
//{
//    static char  str[4096];
//
//    va_start (pArgList, formatString);
//    vsnprintf (str, 4000, formatString, pArgList);
//    va_end (pArgList);
//    fprintf(file_, "%d, %s\n", frame, str);
//}
