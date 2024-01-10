#include "ClapTrap.hpp"


int main()
{
    ClapTrap a("ciccio");
    ClapTrap b(a);
    ClapTrap c;

    c.attack(b.get_name());
    b.takeDamange(0);
    b.beRepaired(0);
}