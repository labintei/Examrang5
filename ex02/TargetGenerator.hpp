#pragma once


#include <vector>
#include "ATarget.hpp"

class	TargetGenerator
{
	private:
		std::vector<ATarget*>	_array;
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &copy);

	public:
		TargetGenerator(){;};
		~TargetGenerator();

		void	learnTargetType(ATarget *src)
		{
			std::vector<ATarget *>::iterator		b = this->_array.begin();
			while(b != this->_array.end())
			{
				if((*b)->getType() == src->getType())
					return ;
				++b;
			}
			this->_array.push_back(src->clone());
		};
		void	forgetTargetType(std::string const &name)
		{
			std::vector<ATarget *>::iterator		b = this->_array.begin();
			while(b != this->_array.end())
			{
				if((*b)->getType() == name)
				{
					delete (*b);
					this->_array.erase(b);
					return ;
				}
				++b;
			}
		};
		ATarget	*createTarget(std::string	const &name)
		{
			std::vector<ATarget *>::iterator		b = this->_array.begin();
			std::vector<ATarget *>::iterator		e = this->_array.end();

			while(b != e)
			{
				if((*b)->getType() == name)
					return (*b);
				++b;
			}
			return (nullptr);
		};
};

