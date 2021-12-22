#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"

class	Warlock
{
	private:
		std::string		_name;
		std::string		_title;
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);
		std::vector<ASpell *>	_array;
	public:
		Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
		{
			std::cout << _name << ": This looks like another boring day.\n";
		};
		~Warlock(){
			std::vector<ASpell *>::iterator		b = _array.begin();
			while(b != _array.end())
			{
				delete (*b);
				b++;
			}
			_array.clear();
			std::cout << _name << ": My job here is done!\n";};
		std::string const	getName(void) const {return _name;};
		std::string const	getTitle(void) const {return _title;};
		void	setTitle(std::string const &title){_title = title;};
		void	introduce(void) const
		{
			std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
		};
		void	learnSpell(ASpell *src)
		{
			std::vector<ASpell *>::iterator		b = _array.begin();
			while(b != _array.end())
			{
				if((*b)->getName() == src->getName())
					return ;
				b++;
			}
			_array.push_back(src);
		};
		void	forgetSpell(std::string const &name)
		{
			std::vector<ASpell *>::iterator		b = _array.begin();
			while(b != _array.end())
			{
				if((*b)->getName() == name)
				{
					delete (*b);
					_array.erase(b);
					return ;
				}
				b++;
			}
		};
		void	launchSpell(std::string	const &name, ATarget const &ref)
		{
			std::vector<ASpell *>::iterator		b = _array.begin();
			while(b != _array.end())
			{
				if((*b)->getName() == name)
				{
					(*b)->launch(ref);
					return ;
				}
				b++;
			}
		};
};

//#endif
