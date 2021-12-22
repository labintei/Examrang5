
#pragma once

#include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public:

	Fwoosh(): ASpell("Fwoosh", "fwooshed"){;};
	~Fwoosh(){;};
	virtual ASpell	*clone(void) const{return new Fwoosh();};
};
