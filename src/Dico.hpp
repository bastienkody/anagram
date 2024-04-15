#ifndef DICO_HPP
#define DICO_HPP

#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include <vector>
#include <map>

#include "../inc/main.hpp"

/*
	Map de vector de string : 
	"A" : vector tous les mots en a
	"B" : vector tous les b etc

	C'est encore trop long il faut aller vers 26^26: 
	"AA": tous les mots en "aa"
	"AB":
	"AC":
	...
	"BA": 
	"BB"
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
