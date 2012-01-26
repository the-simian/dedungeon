#pragma once
#include <vector>

namespace dedungeon
{
    typedef std::vector<std::vector<char> > mapMatrix;

    class Dungeon
    {
        private:
            mapMatrix _map;
            unsigned int _width;
            unsigned int _height;

        public:
            Dungeon(unsigned int width = 80, unsigned int height = 40)
            {
                _width = width;
                _height = height;
            }

            mapMatrix GetMap()
            {
                return _map;
            }

            unsigned int GetHeight() { return _height; }
            unsigned int GetWidth() { return _width; }

            void SetCell(unsigned int x, unsigned int y, char cellValue)
            {
                if(x > _width || y > _height || x < 0 || y < 0 || cellValue < 0 || cellValue > 255)
                {
                    return;
                }
                _map[x][y] = cellValue;
            }

            char GetCell(unsigned int x, unsigned int y)
            {
                if(x > _width || y > _height || x < 0 || y < 0)
                {
                    return 0;
                }

                return _map[x][y];
            }
    };
}
