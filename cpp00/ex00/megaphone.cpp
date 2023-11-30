#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int i;
    int y;
    
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        i = 0;
        while(++i < ac)
        {
            y = -1;
            while(av[i][++y])
            {
                if(av[i][y] > 96 && av[i][y] < 123)
                    std::cout << (char)(av[i][y] - 32);
                else
                std::cout << av[i][y];
            }
        }
    }
    std::cout << std::endl;
}