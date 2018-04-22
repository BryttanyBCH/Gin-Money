#include "interface.h"

// Here for the sake of being here, useful if we wanted to include the name of the game in the display
Interface::Interface(std::string nameIn)
{
    name = nameIn;
}


void Interface::preDealDisplay(Player p1, Player p2)
{
    system("tput clear");
    
    std::cout << p2.getName() << std::endl;
    std::cout << "[  ][  ][  ][  ][  ][  ][  ][  ][  ][  ]" << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "            [DW]        [TH]            " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "[  ][  ][  ][  ][  ][  ][  ][  ][  ][  ]" << std::endl;
    std::cout << " 0   1   2   3   4   5   6   7   8   9  " << std::endl;
    std::cout << p1.getName() << std::endl;
    return;
}

// displays gameplay, WIP
void Interface::mainGameDisplay(Player p1, Player p2, Pile draw, Pile trash)
{
    system("tput clear");
    
    std::cout << p2.getName() << std::endl;
    p2.displayDebug();
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "            " << draw.getTopCard() << "        " << trash.getTopCard() << "            " << std::endl;
  //std::cout << "            [DW]        [TH]            " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    std::cout << "                                        " << std::endl;
    p1.displayDebug();
    std::cout << " 0   1   2   3   4   5   6   7   8   9  " << std::endl;
    std::cout << p1.getName() << std::endl;
    return;
}