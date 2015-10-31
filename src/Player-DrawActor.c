char *key;
bool action = false;

//----------------------------------------------
key = GetKeyState();  // Get entire keyboard state


if (IsLeft (key))
{
    flipX (true);
    //animpos = STEP1; // swap to STEP2 every 100ms or 3 frames
    animpos = (frame / 5) % 2 + 1; // STEP1, STEP2
    x -= 5;
    action = true;
}
if (IsRight (key))
{
    flipX (false);
    animpos = (frame / 5) % 2 + 1; // STEP1, STEP2
    x += 5;
    action = true;
}
if (IsBlow (key))
{
    if (percentageAir > 0)
    {
        percentageAir -= 2;
        animpos = BLOWDOWN;
        y -= 5;
        action = true;
    }
}
if (IsSuck (key))
{
    if (percentageAir < 100)
    {
        if (IsUp (key))
        {
            animpos = SUCKUP;
        }
        else
        {
            animpos = SUCK;
        }

        action = true;
        percentageAir++;
    }
}

// if falling
if (y == yprevious)
{
    while (CollisionFree ("Event Actor", x, y+1) && y < yprevious + 5)
        y++;
}

// collision.check
while (!CollisionFree ("Event Actor", x, y))
{
    if (x > xprevious)
    {
        x--;
    }
    else if (x < xprevious)
    {
        x++;
    }
    if (CollisionFree ("Event Actor", x, y))
        break;
 
    if (y > yprevious)
    {
        y--;
    }
    else if (y < yprevious)
    {
        y++;
    }

    if (x == xprevious && y == yprevious)
        break;
}

if (x == xprevious && y == yprevious && action == false)
{
    animpos = STAND;
}
else if (y > yprevious)
{
    animpos = FALL;
}

//-manage the view port-----------------------------
// move view if less than 4 tiles from the left or the right
if (x - view.x > 256)
{
    view.x = x - 256;
}
else if (x - view.x < 64)
{
    view.x = x - 64;
}

// move view if less than one tile from the top or bottom
if (y - view.y < 16)
{
    view.y = y - 16;
}
else if (y - view.y > 192 )
{
    view.y = y - 192;
}