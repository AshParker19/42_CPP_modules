#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void put_line(bool nl)
{
    std::cout << GREEN << "**************************************************" << RESET << std::endl;
    if (nl)
        std::cout << std::endl;
}

int main()
{
    FragTrap bro("bro");
    FragTrap dude("dude");

   std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        put_line(false);
        bro.attack("dude");
        if (bro.getEnergyPoints() > 0)
            dude.takeDamage(bro.getAttackDamage());
        if (dude.getHitPoints() <= 0)
        {
            put_line(true);
            break ;
        }
        if (i && i % 3 == 0)
            bro.beRepaired(i * 20);

        dude.attack("bro");
        if (dude.getEnergyPoints() > 0)
            bro.takeDamage(dude.getAttackDamage());
         if (bro.getHitPoints() <= 0)
        {
            put_line(true);
            break ;
        }
        if (i && i % 2 == 0)
            dude.beRepaired(i * 25);

        std::cout   << GREEN << ">>>>>>>>>>>>>>>>>> " << PURPLE << "ROUND " << (i + 1) << " RESULT"
                    << GREEN << " <<<<<<<<<<<<<<<<<<" << RESET << std::endl;
        bro.roundResult();
        dude.roundResult();
        put_line(true);
    }
    std::cout << std::endl;
    bro.highFivesGuys();
}