#pragma once

#include <string>
#include <iostream>

class	ASpell;

class	ATarget
{
	private:
		std::string		_type;
	public:
		ATarget(){;};
		ATarget(std::string const &type): _type(type){;};
		ATarget(ATarget const &copy){*this = copy;};
		ATarget	&operator=(ATarget const &copy){_type = copy.getType(); return *this;};
		virtual ~ATarget(){;};
		std::string	const	&getType(void)const	{return _type;};
		void	getHitBySpell(ASpell const &src) const;
		virtual ATarget	*clone()const = 0;
};

#include "ASpell.hpp"
