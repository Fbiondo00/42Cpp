#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap
{
private:
    std::string	name;
    int Hit_points;
    int Energy_points;
    int Attack_damage;
public:
    void attack( std::string const &target);
    void takeDamange(unsigned int amount);
    void beRepaired(unsigned int amount);
    int get_Hp(void) const;
    int get_Ep(void) const;
    int get_Ad(void) const;
    std::string get_name(void) const;
    void set_Hp(const unsigned int Hit_points);
    void set_Ep(const unsigned int Energy_points); 
    void set_Ad(const unsigned int Attack_damage); 
    // void set_name(C);
    ClapTrap();
    void operator = (const ClapTrap &Trap);
    ClapTrap(std::string const _name);
    ClapTrap(const ClapTrap &Trap);
    ~ClapTrap();
};

#endif