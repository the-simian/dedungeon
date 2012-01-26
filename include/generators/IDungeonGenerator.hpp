#pragma once
#include "../Dungeon.hpp"


namespace dedungeon {
namespace generators{

class IDungeonGenerator
{
    public:
        virtual Dungeon Generate() = 0;
};

} //end namespace generators
} //end namespace dedungeon
