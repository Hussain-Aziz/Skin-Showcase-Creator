#ifndef LOCATIONS
#define LOCATIONS
struct Location
{
    int x;
    int y;
    int width;
    int height;
    bool shouldRotate;
    int rotation;

    Location(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        shouldRotate = false;
    }
    Location(int x, int y, int width, int height, int rotation)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        shouldRotate = true;
        this->rotation = rotation;
    }
};

class Locations
{
public:

    const Location KnightStanding = Location(3278, 2395, 60, 130);
    const Location KnightDashing = Location(1904, 2732, 150, 100);
    const Location KnightCDash = Location(0, 1882, 345, 505, cv::ROTATE_90_COUNTERCLOCKWISE);
    const Location KnightLantern = Location(2823, 2831, 130, 80, cv::ROTATE_90_COUNTERCLOCKWISE);
    const Location GeoSmall = Location(3, 252, 26, 28);
    const Location GeoMed = Location(222, 306, 30, 40);
    const Location GeoBig = Location(187, 402, 38, 38);
    const Location GeoSmall2 = Location(160, 230, 27, 24);
    const Location GeoMed2 = Location(177, 289, 39, 30);
    const Location GeoBig2 = Location(181, 358, 39, 38);
    const Location SpellShriek = Location(670, 1470, 295, 275);
    const Location SpellDive = Location(340, 1466, 300, 292);
    const Location SpellFireball = Location(795, 1325, 500, 135);
    const Location HudOrb = Location(790, 925, 120, 120);
    const Location HudHud = Location(1352, 1632, 154, 242, cv::ROTATE_90_COUNTERCLOCKWISE);
    const Location HudMask = Location(76, 855, 70, 55, cv::ROTATE_90_COUNTERCLOCKWISE);
    const Location HudOrangeMask = Location(1984, 409, 53, 77);
    const Location HudBlueMask = Location(1893, 312, 80, 84);
};
#endif