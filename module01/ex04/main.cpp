/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:36:05 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/22 16:16:33 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

/*std::string replaceline(std::string line, std::string s1, std::string s2)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;
	//size_t	len = s1.length();
	char res[100];

	while (line[k])
	{
		if (strncmp(&line[i], s1.c_str(), s1.length()) == 0)
		{
			std::cout << line[i] << std::endl;
			j = 0;
			while (j < s2.length())
			{
				res[i] = s2[j];
				i++;
				j++;
			}
			k += s1.length();
		}
		else
		{
			res[i] = line[k];
			i++;
			k++;
		}
	}
	res[i] = '\0';
	return (res);
}*/

void	replaceline(std::string &str, std::string s1, std::string s2)
{
	size_t startPos = 0;

	while ((startPos = str.find(s1, startPos)) != std::string::npos)
	{
		str = str.substr(0, startPos) + s2 + str.substr(startPos + s1.length());
		startPos += s2.length();
	}
}

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		namereplace;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	namereplace = argv[1];
	namereplace.append(".replace");
	std::ofstream outfile(namereplace.c_str());
	file.open(argv[1]);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			line + "\n";
			replaceline(line, argv[2], argv[3]);
			outfile << line;
			if (!file.eof())
				outfile << std::endl;
		}
		file.close();
		outfile.close();
	}
	else
		std::cout << "Error: cannot open file" << std::endl;
	return (0);
}
