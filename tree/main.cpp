#include "tree.h"



int main( int argc, char* argv [ ] )
{
   tree b1( std::string( "b1" ));
   tree b2( std::string( "b2" )); 
   tree b = tree( std::string( "b" ), { b1 , b2 } );

   tree a1( std::string( "a1" ));
   tree a2( std::string( "a2" )); 
   tree a3( std::string( "a3" ));
   tree a = tree( std::string( "a" ), { a1 , a2, a3 } );
   // tree a = tree ( std::string( "lol"));


   tree c1( std::string( "c1" ));
   tree c2( std::string( "c2" )); 
   tree c31( std::string( "c31" ));
   tree c32( std::string( "c32" ));  
   tree c3 = tree( std::string( "c3" ) , { c31, c32 } ); 
   tree c4( std::string( "c4" ));
   tree c = tree( std::string( "c" ), { c1 , c2, c3, c4 } );

   tree t = tree( std::string( "t" ), { a, b, c } ); 

   
/*
   +-t
     +-a
       +-a1
       +-a2
       +-a3
     +-b
       +-b1
       +-b2
     +-c
       +-c1
       +-c2
       +-c3
         +-c31
         +-c32
       +-c4
*/	


    // std::cout << t.get_refcnt() << "\n";

    // std::cout << t[0].get_refcnt() << "\n";

    tree tst1( std::string( "tst1" ));
   	tree tst2( std::string( "tst2" )); 
   	tree tst = tree( std::string( "tst" ), { tst1 , tst2 } );
    
    // tmp.replacefunctor("replaced");



    tree tmp = subst(t,"a1",tst);

    std::cout << tmp;



	return 0;   
}


