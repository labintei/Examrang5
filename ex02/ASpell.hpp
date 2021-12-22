
#pragma once

#include <string>
#include <iostream>

class	ATarget;

class	ASpell
{
	private:
		std::string		_name;
		std::string		_effects;
	public:
		ASpell(){;};
		ASpell(std::string const &name, std::string const &effects): _name(name), _effects(effects)
		{;};
		ASpell(ASpell const &copy){*this = copy;};
		ASpell	&operator=(ASpell const &copy){_name = copy.getName();_effects = copy.getEffects();return *this;};
		virtual ~ASpell(void){;};
		std::string	const	&getName(void)const	{return _name;};
		std::string const	&getEffects(void)const	{return _effects;};
		void	launch(ATarget const &src);
		virtual ASpell	*clone() const = 0;
};

#include "ATarget.hpp"
