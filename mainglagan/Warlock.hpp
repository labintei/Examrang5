#ifndef		WARLOCK_HPP
#define		WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class	Warlock
{
	private:
		std::string		_name;
		std::string		_title;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);
		SpellBook	_book;
	public:
		Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
		{
			std::cout << _name << ": This looks like another boring day.\n";
		};
		virtual ~Warlock(){std::cout << _name << ": My job here is done!\n";};
		std::string const	getName(void) const {return _name;};
		std::string const	getTitle(void) const {return _title;};
		void	setTitle(std::string const &title){_title = title;};
		void	introduce(void) const
		{
			std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
		};
		void	learnSpell(ASpell *src)
		{
			this->_book.learnSpell(src);
		};
		void	forgetSpell(std::string const &name)
		{
			this->_book.forgetSpell(name);
		};
		void	launchSpell(std::string	const &name, ATarget const &ref)
		{
			ASpell	*a= this->_book.createSpell(name);
			if(a)
				a->launch(ref);
		};
};

#endif
