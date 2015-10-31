// Player-CreatActor.c
//
// The following variables are defined for Player
// int xgood;
// int ygood;
// int Status;

FILE* fl = fopen("octopus_trace.txt", "w");
file_ = fl;

// call the constructor
percentageAir = 100;

// set the default horizontal & vertical speed (accel vector)
xvelocity = 0;
yvelocity = 0;

State = STAND;
ChangeAnimationDirection("Event Actor", STOPPED);