#include"Dico.hpp"

Dico::Dico()	{}
Dico::~Dico()	{}

bool	Dico::init(const std::string & filename)
{
	_infile.open(filename.c_str());
	if (_infile.fail())
		return false;

	for (char i = 'A'; i <= 'Z' ; ++i)
		_data.insert(std::make_pair(i, std::vector<std::string>()));

	std::string	entry;
	while(std::getline(_infile, entry))
		_data[toupper(entry[0])].push_back(entry);

	_infile.close();
	return true;
}

bool	Dico::searchStr(const std::string & str)
{
	std::vector<std::string>	vect = _data[toupper(str[0])];

	if ( std::find(vect.begin(), vect.end(), str) != vect.end() )
		return true;
	return false;
}

void	Dico::printAll() const
{
	for (std::map<char, std::vector<std::string> >::const_iterator itMap = _data.begin(); itMap != _data.end(); ++itMap)
	{
		std::cout << "####\t" << itMap->first << "\t####" << std::endl;
		for (std::vector<std::string>::const_iterator itVect = itMap->second.begin(); itVect != itMap->second.end(); ++itVect)
			std::cout << *itVect<<  std::endl;
	}
}
