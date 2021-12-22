#pragma once


#include <vector>
#include "ASpell.hpp"

class	SpellBook
{
	private:
		std::vector<ASpell *>	_array;
		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &copy);
	public:
		SpellBook(){;};
		~SpellBook()
		{
			std::vector<ASpell *>::iterator		b = _array.begin();
			std::vector<ASpell *>::iterator	e = _array.end();
			while(b != e)
			{
				delete (*b);
				b++;
			}
			_array.clear();
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
			this->_array.push_back(src->clone());
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
		ASpell	*createSpell(std::string	const &name)
		{
			std::vector<ASpell *>::iterator		b = _array.begin();
			while(b != _array.end())
			{
				if((*b)->getName() == name)
				{
					return (*b);
				}
				b++;
			}
			return (NULL);
		};
};

