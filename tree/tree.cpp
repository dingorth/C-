#include "tree.h"
#include <stack>
#include <utility>
#include <string>
#include <stdexcept>

void tree::operator = ( tree&& t )
{
	// std::cout << "*move assignment*\n";
	std::swap( pntr, t.pntr );
}

void tree::operator = ( const tree& t )
{
	// std::cout << "*cpy assignment*\n";
	*this = tree(t);
}

const tree& tree::operator [ ] ( size_t i ) const
{
	if(i > nrsubtrees()-1 )
		throw std::runtime_error( "out of range" );	
	return pntr -> subtrees[i];
}

const std::string& tree::functor( ) const
{
	return pntr -> f;
}

size_t tree::nrsubtrees( ) const
{
	return pntr -> subtrees.size();
}

std::ostream& operator << ( std::ostream& stream, const tree& t )
{	
	std::string spaces_base = "  ";
	std::stack < std::pair<tree,size_t> > s;
	s.push( std::make_pair(t,0) );

	while(!s.empty())
	{
		std::pair<tree,size_t> tmp = s.top();
		size_t level = tmp.second;
		std::string spaces = "";
		for(size_t i=0; i<level; i++)
			spaces=spaces+spaces_base;
		stream << spaces << "+-" << tmp.first.functor() << "\n";

		s.pop();
		size_t subt = tmp.first.nrsubtrees();
		for(size_t i=0; i<subt; i++ )
			s.push( std::make_pair(tmp.first[subt-i-1],level+1) );
	}
	return stream;
}

void tree::ensure_not_shared( )
{
	if( pntr -> refcnt > 1)
	{
		pntr -> refcnt--;
		pntr = new trnode(pntr -> f , pntr -> subtrees ,1);
	}
}

void tree::replacesubtree( size_t i, const tree& t ){
	if(i > nrsubtrees()-1 )
		throw std::runtime_error( "out of range" );
	if( t.pntr == pntr -> subtrees[i].pntr )
		return;
	ensure_not_shared();
	pntr -> subtrees[i] = t;
}

void tree::replacefunctor( const std::string& f  )
{
	if( pntr -> f == f )
		return;
	ensure_not_shared();
	pntr -> f = f;
}

 tree subst( const tree& t, const std::string& var, const tree& val )
 {
    if( t.nrsubtrees() == 0){
    	if( t.functor() == var )
    		return val;
    	return t;
    }
    else
    {
    	tree rtn = t;
    	for( size_t i =0; i<rtn.nrsubtrees(); i++ )
    		rtn.replacesubtree( i, subst(rtn[i],var,val) );
    	return rtn;
    }

 }