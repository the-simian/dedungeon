#pragma once
#include "IDungeonGenerator.hpp"

namespace dedungeon {
namespace generators {

class MazeGenerator : public IDungeonGenerator
{
    private:
        void GenerateRooms(Dungeon& d);
        void GenerateHallways(Dungeon& d);
    public:
        virtual Dungeon Generate();
};

} //end namespace generators
} //end namespace dedungeon
