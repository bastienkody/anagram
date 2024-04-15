#ifndef DICO_HPP
#define DICO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

#include "../inc/main.hpp"

/*
	Map de vector de string : 
	"AA": tous les mots en "aa"
	"AB":
	"AC":
	...
	"ZY":
	"ZZ".
*/

class Dico
{
	public:

		Dico();
		~Dico();

		bool	init(const std::string & filename);
		bool	searchStr(const std::string & str);
		void	printAll() const ;

	private:

		std::ifstream										_infile;
		std::map<std::string, std::vector<std::string> >	_data;

		std::string	extractFirstTwoCharUpper(std::string src);

};

#endif
