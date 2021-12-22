#include "TargetGenerator.hpp"
//#include "BrickWall.hpp"
//#include "Dummy.hpp"

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator		b = this->_array.begin();
	std::vector<ATarget *>::iterator		e = this->_array.end();
	while(b != e)
	{
		delete *b;
		b++;
	}
	this->_array.clear();
}
