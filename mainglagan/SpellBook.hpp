/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:51:10 by ncolomer          #+#    #+#             */
/*   Updated: 2021/12/22 19:23:40 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <vector>
# include "ASpell.hpp"

class SpellBook
{
private:
	std::vector<ASpell*> spells;

	SpellBook(SpellBook const &other);
	SpellBook &operator=(SpellBook const &other);
public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &spellName);
	ASpell *createSpell(std::string const &spellName);
};

#endif
