// we want to push "Player" out of the way
// RedRock-DrawActor.c
if (walkLeft == true)
{
    x -= 1;
    if (x <= startX)
    {
        flipX(false);
        x = startX;
        walkLeft = false;
        animpos = 0;
    }
}
else
{
    x += 1;
    if (x >= endX)
    {
        flipX(true);
        x = endX;
        walkLeft = true;
        animpos = 1;
    }
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