#pragma once

#include <iostream>
#include <string>

class	Warlock
{
	private:
		std::string		_name;
		std::string		_title;
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);
	public:
		Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
		{
			std::cout << _name << ": This looks like another boring day.\n";
		};
		~Warlock()
		{	std::cout << _name << ": My job here is done!\n";};
		std::string const	getName(void) const {return _name;};
		std::string const	getTitle(void) const {return _title;};
		void	setTitle(std::string const &title){_title = title;};
		void	introduce(void) const
		{
			std::cout << _name << ": I am " << _name << ", " << _title << " !\n";
		};
};

//#endif
