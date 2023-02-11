#include<opencv2/opencv.hpp>
#include<string>
#include<vector>
#include <iostream>
#include <filesystem>
#include <chrono>
#include"Locations.h"

using namespace std;
using namespace cv;
using namespace chrono;

string getImagesPath();
string CreateOutputDirectory(string);
Mat getImage(const string&);
void cropImage(Mat, Location, string, string);

const string outputFolderName = "Output";

int main()
{
    string imagePath = getImagesPath();

    string outputPath = CreateOutputDirectory(imagePath);

    auto start = high_resolution_clock::now();

    //the class where all our data is stored for how to edit the images
    Locations locations;

    auto knight = getImage(imagePath + "Knight.png");
    auto geo = getImage(imagePath + "Geo.png");
    auto spells = getImage(imagePath + "VoidSpells.png");
    auto hud = getImage(imagePath + "Hud.png");

    //for naming
    int i = 0;

    cropImage(knight, locations.KnightStanding, outputPath, to_string(i++));
    cropImage(knight, locations.KnightDashing, outputPath, to_string(i++));
    cropImage(knight, locations.KnightCDash, outputPath, to_string(i++));
    cropImage(knight, locations.KnightLantern, outputPath, to_string(i++));

    cropImage(geo, locations.GeoSmall, outputPath, to_string(i++));
    cropImage(geo, locations.GeoMed, outputPath, to_string(i++));
    cropImage(geo, locations.GeoBig, outputPath, to_string(i++));
    cropImage(geo, locations.GeoSmall2, outputPath, to_string(i++));
    cropImage(geo, locations.GeoMed2, outputPath, to_string(i++));
    cropImage(geo, locations.GeoBig2, outputPath, to_string(i++));

    cropImage(spells, locations.SpellShriek, outputPath, to_string(i++));
    cropImage(spells, locations.SpellDive, outputPath, to_string(i++));
    cropImage(spells, locations.SpellFireball, outputPath, to_string(i++));

    cropImage(hud, locations.HudOrb, outputPath, to_string(i++));
    cropImage(hud, locations.HudHud, outputPath, to_string(i++));
    cropImage(hud, locations.HudMask, outputPath, to_string(i++));
    cropImage(hud, locations.HudOrangeMask, outputPath, to_string(i++));
    cropImage(hud, locations.HudBlueMask, outputPath, to_string(i++));

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Done in " << duration.count() << "ms" << endl;
}

//ask user for path, if empty use current directory
//also ensure last character is /
string getImagesPath()
{
    string providedPath;
    cout << "Please provide path to Knight.png, Geo.png, VoidSpells.png, Hud.png (leave blank for current directory) : " << endl;
    getline(cin, providedPath);

    if (providedPath == "")
    {
        providedPath = filesystem::current_path().generic_string();
    }

    if (!filesystem::is_directory(providedPath))
    {
        cout << "The path " << providedPath << "is not valid" << endl;
        exit(-1);
    }

    replace(providedPath.begin(), providedPath.end(), '\\', '/');

    if (providedPath.at(providedPath.size() - 1) != '/')
    {
        providedPath += '/';
    }

    return providedPath;

}

string CreateOutputDirectory(string path)
{
    if (filesystem::is_directory(path + outputFolderName))
    {
        filesystem::remove_all(path + outputFolderName);
    }

    filesystem::create_directory(path + outputFolderName);

    return path + outputFolderName + "/";
}

//read the image as a transparent png
Mat getImage(const string& path)
{
    return imread(path, IMREAD_UNCHANGED);
}

//crop the
void cropImage(const Mat image, const Location location, const string path, const string fileName)
{
    Mat newImg = image(Rect(location.x, location.y, location.width, location.height));
    if (location.shouldRotate)
    {
        Mat rotated;
        rotate(newImg, rotated, location.rotation);
        newImg = rotated;
    }
    imwrite(path + fileName + ".png", newImg);
}
