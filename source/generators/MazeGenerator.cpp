#include "generators/MazeGenerator.hpp"
#include <vector>
#include <cstdlib>

using namespace std;
using namespace dedungeon;
using namespace generators;

Dungeon MazeGenerator::Generate()
{
    Dungeon d;

    d.SetCell(5,5,'@');


    return d;
}

struct Room
{
    int topX;
    int topY;
    int bottomX;
    int bottomY;

    bool IsOverlapping(Room r)
    {
        //if topleft or bottom right points are within other room, it is overlapping.
        if((r.topX >= topX && r.topY >= topY && r.topX <= bottomX && r.topY <= bottomY) ||
           (r.bottomX >= topX && r.bottomY >= topY && r.bottomX <= bottomX && r.bottomY <= bottomY) )
        {
            return true;
        }
        return false;
    }
};

void MazeGenerator::GenerateRooms(Dungeon& d)
{
    vector<Room> rooms;
    int numberOfRooms = (rand() % 10) + 1;
    for(int i = 0; i < numberOfRooms; ++i)
    {
        int height = (rand() % 10) + 1;
        int width = (rand() % 10) + 1;
        int topX = (rand() % d.GetWidth());
        int topY = (rand() % d.GetHeight());

        if(topX + width > d.GetWidth())
        {
            width = d.GetWidth() - topX;
        }

        if(topY + height > d.GetHeight())
        {
            width = d.GetWidth() - topX;
        }

        Room r;
        r.topX = topX;
        r.topY = topY;
        r.bottomX = topX + width;
        r.bottomY = topY + height;

        for(vector<Room>::iterator it = rooms.begin(); it != rooms.end(); it++)
        {
            if((*it).IsOverlapping(r))
            {
                --i;
            }
            else
            {
                rooms.push_back(r);
            }
        }
    }
}

void MazeGenerator::GenerateHallways(Dungeon& d)
{

}
