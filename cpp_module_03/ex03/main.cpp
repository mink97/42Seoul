/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:19:08 by mingkang          #+#    #+#             */
/*   Updated: 2023/05/11 13:03:30 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap	t1;
	std::cout << "-------------------------------------------------------------" << std::endl;
	DiamondTrap	t2("one");
	std::cout << "-------------------------------------------------------------" << std::endl;
	DiamondTrap	t3("two", 10 , 10, 10);
	std::cout << "-------------------------------------------------------------" << std::endl;
	DiamondTrap	t4(t3);
	std::cout << "-------------------------------------------------------------" << std::endl;
	DiamondTrap	t5;
	t5 = t2;

	std::cout << "\n\033[0;94m" <<
	"-----------------------------default diamond-----------------------------"
	<< "\033[0;39m" << std::endl;
	std::cout << "t1's name : " << t1.get_name() << std::endl;
	std::cout << "t1's ClapTrap name : " << t1.ClapTrap::get_name() << std::endl;
	std::cout << "t1's Hit Points : " << t1.get_hitPoints() << std::endl;
	std::cout << "t1's energy : " << t1.get_energyPoints() << std::endl;
	std::cout << "t1's attack damage : " << t1.get_attackDamage() << std::endl;
	t1.attack("monster");
	t1.whoAmI();
	std::cout << "\n\033[0;94m" <<
	"----------------------------only name diamond----------------------------"
	<< "\033[0;39m" << std::endl;
	std::cout << "t2's name : " << t2.get_name() << std::endl;
	std::cout << "t2's ClapTrap name : " << t2.ClapTrap::get_name() << std::endl;
	std::cout << "t2's Hit Points : " << t2.get_hitPoints() << std::endl;
	std::cout << "t2's energy : " << t2.get_energyPoints() << std::endl;
	std::cout << "t2's attack damage : " << t2.get_attackDamage() << std::endl;
	t2.attack("monster");
	t2.whoAmI();
	std::cout << "\n\033[0;94m" <<
	"-----------------------------parameter diamond------------------------------"
	<< "\033[0;39m" << std::endl;
	std::cout << "t3's name : " << t3.get_name() << std::endl;
	std::cout << "t3's ClapTrap name : " << t3.ClapTrap::get_name() << std::endl;
	std::cout << "t3's Hit Points : " << t3.get_hitPoints() << std::endl;
	std::cout << "t3's energy : " << t3.get_energyPoints() << std::endl;
	std::cout << "t3's attack damage : " << t3.get_attackDamage() << std::endl;
	t3.attack("monster");
	t3.whoAmI();
	std::cout << "\n\033[0;94m" <<
	"------------------------------t4's diamond--------------------------------"
	<< "\033[0;39m" << std::endl;
	std::cout << "t4's name : " << t4.get_name() << std::endl;
	std::cout << "t4's ClapTrap name : " << t4.ClapTrap::get_name() << std::endl;
	std::cout << "t4's Hit Points : " << t4.get_hitPoints() << std::endl;
	std::cout << "t4's energy : " << t4.get_energyPoints() << std::endl;
	std::cout << "t4's attack damage : " << t4.get_attackDamage() << std::endl;
	t4.attack("monster");
	t4.whoAmI();
	std::cout << "\n\033[0;94m" <<
	"----------------------------operator= diamond------------------------------"
	<< "\033[0;39m" << std::endl;
	std::cout << "t5's name : " << t5.get_name() << std::endl;
	std::cout << "t5's ClapTrap name : " << t5.ClapTrap::get_name() << std::endl;
	std::cout << "t5's Hit Points : " << t5.get_hitPoints() << std::endl;
	std::cout << "t5's energy : " << t5.get_energyPoints() << std::endl;
	std::cout << "t5's attack damage : " << t5.get_attackDamage() << std::endl;
	t5.attack("monster");
	t5.whoAmI();
	std::cout << "\n\033[0;94m" <<
	"-----------------------------------test-------------------------------------"
	<< "\033[0;39m" << std::endl;
	t1.takeDamage(10);
	std::cout << "t1's Hit Points : " << t1.get_hitPoints() << std::endl;
	std::cout << "t1's energy : " << t1.get_energyPoints() << std::endl;
	std::cout << "t5's Hit Points : " << t5.get_hitPoints() << std::endl;
	std::cout << "t5's energy : " << t5.get_energyPoints() << std::endl;
	t1.beRepaired(30);
	std::cout << "t1's Hit Points : " << t1.get_hitPoints() << std::endl;
	std::cout << "t1's energy : " << t1.get_energyPoints() << std::endl;
	std::cout << "t5's Hit Points : " << t5.get_hitPoints() << std::endl;
	std::cout << "t5's energy : " << t5.get_energyPoints() << std::endl;
	t1.highFivesGuys();
	t1.guardGate();
	ScavTrap	*s1 = new DiamondTrap();
	delete s1;
	std::cout << "\n\033[0;94m" <<
	"------------------------------destructor call--------------------------------"
	<< "\033[0;39m" << std::endl;
}
