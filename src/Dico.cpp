#include"Dico.hpp"

Dico::Dico()	{}
Dico::~Dico()	{}

bool	Dico::init(const std::string & filename)
{
	_infile.open(filename.c_str());
	if (_infile.fail())
		return false;

	for (char i = 'A'; i <= 'Z' ; ++i)
	{
		for (char j = 'A'; i <= 'Z' ; ++j)
		{
			std::string	tmp;
			tmp+=i; tmp+=j;
			_data.insert(std::make_pair(tmp, std::vector<std::string>()));
		}
	}
// cas ou entry fait un seul char (ie: a, y)
	std::string	entry;
	while(std::getline(_infile, entry))
	{
		std::string	id(entry.begin(), entry.begin() +1);
		for (std::string::iterator it = id.begin(); it != id.end(); ++it)
			*it = toupper(*it);
		_data[id].push_back(entry);
	}

	_infile.close();
	return true;
}

bool	Dico::searchStr(const std::string & str)
{
	if (str.size() > 1)
		std::string	tmp(str.begin(), str.end());
	else
	{
		std::string	tmp = ;
	}
	std::vector<std::string>	vect = _data[tmp];

	if ( std::find(vect.begin(), vect.end(), str) != vect.end() )
		return true;
	return false;
}

void	Dico::printAll() const
{
	for (std::map<std::string, std::vector<std::string> >::const_iterator itMap = _data.begin(); itMap != _data.end(); ++itMap)
	{
		std::cout << "####\t" << itMap->first << "\t####" << std::endl;
		for (std::vector<std::string>::const_iterator itVect = itMap->second.begin(); itVect != itMap->second.end(); ++itVect)
			std::cout << *itVect<<  std::endl;
	}
}
