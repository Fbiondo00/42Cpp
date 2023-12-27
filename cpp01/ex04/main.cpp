#include <iostream>
#include <fstream>

std::string ft_repl_line(std::string& line, std::string& str,std::string& new_str)
{
    std::size_t pos = 0;
    std::size_t new_pos = 0;
    std::string new_line;

    while((new_pos = line.find(str,pos)) != std::string::npos)
    {   
        new_line+=line.substr(pos, new_pos-pos);
        new_line+=new_str;
        pos +=new_pos + str.length();
    }
    new_line += line.substr(pos);
    return new_line;

}

int ft_replace(std::string& filename, std::string& str, std::string& new_str)
{
    std::ifstream input;
    std::ofstream output;
    std::string line;
    std::size_t f;

    input.open(filename, std::ios::in);
    output.open(filename + ".replace", std::ios::out);
    if (!input.is_open() || !output.is_open()) {
		std::cerr << "Error: Could not open file." << std::endl;
        return 3;
    }
    while(std::getline(input, line))
    {
        f = line.find(str);
        if(f != std::string::npos)
            output << ft_repl_line(line, str, new_str) << std::endl;
        else
            output << line << std::endl;
    }
    input.close();
	output.close();
    return 0;

}


int main(int ac, char **av)
{
    std::string filename;
    std::string str;
    std::string new_str;

   if (ac !=  4)
   {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1; 
   }
    filename = av[1];
    str = av[2];
    new_str = av[3];
    if(str.empty()|| new_str.empty()){
		std::cerr << "Error: The strings is empty." << std::endl;
		return 2;
	}
    ft_replace(filename,str,new_str);
}
