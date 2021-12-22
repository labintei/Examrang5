/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:58:33 by ncolomer          #+#    #+#             */
/*   Updated: 2021/12/22 19:27:54 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dummy_HPP
# define Dummy_HPP

# include "ATarget.hpp"

class Dummy: public ATarget
{
public:
	Dummy();
	virtual ~Dummy();

	virtual ATarget *clone(void) const;
};

#endif
