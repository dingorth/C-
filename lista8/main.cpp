#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>


struct case_insensitive
{
	// Return true if s1 < s2, ignoring case of the letters.
	bool operator( ) ( const std::string& s1, const std::string& s2 ) const 
	{
		auto min = std::min(s1.size(), s2.size());
		for( size_t i =0; i < min; i++ )
		{
			auto l1 = tolower(s1[i]);
			auto l2 = tolower(s2[i]);
			if( l1 < l2 ) return true;
			if( l1 > l2 ) return false; 
		}
		if(s2.size() > min)
			return true;
		return false;
	}

};

std::map< std::string, unsigned int, case_insensitive > frequencytable( const std::vector < std::string > & text ) 
{
	std::map < std::string, unsigned int, case_insensitive > mapa;
	for( auto i = text.begin(); i != text.end(); ++i )
		mapa[*i]++;
	return mapa;
}


std::ostream& operator << ( std::ostream& stream, const std::map< std::string, unsigned int, case_insensitive > & freq )
{
	for( const auto &i : freq )
		stream << i.first << "\t" << i.second << "\n";
	return stream;
}

struct case_insensitive_hash
{
	size_t operator ( ) ( const std::string& s ) const
	{
		size_t w = 1;

		for(size_t i =0; i < s.size(); i++)
			w += (tolower(s[i])+ w*17) % 1000000007;

		return w;
	}
};

struct case_insensitive_equality
{
	bool operator ( ) ( const std::string& s1, const std::string& s2 ) const
	{
		auto i2 = s2.begin();
		for( auto i1 = s1.begin(); i1 != s1.end(); i1++ )
		{
			auto l1 = tolower(*i1);
			auto l2 = tolower(*i2); 
			if(l1 != l2)
				return false;
			i2++;
		}
		return true;
	}
};


std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > 
frequencytable_hash( const std::vector < std::string> & text )
{
	std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > mapa;
	for( auto i = text.begin(); i != text.end(); ++i )
		mapa[*i]++;
	return mapa;
}

std::ostream& operator << ( std::ostream& stream, 
const std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > & freq )
{
	for( const auto &i : freq )
		stream << i.first << "\t" << i.second << "\n";
	return stream;
}



int main(){


	std::vector < std::string > tst = {"Ala", "Ma", "kota", "a", "kota", "ma", "ala" };
	auto mapa = frequencytable_hash(tst);
	auto mapa2 = frequencytable(tst);

	case_insensitive_equality c;

	std::cout << mapa << "\n";
	std::cout << mapa2;




	return 0;
}