int d = 4.1666666; // 100/4/6

if (Player.percentageAir > 100 - cloneindex*4*d - d)
{
    animpos = 0;
}
else if (Player.percentageAir > 100 - cloneindex*4*d - d*2)
{
    animpos = 1;
}
else if (Player.percentageAir > 100 - cloneindex*4*d - d*3)
{
    animpos = 2;
}
else if (Player.percentageAir > 100 - cloneindex*4*d - d*4)
{
    animpos = 4;
}
else
{
    animpos = 5;
}
