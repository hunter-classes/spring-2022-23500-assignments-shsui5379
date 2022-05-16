#include "Labyrinth.h"

bool isPathToFreedom(MazeCell *start, const std::string &moves)
{
    bool hasSpellbook = false;
    bool hasPotion = false;
    bool hasWand = false;

    MazeCell *current = start;

    if (current->whatsHere == Item::POTION)
        hasPotion = true;
    else if (current->whatsHere == Item::SPELLBOOK)
        hasSpellbook = true;
    else if (current->whatsHere == Item::WAND)
        hasWand = true;

    for (char move : moves)
    {
        switch (move)
        {
        case 'N':
            current = current->north;
            break;

        case 'E':
            current = current->east;
            break;
        case 'S':
            current = current->south;
            break;
        case 'W':
            current = current->west;
            break;
        }

        if (current == nullptr)
            return false;

        if (current->whatsHere == Item::POTION)
            hasPotion = true;
        else if (current->whatsHere == Item::SPELLBOOK)
            hasSpellbook = true;
        else if (current->whatsHere == Item::WAND)
            hasWand = true;
    }

    return hasPotion && hasSpellbook && hasWand;
}
