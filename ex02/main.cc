/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:35:12 by ncolomer          #+#    #+#             */
/*   Updated: 2021/12/22 20:45:30 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"

int main(void)
{
	std::cout << "--- Constructors:\n";
	Warlock richard("Aang", "The Avatar");

	std::cout << "--- Spells:\n";
	Polymorph *water = new Polymorph();
	Fireball *fire = new Fireball();
	Fwoosh *air = new Fwoosh();
	richard.learnSpell(water);
	richard.learnSpell(fire);
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(air);
	richard.forgetSpell("Fwoosh");
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(air);

	std::cout << "--- Targets:\n";
	Dummy *hay = new Dummy();
	BrickWall *earth = new BrickWall();

	TargetGenerator tarGen;
	tarGen.learnTargetType(hay);
	tarGen.learnTargetType(earth);

	std::cout << "--- Spells (all):\n";

	std::cout << "1\n";
	Dummy	a;
	richard.launchSpell("Fwoosh", a);
//	std::cout << "2\n";
	std::cout << "*tarGen.createTarget(ffwefwfw) ne marche pas \n";
//	BrickWall b = *tarGen.createTarget("BrickWall Practice");
//	richard.launchSpell("Fireball", b);
	std::cout << "3\n";
	richard.launchSpell("Polymorph", *tarGen.createTarget("Dummy Practice"));
	std::cout << "4\n";
	std::cout << "--- Forgotten \"Fwoosh\":\n";

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Dummy Practice"));
	richard.launchSpell("Fireball", *tarGen.createTarget("BrickWall Practice"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Dummy Practice"));

	std::cout << "--- Spells (all):\n";

	richard.learnSpell(air);
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Dummy Practice"));
	richard.launchSpell("Fireball", *tarGen.createTarget("BrickWall Practice"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Dummy Practice"));

	std::cout << "--- Non-existant spell:\n";

	richard.launchSpell("ACID", *tarGen.createTarget("BrickWall Practice"));
	richard.forgetSpell("ACID");
	richard.launchSpell("ACID", *tarGen.createTarget("Dummy Practice"));

	std::cout << "--- Destructors:\n";
	return (0);
}
