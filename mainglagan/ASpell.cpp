#include "ASpell.hpp"

void	ASpell::launch(ATarget const &src)
{
	src.getHitBySpell((*this));
}
