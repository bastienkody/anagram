#include"Dico.hpp"

Dico::Dico()	{}
Dico::~Dico()	{}

//	if str == "a": ret = "AA"
std::string	Dico::extractFirstTwoCharUpper(std::string src)
{
	std::string	ret;

	if (src.size() > 1)
		ret.assign(src.begin(), src.begin() + 2);
	else
		for (uint i = 0; i < 2; ++i)
			ret+= src[0];
	ret[0] = toupper(ret[0]);
	ret[1] = toupper(ret[1]);
	return ret;
}

bool	Dico::init(const std::string & filename)
{
	_infile.open(filename.c_str());
	if (_infile.fail())
		return false;

	for (char i = 'A'; i <= 'Z' ; ++i)
	{
		for (char j = 'A'; j <= 'Z' ; ++j)
		{
			std::string	tmp;
			tmp+=i; tmp+=j;
			_data.insert(std::make_pair(tmp, std::vector<std::string>()));
		}
	}

	std::string	entry;
	while(std::getline(_infile, entry))
		_data[extractFirstTwoCharUpper(entry)].push_back(entry);

	_infile.close();
	return true;
}

bool	Dico::searchStr(const std::string & str)
{
	std::vector<std::string>	vect = _data[extractFirstTwoCharUpper(str)];

	return std::binary_search(vect.begin(), vect.end(), str) ? true : false;
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
