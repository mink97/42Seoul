/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:33:57 by mingkang          #+#    #+#             */
/*   Updated: 2023/04/25 18:13:49 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else
	{
		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++)
			{
				argv[i][j] = toupper(argv[i][j]);
			}
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
